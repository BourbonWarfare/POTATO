/*
 * Author: PabstMirror
 * Creates a dismount squad arround a vehicle and adds parachutes for units exiting aircraft
 */

#include "script_component.hpp"

params ["_attachedVehicle", "_side", "_createUnits", "_placerOwner"];
TRACE_4("params",_attachedVehicle, _side, _createUnits,_placerOwner);


//Exit if bad conditions and send hint back to orginal module placer:
if (isNull _attachedVehicle) exitWith {
    ["Module needs to be attached on a vehicle", _placerOwner] call FUNC(sendCuratorHint);
};
if ((_attachedVehicle isKindOf "Air") && {((getPosATL _attachedVehicle) select 2) < 75}) exitWith {
    ["Aircraft is too low", _placerOwner] call FUNC(sendCuratorHint);
};
if ((!(_attachedVehicle isKindOf "Air")) && {(vectorMagnitude velocity _attachedVehicle) > 5}) exitWith {
    ["Vehicle moving too fast", _placerOwner] call FUNC(sendCuratorHint);
};
if !([_side, count _createUnits] call FUNC(canCreateGroup)) exitWith {
    ["Cannot create a new group at this time", _placerOwner] call FUNC(sendCuratorHint);
};

private _newGroup = createGroup [_side, true]; // explicitly mark for cleanup

private _cargoSelection = getText (configFile >> "CfgVehicles" >> (typeOf _attachedVehicle) >> "memoryPointsGetInCargo");
if (_cargoSelection == "") then {
    private _cargoSelection = getArray (configFile >> "CfgVehicles" >> (typeOf _attachedVehicle) >> "memoryPointsGetInCargo");
    if (_cargoSelection isEqualTo []) exitWith {};
    _cargoSelection = _cargoSelection select ((count _cargoSelection) - 1);
};

private _modelOffset = _attachedVehicle selectionPosition _cargoSelection;
TRACE_3("cargo eject point",typeOf _attachedVehicle,_cargoSelection,_modelOffset);
if (_modelOffset isEqualTo [0,0,0]) then {_modelOffset = [0,-8,0];};
_modelOffset = _modelOffset vectorAdd ((vectorNormalized _modelOffset) vectorMultiply 1.5); //move eject point further away from vic

[{
    params ["_args", "_PFID"];
    _args params ["_attachedVehicle", "_modelOffset", "_newGroup", "_createUnits"];

    if ((!alive _attachedVehicle) || {isNull _newGroup} || {(_createUnits isEqualTo [])}) exitWith {
        TRACE_4("done",alive _attachedVehicle,_newGroup,count units _newGroup,_createUnits);
        [_PFID] call CBA_fnc_removePerFrameHandler;
    };

    //Wait for area to be clear of other units/parachutes
    if ((_attachedVehicle isKindOf "Air") && {!((_attachedVehicle nearEntities 15) isEqualTo [_attachedVehicle])}) exitWith {};

    private _unitType = _createUnits deleteAt 0;
    private _posAGL = _attachedVehicle modelToWorld _modelOffset;
    if ((_posAGL select 2) < 3) then {_posAGL set [2, 0]}; // prevent creating in mid-air for ground vehicles
    private _unit = _newGroup createUnit [_unitType, _posAGL, [], 0, "FORM"];
    TRACE_2("created unit",_unitType,_unit);

    if (_attachedVehicle isKindOf "Air") then { //Add velocity and move into parachute
        _unit setPosASL (AGLtoASL _posAGL);
        _unit setVelocity ((velocity _attachedVehicle) vectorAdd ((vectorNormalized _modelOffset) vectorMultiply (random 10)));

        [{
            params ["_attachedVehicle", "_unit"];
            ((isTouchingGround _unit) || {!alive _unit}) || {(((getPosATL _unit) select 2) < 200) && {(_attachedVehicle distance _unit) > 6}}
        }, {
            params ["_attachedVehicle", "_unit"];
            if ((isTouchingGround _unit) || {!alive _unit}) exitWith {};

            private _posASL = getPosASL _unit;
            private _vel = velocity _unit;
            _vel set [2, ((_vel select 2) + (0 max (-0.3 * (_vel select 2))))];

            private _chute = "NonSteerable_Parachute_F" createVehicle _posASL;
            TRACE_2("",_unit,_chute);

            _unit moveInAny _chute;
            //make sure the idiots don't get out
            [{(_this select 0) moveInAny (_this select 1)}, [_unit, _chute], 1] call CBA_fnc_waitAndExecute;

            _chute setPosASL _posASL;
            _chute setVelocity _vel;
        }, [_attachedVehicle, _unit]] call CBA_fnc_waitUntilAndExecute;
    };
}, 1.5, [_attachedVehicle, _modelOffset, _newGroup, _createUnits]] call CBA_fnc_addPerFrameHandler;

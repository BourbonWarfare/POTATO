#include "script_component.hpp"

params ["_posATL", "_typeOf", ["_attachedVehicle", objNull, [objnull]]];
TRACE_3("params",_posATL,_typeOf,_attachedVehicle);

private _config = (configFile >> "CfgVehicles" >> _typeOf);
if (!isClass _config) exitWith {TRACE_1("bad class?",_config)};

private _curatorCanAttach = (getNumber (_config >> "curatorCanAttach")) > 0;
private _faction = toLower (((getText (_config >> "category")) splitString "_") param [2, "err", [""]]);
private _createVic = getText (_config >> QGVAR(createVic));
private _createUnits = getArray (_config >> QGVAR(createUnits));
private _crewAir = getText (_config >> QGVAR(crewAir));
private _crewArmor = getText (_config >> QGVAR(crewArmor));

TRACE_5("",_faction,_createVic,_createUnits,_crewAir,_crewArmor);

private _side = switch (_faction) do {
case ("east");
case ("msv"): {east};
case ("west"): {west;};
case ("ind"): {resistance;};
    default {sideUnknown};
};

private _newGroup = createGroup _side;
TRACE_4("",_side,_newGroup,_createVic,_createUnits);

if (_createVic != "") then {
    private _createArg = "NONE";
    private _crewType = _createUnits select 0;
    switch (true) do {
    case (_createVic isKindOf "Air"): {_createArg = "FLY"; _crewType = _crewAir};
    case (_createVic isKindOf "Wheeled_APC"): {_crewType = _crewArmor};
    case (_createVic isKindOf "Wheeled_APC_F"): {_crewType = _crewArmor};
    case (_createVic isKindOf "Tank"): {_crewType = _crewArmor};
    };
    private _newVehicle = createVehicle [_createVic,_posATL, [], 0, _createArg];
    _newVehicle setVariable ["F_Gear", "Empty", true]; //Clear gear on these
    _newGroup addVehicle _newVehicle;

    //custom `createVehicleCrew`
    {
        _x params ["", "_role", "_cargoIndex", "_turretPath"];
        if (_cargoIndex == -1 && {(_turretPath isEqualTo []) || {!(_newVehicle lockedTurret _turretPath)}}) then { //anything besides a cargo slot (and not locked)
            _unit = _newGroup createUnit [_crewType, _posATL, [], 0, "NONE"];
            TRACE_2("",_crewType,_unit);
            if (_role == "driver") then {
                _unit moveInDriver _newVehicle;
            } else {
                _unit moveInTurret [_newVehicle, _turretPath];
            };
        };
    } forEach (fullCrew [_newVehicle, "", true]);

    _newGroup selectLeader (effectiveCommander _newVehicle);
    _newGroup addVehicle _newVehicle;
} else {
    if (!_curatorCanAttach) then {
        {
            _unit = _newGroup createUnit [_x, _posATL, [], 0, "FORM"];
            TRACE_2("",_x,_unit);
        } forEach _createUnits;
    } else {
        //Paradrop / dismounts:
        if (isNull _attachedVehicle) exitWith {diag_log text format ["[POTATO] - Attachable not attached"];};
        if ((_attachedVehicle isKindOf "Air") && {((getPosATL _attachedVehicle) select 2) < 75}) exitWith {diag_log text format ["[POTATO] - Air veh too low"];};

        private _cargoSelection = getText (configFile >> "CfgVehicles" >> (typeOf _attachedVehicle) >> "memoryPointsGetInCargo");
        if (_cargoSelection == "") then {
            private _cargoSelection = getArray (configFile >> "CfgVehicles" >> (typeOf _attachedVehicle) >> "memoryPointsGetInCargo");
            if (_cargoSelection isEqualTo []) exitWith {};
            _cargoSelection = _cargoSelection select ((count _cargoSelection) - 1);
        };
        private _modelOffset = _attachedVehicle selectionPosition _cargoSelection;
        TRACE_3("cargo eject point",typeOf _attachedVehicle,_cargoSelection,_modelOffset);
        if (_modelOffset isEqualTo [0,0,0]) then {_modelOffset = [0,-10,0];};
        _modelOffset = _modelOffset vectorAdd ((vectorNormalized _modelOffset) vectorMultiply 1.5); //move eject further away from vic

        [{
            params ["_args", "_PFID"];
            _args params ["_attachedVehicle", "_modelOffset", "_newGroup", "_createUnits"];

            if ((!alive _attachedVehicle) || {isNull _newGroup} || {(_createUnits isEqualTo [])}) exitWith {
                [_PFID] call CBA_fnc_removePerFrameHandler;
            };

            //Wait for area to be clear of other units/parachutes
            if ((_attachedVehicle isKindOf "Air") && {!((_attachedVehicle nearEntities 15) isEqualTo [_attachedVehicle])}) exitWith {};

            private _unitType = _createUnits deleteAt 0;
            private _posAGL = _attachedVehicle modelToWorld _modelOffset;
            private _unit = _newGroup createUnit [_unitType, _posAGL, [], 0, "FORM"];
            TRACE_2("",_unitType,_unit);

            if (_attachedVehicle isKindOf "Air") then {
                _unit setPosASL (AGLtoASL _posAGL);
                _unit setVelocity ((velocity _attachedVehicle) vectorAdd ((vectorNormalized _modelOffset) vectorMultiply (random 10)));

                [{
                    params ["_attachedVehicle", "_unit"];
                    (isTouchingGround _unit) || {!alive _unit} || {(_attachedVehicle distance _unit) > 6}
                }, {
                    params ["_attachedVehicle", "_unit"];
                    if ((isTouchingGround _unit) || {!alive _unit}) exitWith {};

                    private _posASL = getPosASL _unit;
                    private _vel = velocity _unit;
                    _vel set [2, ((_vel select 2) + (0 max (-0.25 * (_vel select 2))))];

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
    };
};

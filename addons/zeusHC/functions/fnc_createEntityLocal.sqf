/*
 * Author: PabstMirror
 * Creates a crewed vehicle, group, or calls the create dismounts function
 */

#include "script_component.hpp"

params ["_posATL", "_typeOf", ["_attachedVehicle", objNull, [objnull]], "_placerOwner"];
TRACE_4("params",_posATL,_typeOf,_attachedVehicle,_placerOwner);

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

TRACE_3("",_side,_createVic,_createUnits);

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
    _newVehicle setVariable ["F_Gear", "Empty", true]; //Clear gear on these [BWMF]

    private _crew = fullCrew [_newVehicle, "", true];
    if ([_side, [_newVehicle] call FUNC(getCrewCount)] call FUNC(canCreateGroup)) then {
        private _newGroup = createGroup _side;

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
        deleteVehicle _newVehicle;
    };
} else {
    if (!_curatorCanAttach) then {
        [_side, _posATL, _createUnits, "FORM"] call FUNC(createGroup);
    } else {
        //Paradrop / dismounts:
        [_attachedVehicle, _side, _createUnits, _placerOwner] call FUNC(createEntityDismounts);
    };
};

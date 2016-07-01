/*
 * Author: AACO
 * Function used to safely spawn groups, will check for a group count and a total AI count
 *
 * Arguments:
 * 0: side of the group you want spawned <SIDE>
 * 1: location you want the units to spawn <ARRAY>
 * 2: array of unit classnames you want added to the group <ARRAY>
 * 3: should the units be spawned in a delayed fashion *MUST BE EXECUTED IN A SCHEDULED ENVIRONMENT!!* (optional, default: false) <BOOL>
 * 4: special formation to spawn the group with (optional, default: "NONE") <STRING>
 * 5: code you want to execute on each unit. _this will be the created unit (optional) <STRING>

 *
 * Return Value:
 * The created group or grpNull if the group couldn't be created <GROUP>
 *
 * Examples:
 * [west, position player, ["SoldierWB"]] call potato_zeusHC_fnc_createGroup;
 * [east, [1,2,3], ["SoldierWB","SoldierWB"], "FORM", "_this setPos [4,5,6];"] call potato_zeusHC_fnc_createGroup;
 *
 * Public: Yes
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_side", civilian, [civilian]],
    ["_vehicle", objNull, [objNull]],
    ["_crewType", "", [""]],
    ["_delayed", false, [false]]
];

private _crew = [];
private _crewCount = {
    _x params ["", "_role", "_cargoIndex"];
    if (_cargoIndex == -1 && _role in ["driver","commander","gunner"]) then {
        _crew pushBack _x;
        true
    } else {
        false
    };
} count (fullCrew [_vehicle, "", true]);

if ([_side, _crewCount] call FUNC(canCreateGroup)) then {
    private _group = createGroup _side;

    {
        _x params ["_cfgCrewType", "_role"];
        private _unit = _group createUnit [_crewType, [0,0,0], [], 0, "NONE"];

        switch (_role) do {
            case ("driver"): {
                _unit assignAsDriver _vehicle;
                _unit moveInDriver _vehicle;
            };
            case ("commander"): {
                _unit assignAsCommander _vehicle;
                _unit moveInCommander _vehicle;
            };
            case ("gunner"): {
                _unit assignAsGunner _vehicle;
                _unit moveInGunner _vehicle;
            };
        };

        if (_delayed && {_forEachIndex < (_crewCount - 1)}) then {
            sleep GVAR(delayBetweenUnitCreation);
        };
    } forEach _crew;

    _group addVehicle _vehicle;
    _group selectLeader (effectiveCommander _vehicle);

    _group
} else {
    deleteVehicle _vehicle;
    grpNull
};

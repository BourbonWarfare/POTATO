/*
 * Author: AACO
 * Function used to safely spawn a crew, will check for a group count and a total AI count
 *
 * Arguments:
 * 0: side of the crew you want spawned <SIDE>
 * 1: vehicle you want the crew added to <OBJECT>
 * 2: classname of the units spawned as the crew <STRING>
 * 3: should the units be spawned in a delayed fashion *MUST BE EXECUTED IN A SCHEDULED ENVIRONMENT!!* (optional, default: false) <BOOL>

 *
 * Return Value:
 * The created group or grpNull if the group couldn't be created <GROUP>
 *
 * Examples:
 * [west, vic, "SoldierWB", true] spawn potato_zeusHC_fnc_createCrew;
 *
 * Public: Yes
 */

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
        if (_role == "gunner" && {!("gunner" in _crew)}) then {
            _crew = ["gunner"] + _crew;
        } else {
            _crew pushBackUnique _role;
        };

        true
    } else {
        false
    };
} count (fullCrew [_vehicle, "", true]);

TRACE_1("",_crew);

if ([_side, _crewCount] call FUNC(canCreateGroup)) then {
    private _group = createGroup [_side, true]; // explicitly mark for cleanup

    {
        private _unit = _group createUnit [_crewType, [0,0,0], [], 0, "NONE"];
        [_unit] call EFUNC(core,addToCurator);

        switch (_x) do {
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

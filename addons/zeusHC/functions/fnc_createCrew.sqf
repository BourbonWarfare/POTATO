#include "script_component.hpp"
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

params [
    ["_side", civilian, [civilian]],
    ["_vehicle", objNull, [objNull]],
    ["_crewType", "", [""]],
    ["_delayed", false, [false]]
];
TRACE_4("createCrew",_side,_vehicle,_crewType,_delayed);

private _configRoot = configOf _vehicle;
private _crew = if (getNumber (_configRoot >> "hasDriver") == 1) then {
    [[-1]]
} else {
    []
};
private _fnc_getCrewedTurrets = { // based on part of BIS_fnc_getTurrets by Karel Moricky & Killzone_Kid
    params ["_config", ["_path", []]];
    {
        if (1 > getNumber (_x >> "dontCreateAI")) then {
            _crew pushBack (_path + [_forEachIndex]);
        };
        if (isClass (_x >> "Turrets")) then {
            [_x, _path + [_forEachIndex]] call _fnc_getCrewedTurrets
        };
    } forEach ("true" configClasses (_config >> "Turrets"));
};

_configRoot call _fnc_getCrewedTurrets;
private _crewCount = count _crew;

TRACE_1("",_crew);

if ([_side, _crewCount] call FUNC(canCreateGroup)) then {
    private _group = createGroup [_side, true]; // explicitly mark for cleanup

    {
        private _unit = _group createUnit [_crewType, [0,0,0], [], 0, "NONE"];
        [_unit] call EFUNC(core,addToCurator);

        if (_x isEqualTo [-1]) then {
            _unit assignAsDriver _vehicle;
            _unit moveInDriver _vehicle;
        } else {
            _unit assignAsTurret [_vehicle, _x];
            _unit moveInTurret [_vehicle, _x];
        };

        if (_delayed && canSuspend && {_forEachIndex < (_crewCount - 1)}) then {
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

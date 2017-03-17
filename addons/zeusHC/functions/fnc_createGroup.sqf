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

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_side", civilian, [civilian]],
    ["_position", [0,0,0], [[]], 3],
    ["_classNames", [], [[]]],
    ["_delayed", false, [false]],
    ["_special", "NONE", [""]],
    ["_code", "", [""]]
];

private _numUnitsToSpawn = count _classNames;
if !([_side, _numUnitsToSpawn] call FUNC(canCreateGroup)) exitWith { grpNull };

private _unitInitFunction = compile _code;
private _newGroup = createGroup [_side, true]; // explicitly mark for cleanup

{
    private _newUnit = _newGroup createUnit [_x, _position, [], 0, _special];
    _newUnit call _unitInitFunction;

    if (_delayed && {_forEachIndex < (_numUnitsToSpawn - 1)}) then {
        sleep GVAR(delayBetweenUnitCreation);
    };
} forEach _classNames;

// explicitly select leader
_newGroup selectLeader ((units _newGroup) select 0);

_newGroup

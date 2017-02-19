/*
 * Author: AACO
 * Function used to check if the group can be safely created
 *
 * Arguments:
 * 0: side of the group you want spawned <SIDE>
 * 1: Number of units in the group <NUMBER>
 *
 * Return Value:
 * True if the group can be safely create, false otherwise <BOOL>
 *
 * Examples:
 * [west, 1] call potato_zeusHC_fnc_canCreateGroup;
 * [east, 5] call potato_zeusHC_fnc_canCreateGroup;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_side", civilian, [civilian]],
    ["_numberOfUnits", 0, [0]]
];

// ensure we're not creating an empty group
if (_numberOfUnits < 1) exitWith {
    ["Cannot create empty group"] call FUNC(sendCuratorHint);
    false
};

// ensure we're within our group limit
private _currentSideGroupCount = { side _x == _side } count allGroups;
if (_currentSideGroupCount >= GVAR(maxGroupCountPerSide)) exitWith {
    ["Cannot create group, at side group limit"] call FUNC(sendCuratorHint);
    false
};

// ensure we're within our AI limit
private _currentAICount = count (allUnits - allPlayers);
if ((_currentAICount + _numberOfUnits) > GVAR(maxAICount)) exitWith {
    ["Cannot create group, would exceed the AI limit"] call FUNC(sendCuratorHint);
    false
};

true

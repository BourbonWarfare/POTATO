/*
 * Author: AACO
 * Slots the given sepctator into the given path
 *
 * Arguments:
 * 0: Spectator to slot <OBJECT>
 * 1: Path to place the spectator into <ARRAY>
 * 2: Should the unit be forced into the slot <BOOL>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [player, [1,2], true] call potato_respawn_fnc_slotUnit;
 *
 * Public: No
 */

#include "script_component.hpp"
#define UNIT_INDEX 3
#define UNITS_INDEX 8
#define UNIT_DISPLAY_NAME_INDEX 1
TRACE_1("params",_this);

// if we're not on the server, pass to the server
if !(isServer) exitWith {
    _this remoteExecCall [QFUNC(slotUnit), SERVER_CLIENT_ID];
};

params [
    "_spectator",
    "_slotPath",
    ["_force", false, [false]]
];

_slotPath params [
    "_groupIndex",
    "_unitIndex"
];

private _currentlySlottedUnit = (((GVAR(activeGroups) select _groupIndex) select UNITS_INDEX) select _unitIndex) select UNIT_INDEX;
if !(isNull _currentlySlottedUnit || _force) exitWith { LOG("Path is currently occupied"); };

(((GVAR(activeGroups) select _groupIndex) select UNITS_INDEX) select _unitIndex) set [UNIT_INDEX, _spectator];
private _displayName = (((GVAR(activeGroups) select _groupIndex) select UNITS_INDEX) select _unitIndex) select UNIT_DISPLAY_NAME_INDEX;

[_spectator, _displayName, _slotPath] remoteExecCall [QFUNC(slotUnitClient), GVAR(registeredClients)];

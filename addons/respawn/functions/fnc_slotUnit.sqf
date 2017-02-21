/*
 * Author: AACO
 * desc
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_;
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
    ["_isAdmin", false, [false]]
];

_slotPath params [
    "_groupIndex",
    "_unitIndex"
];

private _currentlySlottedUnit = (((GVAR(activeGroups) select _groupIndex) select UNITS_INDEX) select _unitIndex) select UNIT_INDEX;
if !(isNull _currentlySlottedUnit || _isAdmin) exitWith { LOG("Path is currently occupied"); };

if (!isNull _currentlySlottedUnit) then {
    //[_currentlySlottedUnit, _slotPath] call FUNC(unslotUnit);
};

(((GVAR(activeGroups) select _groupIndex) select UNITS_INDEX) select _unitIndex) set [UNIT_INDEX, _spectator];
private _displayName = (((GVAR(activeGroups) select _groupIndex) select UNITS_INDEX) select _unitIndex) select UNIT_DISPLAY_NAME_INDEX;

[_spectator, _displayName, _slotPath] remoteExecCall [QFUNC(slotUnitClient), GVAR(registeredClients)];

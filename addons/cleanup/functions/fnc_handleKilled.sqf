/*
 * Author: AACO
 * Function used register a dead object for cleanup.
 * Should only be called from events
 *
 * Arguments:
 * 0: Object to delete <OBJECT>
 *
 * Examples:
 * [player] call potato_cleanup_fnc_handleKilled;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params [["_object", objNull, [objNull]]];

if (!GVAR(deadCleanupEnabled) || {isNull _object} || {_object getVariable [QGVAR(wasPlayer), false]} || {_object getVariable [QGVAR(ignore), false]}) exitWith {};

_object setVariable [QGVAR(killedAt), CBA_missionTime];
[_object] call FUNC(watchGarbage);

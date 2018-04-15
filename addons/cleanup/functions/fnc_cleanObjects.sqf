/*
 * Author: AACO
 * Function used to cleanup objects
 *
 * Arguments:
 * 0: Array of objects to cleanup <ARRAY>
 *
 * Examples:
 * [[player]] call potato_cleanup_fnc_cleanObjects;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);

if (!isServer) exitWith {
    _this remoteExecCall [QFUNC(cleanObjects), SERVER_CLIENT_ID];
};

params ["_objects"];
{
    [_x] call FUNC(cleanGarbage);
} forEach _objects;

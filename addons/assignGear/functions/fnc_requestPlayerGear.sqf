/*
 * Author: AACO
 * Simple passthrough function that will request gear from the server
 *
 * Arguments:
 * 0: Player who is requesting the gear <OBJECT>
 *
 * Example:
 * [player] call potato_assignGear_fnc_requestPlayerGear;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);

// if not executed on server, pass to server
if !(isServer) exitWith { _this remoteExecCall [QFUNC(requestPlayerGear), SERVER_CLIENT_ID]; };

params [["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith { WARNING("Provided unit is null"); };
[_unit, true] call FUNC(assignGearMan);

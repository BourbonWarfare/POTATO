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

params [["_unit", objNull, [objNull]]];
TRACE_1("requestPlayerGear",_unit);

_unit setVariable [QGVAR(changeOpticsTimeLimit), CBA_missionTime + 120];

// if not executed on server, pass to server
if !(isServer) exitWith { _this remoteExecCall [QFUNC(requestPlayerGear), SERVER_CLIENT_ID]; };

if (isNull _unit) exitWith { WARNING("Provided unit is null"); };
[_unit] call FUNC(assignGearMan);

#include "script_component.hpp"
/*
 * Setup server EH for script error reporting
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * [] call potato_core_fnc_init_serverScriptErrors;
 */

if (!isServer) exitWith {};

GVAR(serverScriptErrorNext) = -999;
addMissionEventHandler ["ScriptError", {
    if (CBA_missionTime < GVAR(serverScriptErrorNext)) exitWith {}; // so we don't get spamed
    GVAR(serverScriptErrorNext) = CBA_missionTime + 60;
    params ["_errorText", "_sourceFile", "_lineNumber", "_errorPos", "_content", "_stackTraceOutput"];
    private _msg = format ["ScriptError: [%1] in [%2]", _errorText, _sourceFile select [0, 60]];
    [{
        params ["_msg"];
        private _to = ["#ALL", "#TECH"] select ((count allPlayers) > 4); // Send to everyone when mission testing
        ["potato_adminMsg", [_msg, "Server", _to]] call CBA_fnc_globalEvent;
    }, [_msg], 1] call CBA_fnc_waitAndExecute;
}];

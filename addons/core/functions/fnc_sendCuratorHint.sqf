/*
 * Author: AACO
 * Function used to send a hint to all curators
 *
 * Arguments:
 * 0: message to send to zeuses <STRING>
 *
 * Return Value:
 * nil in case of error, empty string otherwise
 *
 * Examples:
 * ["You're a zeus, congratulations"] call potato_common_fnc_sendCuratorHint
 *
 * Public: Yes
 */

#include "script_component.hpp"
params ["_message"];
TRACE_1("Curator message", _message);

diag_log text format ["[POTATO] - %1", _message];
_message remoteExecCall ["hint", allCurators]

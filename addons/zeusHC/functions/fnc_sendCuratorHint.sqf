/*
 * Author: AACO
 * Function used to send a hint to all curators
 *
 * Arguments:
 * 0: message to send to zanes <STRING><STRUCTUREDTEXT>
 * 1: Client to send message to (optional, default all curators) <ARRAY,OBJECT,NUMBER>
 *
 * Return Value:
 * nil in case of error, empty string otherwise
 *
 * Examples:
 * ["You're a zeus, congratulations"] call potato_zeusHC_fnc_sendCuratorHint
 * ["You're specifically a zeus, congratulations", objZeusMan] call potato_zeusHC_fnc_sendCuratorHint
 *
 * Public: Yes
 */

#include "script_component.hpp"

params ["_message", ["_curators", allCurators]];
TRACE_2("Curator message",_message,_curators);

diag_log text format ["[POTATO] - %1, sent to: %2", _message, _curators];
[_message] remoteExecCall [QACEFUNC(common,displayTextStructured), _curators]

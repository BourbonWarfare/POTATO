/*
 * Author: PabstMirror
 * Function used to add a briefing to a group/unit on the frame after init
 *
 * Arguments:
 * 0: Object to add briefing to <OBJECT/GROUP>
 * 1: Briefing to add <STRING>
 *
 * Examples:
 * [player, "player brief"] call potato_briefing_fnc_setBriefingVar;
 * [group player, "group brief"] call potato_briefing_fnc_setBriefingVar;
 *
 * Public: Yes
 */

#include "script_component.hpp"

params ["_thing", ["_briefing", "", [""]]];
TRACE_2("params",_thing,_briefing);

if (_briefing == "") exitWith {};

[{
    (_this select 0) setVariable [QGVAR(briefing), (_this select 1), true];
}, [_thing, _briefing]] call CBA_fnc_execNextFrame;

/*
 * Author: PabstMirror
 * Function used to add unit and group briefings as well as the OrBat
 * and credits to a player's diary
 *
 * Arguments:
 * 0: Unit to add to the briefings to <OBJECT>
 *
 * Examples:
 * [player] call potato_briefing_fnc_addBriefingToUnit;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);

params [["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith {};

systemChat "You have been assigned zeus";

private _zeusIntent = getMissionConfigValue [QGVAR(zeusIntent), ""];
if (_zeusIntent == "") exitWith {};
_zeusIntent = [_zeusIntent] call FUNC(convertNewLineToHTML);

systemChat "Mission has custom zeus briefing";
_unit createDiaryRecord ["diary", ["Zeus", _zeusIntent]];

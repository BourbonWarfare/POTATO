#include "..\script_component.hpp"
/*
 * Author: PabstMirror
 * Update player's goBy global var when changing controlled unit or changing setting-string
 *
 * Arguments:
 * None
 */

if (!alive player) exitWith {};
if (player != ace_player) exitWith {}; // ignore zeusing
if (GVAR(goBy) == "") exitWith {};

private _sanatized = [GVAR(goBy), true] call ace_common_fnc_sanitizeString;
TRACE_1("setting goBy sync %1",_sanatized);
player setVariable [QGVAR(goBy), _sanatized, true];
[QGVAR(updateUnit), player] call CBA_fnc_globalEvent; // let everyone know to update me

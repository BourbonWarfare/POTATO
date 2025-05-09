#include "..\script_component.hpp"

if (!alive player) exitWith {};
if (player != ace_player) exitWith {}; // ignore zeusing
if (GVAR(goBy) == "") exitWith {};

private _sanatized = [GVAR(goBy), true] call ace_common_fnc_sanitizeString;
TRACE_1("setting goBy sync %1",_sanatized);
player setVariable [QGVAR(goBy), _sanatized, true];

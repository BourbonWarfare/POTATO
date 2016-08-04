/*
 *
 */
#include "script_component.hpp"

params ["_thing", ["_languageArray",[],[[]]]];
TRACE_2("params",_thing,_languageArray);

if (_languageArray isEqualTo []) exitWith { LOG("No languages set, exiting"); };

[{
    (_this select 0) setVariable [QGVAR(assignedLanguages), (_this select 1), true];
}, [_thing, _languageArray]] call CBA_fnc_execNextFrame;

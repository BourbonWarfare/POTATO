#include "script_component.hpp"

params ["_thing", "_briefing"];
TRACE_2("params",_thing,_briefing);

if (_briefing == "") exitWith {};

[{
    (_this select 0) setVariable [QGVAR(briefing), (_this select 1), true];
}, [_thing, _briefing]] call CBA_fnc_execNextFrame;

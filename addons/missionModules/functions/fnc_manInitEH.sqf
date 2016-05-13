#include "script_component.hpp"

params ["_unit"];
TRACE_1("params",_unit);

if (!local _unit) exitWith {};

[FUNC(setSkillsLocal), [_unit]] call CBA_fnc_execNextFrame;

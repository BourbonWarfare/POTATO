#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_group","_value"];

[{
    params ["_group","_value"];
    (_group) setVariable [QGVAR(addGroupToHC), _value, true];
}, [_group, _value]] call CBA_fnc_execNextFrame;

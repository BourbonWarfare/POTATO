#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_checkVar","_threshold"];

if !(_checkVar isEqualType "" && _threshold isEqualType 0) exitWith {TRACE_2("Bad type(s)",_checkVar,_threshold); false};

diag_ticktime >= ((_unit getVariable [_checkVar, 0]) + _threshold)

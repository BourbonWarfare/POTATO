#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_checkVar","_threshold"];

diag_ticktime >= (_unit getVariable [_checkVar, 0] + _threshold)

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

[_unit] execFSM "\z\potato\addons\aiFrameworks\fsms\vcom_behavior.fsm";

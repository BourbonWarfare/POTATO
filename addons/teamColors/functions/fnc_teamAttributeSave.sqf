/*
 *
 */

#include "script_component.hpp"
TRACE_2("params",_this,_this getVariable QGVAR(selectedColor));

[TEAM_COLORS] select (_this getVariable [QGVAR(selectedColor),0]);

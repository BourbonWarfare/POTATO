#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_waypointPosition"];

_unit getRelPos [60, _unit getDir _waypointPosition]

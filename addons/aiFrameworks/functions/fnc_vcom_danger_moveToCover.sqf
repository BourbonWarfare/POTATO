#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

if !([_unit,VQGVAR(movedRecentlyCover),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold)) then {
    [_unit] call VFUNC(moveToCover);
};

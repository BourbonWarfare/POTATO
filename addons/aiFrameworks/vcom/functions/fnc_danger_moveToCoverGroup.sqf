#include "script_component.hpp"
TRACE_1("params",_this);

params ["_group"];

{
    if !([_x,VQGVAR(movedRecentlyCover),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold)) then {
        [_x] call VFUNC(moveToCover);
    };
    nil
} count (units _group);

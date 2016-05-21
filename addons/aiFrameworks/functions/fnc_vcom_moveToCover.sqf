#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

[_unit] call VFUNC(throwGrenade);
private _closestCover = [_unit] call VFUNC(findCoverPos);

if (isNil "_closestCover") exitWith {};

_unit setVariable [VQGVAR(inCover),false];

_unit setUnitPosWeak "MIDDLE";

[_unit,_closestCover] spawn {
    private _waitTime = diag_ticktime + 15;
    while {alive _unit && !(diag_ticktime > _waitTime) && (_unit distance _closestCover) > 2} do {
        _unit doMove _closestCover;
        _unit forceSpeed -1;
        sleep 2;
    };

    _unit setVariable [VQGVAR(inCover),true];
};

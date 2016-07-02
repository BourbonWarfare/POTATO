#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _unitSide = side (group _unit);

private _returnUnits = [];
{
    if (side _x == _unitSide) then {
        {
            if (alive _x) then { _returnUnits pushBack _x; };
            nil
        } count (units _x);
    };
    nil
} count allGroups;

_returnUnits

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _unitSide = side (group _unit);

private _returnGroups = [];
{
	if ((side _x) == _unitSide) then {
        _returnGroups pushBack _x;
    };
    nil
} count allGroups;

_returnGroups

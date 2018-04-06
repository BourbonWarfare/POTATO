#include "script_component.hpp"

TRACE_1("params",_this);

private _positions = [];
{
    if (isPlayer _x) then {
        _positions pushBack [eyePos _x];
    };
} forEach allUnits;

_positions

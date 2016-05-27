#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _returnValue = false;
private _position = getposASL _unit;

private _array = lineIntersectsObjs [_position,[_position select 0,_position select 1,(_position select 2) - 10], objnull, objnull, true, 4];
{
    if (_x isKindof "Building") exitWith { _returnValue = true; };
    nil
} count _array;

if (_returnValue) exitWith { _returnValue };

_array = lineIntersectsObjs [_position, [_position select 0,_position select 1,(_position select 2) + 10], objnull, objnull, true, 4];
{
    if (_x isKindof "Building") exitWith { _returnValue = true; };
    nil
} count _array;

_returnValue

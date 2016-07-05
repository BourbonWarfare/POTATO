/*
 * Author: AACO
 */

#include "script_component.hpp"
TRACE_1("params",_this);

[
    {
        params ["_object","_name","_value",["_global",false,[false]]];
        _object setVariable [_name, _value, _global];
    },
    _this
] call CBA_fnc_execNextFrame;

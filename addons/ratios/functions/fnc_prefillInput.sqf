#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ratioArray","_ratioCount","_index"];

private _returnString = str 1;

if (_index < _ratioCount) then {
    private _ratioValue = parseNumber (_ratioArray select _index);
    if (_ratioValue > 0) then {
        _returnString = str _ratioValue;
    }
};

TRACE_1("return",_returnString);
_returnString

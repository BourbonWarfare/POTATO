#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _vehicle = vehicle _unit;

if (_vehicle == _unit) exitWith { false };

driver _vehicle == _unit

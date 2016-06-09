#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

[_unit] call VFUNC(defaultSetup);

private _notInVehicle = _unit == vehicle _unit;
private _leader = _unit == leader _unit;

if (_unit != vehicle _unit) then {

} else {

};

//[_unit] execFSM "\z\potato\addons\aiFrameworks\fsms\vcom_behavior.fsm";

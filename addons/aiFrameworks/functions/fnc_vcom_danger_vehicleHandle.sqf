#include "script_component.hpp"
TRACE_1("params",_this);

/*
_AssignedCargo = assignedCargo (vehicle _this);

if (_this in _AssignedCargo) then
{
	[_this] orderGetIn false;
	_this leaveVehicle (vehicle _this);
	unassignVehicle _this;
	commandGetOut _this;
	doGetOut _this;
	_this action ["eject", _Vehicle];
	(vehicle _this) land "GET OUT";
	_Vehicle land "GET OUT";
};

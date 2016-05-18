#include "script_component.hpp"
TRACE_1("params",_this);

//Script will make AI use the proper stances depending on friendlies behind them.

while {_this getVariable "VCOMAI_ActivelyClearing"} do
{
	_this spawn
	{
		_BehindUnit = _this modelToWorld [0,-1,0.5];
		_Nearobjects = _BehindUnit nearObjects ["Man",2];
		if (_this in _Nearobjects) then {_Nearobjects = _Nearobjects - [_this]};
		_NearestUnit = [_Nearobjects,_BehindUnit] call VCOMAI_ClosestObject;
		if (isNil "_NearestUnit" || {typeName _NearestUnit isEqualTo "ARRAY"}) exitWith {_this setUnitPosWeak "UP";};
		if (_NearestUnit isEqualTo _this) then {_this setUnitPosWeak "UP";};
		_StanceCompare = stance _NearestUnit;
		if (_StanceCompare isEqualTo "STAND") then {_this setUnitPosWeak "MIDDLE";};
		if (_StanceCompare isEqualTo "CROUCH") then {_this setUnitPosWeak "DOWN";};
		if (_StanceCompare isEqualTo "PRONE") then {_this setUnitPosWeak "UP";};
		if (_StanceCompare isEqualTo "UNDEFINED") then {_this setUnitPosWeak "UP";};
		if (_StanceCompare isEqualTo "") then {_this setUnitPosWeak "UP";};
	};
	sleep 1;
};

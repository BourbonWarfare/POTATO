#include "script_component.hpp"
TRACE_1("params",_this);

//if !(_this getVariable "VCOM_VisuallyCanSee") then
//{

	_MovingToWP = _this getVariable ["VCOM_MovedRecently",false];
	_MovingToCover = _this getVariable ["VCOM_InCover",true];

	if (_MovingToWP || !(_MovingToCover)) exitWith {};

	_NearestEnemy = _this call VCOMAI_ClosestEnemy;
	if (isNil "_NearestEnemy" || {(typeName _NearestEnemy isEqualTo "ARRAY")} || {isNil "_this"} || {!(alive _NearestEnemy)} || {(_NearestEnemy distance _this) > 5000}) exitWith {};

	_intersections = lineIntersectsSurfaces [eyePos _this,eyepos _NearestEnemy,_this,_NearestEnemy, true, 1];

	if ((count _intersections) isEqualTo 0 && ((_NearestEnemy distance _this) < 1000)) then
	{
			_this setVariable ["VCOM_VisuallyCanSee",true,false];
			_this forceSpeed 0;
			_this setUnitPos "AUTO";
			_this suppressfor 5;
	}
	else
	{
			_this setVariable ["VCOM_VisuallyCanSee",false,false];
			//_this spawn {sleep 10;if !(_this getVariable "VCOM_VisuallyCanSee") then {_this forceSpeed -1;};};
	};
//};

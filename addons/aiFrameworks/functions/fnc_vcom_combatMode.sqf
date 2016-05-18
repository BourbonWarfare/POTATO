#include "script_component.hpp"
TRACE_1("params",_this);

//VCOMAI_CombatMode
_TimeShot = _this getVariable "VCOM_FiredTime";
_NearestEnemy = _this call VCOMAI_ClosestEnemy;
if (isNil "_NearestEnemy") then {_NearestEnemy = [0,0,0];};

if ((diag_tickTime - _TimeShot) > 60 && ((_NearestEnemy distance _this) > 1000)) then
{
	_this setBehaviour (_this getVariable "VCOMAI_LastCStance");
};

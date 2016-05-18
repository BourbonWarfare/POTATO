#include "script_component.hpp"
TRACE_1("params",_this);

private ["_Unit", "_TargetPosition", "_unit", "_NewPosition", "_Accuracy", "_Shake", "_Speed", "_SpotTime", "_SpotDistance", "_RankReturn"];

_Unit = _this;

_Unit setVariable ["VCOM_DiagLastCheck",diag_ticktime,false];

_TargetPosition = _Unit getvariable "VCOM_AssignedEnemy";

if (_TargetPosition isEqualTo [0,0,0]) then
{
	_target = assignedTarget _unit;
	_TargetPosition = getpos _target;
	_Unit setVariable ["VCOM_AssignedEnemy",_TargetPosition,false];
}
else
{
	_target = assignedTarget _unit;
	_NewPosition = getpos _Target;
	_Unit setVariable ["VCOM_AssignedEnemy",_NewPosition,false];


	if (_TargetPosition distance _NewPosition < 15) then
	{
		_Accuracy = _Unit skill "aimingAccuracy";
		_Shake = _Unit skill "aimingShake";
		_Speed = _Unit skill "aimingSpeed";
		_SpotTime = _Unit skill "spotTime";
		_SpotDistance = _Unit skill "spotDistance";

		_Unit setSkill ["aimingAccuracy",_Accuracy + 0.1];
		_Unit setSkill ["aimingShake",_Shake + 0.1];
		_Unit setSkill ["aimingSpeed",_Speed + 0.1];
		_Unit setSkill ["spotTime",_SpotTime + 0.1];
		_Unit setSkill ["spotDistance",_SpotDistance + 0.1];
	}
	else
	{
		_RankReturn = _Unit call VCOMAI_RankAndSkill;
	};
};

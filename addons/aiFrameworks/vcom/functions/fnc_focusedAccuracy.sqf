#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _oldTargetPos = _unit getvariable [VQGVAR(assignedEnemyPos), [0,0,0]];

if (_oldTargetPos isEqualTo [0,0,0]) then {
    _unit setVariable [VQGVAR(assignedEnemyPos), position (assignedTarget _unit)];
} else {
    private _target = assignedTarget _unit;
    private _newPosition = getpos _target;
    _unit setVariable [VQGVAR(assignedEnemyPos),_newPosition];

    if ((_oldTargetPos distance _newPosition) < VGVAR(maxDistanceToConsiderTargetStatic)) then {
        _unit setSkill ["aimingAccuracy", (_unit skill "aimingAccuracy") + 0.1];
        _unit setSkill ["aimingShake", (_unit skill "aimingShake") + 0.1];
        _unit setSkill ["aimingSpeed", (_unit skill "aimingSpeed") + 0.1];
        _unit setSkill ["spotTime", (_unit skill "spotTime") + 0.1];
        _unit setSkill ["spotDistance", (_unit skill "spotDistance") + 0.1];
    }
    else {
        [_unit] call EFUNC(missionModules,setSkillsLocal);
    };
};

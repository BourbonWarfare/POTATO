#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

if (isNil "_unit" || {isNull _unit}) exitWith {};

if ([_unit,VQGVAR(grenadeThrown),VGVAR(grenadeThreshold)] call VFUNC(pastThreshold) && {VGVAR(chanceToUseGrenade) <= random 100}) then {
    private _nearestEnemy = [_unit] call VFUNC(closestEnemy);
    if (isNull _nearestEnemy) exitWith {};

    private _checkDistance = (_unit distance _nearestEnemy);

    if (!([_unit,_nearestEnemy] call VFUNC(canSee))
            && {_checkDistance < 60}
            && {_checkDistance > 6}) then {

        _unit setVariable [VQGVAR(grenadeThrown),diag_tickTime];

        _unit setDir (_unit getDir _nearestEnemy);
        _unit forceWeaponFire ["HandGrenadeMuzzle","HandGrenadeMuzzle"];
        _unit forceWeaponFire ["MiniGrenadeMuzzle","MiniGrenadeMuzzle"];
    } else {
        if (VGVAR(useSmoke) && {_checkDistance < VGVAR(maxDistanceToSmoke)} && {[missionNamespace,VQGVAR(lastSmokeThrown),VGVAR(globalSmokeThreshold)] call VFUNC(pastThreshold)}) then {
            missionNamespace setVariable [VQGVAR(lastSmokeThrown), diag_tickTime, true];
            _unit setDir (_unit getDir _nearestEnemy);
            _unit forceWeaponFire ["SmokeShellMuzzle","SmokeShellMuzzle"];
        };
    };
};

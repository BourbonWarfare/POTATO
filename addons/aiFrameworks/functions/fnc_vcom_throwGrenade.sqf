#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

if (isNil "_unit" || {isNull _unit}) exitWith {};

if ([_unit,VQGVAR(grenadeThrown),VGVAR(grenadeThreshold)] call VFUNC(pastThreshold) && {VGVAR(chanceToUseGrenade) <= random 100}) then {
    private _nearestEnemy = [_unit] call VFUNC(closestEnemy);
    if (isNull _nearestEnemy) exitWith {};

    private _checkDistance = (_unit distance _nearestEnemy);

    if !(lineintersects [eyepos _unit, eyepos _nearestEnemy, _unit, _nearestEnemy]
        && {_checkDistance < 60}
        && {_checkDistance > 6}) then {

        _unit setDir (_unit getDir _nearestEnemy);
        _unit forceWeaponFire ["HandGrenadeMuzzle","HandGrenadeMuzzle"];
        _unit forceWeaponFire ["MiniGrenadeMuzzle","MiniGrenadeMuzzle"];
    } else {
        if (_checkDistance < VGVAR(maxDistanceToSmoke) && VGVAR(useSmoke)) then {
                _unit setDir (_unit getDir _nearestEnemy);
                _unit forceWeaponFire ["SmokeShellMuzzle","SmokeShellMuzzle"];
            };
        };
    };
};

#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_nearestEnemy"];

private _groupSide = (side (group _unit));

private _support = [];
{
    if (_groupSide == side _x) then {
        {
            if (alive _x
                    && {_x getVariable [VQGVAR(isArtillery),false]}
                    && {[_x,VQGVAR(lastFiredArtillery),VGVAR(artilleryFireThreshold)] call VFUNC(pastThreshold)}
                    && {count (getArtilleryAmmo [(vehicle _x)]) > 0}) then {
                _support pushBackUnique (vehicle _x);
            };
            nil
        } count units _x;
    };

    nil
} count allGroups;

TRACE_1("",_support);
while {count _support > 0} do {

    private _returnedSupport = [_support, _unit] call VFUNC(closestObject);
    if (isNull _returnedSupport) exitWith {};

    private _artilleryUnits = crew _returnedSupport;
    TRACE_2("",_returnedSupport,_artilleryUnits);

    private _ammoArray = getArtilleryAmmo [_returnedSupport];
    private _ammoCount = count _ammoArray;
    if (_ammoCount > 0) then {
        private _randomAmmo = _ammoArray select (floor random [0,0,_ammoCount]);
        private _enemyPos  = getPos _nearestEnemy;
        TRACE_3("",_ammoArray,_randomAmmo,_enemyPos);

        if (_enemyPos inRangeOfArtillery [[_returnedSupport],_randomAmmo]) exitWith {
            _unit setVariable [VQGVAR(calledArtillery),diag_tickTime];
            { _x setVariable [VQGVAR(lastFiredArtillery),diag_tickTime,true]; _x setSkill ["aimingSpeed", 1]; nil } count _artilleryUnits;

            private _firePosition = [
                (_enemyPos select 0) + ((random VGVAR(maximumRoundDispersion)) - (VGVAR(maximumRoundDispersion) / 2)),
                (_enemyPos select 1) + ((random VGVAR(maximumRoundDispersion)) - (VGVAR(maximumRoundDispersion) / 2)),
                _enemyPos select 2
            ];
            _returnedSupport doArtilleryFire [_firePosition, _randomAmmo, 1 + floor(random VGVAR(maximumRoundsPerBarrage))];
        };
    };
    _support = _support - [_returnedSupport];
};

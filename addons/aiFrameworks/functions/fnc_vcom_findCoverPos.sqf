#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_movePosition"];

if (_unit getVariable [VQGVAR(startedInside),false]
        || {_unit getVariable [VQGVAR(garrisoned),false]}
        || {!([_unit,VQGVAR(movedRecentlyCover),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold))}
        || {!([_unit,VQGVAR(activelyClearing),VGVAR(clearingThreshold)] call VFUNC(pastThreshold)})) exitWith {};

private _nearestEnemy = [_unit] call VFUNC(closestEnemy);
if (isNull _nearestEnemy) exitWith {};

_unit setVariable [VQGVAR(movedRecentlyCover),diag_tickTime];

private _untypedListFinal = [];
private _typedListFinal = [];
{
    private _type = typeOf _x;
    if !(_type in ["#crater","#crateronvehicle","#soundonvehicle","#particlesource","#lightpoint","#slop","#mark","HoneyBee","Mosquito","HouseFly","FxWindPollen1","ButterFly_random","Snake_random_F","Rabbit_F","FxWindGrass2","FxWindLeaf1","FxWindGrass1","FxWindLeaf3","FxWindLeaf2"]) then {
        if (!(_x isKindOf "Man") && {!(_x isKindOf "Bird")} && {!(_x isKindOf "BulletCore")} && {!(_x isKindOf "Grenade")} && {!(_x isKindOf "WeaponHolder")}) then {

            TRACE_1("[POTATO] - potential cover type: %1",_type);

            (boundingBoxReal _x) params ["_point1","_point2"];

            if ((abs ((_point2 select 0) - (_point1 select 0))) > 2
                && {abs ((_point2 select 1) - (_point1 select 1)) > 2}
                && {abs ((_point2 select 2) - (_point1 select 2)) > 2)} then {

                if (_type == "") then {
                    _untypedListFinal pushBack _x
                } else {
                    _typedListFinal pushBack _x;
                };
            };
        };
    };
    nil
} count (nearestObjects [_movePosition, [], 50]);


if (_typedListFinal == [] && _untypedListFinal == []) exitWith {};

private _closestCover = if !(_typedListFinal == []) then {
    _typedListFinal select 0
} else {
    _untypedListFinal select 0
};

private _guessLocation = getpos _nearestEnemy;
_guessLocation getRelPos [(_closestCover distance _nearestEnemy) + 2, (_guessLocation getDir _closestCover)]

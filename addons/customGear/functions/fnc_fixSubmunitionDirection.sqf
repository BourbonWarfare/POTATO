#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles a high arcing simulationBullet projectile creating
 * submunitions in a direction that doesn't match their current trajectory.
 *
 * Arguments:
 * 0: The bullet creating a submunition to be corrected <OBJECT>
 *
 * Examples:
 * [bullet0] call potato_customGear_fnc_fixSubmunitionDirection;
 *
 * Public: No
 */
params ["_projectile"];

if (isNull _projectile || {!(_projectile getShotInfo 5)}) exitWith {
    TRACE_3("exiting early",_projectile,isNull _projectile,getShotInfo _projectile);
};

_projectile addEventHandler ["SubmunitionCreated", {
    params ["_projectile", "_submunitionProjectile"];
    _submunitionProjectile setVelocity ((vectorNormalized velocity _projectile) vectorMultiply (speed _submunitionProjectile / 3.6));
}];

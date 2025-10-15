#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_fauxCanada
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This funciton creates initial smnoke around the projectile while the
* underlying smoke shell begins to bellow.
*
* Arguments:
* _projectile - The projectile to create smoke around (OBJECT)
*
* Return:
* None
*
* Example:
* [_projectile] call potato_customGear_fauxCanada_fnc_canonSmoke;
*//***************************************************************************/
params [
    ["_projectile", objNull]
];
TRACE_1("creatingSmoke",_this);
if (isNull _projectile ) exitWith {
    TRACE_1("Bad Init",_this);
};

private _shellPos = (ASLToAGL getPosASL _projectile) vectorAdd [0, 0, 1];
private _smoke0 = createVehicleLocal ["#particlesource", _shellPos, [], 0, "CAN_COLLIDE"];
_smoke0 setParticleRandom [1, [5, 5, 1], [1, 1, 0.1], 0, 0.5, [0, 0, 0, 0.1], 0, 0, 360];
_smoke0 setParticleParams [
	["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8, 0],
	"", "Billboard", 1, 15, [0, 0, 0], [0 ,0, 0],
	1, 3.8, 3, 0.1, [10, 20, 20, 20, 30],
	[[0.75, 0.75, 0.75, 1], [0.5, 0.5, 0.5, 1], [0.25, 0.25, 0.25, 0.75], [0.1, 0.1, 0.1, 0]],
	[1], 0.1, 0.1, "", "", _projectile
];
_smoke0 setDropInterval 0.02;
private _smoke1 = createVehicleLocal ["#particlesource", _shellPos, [], 0, "CAN_COLLIDE"];
_smoke1 setParticleRandom [1, [7, 7, 1], [2, 2, 0.1], 0, 0.5, [0, 0, 0, 0.1], 0, 0, 360];
_smoke1 setParticleParams [
	["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8, 0],
	"", "Billboard", 1, 10, [0, 0, 0], [0 ,0, 0],
	1, 2.55, 2, 0.1, [5, 9, 10],
	[[0.75, 0.75, 0.75, 1], [0.75, 0.75, 0.75, 1], [0.5, 0.5, 0.5, 1], [0.5, 0.5, 0.5, 1], [0.25, 0.25, 0.25, 0.75], [0.1, 0.1, 0.1, 0]],
	[1], 0.1, 0.1, "", "", _projectile
];
_smoke1 setDropInterval 0.0075;
triggerAmmo _projectile;

[{{deleteVehicle _x} forEach _this}, [_smoke0, _smoke1], 0.2] call CBA_fnc_waitAndExecute;

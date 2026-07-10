#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_launchers
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
* [_projectile] call potato_customGear_launchers_fnc_carlGSmoke;
*//***************************************************************************/
params [
    ["_projectile", objNull]
];
TRACE_1("attaching smoke EH",_this);
if (isNull _projectile ) exitWith {
    TRACE_1("Bad Init",_this);
};
_projectile addEventHandler ["Explode", {
	params ["_projectile", "_posASL"];
    private _posAGL = ASLToAGL _posASL;
    private _shellPos = _posAGL vectorAdd [0, 0, 1];
    private _smokeShell = createVehicle [QGVARMAIN(carlg_SmokeShell), _posAGL, [], 0, "CAN_COLLIDE"];
    private _smoke0 = createVehicleLocal ["#particlesource", _shellPos, [], 0, "CAN_COLLIDE"];
    _smoke0 setParticleRandom [1, [7, 7, 1], [2, 2, 0.1], 0, 0.5, [0, 0, 0, 0.1], 0, 0, 360];
    _smoke0 setParticleParams [
        ["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8, 0],
        "", "Billboard", 1, 10, [0, 0, 0], [0 ,0, 0],
        1, 0.87, 0.7, 0.1, [5, 9, 10],
        [[0.75, 0.75, 0.75, 1], [0.75, 0.75, 0.75, 1], [0.5, 0.5, 0.5, 1], [0.5, 0.5, 0.5, 1], [0.25, 0.25, 0.25, 0.75], [0.1, 0.1, 0.1, 0]],
        [1], 0.1, 0.1, "", "", _smokeShell
    ];
    _smoke0 setDropInterval 0.005;
    triggerAmmo _smokeShell;
    [{deleteVehicle _this}, _smoke0, 0.05] call CBA_fnc_waitAndExecute;
}];

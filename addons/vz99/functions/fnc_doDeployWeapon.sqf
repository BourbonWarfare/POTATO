/*
 * Author: PabstMirror
 * Deploys the vz99 into a static weapon and moves the player in
 *
 * Arguments:
 * 0: Target (player) <OBJECT>
 * 1: Player <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [player, player] call potato_vz99_fnc_canDeployWeapon;
 *
 * Public: No
 */
#include "script_component.hpp"

params ["", "_player"];
TRACE_1("params",_player);

private _posATL = _player getRelPos [1.5, 0]; //in front of player
_posATL set [2, (getPosATL _player) select 2];

private _mortarVeh = QGVAR(mortar) createVehicle _posATL;
_mortarVeh setPosATL _posATL;
TRACE_3("created",_mortarVeh,_posATL,_mortarVeh distance _player);

_player removeWeapon QGVAR(carryWeapon);

//Move in auto
_player moveInGunner _mortarVeh;



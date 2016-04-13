/*
 * Author: PabstMirror
 *
 *
 * Arguments:
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call
 *
 * Public: No
 */
#include "script_component.hpp"

params ["", "_player"];
TRACE_1("params",_player);

private _posATL = _player getRelPos [1.5, 0]; //in front of player
_posATL set [2, (getPosATL _player) select 2];

private _mortarVeh = QGVAR(mortar) createVehicle _posATL;
_mortarVeh setPosASL (AGLtoASL _posATL);
TRACE_3("created",_mortarVeh,_posATL,_mortarVeh distance _player);

_player removeWeapon QGVAR(carryWeapon);

//Move in auto
_player moveInGunner _mortarVeh;



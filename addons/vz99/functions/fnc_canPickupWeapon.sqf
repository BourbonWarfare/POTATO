/*
 * Author: PabstMirror
 * Tests if player can pickup a deployed static weapon
 *
 * Arguments:
 * 0: Target (mortar) <OBJECT>
 * 1: Player <OBJECT>
 *
 * Return Value:
 * <BOOL>
 *
 * Example:
 * [mortar, player] call potato_vz99_fnc_canPickupWeapon
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_target", "_player"];
TRACE_2("params",_target,_player);

((secondaryWeapon _player) == "") && 
{(crew _target) isEqualTo []}

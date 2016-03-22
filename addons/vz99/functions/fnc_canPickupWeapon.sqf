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

params ["_target", "_player"];
TRACE_2("params",_target,_player);

((secondaryWeapon _player) == "") && 
{(crew _target) isEqualTo []}

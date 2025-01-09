#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is checks whether the unit is dead and the weapon holders
 * exist before the action to retrieve either a primary or secondary weapon
 * is shown to the player.
 *
 * Arguments:
 * 0: Whether the weapon is a primary or not (BOOL)
 *
 * Return Value:
 * Whether to show the action or not (BOOL)
 *
 * Examples:
 * [(modifierFunction Args), true] call potato_aceEdits_actionPickupWeapon_condition;
 *
 * Public: No
 */
//IGNORE_PRIVATE_WARNING["_target", "_player"];
TRACE_3("",_this,_target,_player);
// _player and _target are provided on call by the ace interact menu
params ["_isPrimaryWeapon"];

private _weaponIndex = [1, 0] select _isPrimaryWeapon;
private _weaponHolder = (getCorpseWeaponholders _target)#_weaponIndex;
!alive _target &&
{count weaponCargo _weaponHolder == 1} &&
{_player distance _weaponHolder < 5}

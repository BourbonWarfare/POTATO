#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is used to make the player take a weapon from a specific
 * weapon holder. The function is passed a boolean of whether the weapon
 * is a primary (not a seoconday).
 *
 * Arguments:
 * 0: Whether the weapon is a primary or not (BOOL)
 *
 * Return Value:
 * None
 *
 * Examples:
 * [true] call potato_aceEdits_actionPickupWeapon_statement;
 *
 * Public: No
 */
//IGNORE_PRIVATE_WARNING["_target", "_player"];
TRACE_3("",_this,_target,_player);
// _player and _target are provided on call by the ace interact menu
params ["_isPrimaryWeapon"];

private _weaponIndex = [1, 0] select _isPrimaryWeapon;

private _weaponHolder = getCorpseWeaponholders _target#_weaponIndex;
_player action ["TakeWeapon", _weaponHolder, weaponCargo _weaponHolder#0];

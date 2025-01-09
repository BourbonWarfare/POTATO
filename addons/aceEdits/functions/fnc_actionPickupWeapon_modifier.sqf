#include "..\script_component.hpp"
/*
 * Funcion inspired by Johnb432's ACE action for everything mod
 * Author: Lambda.Tiger
 * This function is used to modify an action name to be <take weapon gun name>.
 * It takes the default modifierFunction arguments and whether the weapon is a
 * primary or not and uses them to change the name of the action (boolean).
 *
 * Arguments:
 * 0: (ACE Interact Framework modifierFunction ARGS) (ARRAY)
 * 1: Whether the weapon is a primary or not (BOOL)
 *
 * Return Value:
 * None
 *
 * Examples:
 * [(modifierFunction Args), true] call potato_aceEdits_actionPickupWeapon_modifer;
 *
 * Public: No
 */
TRACE_1("",_this);

params ["_actionArgs", "_isPrimaryWeapon"];
_actionArgs params ["_target", "", "", "_actionData"];

private _weaponIndex = [1, 0] select _isPrimaryWeapon;

private _weaponHolder = getCorpseWeaponholders _target#_weaponIndex;
_actionData set [1,
    format [
        localize "STR_ACTION_TAKE_BAG",
        getText (configFile >> "CfgWeapons" >> (weaponCargo _weaponHolder#0) >> "displayName")
]];

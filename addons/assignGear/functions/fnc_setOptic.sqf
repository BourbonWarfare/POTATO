/*
 * Author: AACO
 * Sets optic on player's main weapon.
 * Should only be called from interact menu
 *
 * Arguments:
 * 0: Target of interaction <OBJECT>
 * 1: Player who is interacting <OBJECT>
 * 2: Optic classname <STRING>
 *
 * Example:
 * [objNull, player, "opticClassName"] call potato_assignGear_fnc_setOptic;
 *
 * Public: No
 */
#define DEBUF_MODE_FULL
#include "script_component.hpp"

TRACE_1("params",_this);
params ["", "_player", "_opticClassname"];

if (_opticClassname in ([primaryWeapon _player] call CBA_fnc_compatibleItems)) then {
    _player addPrimaryWeaponItem _opticClassname;
} else {
    WARNING_2("Optic not compatible with player's weapon", primaryWeapon _player, _opticClassname);
};

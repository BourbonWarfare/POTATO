#include "script_component.hpp"
/*
 * Author: Dani (TCVM)
 * Called when a player fires their gun. Calls functions relevant to ammo type used
 *
 * Arguments:
 * 0: Unit that fired <OBJECT>
 * 1: Weapon that fired <STRING>
 * 2: Muzzle <STRING>
 * 3: Mode <STRING>
 * 4: Ammo used <STRING>
 * 5: Magazine used <STRING>
 * 6: Projectile <OBJECT>
 * 7: Gunner whose weapon fired <OBJECT>
 *
 * Examples:
 * _this call potato_adminGun_fnc_onFired;
 *
 * Public: No
 */
params ["_unit", "", "", "", "_ammoType"];

if (local _unit && { isPlayer _unit }) then {
    switch (_ammoType) do {
        case QGVAR(physics): {
            call FUNC(physicsPFH);
        };
        default {};
    };
};


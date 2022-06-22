#include "script_component.hpp"
/*
 * Author: Dani (TCVM)
 * Called when a player fires their gun. Calls functions relevant to ammo type used
 *
 * Arguments:
 * 0: Unit that fired
 * 1: Weapon that fired
 * 2: Muzzle
 * 3: Mode
 * 4: Ammo used
 * 5: Magazine used
 * 6: Projectile
 * 7: Gunner whose weapon fired
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
            _this call FUNC(physicsPFH);
        };
        default {};
    };
};


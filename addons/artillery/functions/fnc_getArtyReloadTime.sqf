#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Cache function that checks a weapon's minimum reload time
 *
 * Arguments:
 * _weaponType - CfgWeapons class for the artillery piece, STRING
 *
 * Return:
 * SCALAR - Minimum reload time
 *
 * Example:
 * ["CUP_Vcannon_D30_veh"] call potato_artillery_fnc_getArtyReloadTime;
 *
 * Public: No
 */
params ["_weaponType"];

if (isNil QGVAR(vehicleReloadCache)) then {
    GVAR(vehicleReloadCache) = createHashMap;
};

GVAR(vehicleReloadCache) getOrDefaultCall [_weaponType, {
    private _weaponConfig = configFile >> "CfgWeapons" >> _weaponType;
    private _fireModes = getArray (_weaponConfig >> "modes");

    if (_fireModes isEqualTo []) then {
        getNumber (_weaponConfig >> "reloadTime");
    } else {
        selectMin (_fireModes apply {
            getNumber (_weaponConfig >> _x >> "reloadTime")
        })
    }
}, true]

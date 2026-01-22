#include "..\script_component.hpp"
/**************************************************************//*
* Get the time reload time for shells between
*
* Arguments:
* _weaponType - CfgWeapons class for the artillery piece
*
* Example:
* private _reloadTime = ["CUP_Vcannon_D30_veh"] call FUNC(getArtyReloadTime);
*//**************************************************************/
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

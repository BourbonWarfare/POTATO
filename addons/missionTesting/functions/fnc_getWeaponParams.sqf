#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
*
*
* Arguments:
* _weapon - The classname of the weapon to get parameters for (STRING)
* _magazine - The classname of the magazine to get parameters for (STRING)
*
* Return:
* The diaphragm hitpoint armor
*
* Example:
* [vest ace_player] call potato_missionTesting_fnc_getWeaponParams;
*//***************************************************************************/
params ["_weapon", "_magazine"];

if (isNil QGVAR(weaponParams)) then {
    GVAR(weaponParams) = createHashMap;
};
GVAR(weaponParams) getOrDefaultCall [_this, {
    private _weaponCfg = configFile >> "CfgWeapons" >> _weapon;
    private _magCfg = configFile >> "CfgMagazines" >> _magazine;
    private _ammo = getText (_magCfg >> "ammo");
    private _ammoCfg = configFile >> "CfgAmmo" >> _ammo;

    private _weaponInitSpeed = getNumber (_weaponCfg >> "initSpeed");
    private _magInitSpeed = getNumber (_magCfg >> "initSpeed");
    private _initSpeed = _magInitSpeed;
    if (_weaponInitSpeed < 0) then {
        _initSpeed = -_initSpeed  * _weaponInitSpeed;
    } else {
        if (_weaponInitSpeed > 0) then {
            _initSpeed = _weaponInitSpeed;
        };
    };

    [
        _weapon+"|"+_magazine,
        _ammo,
        getNumber (_ammoCfg >> "airFriction"),
        _initSpeed,
        getNumber (_ammoCfg >> "typicalSpeed"),
        getNumber (_ammoCfg >> "hit")
    ]
}, true]

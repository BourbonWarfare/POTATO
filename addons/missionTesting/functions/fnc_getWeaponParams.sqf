#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function is used as part of the armor testing system.
* This function takes a weapon and magazine and uses the pair to access a
* cache of weapon parameters. It uses the weapon and magazine classname to
* derive information about the ammo, as well as the initial velocity the round
* is created at. It returns a six element array of weapon params.
*
* Arguments:
* _weapon - The classname of the weapon to get parameters for (STRING)
* _magazine - The classname of the magazine to get parameters for (STRING)
*
* Return:
* A weapon params array consisting of
*  0: An identified consiting of weaponClass + | + magazineClass
*  1: The ammo class name
*  2: The ammo air friction
*  3: The initial speed of the projectile
*  4: The typical speed of the projectile (used for damage)
*  5: The hit value of the projectile (used for damage)
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

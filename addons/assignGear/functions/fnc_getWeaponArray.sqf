/*
 * Author: PabstMirror, AACO
 * Gets a weapon array from a weapon classname, an array of attachement classnames,
 * and an array of magazines
 *
 * Arguments:
 * 0: Weapon classname <STRING>
 * 1: Array of attachements to add to the weapon <ARRAY>
 * 2: Array of magazines to preload the weapon with <ARRAY>
 * 3: Should we check the optic (optional, default: true) <BOOL>
 *
 * Return Value:
 * Weapon array <ARRAY>
 *
 * Example:
 * [_configWeapon, _configAttachments, _configMagazines] call potato_assignGear_fnc_getWeaponArray;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_weapon", "_attachments", "_configMagazines", ["_doOpticCheck", true, [true]]];

if ((_weapon != "") && {isNull (configFile >> "CfgWeapons" >> _weapon)}) then {
    ERROR_MSG_1("[%1] Bad Weapon Classname",_weapon);
    _weapon = "";
};

private _weaponArray = [_weapon, "", "", "", [], [], ""];
private _attachables = [_weapon] call CBA_fnc_compatibleItems;

{
    if (_x != "") then {
        (_x splitString ":") params [["_classname", ""]]; // count makes no sense for attachments, ignore
        private _config = configFile >> "CfgWeapons" >> _classname;
        if ({_x == _classname} count _attachables > 0) then {
            [_weaponArray, _config, _classname, _doOpticCheck] call FUNC(setWeaponAttachment);
        } else {
            WARNING_2("Attachment [%1] not compatible with [%2]",_classname,_weapon);
        };
    } else {
        TRACE_1("Empty string for weapon attachment - ignoring",_weapon);
    };
} forEach _attachments;

{
    if (_x == "this") then { // main gun magazines
        [LAW_PRIMARY_MUZZLE_MAG_INDEX, [configFile >> "CfgWeapons" >> _weapon] call CBA_fnc_compatibleMagazines]
    } else { // underslung weapon magazines
        [LAW_SECONDARY_MUZZLE_MAG_INDEX, [configFile >> "CfgWeapons" >> _weapon >> _x] call CBA_fnc_compatibleMagazines]
    } params ["_arrayIndex", "_magazines"];

    {
        (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
        if ((_magazines findIf {_classname == _x}) > -1) exitWith {
            private _count = getNumber (configFile >> "CfgMagazines" >> _classname >> "count");
            _weaponArray set [_arrayIndex, [_classname, _count]];
            _configMagazines set [_forEachIndex, format ["%1:%2", _classname, ((parseNumber _amount) - 1)]];
        };
    } forEach _configMagazines; // for each used here, since we need the index
} forEach getArray (configFile >> "CfgWeapons" >> _weapon >> "muzzles"); 


if ((_weaponArray select LAW_PRIMARY_MUZZLE_MAG_INDEX) isEqualTo []) then {
    private _weaponCfg = configFile >> "CfgWeapons" >> _weapon;
    if (((getText (_weaponCfg >> "ACE_UsedTube")) != "") || {(getNumber (_weaponCfg >> "rhs_disposable")) == 1}) then {
        private _magazine = (getArray (_weaponCfg >> "magazines")) param [0, ""];
        if (_magazine == "") exitWith {};
        private _count = getNumber (configFile >> "CfgMagazines" >> _magazine >> "count");
        _weaponArray set [LAW_PRIMARY_MUZZLE_MAG_INDEX, [_magazine, _count]];
        TRACE_2("adding disposable mag",_weapon,_magazine);
    };
    // ref cba_disposable_fnc_changeDisposableLauncherClass - we have to replace weapon and magazine
    if ([cba_disposable_normalLaunchers, _weapon, "in"] call FUNC(getDisposableInfo)) then {
        ([cba_disposable_normalLaunchers, _weapon, "get"] call FUNC(getDisposableInfo)) params ["_newWeapon", "_newMagazine"];
        _weaponArray set [LAW_WEAPON_INDEX, _newWeapon];    
        if (!isNil "_newMagazine") then {
            private _count = getNumber (configFile >> "CfgMagazines" >> _newMagazine >> "count");
            _weaponArray set [LAW_PRIMARY_MUZZLE_MAG_INDEX, [_newMagazine, _count]];
        };
        TRACE_2("replacing cba_disposable",_weapon,_newWeapon);
    };
};

_weaponArray

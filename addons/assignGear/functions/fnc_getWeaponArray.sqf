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

private _weaponArray = [_weapon, "", "", "", [], [], ""];
private _attachables = [_weapon] call CBA_fnc_compatibleItems;

{
    if (_x != "") then {
        (_x splitString ":") params [["_classname", ""]]; // count makes no sense for attachments, ignore
        private _config = configFile >> "CfgWeapons" >> _classname;
        if ({_x == _classname} count _attachables > 0) then {
            [_weaponArray, _config, _classname, _doOpticCheck] call FUNC(setWeaponAttachment);
        } else {
            diag_log text format ["[POTATO-assignGear] - Attachment [%1] not compatible with [%2]", _classname, _weapon];
        };
    } else {
        TRACE_1("Empty string for weapon attachment - ignoring", _weapon);
    };
    nil
} count _attachments; // count used here for speed, make sure nil is above this line

{
    if (_x == "this") then { // main gun magazines
        [LAW_PRIMARY_MUZZLE_MAG_INDEX, getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines")]
    } else { // underslung weapon magazines
        [LAW_SECONDARY_MUZZLE_MAG_INDEX, getArray (configFile >> "CfgWeapons" >> _weapon >> _x >> "magazines")]
    } params ["_arrayIndex", "_magazines"];

    {
        (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
        if ({_classname == _x} count _magazines > 0) exitWith {
            private _count = getNumber (configFile >> "CfgMagazines" >> _classname >> "count");
            _weaponArray set [_arrayIndex, [_classname, _count]];
            _configMagazines set [_forEachIndex, format ["%1:%2", _classname, ((parseNumber _amount) - 1)]];
        };
    } forEach _configMagazines; // for each used here, since we need the index
    nil
} count getArray (configFile >> "CfgWeapons" >> _weapon >> "muzzles");  // count used here for speed, make sure nil is above this line

_weaponArray

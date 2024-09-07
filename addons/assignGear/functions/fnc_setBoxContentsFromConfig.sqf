#include "script_component.hpp"
/*
 * Author: Bailey
 * Fills box with gear from a config
 * Edited by Lambda.Tiger to add box names
 *
 * Arguments:
 * 0: Box <OBJECT>
 * 1: missionConfigFile path for the box's loadout <STRING>
 * 2: Optional format string for box name, must contain "%1" <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject] call potato_assignGear_fnc_assignGearSupplyBox
 *
 * Public: No
 */

params ["_theBox", "_path", ["_nameFormatString", "%1", [""]]];

clearWeaponCargoGlobal _theBox;
clearMagazineCargoGlobal _theBox;
clearItemCargoGlobal _theBox;
clearBackpackCargoGlobal _theBox;

private _transportMagazines = getArray(_path >> "TransportMagazines");
private _transportItems = getArray(_path >> "TransportItems");
private _transportWeapons = getArray(_path >> "TransportWeapons");
private _transportBackpacks = getArray(_path >> "TransportBackpacks");

// transportMagazines
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _theBox addMagazineCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportMagazines; // count used here for speed, make sure nil is above this line

// transportItems
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _theBox addItemCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportItems; // count used here for speed, make sure nil is above this line

// transportWeapons
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    private _disposableName = [cba_disposable_LoadedLaunchers, _classname, "get", ""] call potato_assignGear_fnc_getDisposableInfo;
    if (_disposableName != "") then {
        _classname = _disposableName;
    };
    _theBox addWeaponCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportWeapons; // count used here for speed, make sure nil is above this line

// transportBackpacks
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _theBox addBackpackCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportBackpacks; // count used here for speed, make sure nil is above this line

private _boxName = getText (_path >> "boxCustomName");
if (_boxName isNotEqualTo "") then {
    _theBox setVariable ["ace_cargo_customName", format [_nameFormatString, _boxName], true];
};

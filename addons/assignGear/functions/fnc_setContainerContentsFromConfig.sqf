#include "script_component.hpp"
/*
 * Author: Pabst
 * Fills box with gear from a config
 *
 * Arguments:
 * 0: The container to be filled such as a vehicle or supply box <OBJECT>
 * 1: Config path for the box's loadout <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject, missionConfigFile >> "CfgLoadouts" >> "SupplyBox" >> (typeOf cursorObject)] call potato_assignGear_fnc_assignGearSupplyBox
 *
 * Public: No
 */

params ["_theContainer", "_path"];

clearWeaponCargoGlobal _theContainer;
clearMagazineCargoGlobal _theContainer;
clearItemCargoGlobal _theContainer;
clearBackpackCargoGlobal _theContainer;

private _transportMagazines = getArray(_path >> "TransportMagazines");
private _transportItems = getArray(_path >> "TransportItems");
private _transportWeapons = getArray(_path >> "TransportWeapons");
private _transportBackpacks = getArray(_path >> "TransportBackpacks");

// transportMagazines
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _theContainer addMagazineCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportMagazines; // count used here for speed, make sure nil is above this line

// transportItems
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _theContainer addItemCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportItems; // count used here for speed, make sure nil is above this line

// transportWeapons
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    private _disposableName = [cba_disposable_LoadedLaunchers, _classname, "get", ""] call FUNC(getDisposableInfo);
    if (_disposableName != "") then {
        _classname = _disposableName;
    };
    _theContainer addWeaponCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportWeapons; // count used here for speed, make sure nil is above this line

// transportBackpacks
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _theContainer addBackpackCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportBackpacks; // count used here for speed, make sure nil is above this line

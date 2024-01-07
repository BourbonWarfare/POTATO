#include "script_component.hpp"
/*
 * Author: Bailey
 * Fills supply box with gear for a faction
 *
 * Arguments:
 * 0: Box <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject] call potato_assignGear_fnc_assignGearSupplyBox
 *
 * Public: No
 */

params ["_theBox"];

private _config = configOf _theBox;
private _faction = getText (_config >> QGVAR(faction));
private _type = getText (_config >> QGVAR(type)); // 1=squad, 2=platoon

TRACE_1("",GVAR(setSupplyBoxLoadouts));

//Leave default gear when GVAR(setSupplyBoxLoadouts) is 0
if (GVAR(setSupplyBoxLoadouts) == 0) exitWith {};

//Clean out starting inventory when GVAR(setSupplyBoxLoadouts) is -1
if (GVAR(setSupplyBoxLoadouts) == -1) exitWith {
    clearWeaponCargoGlobal _theBox;
    clearMagazineCargoGlobal _theBox;
    clearItemCargoGlobal _theBox;
    clearBackpackCargoGlobal _theBox;
};

private _path = missionConfigFile >> "CfgLoadouts" >> "SupplyBoxes" >> typeOf _theBox;

if (!isClass _path) exitWith {
    diag_log text format ["[POTATO-assignGear] - No loadout found for %1 (typeOf %2)", _theBox, typeof _theBox];
};

//Clean out starting inventory (even if there is no class)
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
    private _disposableName = cba_disposable_LoadedLaunchers getVariable [_classname, ""];
    if (_disposableName != "") then {
        TRACE_2("cba_disposable_LoadedLaunchers replace",_classname,_disposableName);
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

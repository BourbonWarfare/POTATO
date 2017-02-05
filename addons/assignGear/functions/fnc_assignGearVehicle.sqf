/*
 * Author: PabstMirror
 * Applies a loadout to a vehicle
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Default loadout type <STRING>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [cursorTarget] call potato_assignGear_fnc_assignGearVehicle;
 *
 * Public: Yes
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"

TRACE_1("params",_this);
params ["_theVehicle", "_defaultLoadout"];

private _typeOf = typeOf _theVehicle;
private _loadout = _theVehicle getVariable ["F_Gear", _typeOf];
private _faction = toLower faction _theVehicle;

TRACE_2("",GVAR(setVehicleLoadouts),_loadout);

//Leave default gear when "F_Gear" is "Default" or GVAR(setVehicleLoadouts) is 0
if ((GVAR(setVehicleLoadouts) == 0) || {_loadout == "Default"}) exitWith {};

//Clean out starting inventory when "F_Gear" is "Empty" or GVAR(setVehicleLoadouts) is -1
if ((GVAR(setVehicleLoadouts) == -1) || {_loadout == "Empty"}) exitWith {
    clearWeaponCargoGlobal _theVehicle;
    clearMagazineCargoGlobal _theVehicle;
    clearItemCargoGlobal _theVehicle;
    clearBackpackCargoGlobal _theVehicle;
};

private _path = missionConfigFile >> "CfgLoadouts" >> _faction >> _loadout;

if (!isClass _path) then {
    //No CfgLoadouts for exact loadout, try default
    private _vehConfigSide = [_theVehicle, true] call BIS_fnc_objectSide;
    private _vehConfigFaction = switch (_vehConfigSide) do {
        case (west): { "blu_f" };
        case (east): { "opf_f" };
        case (independent): { "ind_f" };
        default { "civ_f" };
    };
    _path = missionConfigFile >> "CfgLoadouts" >> _vehConfigFaction >> _defaultLoadout;

    if (!isClass _path) then {
        _vehConfigFaction = switch (_vehConfigSide) do { // note: will recheck civ_f here
            case (west): { "potato_usmc" };
            case (east): { "potato_msv" };
            case (independent): { "potato_airborne" };
            default { "civ_f" };
        };
        _path = missionConfigFile >> "CfgLoadouts" >> _vehConfigFaction >> _defaultLoadout;
    };
};

if (!isClass _path) exitWith {
    diag_log text format ["[POTATO-AssignGear] - No loadout found for %1 (typeOf %2) (kindOf %3) (defaultLoadout: %4)", _theVehicle, typeof _theVehicle, _loadout, _defaultLoadout];
};

//Clean out starting inventory (even if there is no class)
clearWeaponCargoGlobal _theVehicle;
clearMagazineCargoGlobal _theVehicle;
clearItemCargoGlobal _theVehicle;
clearBackpackCargoGlobal _theVehicle;

private _transportMagazines = getArray(_path >> "TransportMagazines");
private _transportItems = getArray(_path >> "TransportItems");
private _transportWeapons = getArray(_path >> "TransportWeapons");
private _transportBackpacks = getArray(_path >> "TransportBackpacks");

// transportMagazines
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _theVehicle addMagazineCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportMagazines; // count used here for speed, make sure nil is above this line

// transportItems
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _theVehicle addItemCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportItems; // count used here for speed, make sure nil is above this line

// transportWeapons
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _theVehicle addWeaponCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportWeapons; // count used here for speed, make sure nil is above this line

// transportBackpacks
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _theVehicle addBackpackCargoGlobal [_classname, parseNumber _amount];
    nil
} count _transportBackpacks; // count used here for speed, make sure nil is above this line

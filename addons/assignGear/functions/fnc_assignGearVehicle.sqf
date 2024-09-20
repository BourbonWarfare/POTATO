#include "script_component.hpp"
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
params ["_theVehicle", "_defaultLoadout"];
TRACE_2("assignGearVehicle",_theVehicle,_defaultLoadout);

private _typeOf = typeOf _theVehicle;
private _loadout = _theVehicle getVariable ["F_Gear", _typeOf];
private _faction = toLower faction _theVehicle;

TRACE_2("",GVAR(setVehicleLoadouts),_loadout);

//Leave default gear when "F_Gear" is "Default" or GVAR(setVehicleLoadouts) is 0
if ((GVAR(setVehicleLoadouts) == 0) || {_loadout == "Default"}) exitWith {
    if (GVAR(alwaysAddToolkits)) then { _theVehicle addItemCargoGlobal ["Toolkit", 1]; };
    if (GVAR(alwaysAddLandRopes) && {(_theVehicle isKindOf "Car") || {_theVehicle isKindOf "Tank"}}) then { 
        _theVehicle addItemCargoGlobal ["ACE_rope15", 1]; // note: this rope is probably too short to fastrope with, so don't add to air
    };
};

//Clean out starting inventory when "F_Gear" is "Empty" or GVAR(setVehicleLoadouts) is -1
if ((GVAR(setVehicleLoadouts) == -1) || {_loadout == "Empty"}) exitWith {
    clearWeaponCargoGlobal _theVehicle;
    clearMagazineCargoGlobal _theVehicle;
    clearItemCargoGlobal _theVehicle;
    clearBackpackCargoGlobal _theVehicle;
    //Add a Toolkit
    if (GVAR(alwaysAddToolkits)) then { _theVehicle addItemCargoGlobal ["Toolkit", 1]; };
    if (GVAR(alwaysAddLandRopes) && {(_theVehicle isKindOf "Car") || {_theVehicle isKindOf "Tank"}}) then { 
        _theVehicle addItemCargoGlobal ["ACE_rope15", 1];
    };
};

private _path = missionConfigFile >> "CfgLoadouts" >> _faction >> _loadout;

if (!isClass _path) then {
    //No CfgLoadouts for exact loadout, try default
    private _vehConfigSide = [_theVehicle, true] call BIS_fnc_objectSide;
    private _vehConfigFactions = switch (_vehConfigSide) do {
        case (west): { ["blu_f", "potato_w"] };
        case (east): { ["opf_f", "potato_e", "potato_msv"] }; // potato_msv is depcrecated but kept for BWC for now
        case (independent): { ["ind_f", "potato_i"] };
        default { ["civ_f"] };
    };

    {
        private _break = false;
        private _loadoutToCheck = _x;

        {
            _path = missionConfigFile >> "CfgLoadouts" >> _x >> _loadoutToCheck;
            if (isClass _path) exitWith { _break = true; };
        } forEach _vehConfigFactions;

        if (_break) exitWith {};
    } forEach [_loadout, _defaultLoadout];
};

if (!isClass _path) exitWith {
    diag_log text format ["[POTATO-assignGear] - No loadout found for %1 (typeOf %2) (kindOf %3) (defaultLoadout: %4)", _theVehicle, typeOf _theVehicle, _loadout, _defaultLoadout];
};

//Clean out starting inventory (even if there is no class)
clearWeaponCargoGlobal _theVehicle;
clearMagazineCargoGlobal _theVehicle;
clearItemCargoGlobal _theVehicle;
clearBackpackCargoGlobal _theVehicle;
//Add a Toolkit
if (GVAR(alwaysAddToolkits)) then { _theVehicle addItemCargoGlobal ["Toolkit", 1]; };
if (GVAR(alwaysAddLandRopes) && {(_theVehicle isKindOf "Car") || {_theVehicle isKindOf "Tank"}}) then { 
    _theVehicle addItemCargoGlobal ["ACE_rope15", 1];
};

private _transportMagazines = getArray(_path >> "TransportMagazines");
private _transportItems = getArray(_path >> "TransportItems");
private _transportWeapons = getArray(_path >> "TransportWeapons");
private _transportBackpacks = getArray(_path >> "TransportBackpacks");

switch (GVAR(setVehicleLoadouts)) do {
    case 1: { // ammo in vehicle inventory
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
            private _disposableName = [cba_disposable_LoadedLaunchers, _classname, "get", ""] call FUNC(getDisposableInfo);
            if (_disposableName != "") then {
                TRACE_2("cba_disposable_LoadedLaunchers replace",_classname,_disposableName);
                _classname = _disposableName;
            };
            _theVehicle addWeaponCargoGlobal [_classname, parseNumber _amount];
            nil
        } count _transportWeapons; // count used here for speed, make sure nil is above this line

        // transportBackpacks
        {
            (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
            _theVehicle addBackpackCargoGlobal [_classname, parseNumber _amount];
            nil
        } count _transportBackpacks; // count used here for speed, make sure nil is above this line
    };
    case 2: { // ammo in boxes in vehicle
        [_theVehicle, _path, _transportMagazines, _transportItems, _transportWeapons, _transportBackpacks] call FUNC(assignGearVehicle_asBoxes);
    };
};

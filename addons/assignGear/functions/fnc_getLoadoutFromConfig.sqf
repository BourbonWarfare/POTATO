/*
 * Author: PabstMirror
 * Gets a loadout array from a loadout config path
 *
 * Arguments:
 * 0: Config Path <CONFIG>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * Loadout array (https://community.bistudio.com/wiki/Talk:getUnitLoadout) <ARRAY>
 *
 * Example:
 * [missionConfigFile >> "CfgLoadouts" >> (faction player) >> (typeOf player), player] call potato_assignGear_fnc_getLoadoutFromConfig
 *
 * Public: No
 */

#include "script_component.hpp"
#define UNIFORM_INDEX 0
#define VEST_INDEX 1
#define BACKPACK_INDEX 2

params ["_path", ["_unit", objNull]];
TRACE_2("getLoadoutFromConfig",_path,_unit);

private _configUniform = getArray (_path >> "uniform");
private _configVest = getArray (_path >> "vest");
private _configHeadgear = getArray (_path >> "headgear");
private _configGoggles = getArray (_path >> "goggles");	
private _configBackpack = getArray (_path >> "backpack");
private _configBackpackItems = getArray (_path >> "backpackItems");
private _configWeapons = getArray (_path >> "weapons");
private _configLaunchers = getArray (_path >> "launchers");
private _configHandguns = getArray (_path >> "handguns");
private _configMagazines = getArray (_path >> "magazines");
private _configItems = getArray (_path >> "items");
private _configLinkedItems = getArray (_path >> "linkedItems");
private _configAttachments = getArray (_path >> "attachments");
private _configSecondaryAttachments = getArray (_path >> "secondaryAttachments");
private _configHandgunAttachments = getArray (_path >> "handgunAttachments");


// temp - add splints to medics for old missions
if ([_unit] call ACEFUNC(common,isMedic)) then {
    if ((_configBackpackItems findIf {(_x select [0,10]) == "ACE_splint"}) != -1) exitWith {}; // added via mission
    INFO_2("adding splints %1 - %2",_unit,configName _path);
    _configBackpackItems pushBack "ACE_splint:12";

    // Add kat medical to medics if the mod is enabled
    if (isClass(configFile >> "CfgPatches" >> "kat_main")) then {
        if ((_configBackpackItems findIf {(_x select [0,10]) == "kat_X_AED"}) != -1) exitWith {}; // added via mission
        _katItems = [
                        "kat_X_AED","kat_accuvac","kat_Pulseoximeter","kat_larynx:2","kat_aatKit:5","kat_guedel:5",
                        "kat_stethoscope","kat_chestSeal:4","kat_IO_FAST:4","kat_IV_16:6",
                        "ACE_adenosine:8","kat_Carbonate:4","kat_Painkiller:4","kat_nitroglycerin:4",
                        "kat_norepinephrine:4","kat_phenylephrine:4","kat_TXA:4","kat_atropine:4",
                        "kat_amiodarone:4","kat_naloxone:4","kat_lidocaine:4"
                    ];
    
        {
            _configBackpackItems pushBack _x
        } forEach _katItems;
    };
};

// temp - add lock picks
if (isClass(configFile >> "CfgPatches" >> "tsp_breach")) then {
    if ((_configItems findIf {(_x select [0,10]) == "tsp_lockpick"}) != -1) exitWith {}; // added via mission
    _configItems pushBack "tsp_lockpick"
};

private _containersArray = [];

// NOTE: order of the three calls below matter!
[_configUniform, _containersArray] call FUNC(getContainerInfo);
[_configVest, _containersArray] call FUNC(getContainerInfo);
[_configBackpack, _containersArray, false] call FUNC(getContainerInfo);

TRACE_1("containers",_containersArray);

private _headgear = if (_configHeadgear isEqualTo []) then { "" } else { selectRandom _configHeadgear };
private _goggles = if (_configGoggles isEqualTo []) then { "" } else { selectRandom _configGoggles };	
private _binocularArray = [];
private _assignedItems = ["", "", "", "", "", ""];

// Process Weapons
private _primaryWeaponArray = if (_configWeapons isEqualTo []) then { [] } else { [selectRandom _configWeapons, _configAttachments, _configMagazines] call FUNC(getWeaponArray) };
private _launcherWeaponArray = if (_configLaunchers isEqualTo []) then { [] } else { [selectRandom _configLaunchers, _configSecondaryAttachments, _configMagazines, false] call FUNC(getWeaponArray) }; // skip optic check on launchers
private _handgunWeaponArray = if (_configHandguns isEqualTo []) then { [] } else { [selectRandom _configHandguns, _configHandgunAttachments, _configMagazines] call FUNC(getWeaponArray) };

// Process linkedItems (includes binoculars)
{
    private _linkedItemIndex = [_x, _binocularArray, _configMagazines] call FUNC(getLinkedIndex);

    if (_linkedItemIndex >= 0) then {
        _assignedItems set [_linkedItemIndex, _x];
    };
    nil
} count _configLinkedItems; // count used here for speed, make sure nil is above this line

TRACE_1("Adding Items Start: ",_containersArray);

_configItems = [_configItems, _containersArray, UNIFORM_INDEX] call FUNC(addItemsToContainer);
_configItems = [_configItems, _containersArray, VEST_INDEX] call FUNC(addItemsToContainer);
_configItems = [_configItems, _containersArray, BACKPACK_INDEX] call FUNC(addItemsToContainer);
TRACE_1("Remaining items: ", _configItems);

_configBackpackItems = [_configBackpackItems, _containersArray, BACKPACK_INDEX] call FUNC(addItemsToContainer);
_configBackpackItems = [_configBackpackItems, _containersArray, VEST_INDEX] call FUNC(addItemsToContainer);
_configBackpackItems = [_configBackpackItems, _containersArray, UNIFORM_INDEX] call FUNC(addItemsToContainer);
TRACE_1("Remaining backpack items: ", _configBackpackItems);

_configMagazines = [_configMagazines, _containersArray, VEST_INDEX] call FUNC(addItemsToContainer);
_configMagazines = [_configMagazines, _containersArray, BACKPACK_INDEX] call FUNC(addItemsToContainer);
_configMagazines = [_configMagazines, _containersArray, UNIFORM_INDEX] call FUNC(addItemsToContainer);
TRACE_1("Remaining magazines: ", _configBackpackItems);

if (((count _configItems) + (count _configBackpackItems) + (count _configMagazines)) > 0) then {
    WARNING_1("~~~~~~~~~ Items not added for: %1 ~~~~~~~~~~~", configName _path);
    WARNING_1("Items: %1%",_configItems);
    WARNING_1("BackpackItems: %1%",_configBackpackItems);
    WARNING_1("Magazines: %1%",_configMagazines);
};

TRACE_1("Adding Items End: ",_containersArray);

// return array, to spec of https://community.bistudio.com/wiki/Talk:getUnitLoadout
[
    _primaryWeaponArray,
    _launcherWeaponArray,
    _handgunWeaponArray,
    (_containersArray select UNIFORM_INDEX) select 1,
    (_containersArray select VEST_INDEX) select 1,
    (_containersArray select BACKPACK_INDEX) select 1,
    _headgear,
    _goggles,
    _binocularArray,
    _assignedItems
]

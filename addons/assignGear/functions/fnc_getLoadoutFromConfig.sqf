/*
 * Author: PabstMirror
 * Gets a loadout array from a loadout config path
 *
 * Arguments:
 * 0: Config Path <CONFIG>
 *
 * Return Value:
 * Loadout array (https://community.bistudio.com/wiki/Talk:getUnitLoadout) <ARRAY>
 *
 * Example:
 * [missionConfigFile >> "CfgLoadouts" >> (faction player) >> (typeOf player)] call potato_assignGear_fnc_getLoadoutFromConfig
 *
 * Public: No
 */

#include "script_component.hpp"
#define UNIFORM_INDEX 0
#define VEST_INDEX 1
#define BACKPACK_INDEX 2

TRACE_1("params",_this);
params ["_path"];

private _configUniform = getArray (_path >> "uniform");
private _configVest = getArray (_path >> "vest");
private _configHeadgear = getArray (_path >> "headgear");
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

private _containersArray = [];

// NOTE: order of the three calls below matter!
[_configUniform, _containersArray] call FUNC(getContainerInfo);
[_configVest, _containersArray] call FUNC(getContainerInfo);
[_configBackpack, _containersArray, false] call FUNC(getContainerInfo);

TRACE_1("containers",_containersArray);

private _headgear = if (_configHeadgear isEqualTo []) then { "" } else { selectRandom _configHeadgear };
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

TRACE_1("Adding Items End: ",_containersArray);

// return array, to spec of https://community.bistudio.com/wiki/Talk:getUnitLoadout
[_primaryWeaponArray, _launcherWeaponArray, _handgunWeaponArray, (_containersArray select UNIFORM_INDEX) select 1, (_containersArray select VEST_INDEX) select 1, (_containersArray select BACKPACK_INDEX) select 1, _headgear, "", _binocularArray, _assignedItems]

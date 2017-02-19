/*
 * Author: PabstMirror
 * Gets a loadout array from a loadout config path
 *
 * Arguments:
 * 0: Config Path <CONFIG>
 *
 * Return Value:
 * <ARRAY>
 *
 * Example:
 * [missionConfigFile >> "CfgLoadouts" >> (faction player) >> (typeOf player)] call potato_assignGear_fnc_getLoadoutFromConfig
 */
#include "script_component.hpp"

params ["_path"];
TRACE_1("params",_path);

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

private _uniformArray = [];
private _vestArray = [];
private _backpackArray = [];
private _containersArray = [[0],[0],[0]];

if (!(_configUniform isEqualTo [])) then {
    private _uniform = selectRandom _configUniform;
    private _container = getText (configFile >> "CfgWeapons" >> _uniform >> "ItemInfo" >> "containerClass");
    private _uniformSpace = getNumber (configFile >> "CfgVehicles" >> _container >> "maximumLoad");
    TRACE_3("",_uniform,_container,_uniformSpace);
    _uniformArray = [_uniform, []];
    _containersArray set [0, [_uniformSpace, _uniformArray]];
};
if (!(_configVest isEqualTo [])) then {
    private _vest = selectRandom _configVest;
    private _container = getText (configFile >> "CfgWeapons" >> _vest >> "ItemInfo" >> "containerClass");
    private _vestSpace = getNumber (configFile >> "CfgVehicles" >> _container >> "maximumLoad");
    TRACE_3("",_vest,_container,_vestSpace);
    _vestArray = [_vest, []];
    _containersArray set [1, [_vestSpace, _vestArray]];
};
if (!(_configBackpack isEqualTo [])) then {
    private _backpack = selectRandom _configBackpack;
    private _backpackSpace = getNumber (configFile >> "CfgVehicles" >> _backpack >> "maximumLoad");
    TRACE_2("",_backpack,_backpackSpace);
    _backpackArray = [_backpack, []];
    _containersArray set [2, [_backpackSpace, _backpackArray]];
};

TRACE_1("containers",_containersArray);

private _headgear = if (_configHeadgear isEqualTo []) then {""} else {selectRandom _configHeadgear};
private _binocularArray = [];
private _assignedItems = ["", "", "", "", "", ""];

private _fnc_addItemsToContainer = {
    params ["_itemsToAddArray", "_index"];
    TRACE_2("params",_itemsToAddArray,_index);
    if (_itemsToAddArray isEqualTo []) exitWith {_itemsToAddArray};
    private _indexSlotNum = [801, 701, 901] select _index; //for the "allowedSlots" check
    (_containersArray select _index) params ["_sizeLeft", ["_array", []]];
    TRACE_4("Adding Items To Container",_itemsToAddArray,_index,_sizeLeft,_array);
    private _returnArray = [];
    {
        _itemToAdd = _x;
        _xReturn = [] call {
            if (_sizeLeft <= 0) exitWith {TRACE_1("no room",_itemToAdd); _itemToAdd};
            (_itemToAdd splitString ":") params ["_classname", ["_amountToAdd", "1", [""]]];
            _amountToAdd = parseNumber _amountToAdd;
            private _mass = -1;
            private _count = -1;
            private _allowedSlots = [];
            if (isClass (configFile >> "CfgMagazines" >> _classname)) then {
                _mass = getNumber (configFile >> "CfgMagazines" >> _classname >> "mass");
                _count = getNumber (configFile >> "CfgMagazines" >> _classname >> "count");
                _allowedSlots = getArray (configFile >> "CfgMagazines" >> _classname >> "allowedSlots");
            } else {
                if (isClass (configFile >> "CfgWeapons" >> _classname)) exitWith {
                    _mass = getNumber (configFile >> "CfgWeapons" >> _classname >> "ItemInfo" >> "mass");
                    _allowedSlots = getArray (configFile >> "CfgWeapons" >> _classname >> "ItemInfo" >> "allowedSlots");
                };
            };
            if (_mass < 0) exitWith {
                diag_log text format ["[POTATO-assignGear] Item Not Found [%1]", _itemToAdd];
                "";
            };
            if (!((_allowedSlots isEqualTo []) || {_indexSlotNum in _allowedSlots})) exitWith {
                TRACE_3("not allowed in slot",_classname,_allowedSlots,_indexSlotNum);
                _itemToAdd
            };


            private _ammountThatWillFit = if (_mass == 0) then {9999} else {floor (_sizeLeft / _mass)};
            private _ammountAdded = _ammountThatWillFit min _amountToAdd;
            TRACE_6("",_classname,_mass,_count,_amountToAdd,_ammountThatWillFit,_ammountAdded);
            
            if (_ammountAdded == 0) exitWith {_itemToAdd};
            if (_count > 0) then {
                (_array select 1) pushBack [_classname, _ammountAdded, _count];
            } else {
                (_array select 1) pushBack [_classname, _ammountAdded];
            };

            _sizeLeft = _sizeLeft - (_ammountAdded * _mass);
            (_containersArray select _index) set [0, _sizeLeft];

            if (_ammountAdded == _amountToAdd) exitWith {""};
            (format ["%1:%2",_classname, (_amountToAdd - _ammountAdded)])
        };
        if (_xReturn != "") then {_returnArray pushBack _xReturn};
    } forEach _itemsToAddArray;
    _returnArray
};


private _fnc_getWeaponArray = {
    params ["_weapon", "_attachments"];

    private _weaponArray = [_weapon, "", "", "", [], [], ""];
    private _attachables = [_weapon] call CBA_fnc_compatibleItems;

    {
        (_x splitString ":") params [["_classname", ""]]; //count makes no sense for attachments, ignore
        private _config = configFile >> "CfgWeapons" >> _classname;
        if (({_x == _classname} count _attachables) > 0) then {
            switch (getNumber(_config >> "itemInfo" >> "type")) do {
            case (101): {_weaponArray set [1, _classname]}; //muzzle
            case (301): {_weaponArray set [2, _classname]}; //pointer
            case (201): {
                    if (!GVAR(allowMagnifiedOptics)) then {
                        private _minZoom = 999; //FOV, so smaller is more zoomed in
                        {
                            if (isNumber (_x >> "opticsZoomMin")) then {_minZoom = _minZoom min (getNumber (_x >> "opticsZoomMin"));};
                            if (isText (_x >> "opticsZoomMin")) then {_minZoom = _minZoom min (call compile getText (_x >> "opticsZoomMin"));};
                            nil
                        } count configProperties [_config >> "ItemInfo" >> "OpticsModes"];
                        if (_minZoom < 0.25) then {
                            diag_log text format ["[POTATO-assignGear] allowMagnifiedOptics is false, not adding %1 (opticsZoomMin %2)", _classname, _minZoom];
                            _classname = "";
                        };
                    };
                    _weaponArray set [3, _classname]}; //optic
            case (302): {_weaponArray set [6, _classname]}; //bipod
                default {diag_log text format ["[POTATO-assignGear] - Attachment [%1] has unknown type", _classname];};
            };
        } else {
            diag_log text format ["[POTATO-assignGear] - Attachment [%1] not compatible with [%2]", _classname, _weapon];
        };
    } forEach _attachments;

    private _muzzles = getArray (configFile >> "CfgWeapons" >> _weapon >> "muzzles");
    {
        private _magazines = getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines");
        private _arrayIndex = 4;
        if (_x != "this") then {
            _magazines = getArray (configFile >> "CfgWeapons" >> _weapon >> _x >> "magazines");
            _arrayIndex = 5;
        };
        {
            (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
            if (({_x == _classname} count _magazines) > 0) exitWith {
                private _count = getNumber (configFile >> "CfgMagazines" >> _classname >> "count");
                _weaponArray set [_arrayIndex, [_classname, _count]];
                _configMagazines set [_forEachIndex, format ["%1:%2", _classname, ((parseNumber _amount) - 1)]];
            };
        } forEach _configMagazines;
    } forEach _muzzles;
    _weaponArray
};


//Process Weapons:
private _primaryWeaponArray = if (_configWeapons isEqualTo []) then {[]} else {[selectRandom _configWeapons, _configAttachments] call _fnc_getWeaponArray};
private _launcherWeaponArray = if (_configLaunchers isEqualTo []) then {[]} else {[selectRandom _configLaunchers, _configSecondaryAttachments] call _fnc_getWeaponArray};
private _handgunWeaponArray = if (_configHandguns isEqualTo []) then {[]} else {[selectRandom _configHandguns, []] call _fnc_getWeaponArray};

//Process linkedItems (includes binocular)
{
    private _type = [] call {
        if (_x isKindOf ["ItemMap", configFile >> "CfgWeapons"]) exitWith {0};
        if (_x isKindOf ["ItemGPS", configFile >> "CfgWeapons"]) exitWith {1};
        if (_x isKindOf ["UavTerminal_base", configFile >> "CfgWeapons"]) exitWith {1};
        if (_x isKindOf ["ItemRadio", configFile >> "CfgWeapons"]) exitWith {2};
        if (_x isKindOf ["ItemCompass", configFile >> "CfgWeapons"]) exitWith {3};
        if (_x isKindOf ["ItemWatch", configFile >> "CfgWeapons"]) exitWith {4};
        if (_x isKindOf ["NVGoggles", configFile >> "CfgWeapons"]) exitWith {5};
        if (_x isKindOf ["Binocular", configFile >> "CfgWeapons"]) exitWith {
            _binocularArray = [_x, []] call _fnc_getWeaponArray;
            -2
        };
        -1
    };
    if (_type >= 0) then {
        _assignedItems set [_type, _x];
    } else {
        if (_type == -1) then { diag_log text format ["[POTATO-assignGear] - linkedItems [%1] unknown type", _x]; };
    };
} forEach _configLinkedItems;

TRACE_1("Adding Items Start x",_containersArray);

_configItems = [_configItems, 0] call _fnc_addItemsToContainer;
_configItems = [_configItems, 1] call _fnc_addItemsToContainer;
_configItems = [_configItems, 2] call _fnc_addItemsToContainer;

_configBackpackItems = [_configBackpackItems, 2] call _fnc_addItemsToContainer;
_configBackpackItems = [_configBackpackItems, 1] call _fnc_addItemsToContainer;
_configBackpackItems = [_configBackpackItems, 0] call _fnc_addItemsToContainer;

_configMagazines = [_configMagazines, 1] call _fnc_addItemsToContainer;
_configMagazines = [_configMagazines, 2] call _fnc_addItemsToContainer;
_configMagazines = [_configMagazines, 0] call _fnc_addItemsToContainer;

TRACE_1("Adding Items End",_containersArray);

private _return = [_primaryWeaponArray, _launcherWeaponArray, _handgunWeaponArray, _uniformArray, _vestArray, _backpackArray, _headgear, "", _binocularArray, _assignedItems];

_return;

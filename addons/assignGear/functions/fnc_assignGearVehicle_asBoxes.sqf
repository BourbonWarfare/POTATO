#include "script_component.hpp"
/*
 * Author: tcvm
 * Applies a loadout to a vehicle as loaded ammo-boxes
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Default loadout type <STRING>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [cursorTarget] call potato_assignGear_fnc_assignGearVehicle_asBoxes;
 *
 * Public: No
 */

params ["_theVehicle", "_loadoutPath", "_transportMagazines", "_transportItems", "_transportWeapons", "_transportBackpacks"];

#define BAGS_PER_BOX 10
#define WEAPONS_PER_BOX 5
#define MAGAZINES_PER_BOX 100

private _getMassLbs = {
    params ["_config"];
    private _mass = getNumber (_config >> "mass");

    if (_mass == 0 && {isClass (_config >> "itemInfo")}) then {
        _mass = getNumber (_config >> "itemInfo" >> "mass");
    };

    if (_mass == 0 && {isClass (_config >> "WeaponSlotsInfo")}) then {
        _mass = getNumber (_config >> "WeaponSlotsInfo" >> "mass");
    };
    _mass / 10
};

private _getShortName = {
    params ["_displayName"];
    (_displayName splitString " ") params ["_f", "_s"];
    private _shortName = format ["%1 %2", _f, _s];
    if (isNil "_s") then {
        _shortName = _f;
    };
    _shortName
};

private _semiGreedyFill = {
    params ["_currentWeight", "_maxWeight", "_available", "_loadoutInfo", "_max"];
    scopeName "greedy_pick";
    private _name = [];
    private _pickedItems = [];
    private _chosen = "";
    private _amounts = [0];
    for "_added" from 0 to _max do {
        // check if item of this type remain
        if ((_amounts select 0) == 0) then {
            _loadoutInfo deleteAt _chosen;
            if (_available isEqualTo []) exitWith {
                _chosen = "";
                breakTo "greedy_pick";
            };
            _chosen = _available deleteAt 0;
            _amounts = _loadoutInfo get _chosen;
            _name pushBackUnique ([_amounts select 2] call _getShortName);
        };

        _amounts params ["_count", "_weight"];
        private _toAdd = 1;
        if (_weight == 0) then {
            _toAdd = _count;
        } else {
            _toAdd = floor ((_maxWeight - _currentWeight) / _weight);
        };
        // always add at least one item, up to the specified bound
        _toAdd = 1 max (_toAdd min _count min (_max - _added));
        _added = _added + _toAdd;

        _currentWeight = _currentWeight + _weight * _toAdd;
        _amounts set [0, _count - _toAdd];
        _pickedItems pushBack [_chosen, _toAdd];

        if (_currentWeight >= _maxWeight) exitWith {
            breakTo "greedy_pick";
        };
    };
    if (_chosen isNotEqualTo "") then {
        // Since, if an item still exists to add we exist here, we need to re-add it
        _loadoutInfo set [_chosen, _amounts];
        _available pushBack _chosen;
    };

    [_name, _pickedItems, _currentWeight]
};

private _transportBoxClassname = getText (_loadoutPath >> "AmmoBox");
if (_transportBoxClassname == "") then {
    _transportBoxClassname = "Box_NATO_Ammo_F";
};
private _transportBoxWeight = getNumber (_loadoutPath >> "AmmoBoxCapacity");
if (_transportBoxWeight == 0) then {
    _transportBoxWeight = 75;
};

private _loadoutInfo = createHashMap;
private _availableMagazines = [];
private _availableItems = [];
private _availableWeapons = [];
private _availableBackpacks = [];
// transportMagazines
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _availableMagazines pushBackUnique _classname;
    private _config = configFile >> "CfgMagazines" >> _classname;
    (_loadoutInfo getOrDefault [_classname, [0, _config call _getMassLbs, getText (_config >> "displayName")]]) params ["_existingAmount", "_mass", "_name"];
    _loadoutInfo set [_classname, [_existingAmount + parseNumber _amount, _mass, _name]];
    nil
} count _transportMagazines; // count used here for speed, make sure nil is above this line

// transportItems
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _availableItems pushBackUnique _classname;
    private _config = configFile >> "CfgWeapons" >> _classname;
    (_loadoutInfo getOrDefault [_classname, [0, _config call _getMassLbs, getText (_config >> "displayName")]]) params ["_existingAmount", "_mass", "_name"];
    _loadoutInfo set [_classname, [_existingAmount + parseNumber _amount, _mass, _name]];
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
    _availableWeapons pushBackUnique _classname;
    private _config = configFile >> "CfgWeapons" >> _classname;
    (_loadoutInfo getOrDefault [_classname, [0, _config call _getMassLbs, getText (_config >> "displayName")]]) params ["_existingAmount", "_mass", "_name"];
    _loadoutInfo set [_classname, [_existingAmount + parseNumber _amount, _mass, _name]];
    nil
} count _transportWeapons; // count used here for speed, make sure nil is above this line

// transportBackpacks
{
    (_x splitString ":") params ["_classname", ["_amount", "1", [""]]];
    _availableBackpacks pushBackUnique _classname;
    private _config = configFile >> "CfgBackpacks" >> _classname;
    (_loadoutInfo getOrDefault [_classname, [0, _config call _getMassLbs, getText (_config >> "displayName")]]) params ["_existingAmount", "_mass", "_name"];
    _loadoutInfo set [_classname, [_existingAmount + parseNumber _amount, _mass, _name]];
    nil
} count _transportBackpacks; // count used here for speed, make sure nil is above this line

while {
    _availableBackpacks isNotEqualTo [] ||
    { _availableItems isNotEqualTo [] } ||
    { _availableWeapons isNotEqualTo [] } ||
    { _availableMagazines isNotEqualTo [] }
} do {
    scopeName "item_select_loop";
    private _currentWeight = 0;
    private _box = createVehicle [_transportBoxClassname, [0, 0, 0], [], 0, "NONE"];
    clearWeaponCargoGlobal _box;
    clearMagazineCargoGlobal _box;
    clearItemCargoGlobal _box;
    clearBackpackCargoGlobal _box;
    [_box, 0] call ACEFUNC(cargo,setSize);
    [_box, _theVehicle, true] call ACEFUNC(cargo,loadItem);
    [_box, true, [0, 1.5, 0], 0, true, true] call ACEFUNC(dragging,setDraggable);
    [_box, true, [0, 1, 1], 0, true, true] call ACEFUNC(dragging,setCarryable);

    private _name = [];
    if (_currentWeight < _transportBoxWeight && _availableBackpacks isNotEqualTo []) then {
        private _fillInfo = [_currentWeight, _transportBoxWeight, _availableBackpacks, _loadoutInfo, BAGS_PER_BOX] call _semiGreedyFill;
        _fillInfo params ["_newName", "_toAdd", "_newWeight"];
        _currentWeight = _newWeight;
        _name = _name + _newName;
        {
            _box addBackpackCargoGlobal _x;
        } forEach _toAdd;
    };
    if (_currentWeight < _transportBoxWeight && _availableWeapons isNotEqualTo []) then {
        private _fillInfo = [_currentWeight, _transportBoxWeight, _availableWeapons, _loadoutInfo, WEAPONS_PER_BOX] call _semiGreedyFill;
        _fillInfo params ["_newName", "_toAdd", "_newWeight"];
        _currentWeight = _newWeight;
        _name = _name + _newName;
        {
            _box addWeaponCargoGlobal _x;
        } forEach _toAdd;
    };
    if (_currentWeight < _transportBoxWeight && _availableMagazines isNotEqualTo []) then {
        private _fillInfo = [_currentWeight, _transportBoxWeight, _availableMagazines, _loadoutInfo, MAGAZINES_PER_BOX] call _semiGreedyFill;
        _fillInfo params ["_newName", "_toAdd", "_newWeight"];
        _currentWeight = _newWeight;
        _name = _name + _newName;
        {
            _box addMagazineCargoGlobal _x;
        } forEach _toAdd;
    };
    if (_currentWeight < _transportBoxWeight && _availableItems isNotEqualTo []) then {
        private _fillInfo = [_currentWeight, _transportBoxWeight, _availableItems, _loadoutInfo, MAGAZINES_PER_BOX] call _semiGreedyFill;
        _fillInfo params ["_newName", "_toAdd", "_newWeight"];
        _currentWeight = _newWeight;
        _name = _name + _newName;
        {
            _box addItemCargoGlobal _x;
        } forEach _toAdd;
    };
    _box setVariable [QGVAR(initialized), true, true];
    _box setVariable [QACEGVAR(cargo,customName), _name joinString ",", true];
};


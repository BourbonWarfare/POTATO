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

#define BAGS_PER_BOX 10
#define WEAPONS_PER_BOX 5
#define MAGAZINES_PER_BOX 100

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

switch (GVAR(setVehicleLoadouts)) do {
    case 1: { // ammo in vehicle inventory
        [_theVehicle, _path] call FUNC(setContainerContentsFromConfig);
    };
    case 2: { // ammo in boxes in vehicle from inventory
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

        clearWeaponCargoGlobal _theVehicle;
        clearMagazineCargoGlobal _theVehicle;
        clearItemCargoGlobal _theVehicle;
        clearBackpackCargoGlobal _theVehicle;

        private _transportMagazines = getArray(_path >> "TransportMagazines");
        private _transportItems = getArray(_path >> "TransportItems");
        private _transportWeapons = getArray(_path >> "TransportWeapons");
        private _transportBackpacks = getArray(_path >> "TransportBackpacks");
        private _transportBoxClassname = getText(_path >> "AmmoBox");
        if (_transportBoxClassname == "") then {
            _transportBoxClassname = "Box_NATO_Ammo_F";
        };
        private _transportBoxWeight = getNumber(_path >> "AmmoBoxCapacity");
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
            [_box, 0] call ace_cargo_fnc_setSize;
            [_box, _theVehicle, true] call ace_cargo_fnc_loadItem;

            private _name = [];
            if (_currentWeight < _transportBoxWeight && _availableBackpacks isNotEqualTo []) then {
                scopeName "add_Backpack";
                private _chosen = "";
                private _amounts = [0];
                for "_i" from 0 to BACKPACKS_PER_BOX do {
                    // check if Backpacks of this type remain
                    if ((_amounts select 0) == 0) then {
                        _loadoutInfo deleteAt _chosen;
                        if (_availableBackpacks isEqualTo []) exitWith {
                            breakTo "item_select_loop";
                        };
                        _chosen = _availableBackpacks deleteAt 0;
                        _amounts = _loadoutInfo get _chosen;
                        _name pushBackUnique ([_amounts select 2] call _getShortName);
                    };
                    _amounts params ["_count", "_weight"];
                    // always add at least one item
                    _currentWeight = _currentWeight + _weight;
                    _amounts set [0, _count - 1];
                    _box addBackpackCargoGlobal [_chosen, 1];

                    if (_currentWeight >= _transportBoxWeight) exitWith {
                        breakTo "add_Backpack";
                    };
                };
                // Since, if a bag still exists to add we exist here, we need to re-add it
                _loadoutInfo set [_chosen, _amounts];
                _availableBackpacks pushBack _chosen;
            };
            if (_currentWeight < _transportBoxWeight && _availableWeapons isNotEqualTo []) then {
                scopeName "add_weapon";
                private _chosen = "";
                private _amounts = [0];
                for "_i" from 0 to WEAPONS_PER_BOX do {
                    // check if weapons of this type remain
                    if ((_amounts select 0) == 0) then {
                        _loadoutInfo deleteAt _chosen;
                        if (_availableWeapons isEqualTo []) exitWith {
                            breakTo "item_select_loop";
                        };
                        _chosen = _availableWeapons deleteAt 0;
                        _amounts = _loadoutInfo get _chosen;
                        _name pushBackUnique ([_amounts select 2] call _getShortName);
                    };
                    _amounts params ["_count", "_weight"];
                    // always add at least one item
                    _currentWeight = _currentWeight + _weight;
                    _amounts set [0, _count - 1];
                    _box addWeaponCargoGlobal [_chosen, 1];

                    if (_currentWeight >= _transportBoxWeight) exitWith {
                        breakTo "add_weapon";
                    };
                };
                // Since, if a bag still exists to add we exist here, we need to re-add it
                _loadoutInfo set [_chosen, _amounts];
                _availableWeapons pushBack _chosen;
            };
            if (_currentWeight < _transportBoxWeight && _availableMagazines isNotEqualTo []) then {
                scopeName "add_magazine";
                private _chosen = "";
                private _amounts = [0];
                for "_i" from 0 to MAGAZINES_PER_BOX do {
                    // check if magazines of this type remain
                    if ((_amounts select 0) == 0) then {
                        _loadoutInfo deleteAt _chosen;
                        if (_availableMagazines isEqualTo []) exitWith {
                            breakTo "item_select_loop";
                        };
                        _chosen = _availableMagazines deleteAt 0;
                        _amounts = _loadoutInfo get _chosen;
                        _name pushBackUnique ([_amounts select 2] call _getShortName);
                    };
                    _amounts params ["_count", "_weight"];
                    private _toAdd = 1;
                    if (_weight == 0) then {
                        _toAdd = _count;
                    } else {
                        _toAdd = floor ((_transportBoxWeight - _currentWeight) / _weight);
                    };
                    // always add at least one item
                    _toAdd = 1 max (_toAdd min _count);

                    _currentWeight = _currentWeight + _weight * _toAdd;
                    _amounts set [0, _count - _toAdd];
                    _box addMagazineCargoGlobal [_chosen, _toAdd];

                    if (_currentWeight >= _transportBoxWeight) exitWith {
                        breakTo "add_magazine";
                    };
                };
                // Since, if a bag still exists to add we exist here, we need to re-add it
                _loadoutInfo set [_chosen, _amounts];
                _availableMagazines pushBack _chosen;
            };
            if (_currentWeight < _transportBoxWeight && _availableItems isNotEqualTo []) then {
                scopeName "add_item";
                private _chosen = "";
                private _amounts = [0];
                for "_i" from 0 to MAGAZINES_PER_BOX do {
                    // check if items of this type remain
                    if ((_amounts select 0) == 0) then {
                        _loadoutInfo deleteAt _chosen;
                        if (_availableItems isEqualTo []) exitWith {
                            breakTo "item_select_loop";
                        };
                        _chosen = _availableItems deleteAt 0;
                        _amounts = _loadoutInfo get _chosen;
                        _name pushBackUnique ([_amounts select 2] call _getShortName);
                    };
                    _amounts params ["_count", "_weight"];
                    private _toAdd = 1;
                    if (_weight == 0) then {
                        _toAdd = _count;
                    } else {
                        _toAdd = floor ((_transportBoxWeight - _currentWeight) / _weight);
                    };
                    // always add at least one item
                    _toAdd = 1 max (_toAdd min _count);

                    _currentWeight = _currentWeight + _weight * _toAdd;
                    _amounts set [0, _count - _toAdd];
                    _box addItemCargoGlobal [_chosen, _toAdd];

                    if (_currentWeight >= _transportBoxWeight) exitWith {
                        breakTo "add_item";
                    };
                };
                // Since, if a bag still exists to add we exist here, we need to re-add it
                _loadoutInfo set [_chosen, _amounts];
                _availableItems pushBack _chosen;
            };

            _box setVariable ["ace_cargo_customName", _name joinString ",", true];
        };
    };
    case 3: { // ammo in boxes in vehicle from config
        private _boxes = "true" configClasses _path;
        {
            private _boxType = configName _x;
            private _boxCount = (getNumber (_x >> "boxCount")) max 1;
            for "_i" from 1 to _boxCount do {
                private _box = createVehicle [_boxType, [2,5,105], [], 0, "CAN_COLLIDE"];
                [_box, _x, ["%1", "%1 " + str _i] select (_boxCount > 1)] call FUNC(setBoxContentsFromConfig);
                [_box, 1] call ace_cargo_fnc_setSize;
                if !([_box, _theVehicle, true] call ace_cargo_fnc_loadItem) exitWith {
                    diag_log text format ["[POTATO-assignGear] - Failed to create %1 supply box(es) for %2 - out of space ", _boxType, typeOf _theVehicle];
                    deleteVehicle _box;
                };
                _box setVariable [QGVAR(initialized), true];
            };
        } forEach _boxes;
    };
};


//Add a Toolkit
if (GVAR(alwaysAddToolkits)) then { _theVehicle addItemCargoGlobal ["Toolkit", 1]; };
if (GVAR(alwaysAddLandRopes) && {(_theVehicle isKindOf "Car") || {_theVehicle isKindOf "Tank"}}) then {
    _theVehicle addItemCargoGlobal ["ACE_rope15", 1];
};

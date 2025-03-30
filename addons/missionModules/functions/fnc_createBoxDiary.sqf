#include "..\script_component.hpp"
#define TRAVERSE_TYPE_SINGLE 0
#define TRAVERSE_TYPE_CHILDREN 1
/*
 * Author: Lambda.Tiger
 * This function is run by a module on init. It takes the configured
 * side and configs to create resupply entries for them in the
 * players diary. This function can be called on the module later as the
 * module should not be automatically deleted.
 *
 * Arguments:
 * 0: The module being initialized
 * 2: Whether the module is active
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
 TRACE_1("create diary entry from config",_this);
params ["_logic", "", "_activated", ["_player", ace_player, [objNull]]];
if (!_activated || !hasInterface || isNull _player) exitWith {
    TRACE_3("leaving resup diary early",_logic,_activated,hasInterface);
};

// we would like _player, so we may have to wait a moment
if !(ACEGVAR(common,settingsInitFinished)) exitWith {
    if (isNil QGVAR(resupplyToRun)) then {
        GVAR(resupplyToRun) = [];
    };
    GVAR(resupplyToRun) pushBack [_this, {call FUNC(createBoxDiary)}];
};

private _side = switch (_logic getVariable ["side", 0]) do {
    case 1: {west};
    case 2: {east};
    case 3: {resistance};
    case 4: {civilian};
    default {0};
};

if (_side isEqualType west && {side _player != _side}) exitWith {
    TRACE_2("side error",_side,side _player);
};

private _baseCfg = missionConfigFile >> "CfgLoadouts";
private _boxLoadouts = getNumber (_baseCfg >> "setSupplyBoxLoadouts");
private _vicLoadouts = getNumber (_baseCfg >> "setVehicleLoadouts");
TRACE_2("loadout types",_boxLoadouts,_vicLoadouts);
if (_boxLoadouts <= 0 && _vicLoadouts <= 0) exitWith {};

private _parsedBox = (_logic getVariable ["boxClass", "ALL"]) splitString "|";
private _traverseType = TRAVERSE_TYPE_SINGLE;
(switch (_parsedBox#0) do {
    case "ALL": {
        _traverseType = TRAVERSE_TYPE_CHILDREN;
        [[_baseCfg >> "SupplyBoxes"], switch (_side) do {
            case west: {[_baseCfg >> "potato_w"]};
            case east: {[_baseCfg >> "potato_e"]};
            case resistance: {[_baseCfg >> "potato_i"]};
            default {[
                _baseCfg >> "potato_w",
                _baseCfg >> "potato_e",
                _baseCfg >> "potato_i"
            ]};
        }]
    };
    case "SUPPLY": {
        _traverseType = TRAVERSE_TYPE_CHILDREN;
        [[_baseCfg >> "SupplyBoxes"], []]
    };
    case "SIDE": {
        _traverseType = TRAVERSE_TYPE_CHILDREN;
        private _subPath = switch (_parsedBox#1) do {
            case "East": {"potato_e"};
            case "Indi": {"potato_i"};
            default {"potato_w"};
        };
        [[], switch (_side) do {
            case east: {[_baseCfg >> "potato_e"]};
            case resistance: {[_baseCfg >> "potato_i"]};
            case west: {[_baseCfg >> "potato_w"]};
            default {[
                _baseCfg >> "potato_w",
                _baseCfg >> "potato_e",
                _baseCfg >> "potato_i"
            ]};
        }]
    };
    default {
        _parsedBox params ["_className", "_path"];
        private _supplyBox = false;
        private _subCfgPath = switch (_path) do {
            case "Supply Boxes": {_supplyBox = true; "SupplyBoxes"};
            case "East": {"potato_e"};
            case "Indi": {"potato_i"};
            default {"potato_w"};
        };
        if (_supplyBox) then {
            [[_baseCfg >> _subCfgPath >> _className], []]
        } else {
            [[], [_baseCfg >> _subCfgPath >> _className]]
        }
    };
}) params ["_supplyBoxCfgs", "_loadoutCfgs"];

TRACE_2("Gathered box types",_supplyBoxCfgs,_loadoutCfgs);
_supplyBoxCfgs = _supplyBoxCfgs select {isClass _x};
_loadoutCfgs = _loadoutCfgs select {isClass _x};
if (_supplyBoxCfgs isEqualTo []
    && _loadoutCfgs isEqualTo []) exitWith {};

// We need a few funcitons to gather config
private _fnc_hasSubboxes = {
    params [["_configPath", configNull, [configNull]]];
    [] isNotEqualTo (configProperties [_configPath, "isClass _x"]);
};
private _fnc_transportContents = {
    params [["_path", configNull]];
    if (isNull _path) exitWith {[[], [], [], []]};
    params [["_configPath", configNull]];
    private _contents = [getArray (_path >> "TransportBackpacks")];
    _contents pushBack getArray (_path >> "TransportWeapons");
    _contents pushBack getArray (_path >> "TransportMagazines");
    _contents pushBack getArray (_path >> "TransportItems");
    _contents
};

// pull configs needed
if (_boxLoadouts < 1) then {
    _supplyBoxCfgs = [];
};

if (_traverseType > 0 ) then {
    // if _traverseType > 0 then _supplyBoxCfgs is either just the supplyBoxes
    // config path OR it's emtpy
    switch (_boxLoadouts) do {
        case 1: { // just the cfg into the box
            _supplyBoxCfgs = configProperties [_supplyBoxCfgs#0, "isClass _x"];
        };
        case 2;
        case 3: { // subboxes
            _supplyBoxCfgs = configProperties [_supplyBoxCfgs#0, "isClass _x"];
            private _endBoxes = [];
            {
                if ([_x] call _fnc_hasSubboxes) then {
                    _endBoxes append (configProperties [_x, "isClass _x"]);
                };
            } forEach _supplyBoxCfgs;
            _supplyBoxCfgs append _endBoxes;
        };
        default {
            _supplyBoxCfgs = [];
        };
    };

    switch (_vicLoadouts) do {
        case 1;
        case 2: {
            // Only use this function here
            private _fnc_containsTransport = {
                params [["_configPath", configNull]];
                if (isNull _path) exitWith {false};
                private _contents = getArray (_path >> "TransportBackpacks");
                _contents append getArray (_path >> "TransportWeapons");
                _contents append getArray (_path >> "TransportMagazines");
                _contents append getArray (_path >> "TransportItems");
                _contents isNotEqualTo []
            };
            {
                {
                    private _cfgName = configName _x;
                    if !(isClass (configFile >> "CfgVehicles" >> _cfgName)) then {continue};
                    if ([_x] call _fnc_containsTransport) then {
                        _supplyBoxCfgs pushBack _x;
                    };
                } forEach configProperties [_x, "isClass _x"];
            } forEach _loadoutCfgs;
        };
        case 3: {
            {
                {
                    private _cfgName = configName _x;
                    if !(isClass (configFile >> "CfgVehicles" >> _cfgName)) then {continue};
                    if ([_x] call _fnc_hasSubboxes) then {
                        _supplyBoxCfgs append (configProperties [_x, "isClass _x"])
                    } else {
                        _supplyBoxCfgs pushBack _x;
                    };
                } forEach configProperties [_x, "isClass _x"];
            } forEach _loadoutCfgs;
        };
        default {};
    };
};

// Figure out the contents of each box and list them
private _fnc_isSupplyBox = {
    params ["_path"];
    "SupplyBox" in str _path;
};
if (isNil QGVAR(configSupplyToAdd)) then {
    GVAR(configSupplyToAdd) = createHashMap;
};
private _useSubBoxes = [_vicLoadouts > 2, _boxLoadouts > 1];
{
    private _isSupplyBox = [_x] call _fnc_isSupplyBox;
    private _checkChildren = _useSubBoxes select _isSupplyBox;
    private _hasSubBoxes = [_x] call _fnc_hasSubboxes;
    private _name = getText (_x >> "boxCustomName");
    if (_name == "") then {
        _name = getText (configFile >> "CfgVehicles" >> (configName _x) >> "displayName");
    };
    private _boxEnum = if (_isSupplyBox) then {
        [
            LOADOUT_DIARY_TYPE_BOX,
            LOADOUT_DIARY_TYPE_BOXOFBOX
        ] select (_hasSubBoxes && _checkChildren);
    } else {
        LOADOUT_DIARY_TYPE_VEHICLE
    };
    if (_checkChildren && {_hasSubBoxes}) then {
        GVAR(configSupplyToAdd) set [_x, [
            _name,
            _boxEnum,
            [[], [], [], [], configProperties [_x, "isClass _x"]]
        ]];
    } else {
        private _boxContents = [_x] call _fnc_transportContents;
        if (_boxContents isNotEqualTo [[], [], [], []]) then {
            GVAR(configSupplyToAdd) set [_x, [_name, _boxEnum, _boxContents]];
        };
    };
} forEach _supplyBoxCfgs;

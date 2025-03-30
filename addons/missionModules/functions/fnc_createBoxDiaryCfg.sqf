#include "..\script_component.hpp"
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
if (!_activated || !hasInterface) exitWith {
    TRACE_3("leaving resup diary early",_logic,_activated,hasInterface);
};

// we would like _player, so we may have to wait a moment
if !(ACEGVAR(common,settingsInitFinished)) exitWith {
    if (isNil QGVAR(resupplyToRun)) then {
        GVAR(resupplyToRun) = [];
    };
    GVAR(resupplyToRun) pushBack [_this, {call FUNC(createBoxDiaryCfg)}];
};

if (isNull _player) exitWith {};

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

private _parsedBox = (_logic getVariable ["Box", "ALL"]) splitString "|";
DIAG_log formatText ["[lmd][dbg] %2 || %1", allVariables _logic, _parsedBox];
(switch (_parsedBox#0) do {
    case "ALL": {
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
        [[_baseCfg >> "SupplyBoxes"], []]
    };
    case "SIDE": {
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
        TRACE_2("specific config path",_supplyBox,isClass (_baseCfg >> _subCfgPath >> _className));
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
private _fnc_combineInventroy = {
    params [["_inputArray", []]];
    private _itemHash = createHashMap;
    {
        (_x splitString ":") params ["_magazine", ["_count", "1"]];
        if (_magazine in _itemHash) then {
            _itemHash set [_magazine, (_itemHash get _magazine) + parseNumber _count];
        } else {
            _itemHash set [_magazine, parseNumber _count];
        };
    } forEach _inputArray;
    private _outputArray = [];
    {
        _outputArray pushBack (_x + ":" + str _y);
    } forEach _itemHash;
    _outputArray
};
private _fnc_transportContents = {
    params [["_path", configNull]];
    if (isNull _path) exitWith {[[], [], [], []]};
    params [["_configPath", configNull]];
    private _contents = [[getArray (_path >> "TransportBackpacks")] call _fnc_combineInventroy];
    _contents pushBack ([getArray (_path >> "TransportWeapons")] call _fnc_combineInventroy);
    _contents pushBack ([getArray (_path >> "TransportMagazines")] call _fnc_combineInventroy);
    _contents pushBack ([getArray (_path >> "TransportItems")] call _fnc_combineInventroy);
    _contents
};

// pull configs needed
if (_boxLoadouts < 1) then {
    _supplyBoxCfgs = [];
};
// if _traverseType > 0 then _supplyBoxCfgs is either just the supplyBoxes
// config path OR it's emtpy
switch (_boxLoadouts) do {
    case 1: { // just the cfg into the box
        if (_supplyBoxCfgs isNotEqualTo []) then {
            _supplyBoxCfgs = configProperties [_supplyBoxCfgs#0, "isClass _x"];
        };
    };
    case 2;
    case 3: { // subboxes
        if (_supplyBoxCfgs isNotEqualTo []) then {
            _supplyBoxCfgs = configProperties [_supplyBoxCfgs#0, "isClass _x"];
        };
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
            _supplyBoxCfgs pushBack _x;
            {
                private _cfgName = configName _x;
                if !(isClass (configFile >> "CfgVehicles" >> _cfgName)) then {continue};
                _supplyBoxCfgs pushBack _x;
                if ([_x] call _fnc_hasSubboxes) then {
                    _supplyBoxCfgs append (configProperties [_x, "isClass _x"])
                };
            } forEach configProperties [_x, "isClass _x"];
        } forEach _loadoutCfgs;
    };
    default {};
};

// Figure out the contents of each box and list them
private _fnc_isSupplyBox = {
    params ["_path"];
    (configName _path) isKindOf "ReammoBox_F";
};
if (isNil QGVAR(configSupplyToAdd)) then {
    GVAR(configSupplyToAdd) = createHashMap;
};
TRACE_1("boxCfgs",_supplyBoxCfgs apply {configName _x});
private _useSubBoxes = [_vicLoadouts > 2, _boxLoadouts > 1];
{
    private _isSupplyBox = [_x] call _fnc_isSupplyBox;
    private _checkChildren = _useSubBoxes select _isSupplyBox;
    private _hasSubBoxes = [_x] call _fnc_hasSubboxes;
    private _cfgName = configName _x;
    private _name = getText (_x >> "boxCustomName");
    if (_name == "") then {
        if ((toLowerANSI _cfgName) in ["car", "tank", "helicopter"]) then {
            _name = switch (toLowerANSI _cfgName) do {
                case "car": {
                    "Wheeled Vehicles"
                };
                case "tank": {
                    "Tracked Vehicles"
                };
                default {
                    "Helicopters"
                };
            }
        } else {
            _name = getText (configFile >> "CfgVehicles" >> _cfgName >> "displayName");
        };
    };
    private _boxEnum = if (_isSupplyBox) then {
        [
            LOADOUT_DIARY_TYPE_BOX,
            LOADOUT_DIARY_TYPE_BOXOFBOX
        ] select (_hasSubBoxes && _checkChildren);
    } else {
        LOADOUT_DIARY_TYPE_VEHICLE
    };
    TRACE_5("adding entry to hash",_isSupplyBox,_checkChildren,_hasSubBoxes,_cfgName,_name);
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

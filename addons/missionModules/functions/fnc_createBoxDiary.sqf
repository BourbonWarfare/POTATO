#include "..\script_component.hpp"
#define TRAVERSE_TYPE_SINGLE 0
#define TRAVERSE_TYPE_CHILDREN 1
/*
 * Author: Lambda.Tiger
 * This function handles initialization of teleport between a module and a
 * sync'd object.
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
params ["_logic", "", "_activated"];
if (!_activated || !hasInterface) exitWith {
    TRACE_3("leaving resup diary early",_logic,_activated,hasInterface);
};

private _side = switch (_logic getVariable [QGVAR(side), 0]) do {
    case 1: {west};
    case 2: {east};
    case 3: {resistance};
    case 4: {civilian};
    default {0};
};

if (_side isEqualType west && {side ace_player != _side}) exitWith {};

private _boxLoadouts = getNumber (_baseConfigPath >> "setSupplyBoxLoadouts");
private _vicLoadouts = getNumber (_baseConfigPath >> "setVehicleLoadouts");
if (_boxLoadouts <= 0 && _vicLoadouts <= 0) exitWith {};

private _parsedBox = (_logic getVariable [QGVAR(boxClass), "ALL"]) splitString "|";
private _traverseType = TRAVERSE_TYPE_SINGLE;
private _baseCfg = missionConfigFile >> "CfgLoadouts";
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

_supplyBoxCfgs = _supplyBoxCfgs select {isClass _x};
_loadoutCfgs = _loadoutCfgs select {isClass _x};
if (_supplyBoxCfgs isEqualTo []
    && _loadoutCfgs isEqualTo []) exitWith {};

// We need a few funcitons
private _fnc_transportContents = {
    params [["_path", configNull]];
    if (isNull _path) exitWith {[[], [], [], []]};
    private _contents = [];
    {
        private _gearArray = getArray (_path >> _x);
        private _content = [];
        {
            (_x splitString ":") params [
                "_magazine",
                ["_roundCount", 1]
            ];
            _content pushBack [_magazine, _roundCount];
        } forEach _gearArray;
        _contents pushBack _content;
    } forEach ["TransportBackpacks", "TransportWeapons", "TransportMagazines", "TransportItems"];
};

if (isNil QGVAR(boxContentsHash)) then { // we're going to cache these
    // format: cfgLoadoutsPath => [trnsprtBackpack, trnsprtWeaps, trnsprtMags, trnsprtItems]
    GVAR(boxContentsHash) = createHashMap; // deleted/set nil'd at end of safe-start
};

private _fnc_showObj = {
    params [
        ["_configPath", configNull, [configNull]],
        ["_searchSubClasses", false, [false]]
    ];

    if (isNull _configPath) exitWith {[]};
    private _return = false;
    if (_searchSubClasses) then {
        {
            _return = _return || {[_x, _searchSubClasses] call _fnc_showObj};
        } forEach (configProperties [_configPath, "isClass _x"]);
    };
    _return || ([_configPath] call _fnc_containsTransport)
};

if (_traverseType > 0) then {
    // pull supply box classes
    // check  each and then add classes to queue as needed

};

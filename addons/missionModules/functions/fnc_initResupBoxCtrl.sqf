#define DEBUG_MODE_FULL
#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function initializes teleports available in the ACE self-interact menu.
 *
 * Arguments:
 * 0: The module being initialized
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
params ["_ctrlGrp", "_savedValue"];
TRACE_1("initResupCtrl params",_this);
private _ctrlCombo = _ctrlGrp controlsGroupCtrl 100;
private _baseConfigPath = missionConfigFile >> "CfgLoadouts";
private _boxLoadouts = getNumber (_baseConfigPath >> "setSupplyBoxLoadouts");
private _vicLoadouts = getNumber (_baseConfigPath >> "setVehicleLoadouts");

TRACE_2("Check box ctrl",_boxLoadouts,_vicLoadouts);
if (_boxLoadouts < 0 && _vicLoadouts < 0) exitWith {
    _ctrlCombo lbAdd "Vehicle and Supply boxes are not enabled";
};

private _idx = _ctrlCombo lbAdd "All Supply Boxes and Side Vehicles";
_ctrlCombo lbSetData [_idx, "ALL"];
_ctrlCombo lbSetCurSel _idx;
private _idx = _ctrlCombo lbAdd "All Supply Boxes";
_ctrlCombo lbSetData [_idx, "SUPPLY"];
private _idx = _ctrlCombo lbAdd "Side Vehicles";
_ctrlCombo lbSetData [_idx, "SIDE"];

private _fnc_containsTransport = {
    params [["_path", configNull]];
    if (isNull _path) exitWith {false};
    private _contents = getArray (_path >> "TransportWeapons");
    _contents append getArray (_path >> "TransportMagazines");
    _contents append getArray (_path >> "TransportItems");
    _contents append getArray (_path >> "TransportBackpacks");
    _contents isNotEqualTo []
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

private _boxes = [];
if (_boxLoadouts > 0) then {
    private _checkChildren = _boxLoadouts == 2;
    {
        TRACE_2("checkBox",_x,_checkChildren);
        if ([_x, _checkChildren] call _fnc_showObj) then {
            private _text = getText (_x >> "boxCustomName");
            _boxes pushBack [
                configName _x,
                [_text, configName _x] select (_text == "")
            ];
        };
    } forEach (configProperties [_baseConfigPath >> "SupplyBoxes", "isClass _x"]);
};

if (_vicLoadouts > 0) then {
    private _sides = getArray (_baseConfigPath >> "prefixes");
    private _checkChildren = _boxLoadouts == 3;
    {
        private _sideString = switch (_x) do {
            case "potato_w_": {"West"};
            case "potato_e_": {"East"};
            case "potato_i_": {"Indi"};
            default {"???"};
        };
        private _cfgPathLocal = _baseConfigPath >> (_x select [0, 8]);
        if !(isClass _cfgPathLocal) then {continue};
        {
            private _cfgName = configName _x;
            if !(isClass (configFile >> "CfgVehicles" >> _cfgName)) then {continue};
            if ([_x, _checkChildren] call _fnc_showObj) then {
                _boxes pushBack [
                    _cfgName,
                    getText (configFile >> "CfgVehicles" >> _cfgName >> "displayName"),
                    _sideString
                ];
            };
        } forEach (configProperties [_cfgPathLocal, "isClass _x"]);
    } forEach _sides;
};

{
    _x params [
        "_configName",
        "_displayName",
        ["_boxPath", "Supply Boxes"]
    ];
    _idx = _ctrlCombo lbAdd _displayName;
    _ctrlCombo lbSetData [_idx, _configName + "|" + _boxPath];
    _ctrlCombo lbSetTextRight [_idx, _boxPath];
} forEach _boxes;

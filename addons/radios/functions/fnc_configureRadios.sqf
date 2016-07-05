/*
 *
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

TRACE_3("statuses",(player == player), (alive player), (player getVariable "F_Gear_Setup"));

private _group = group player;
private _groupLanguages = _group getVariable [QGVAR(assignedLanguages),[]];
private _playerLanguages = player getVariable [QGVAR(assignedLanguages), _groupLanguages];

TRACE_1("",playerSide);
switch (playerSide) do {
    case west: {
        if (_playerLanguages isEqualTo []) then {
            _playerLanguages = GVAR(westDefaultLanguage);
        };
        ["ACRE_PRC343", WEST_SR] call ACRE_FUNC(setPreset);
        TRACE_2("west148",["ACRE_PRC148"] call acre_api_fnc_getPreset,[ARR_2("ACRE_PRC148", ["ACRE_PRC148"] call acre_api_fnc_getPreset)] call acre_api_fnc_getPresetData);
        ["ACRE_PRC148", WEST_MR] call ACRE_FUNC(setPreset);
        TRACE_2("west148",["ACRE_PRC148"] call acre_api_fnc_getPreset,[ARR_2("ACRE_PRC148", ["ACRE_PRC148"] call acre_api_fnc_getPreset)] call acre_api_fnc_getPresetData);
        ["ACRE_PRC117F", WEST_LR] call ACRE_FUNC(setPreset);
    };
    case east: {
        if (_playerLanguages isEqualTo []) then {
            _playerLanguages = GVAR(eastDefaultLanguage);
        };
        ["ACRE_PRC343", EAST_SR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC148", EAST_MR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC117F", EAST_LR] call ACRE_FUNC(setPreset);
    };
    case independent: {
        if (_playerLanguages isEqualTo []) then {
            _playerLanguages = GVAR(indyDefaultLanguage);
        };
        ["ACRE_PRC343", INDY_SR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC148", INDY_MR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC117F", INDY_LR] call ACRE_FUNC(setPreset);
    };
    default { // should just be civs
        if (_playerLanguages isEqualTo []) then {
            _playerLanguages = GVAR(civDefaultLanguage);
        };
        ["ACRE_PRC343", CIV_SR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC148", CIV_MR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC117F", CIV_LR] call ACRE_FUNC(setPreset);
    };
};

_playerLanguages call ACRE_FUNC(babelSetSpokenLanguages);

private _groupSRChannel = _group getVariable [QGVAR(srChannel),1];
private _playerSRChannel = player getVariable [QGVAR(srChannel), _groupSRChannel];

private _groupMRChannel = _group getVariable [QGVAR(mrChannel),1];
private _playerMRChannel = player getVariable [QGVAR(mrChannel), _groupMRChannel];

private _groupLRChannel = _group getVariable [QGVAR(lrChannel),1];
private _playerLRChannel = player getVariable [QGVAR(lrChannel), _groupLRChannel];

//TODO: build some kind of signal briefing

private _radio343 = ["ACRE_PRC343"] call ACRE_FUNC(getRadioByType);
if (!(isNil "_radio343") && {_radio343 != ""}) then {
    systemChat format ["[%1] is set to CH [%2]", _radio343, _playerSRChannel];
    [_radio343, _playerSRChannel] call ACRE_FUNC(setRadioChannel);
};

private _radio148 = ["ACRE_PRC148"] call ACRE_FUNC(getRadioByType);
if (!(isNil "_radio148") && {_radio148 != ""}) then {
    systemChat format ["[%1] is set to CH [%2]", _radio148, _groupMRChannel];
    [_radio148, _playerMRChannel] call ACRE_FUNC(setRadioChannel);
};

private _radio117 = ["ACRE_PRC117F"] call ACRE_FUNC(getRadioByType);
if (!(isNil "_radio117") && {_radio117 != ""}) then {
    systemChat format ["[%1] is set to CH [%2]", _radio117, _groupLRChannel];
    [_radio117, _playerLRChannel] call ACRE_FUNC(setRadioChannel);
};

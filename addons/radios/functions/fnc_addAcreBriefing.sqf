/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if ((ace_player getVariable [QGVAR(briefingAdded), objNull]) isEqualTo ace_player) exitWith {
    TRACE_1("briefing already added",_this);
};

// helper function
private _cleanLines = {
    TRACE_1("cleanLines params",_this);
    params ["_array", ["_maxPerLine", 25], ["_newLineSpace", "      "]];

    private _output = "";
    private _charCount = 0;

    {
        _charCount = _charCount + count _x;
        if (_charCount > _maxPerLine) then {
            _output = _output + format ["<br/>%1%2, ", _newLineSpace, _x];
            _charCount = count _x;
        } else {
            _output = _output + format ["%1, ", _x];
        };
        nil
    } count _array;

    _output select [0, (count _output - 2)];
};

private _addNetToBriefing = {
    TRACE_1("addNetToBriefing params",_this);
    params ["_diaryBuilder", "_hasRadio", "_nets", "_setChannelVar", "_group"];

    private _groupChannel = _group getVariable [_setChannelVar,1];
    private _playerChannel = ace_player getVariable [_setChannelVar, _groupChannel];

    {
        private _channelNumber = _forEachIndex + 1;
        if (_x != format ["Channel %1", _channelNumber]) then {
            if (_hasRadio && {_playerChannel == _channelNumber}) then {
                _diaryBuilder pushBack format [" <font color='#ff0000' size=14>&gt;%1:</font> %2<br/>", _channelNumber, _x];
            } else {
                _diaryBuilder pushBack format ["  <font size=14>%1:</font> %2<br/>", _channelNumber, _x];
            };
        };
    } forEach _nets;
};

private _group = group ace_player;

(switch ((getNumber (configFile >> "CfgVehicles" >> (typeOf ace_player) >> "side"))) do {
    case (1): {
        [
            missionNamespace getVariable [QGVAR(westDefaultLanguages), [DEFAULT_WEST_LANG]],
            missionNamespace getVariable [QGVAR(westSRChannelNames), [DEFAULT_SR_NAMES]],
            missionNamespace getVariable [QGVAR(westMRChannelNames), [DEFAULT_MR_NAMES]],
            missionNamespace getVariable [QGVAR(westLRChannelNames), [DEFAULT_LR_NAMES]],
            missionNamespace getVariable [QGVAR(addCommonChannelWestMR), DEFAULT_COMMON_CH_ENABLED],
            missionNamespace getVariable [QGVAR(addCommonChannelWestLR), DEFAULT_COMMON_CH_ENABLED]
        ]
    };
    case (0): {
        [
            missionNamespace getVariable [QGVAR(eastDefaultLanguages), [DEFAULT_EAST_LANGS]],
            missionNamespace getVariable [QGVAR(eastSRChannelNames), [DEFAULT_SR_NAMES]],
            missionNamespace getVariable [QGVAR(eastMRChannelNames), [DEFAULT_MR_NAMES]],
            missionNamespace getVariable [QGVAR(eastLRChannelNames), [DEFAULT_LR_NAMES]],
            missionNamespace getVariable [QGVAR(addCommonChannelEastMR), DEFAULT_COMMON_CH_ENABLED],
            missionNamespace getVariable [QGVAR(addCommonChannelEastLR), DEFAULT_COMMON_CH_ENABLED]
        ]
    };
    case (2): {
        [
            missionNamespace getVariable [QGVAR(indyDefaultLanguages), [DEFAULT_INDY_LANGS]],
            missionNamespace getVariable [QGVAR(indySRChannelNames), [DEFAULT_SR_NAMES]],
            missionNamespace getVariable [QGVAR(indyMRChannelNames), [DEFAULT_MR_NAMES]],
            missionNamespace getVariable [QGVAR(indyLRChannelNames), [DEFAULT_LR_NAMES]],
            missionNamespace getVariable [QGVAR(addCommonChannelIndyMR), DEFAULT_COMMON_CH_ENABLED],
            missionNamespace getVariable [QGVAR(addCommonChannelIndyLR), DEFAULT_COMMON_CH_ENABLED]
        ]
    };
    default {
        [
            missionNamespace getVariable [QGVAR(civDefaultLanguages), [DEFAULT_CIV_LANGS]],
            missionNamespace getVariable [QGVAR(civSRChannelNames), [DEFAULT_SR_NAMES]],
            missionNamespace getVariable [QGVAR(civMRChannelNames), [DEFAULT_MR_NAMES]],
            missionNamespace getVariable [QGVAR(civLRChannelNames), [DEFAULT_LR_NAMES]],
            missionNamespace getVariable [QGVAR(addCommonChannelCivMR), DEFAULT_COMMON_CH_ENABLED],
            missionNamespace getVariable [QGVAR(addCommonChannelCivLR), DEFAULT_COMMON_CH_ENABLED]
        ]
    };
}) params ["_defaultLanguages", "_srChannels", "_mrChannels", "_lrChannels", "_addSharedMRNetSide", "_addSharedLRNetSide"];

if ((missionNamespace getVariable [QGVAR(addCommonChannelAllMR), DEFAULT_COMMON_CH_ENABLED]) || {_addSharedMRNetSide}) then {
    _mrChannels set [
        (missionNamespace getVariable [QGVAR(addCommonChannelNumber), DEFAULT_COMMON_CH_NUM]) - 1,
        missionNamespace getVariable [QGVAR(addCommonChannelName), DEFAULT_COMMON_CH_NAME]
    ];
};
if ((missionNamespace getVariable [QGVAR(addCommonChannelAllLR), DEFAULT_COMMON_CH_ENABLED]) || {_addSharedLRNetSide}) then {
    _lrChannels set [
        (missionNamespace getVariable [QGVAR(addCommonChannelNumber), DEFAULT_COMMON_CH_NUM]) - 1,
        missionNamespace getVariable [QGVAR(addCommonChannelName), DEFAULT_COMMON_CH_NAME]
    ];
};

private _groupLanguages = _group getVariable [QGVAR(assignedLanguages), _defaultLanguages];
private _playerLanguages = ace_player getVariable [QGVAR(assignedLanguages), _groupLanguages];

//Show Spoken Languages:
private _languageDisplayNames = [];
{
    _x params ["_short", "_long"];
    if (_short in _playerLanguages) then { _languageDisplayNames pushBack _long };
} forEach GVAR(availableLanguages);

private _diaryBuilder = [];
_diaryBuilder pushBack format ["<font size=15>You speak: %1</font><br/>", ([_languageDisplayNames] call _cleanLines)];

//Show Radio Nets:
private _hasSR = false;
private _hasMR = false;
private _hasLR = false;
{
    if (_x isKindOf [RADIO_SR, configFile >> "CfgWeapons"]) then { _hasSR = true; };
    if (_x isKindOf [RADIO_MR, configFile >> "CfgWeapons"]) then { _hasMR = true; };
    if (_x isKindOf [RADIO_LR, configFile >> "CfgWeapons"]) then { _hasLR = true; };
} forEach (items ace_player);

TRACE_7("ACRE info",_languageDisplayNames,_hasSR,_srChannels,_hasMR,_mrChannels,_hasLR,_lrChannels);

_diaryBuilder pushBack "<br/><font size=15>SR Radio Net (343)</font><br/>";
[_diaryBuilder, _hasSR ,_srChannels, QGVAR(srChannel), _group] call _addNetToBriefing;

_diaryBuilder pushBack "<br/><font size=15>MR Radio Net (148)</font><br/>";
[_diaryBuilder, _hasMR ,_mrChannels, QGVAR(mrChannel), _group] call _addNetToBriefing;

_diaryBuilder pushBack "<br/><font size=15>LR Radio Net (117)</font><br/>";
[_diaryBuilder, _hasLR, _lrChannels, QGVAR(lrChannel), _group] call _addNetToBriefing;

_diaryBuilder pushBack "<br/><br/>Note: Subject to change.";

_diaryBuilder pushBack QUOTE(<br/><br/><execute expression='[] call FUNC(reinitializeRadios);'>Reinitialize radios</execute>);

ace_player createDiaryRecord ["diary", ["SIGNALS", _diaryBuilder joinString ""]];
ace_player setVariable [QGVAR(briefingAdded), ace_player];

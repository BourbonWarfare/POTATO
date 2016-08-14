/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

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
    private _playerChannel = player getVariable [_setChannelVar, _groupChannel];

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

private _group = group player;

(switch (playerSide) do {
    case (west): {
        [
            GVAR(westDefaultLanguages),
            GVAR(westSRChannelNames),
            GVAR(westMRChannelNames),
            GVAR(westLRChannelNames),
            GVAR(addCommonChannelWestMR),
            GVAR(addCommonChannelWestLR)
        ]
    };
    case (east): {
        [
            GVAR(eastDefaultLanguages),
            GVAR(eastSRChannelNames),
            GVAR(eastMRChannelNames),
            GVAR(eastLRChannelNames),
            GVAR(addCommonChannelEastMR),
            GVAR(addCommonChannelEastLR)
        ]
    };
    case (independent): {
        [
            GVAR(indyDefaultLanguages),
            GVAR(indySRChannelNames),
            GVAR(indyMRChannelNames),
            GVAR(indyLRChannelNames),
            GVAR(addCommonChannelIndyMR),
            GVAR(addCommonChannelIndyLR)
        ]
    };
    default {
        [
            GVAR(indyDefaultLanguages),
            GVAR(civSRChannelNames),
            GVAR(civMRChannelNames),
            GVAR(civLRChannelNames),
            GVAR(addCommonChannelCivMR),
            GVAR(addCommonChannelCivLR)
        ]
    };
}) params ["_defaultLanguages","_srChannels","_mrChannels","_lrChannels","_addSharedMRNetSide","_addSharedLRNetSide"];

if (GVAR(addCommonChannelAllMR) || {_addSharedMRNetSide}) then {
    _mrChannels set [GVAR(addCommonChannelNumber) - 1, GVAR(addCommonChannelName)];
};
if (GVAR(addCommonChannelAllLR) || {_addSharedLRNetSide}) then {
    _lrChannels set [GVAR(addCommonChannelNumber) - 1, GVAR(addCommonChannelName)];
};

private _groupLanguages = _group getVariable [QGVAR(assignedLanguages),_defaultLanguages];
private _playerLanguages = player getVariable [QGVAR(assignedLanguages), _groupLanguages];

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
} forEach (items player);

TRACE_7("ACRE info",_languageDisplayNames,_hasSR,_srChannels,_hasMR,_mrChannels,_hasLR,_lrChannels);

_diaryBuilder pushBack "<br/><font size=15>SR Radio Net (343)</font><br/>";
[_diaryBuilder,_hasSR,_srChannels,QGVAR(srChannel),_group] call _addNetToBriefing;

_diaryBuilder pushBack "<br/><font size=15>MR Radio Net (148)</font><br/>";
[_diaryBuilder,_hasMR,_mrChannels,QGVAR(mrChannel),_group] call _addNetToBriefing;

_diaryBuilder pushBack "<br/><font size=15>LR Radio Net (117)</font><br/>";
[_diaryBuilder,_hasLR,_lrChannels,QGVAR(lrChannel),_group] call _addNetToBriefing;

_diaryBuilder pushBack "<br/><br/>Note: Subject to change.";

_diaryBuilder pushBack QUOTE(<br/><br/><execute expression='[] call FUNC(reinitializeRadios);'>Reinitialize radios</execute>);

player createDiaryRecord ["diary", ["SIGNALS", _diaryBuilder joinString ""]];

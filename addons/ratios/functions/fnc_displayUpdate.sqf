#include "script_component.hpp"

params ["_sideCount","_sideArray"];

private _numberOfPlayers = lbSize PLAYER_LIST;

private _ratioInput1 = ctrlText RATIO_INPUT_1;
private _ratioInput2 = ctrlText RATIO_INPUT_2;
private _ratioInput3 = ctrlText RATIO_INPUT_3;
private _ratioInput4 = ctrlText RATIO_INPUT_4;

private _nonPlayerTextureCache = GET_UI_VAR(nonPlayerTextureCache);
if (isNil "_nonPlayerTextureCache") then {
    _nonPlayerTextureCache = [];

    {
        _nonPlayerTextureCache pushBack (getText (configFile >> SLOT_DISPLAY_NAME >> _x));
    } forEach ["logicLocked","logicUnlocked","virtLocked","virtUnlocked"];

    SET_UI_VAR(nonPlayerTextureCache,_nonPlayerTextureCache);
};

private _nonPlayers = 0;

for "_i" from 0 to (_numberOfPlayers - 1) do {
    if ((PLAYER_LIST lbPicture _i) in _nonPlayerTextureCache) then {
        INC(_nonPlayers);
    };
};

private _players = _numberOfPlayers - _nonPlayers;

if ([_players, _ratioInput1, _ratioInput2, _ratioInput3, _ratioInput4] call FUNC(skipUpdate)) exitWith {};

private _ratioInputValue1 = parseNumber _ratioInput1;
private _ratioInputValue2 = parseNumber _ratioInput2;
private _ratioInputValue3 = parseNumber _ratioInput3;
private _ratioInputValue4 = parseNumber _ratioInput4;

// save cyles when values are invalid for ratios 1 or 2
if (_ratioInputValue1 == 0
        || {_ratioInputValue2 == 0}
        || {_sideCount > 2 && _ratioInputValue3 == 0}
        || {_sideCount > 3 && _ratioInputValue4 == 0}) exitWith {

    if (_ratioInputValue1 == 0) then { RATIO_INPUT_1 ctrlSetText ""; };
    if (_ratioInputValue2 == 0) then { RATIO_INPUT_2 ctrlSetText ""; };
    if (_sideCount > 2 && _ratioInputValue3 == 0) then { RATIO_INPUT_3 ctrlSetText ""; };
    if (_sideCount > 3 && _ratioInputValue4 == 0) then { RATIO_INPUT_4 ctrlSetText ""; };
};

lbClear RATIO_OUTPUT_1;
lbClear RATIO_OUTPUT_2;
lbClear RATIO_OUTPUT_3;
lbClear RATIO_OUTPUT_4;

//redo this shit later
private _playerTextureCache = GET_UI_VAR(playerTextureCache);
if (isNil "_playerTextureCache") then {
    _playerTextureCache = [];

    {
        if (_sideArray select _forEachIndex) then {
            _playerTextureCache pushBack (getText (configFile >> SLOT_DISPLAY_NAME >> _x));
        };
    } forEach ["westUnlocked","eastUnlocked","guerUnlocked","civlUnlocked"];

    SET_UI_VAR(playerTextureCache,_playerTextureCache);
};

private _denominator = (_ratioInputValue1 + _ratioInputValue2 + _ratioInputValue3 + _ratioInputValue4);

private _teamCount1 = round(_players / _denominator * _ratioInputValue1);
private _teamCount2 = round(_players / _denominator * _ratioInputValue2);
private _teamCount3 = round(_players / _denominator * _ratioInputValue3);
private _teamCount4 = round(_players / _denominator * _ratioInputValue4);

if (_teamCount1 > 0) then {
    RATIO_OUTPUT_1 lbAdd (str _teamCount1);
    RATIO_OUTPUT_1 lbSetPicture [0, _playerTextureCache select 0];
};
if (_teamCount2 > 0) then {
    RATIO_OUTPUT_2 lbAdd (str _teamCount2);
    RATIO_OUTPUT_2 lbSetPicture [0, _playerTextureCache select 1];
};
if (_teamCount3 > 0) then {
    RATIO_OUTPUT_3 lbAdd (str _teamCount3);
    RATIO_OUTPUT_3 lbSetPicture [0, _playerTextureCache select 2];
};
if (_teamCount4 > 0) then {
    RATIO_OUTPUT_4 lbAdd (str _teamCount4);
    RATIO_OUTPUT_4 lbSetPicture [0, _playerTextureCache select 3];
};

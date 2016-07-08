/*
 * Author: AACO
 * Function used to update the ratio display
 *
 * Arguments:
 * 0: Number of sides (to use in ratio calculating) <NUMBER>
 * 1: Array of side statuses (enabled/disabled) in order [west,east,resistance] <ARRAY>
 *
 * Examples:
 * [_sideCount,_sideArray] call potato_ratios_displayUpdate;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_sideCount","_sideArray"];

// get literal count from the player list, if override is filled out, use that instead
private _numberOfPlayers = lbSize PLAYER_LIST;
private _override = parseNumber (ctrlText RATIO_PLAYER_OVERRIDE_INPUT);
if (_override > 0) then {
    _numberOfPlayers = _override;
};

// get ratio text inputs
private _ratioInput1 = ctrlText RATIO_INPUT_1;
private _ratioInput2 = ctrlText RATIO_INPUT_2;
private _ratioInput3 = ctrlText RATIO_INPUT_3;

// get the non player icons, to remove 'non players' from the player count
private _nonPlayerTextureCache = GET_UI_VAR(nonPlayerTextureCache);
if (isNil "_nonPlayerTextureCache") then {
    _nonPlayerTextureCache = [];

    {
        _nonPlayerTextureCache pushBack (getText (configFile >> SLOT_DISPLAY_NAME >> _x));
    } forEach ["civlLocked","civlUnlocked","logicLocked","logicUnlocked","virtLocked","virtUnlocked"];

    SET_UI_VAR(nonPlayerTextureCache,_nonPlayerTextureCache);
};

// remove 'non players' from the player count
private _nonPlayers = 0;
for "_i" from 0 to (_numberOfPlayers - 1) do {
    if ((PLAYER_LIST lbPicture _i) in _nonPlayerTextureCache) then {
        INC(_nonPlayers);
    };
};

private _players = _numberOfPlayers - _nonPlayers;

// check if the input information has changed, if it hasn't, skip updating
if ([_ratioInput1, _ratioInput2, _ratioInput3, _players] call FUNC(skipUpdate)) exitWith {};

// parse the input into numbers
private _ratioInputValue1 = parseNumber _ratioInput1;
private _ratioInputValue2 = parseNumber _ratioInput2;
private _ratioInputValue3 = parseNumber _ratioInput3;

// make sure the inputs are valid, otherwise reset the inputs and exit
if (_ratioInputValue1 == 0
        || {_ratioInputValue2 == 0}
        || {_sideCount > 2 && _ratioInputValue3 == 0}) exitWith {

    if (_ratioInputValue1 == 0) then { RATIO_INPUT_1 ctrlSetText ""; };
    if (_ratioInputValue2 == 0) then { RATIO_INPUT_2 ctrlSetText ""; };
    if (_sideCount > 2 && _ratioInputValue3 == 0) then { RATIO_INPUT_3 ctrlSetText ""; };
};

// clear out the old ratio values
lbClear RATIO_OUTPUT_1;
lbClear RATIO_OUTPUT_2;
lbClear RATIO_OUTPUT_3;

// order the textures by enabled slots
private _playerTextureCache = GET_UI_VAR(playerTextureCache);
if (isNil "_playerTextureCache") then {
    _playerTextureCache = [];

    {
        if (_sideArray select _forEachIndex) then {
            _playerTextureCache pushBack (getText (configFile >> SLOT_DISPLAY_NAME >> _x));
        };
    } forEach ["westUnlocked","eastUnlocked","guerUnlocked"];

    SET_UI_VAR(playerTextureCache,_playerTextureCache);
};

// calculate the ratios
private _denominator = (_ratioInputValue1 + _ratioInputValue2 + _ratioInputValue3);

private _teamCount1 = round (_players / _denominator * _ratioInputValue1);
private _teamCount2 = round (_players / _denominator * _ratioInputValue2);
private _teamCount3 = round (_players / _denominator * _ratioInputValue3);

// display calculated ratios
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

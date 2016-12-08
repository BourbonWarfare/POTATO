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

// if the display is no longer loaded, exit early
if (!GET_UI_VAR(loaded)) exitWith { true };

params ["_sideCount","_sideArray"];

// get literal count from the player list, if override is filled out, use that instead
private _numberOfPlayers = (lnbSize PLAYER_LIST) select 0;
private _override = parseNumber (ctrlText RATIO_PLAYER_OVERRIDE_INPUT);
if (_override > 0) then {
    _numberOfPlayers = _override;
};

// get ratio text inputs
private _ratioInput1 = ctrlText RATIO_INPUT_1;
private _ratioInput2 = ctrlText RATIO_INPUT_2;
private _ratioInput3 = ctrlText RATIO_INPUT_3;
TRACE_3("inputs",_ratioInput1,_ratioInput2,_ratioInput3);

private _ratioChecked1 = cbChecked RATIO_CHECK_1;
private _ratioChecked2 = cbChecked RATIO_CHECK_2;
private _ratioChecked3 = cbChecked RATIO_CHECK_3;
TRACE_3("checks",_ratioChecked1,_ratioChecked2,_ratioChecked3);

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
    if ((PLAYER_LIST lnbPicture [_i, 0]) in _nonPlayerTextureCache) then {
        INC(_nonPlayers);
    };
};

private _players = _numberOfPlayers - _nonPlayers;

// check if the input information has changed, if it hasn't, skip updating
if ([_ratioInput1, _ratioInput2, _ratioInput3, _players, _ratioChecked1, _ratioChecked2, _ratioChecked3] call (uiNamespace getVariable QFUNC(skipUpdate))) exitWith { !GET_UI_VAR(loaded) };

// parse the input into numbers
private _ratioInputValue1 = parseNumber _ratioInput1;
private _ratioInputValue2 = parseNumber _ratioInput2;
private _ratioInputValue3 = parseNumber _ratioInput3;

// make sure the inputs are valid, otherwise reset the inputs and exit
if ((_ratioInputValue1 == 0 && {_ratioInput1 != "0"})
        || {_ratioInputValue2 == 0 && {_ratioInput2 != "0"}}
        || {_sideCount > 2 && {_ratioInputValue3 == 0} && {_ratioInput3 != "0"}}) exitWith {

    if (_ratioInputValue1 == 0 && {_ratioInput1 != "0"}) then { RATIO_INPUT_1 ctrlSetText ""; };
    if (_ratioInputValue2 == 0 && {_ratioInput2 != "0"}) then { RATIO_INPUT_2 ctrlSetText "";};
    if (_sideCount > 2 && {_ratioInputValue3 == 0} && {_ratioInput3 != "0"}) then { RATIO_INPUT_3 ctrlSetText ""; };
    LOG("Invalid input(s), exiting early");
    !GET_UI_VAR(loaded)
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
private _denominator = 0;

if (_ratioChecked1) then {
    _players = _players - _ratioInputValue1;
} else {
    _denominator = _denominator + _ratioInputValue1;
};
if (_ratioChecked2) then {
    _players = _players - _ratioInputValue2;
} else {
    _denominator = _denominator + _ratioInputValue2;
};
if (_ratioChecked3) then {
    _players = _players - _ratioInputValue3;
} else {
    _denominator = _denominator + _ratioInputValue3;
};

// exit if the denominator is zero to avoid blowing up the world
if (_denominator == 0) exitWith {
    LOG("Please don't divide by zero");
    !GET_UI_VAR(loaded)
};

private _teamCount1 = if (_ratioChecked1) then {
    _ratioInputValue1
} else {
    round ((_players / _denominator * _ratioInputValue1) * 10) / 10;
};

private _teamCount2 = if (_ratioChecked2) then {
    _ratioInputValue2
} else {
    round ((_players / _denominator * _ratioInputValue2) * 10) / 10;
};

private _teamCount3 = if (_ratioChecked3) then {
    _ratioInputValue3
} else {
    round ((_players / _denominator * _ratioInputValue3) * 10) / 10;
};

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

!GET_UI_VAR(loaded)

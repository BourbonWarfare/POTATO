#include "script_component.hpp"

TRACE_1("params",_this);

if (!hasInterface) exitWith {};

SET_UI_VAR(loaded,true);
SET_UI_VAR(lastValues,nil);
SET_UI_VAR(nonPlayerTextureCache,nil);
SET_UI_VAR(playerTextureCache,nil);

PREP(skipUpdate);
PREP(prefillInput);
PREP(displayUpdate);
PREP(getNumberAsString);

waitUntil {
    ctrlEnabled SIDE_CIV
        || {ctrlEnabled SIDE_EAST}
        || {ctrlEnabled SIDE_INDY}
        || {ctrlEnabled SIDE_LOGIC}
        || {ctrlEnabled SIDE_VIRTUAL}
        || {ctrlEnabled SIDE_WEST}
        || {!GET_UI_VAR(loaded)}
};

private _countCivs = if (isNumber (missionConfigFile >> QGVAR(config) >> "includeCivs")) then {
    (getNumber ((missionConfigFile >> QGVAR(config) >> "includeCivs"))) > 0
} else {
    false
};

private _westEnabled = ctrlEnabled SIDE_WEST;
private _eastEnabled = ctrlEnabled SIDE_EAST;
private _indyEnabled = ctrlEnabled SIDE_INDY;
private _civEnabled = _countCivs && {ctrlEnabled SIDE_CIV};

//if this order changes, change it in update
private _sideArray = [_westEnabled,_eastEnabled,_indyEnabled,_civEnabled];
private _sideCount = { _x } count _sideArray;

private _exit = false;
switch (_sideCount) do {
    case (2): {
        RATIO_INPUT_3 ctrlShow false;
        RATIO_INPUT_4 ctrlShow false;

        RATIO_OUTPUT_3  ctrlShow false;
        RATIO_OUTPUT_4  ctrlShow false;
    };
    case (3): {
        RATIO_INPUT_4 ctrlShow false;
        RATIO_OUTPUT_4  ctrlShow false;
    };
    case (4): {};
    default {
        _exit = true;

        RATIO_PLAYER_OVERRIDE ctrlShow false;
        RATIO_PLAYER_OVERRIDE_INPUT ctrlShow false;

        RATIO_TEXT ctrlShow false;

        RATIO_INPUT_1 ctrlShow false;
        RATIO_INPUT_2 ctrlShow false;
        RATIO_INPUT_3 ctrlShow false;
        RATIO_INPUT_4 ctrlShow false;

        RATIO_OUTPUT_1 ctrlShow false;
        RATIO_OUTPUT_2 ctrlShow false;
        RATIO_OUTPUT_3 ctrlShow false;
        RATIO_OUTPUT_4 ctrlShow false;
    };
};

if (_exit) exitWith {};

if ((isNumber (missionConfigFile >> QGVAR(config) >> "blueFor"))
        || {isNumber (missionConfigFile >> QGVAR(config) >> "opFor")}
        || {isNumber (missionConfigFile >> QGVAR(config) >> "indy")}
        || {isNumber (missionConfigFile >> QGVAR(config) >> "civ")}) then {

    private _addArray = [_westEnabled,_eastEnabled,_indyEnabled,_civEnabled];

    if (ctrlEnabled RATIO_INPUT_1) then {
        _addArray = [RATIO_INPUT_1_IDC,_addArray] call FUNC(prefillInput);
    };

    if (ctrlEnabled RATIO_INPUT_2) then {
        _addArray = [RATIO_INPUT_2_IDC,_addArray] call FUNC(prefillInput);
    };

    if (ctrlEnabled RATIO_INPUT_3) then {
        _addArray = [RATIO_INPUT_3_IDC,_addArray] call FUNC(prefillInput);
    };

    if (ctrlEnabled RATIO_INPUT_4) then {
        [RATIO_INPUT_4_IDC,_addArray] call FUNC(prefillInput);
    };
};

while {GET_UI_VAR(loaded)} do {
    [_sideCount,_sideArray,_countCivs] call FUNC(displayUpdate);
};

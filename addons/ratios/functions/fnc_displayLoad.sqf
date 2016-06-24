/*
 * Author: AACO
 * Function used to prep the UI functions, populate/configure the ratio UI,
 * and call the UI update function
 * Should only be called from UI events
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// display shouldn't load if there's no interface, but belt & suspenders
if (!hasInterface) exitWith {};

// set defaults for pseduo GVARs
SET_UI_VAR(loaded,true);
SET_UI_VAR(lastValues,nil);
SET_UI_VAR(nonPlayerTextureCache,nil);
SET_UI_VAR(playerTextureCache,nil);

// prepare functions used by the calculator
// (using the normal prestart/preinit method does not work in this environment)
PREP(skipUpdate);
PREP(prefillInput);
PREP(displayUpdate);

// wait until the display elements we need are displayed, or the display is unloaded
waitUntil {
    ctrlEnabled SIDE_CIV
        || {ctrlEnabled SIDE_EAST}
        || {ctrlEnabled SIDE_INDY}
        || {ctrlEnabled SIDE_LOGIC}
        || {ctrlEnabled SIDE_VIRTUAL}
        || {ctrlEnabled SIDE_WEST}
        || {!GET_UI_VAR(loaded)}
};

// check which side displays are enabled
private _westEnabled = ctrlEnabled SIDE_WEST;
private _eastEnabled = ctrlEnabled SIDE_EAST;
private _indyEnabled = ctrlEnabled SIDE_INDY;

//if this order changes, change it in update
private _sideArray = [_westEnabled,_eastEnabled,_indyEnabled];
private _sideCount = { _x } count _sideArray;
TRACE_2("",_sideArray,_sideCount);

// if there is less than two sides (COOPs), disable the ratio display, and exit
if (_sideCount < 2) exitWith {
    RATIO_PLAYER_OVERRIDE ctrlShow false;
    RATIO_PLAYER_OVERRIDE_INPUT ctrlShow false;

    RATIO_TEXT ctrlShow false;

    RATIO_INPUT_1 ctrlShow false;
    RATIO_INPUT_2 ctrlShow false;
    RATIO_INPUT_3 ctrlShow false;

    RATIO_OUTPUT_1 ctrlShow false;
    RATIO_OUTPUT_2 ctrlShow false;
    RATIO_OUTPUT_3 ctrlShow false;
};

// if there are less than three sides, disable the third ratio display
if (_sideCount < 3) then {
    RATIO_INPUT_3 ctrlShow false;
    RATIO_OUTPUT_3  ctrlShow false;
};

// check the mission description for ratio information
private _description = ctrlText DESCRIPTION;
private _ratioCanidate = (_description splitString " ") select 0;
TRACE_2("prefill info",_description,_ratioCanidate);

// if the ratio information looks good, try to parse it
if (!(isNil "_ratioCanidate") && (_ratioCanidate find ":") > -1) then {
    private _ratioArray = _ratioCanidate splitString ":";
    private _ratioCount = count _ratioArray;

    if (_sideCount > 0) then {
        RATIO_INPUT_1 ctrlSetText ([_ratioArray,_ratioCount,0] call FUNC(prefillInput));
    };
    if (_sideCount > 1) then {
        RATIO_INPUT_2 ctrlSetText ([_ratioArray,_ratioCount,1] call FUNC(prefillInput));
    };
    if (_sideCount > 2) then {
        RATIO_INPUT_3 ctrlSetText ([_ratioArray,_ratioCount,2] call FUNC(prefillInput));
    };
};

// while the display is loaded, update the display
while {GET_UI_VAR(loaded)} do {
    [_sideCount,_sideArray] call FUNC(displayUpdate);
};

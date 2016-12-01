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
if (!hasInterface) exitWith { LOG("no interface, exiting"); };

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

TRACE_5("pre",ctrlEnabled SIDE_CIV,ctrlEnabled SIDE_EAST,ctrlEnabled SIDE_INDY,ctrlEnabled SIDE_WEST,!GET_UI_VAR(loaded));

// wait until the display elements we need are displayed, or the display is unloaded
waitUntil {
    ctrlEnabled SIDE_CIV
        || {ctrlEnabled SIDE_EAST}
        || {ctrlEnabled SIDE_INDY}
        || {ctrlEnabled SIDE_WEST}
        || {!GET_UI_VAR(loaded)}
};

TRACE_5("post",ctrlEnabled SIDE_CIV,ctrlEnabled SIDE_EAST,ctrlEnabled SIDE_INDY,ctrlEnabled SIDE_WEST,!GET_UI_VAR(loaded));

uiSleep 0.1; // sleep to stabilize

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

    RATIO_INPUT_1 ctrlShow false;
    RATIO_INPUT_2 ctrlShow false;
    RATIO_INPUT_3 ctrlShow false;

    RATIO_CHECK_1 ctrlShow false;
    RATIO_CHECK_2 ctrlShow false;
    RATIO_CHECK_3 ctrlShow false;

    RATIO_OUTPUT_1 ctrlShow false;
    RATIO_OUTPUT_2 ctrlShow false;
    RATIO_OUTPUT_3 ctrlShow false;
};

// if there are less than three sides, disable the third ratio display
if (_sideCount < 3) then {
    RATIO_INPUT_3 ctrlShow false;
    RATIO_CHECK_3 ctrlShow false;
    RATIO_OUTPUT_3 ctrlShow false;
};

// check the mission description for ratio information
private _description = ctrlText DESCRIPTION;
private _ratioCanidate = (_description splitString " ") select 0;
TRACE_2("prefill info",_description,_ratioCanidate);

// if the ratio information looks good, try to parse it
if ((!isNil "_ratioCanidate") && {(_ratioCanidate find ":") > -1}) then {
    private _ratioArray = _ratioCanidate splitString ":";
    private _ratioCount = count _ratioArray;

    // first two ratios ensured
    ([_ratioArray,_ratioCount,0] call FUNC(prefillInput)) params ["_input1","_check1"];
    RATIO_INPUT_1 ctrlSetText _input1;
    RATIO_CHECK_1 cbSetChecked _check1;

    ([_ratioArray,_ratioCount,1] call FUNC(prefillInput)) params ["_input2","_check2"];
    RATIO_INPUT_2 ctrlSetText _input2;
    RATIO_CHECK_2 cbSetChecked _check2;

    if (_sideCount > 2) then {
        ([_ratioArray,_ratioCount,2] call FUNC(prefillInput)) params ["_input3","_check3"];
        RATIO_INPUT_3 ctrlSetText _input3;
        RATIO_CHECK_3 cbSetChecked _check3;
    };
};

// while the display is loaded, update the display
waitUntil {
    [_sideCount,_sideArray] call FUNC(displayUpdate);
    !GET_UI_VAR(loaded)
};

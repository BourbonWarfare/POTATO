/*
 * Author: AACO
 * Function used to sync the changes between the sliders and the text boxes
 * Should only be called by UI events
 *
 * Arguments:
 * 0: Slider <BOOL>
 * 1: Index <NUMBER>
 *
 * Example:
 * [true,0] call potato_zeusHC_fnc_garrisonDialogControlChange;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_isSlider","_controlIndex"];

private _sliderIdc = -1;
private _editIdc = -1;
private _checkMinMax = false;

switch (_controlIndex) do {
    case (0): {
        _sliderIdc = GARRISON_CHANCE_SLIDER_IDC;
        _editIdc = GARRISON_CHANCE_EDIT_IDC;
    };
    case (1): {
        _sliderIdc = GARRISON_RADIUS_SLIDER_IDC;
        _editIdc = GARRISON_RADIUS_EDIT_IDC;
    };
    case (2): {
        _sliderIdc = GARRISON_MIN_SLIDER_IDC;
        _editIdc = GARRISON_MIN_EDIT_IDC;
        _checkMinMax = true;
    };
    case (3): {
        _sliderIdc = GARRISON_MAX_SLIDER_IDC;
        _editIdc = GARRISON_MAX_EDIT_IDC;
        _checkMinMax = true;
    };
    case (4): {
        _sliderIdc = GARRISON_UNITS_SLIDER_IDC;
        _editIdc = GARRISON_UNITS_EDIT_IDC;
    };
};

if (_sliderIdc == -1 || _editIdc == -1) exitWith { TRACE_1("Control index is in a bad state",_controlIndex) };

private _newValue = if (_isSlider) then {
    floor (sliderPosition _sliderIdc)
} else {
    (sliderRange _sliderIdc) params ["_min","_max"];
    private _returnValue = floor (parseNumber (ctrlText _editIdc));
    [_returnValue,_min,_max] call EFUNC(core,ensureRange)
};

sliderSetPosition [_sliderIdc, _newValue];
ctrlSetText [_editIdc, str _newValue];

if (_checkMinMax) then {
    [] call FUNC(garrisonDialogCheckMinMax);
};

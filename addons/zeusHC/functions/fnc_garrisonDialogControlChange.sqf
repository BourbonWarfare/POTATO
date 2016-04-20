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
};

if (_sliderIdc == -1 || _editIdc == -1) exitWith { TRACE_1("Control index is in a bad state", _controlIndex) };

private _newValue = if (_isSlider) then {
    floor (sliderPosition _sliderIdc)
} else {
    private _sliderRange = sliderRange _sliderIdc;
    private _min = (_sliderRange select 0);
    private _max = (_sliderRange select 1);
    private _returnValue = floor (parseNumber (ctrlText _editIdc));
    _returnValue = _max min _returnValue;
    _returnValue = _min max _returnValue;
    _returnValue
};

sliderSetPosition [_sliderIdc, _newValue];
ctrlSetText [_editIdc, str _newValue];

if (_checkMinMax) then {
    [] call FUNC(garrisonDialogCheckMinMax);
};

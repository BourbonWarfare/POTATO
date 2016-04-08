#include "script_component.hpp"
TRACE_1("Params",_this);

private _minValue = sliderPosition GARRISON_MIN_SLIDER_IDC;
private _maxValue = sliderPosition GARRISON_MAX_SLIDER_IDC;

if (_minValue > _maxValue) then {
    sliderSetPosition [GARRISON_MAX_SLIDER_IDC, _minValue];
    ctrlSetText [GARRISON_MAX_EDIT_IDC, str _minValue];
};

if (_maxValue < _minValue) then {
    sliderSetPosition [GARRISON_MIN_SLIDER_IDC, _maxValue];
    ctrlSetText [GARRISON_MIN_EDIT_IDC, str _maxValue];
};

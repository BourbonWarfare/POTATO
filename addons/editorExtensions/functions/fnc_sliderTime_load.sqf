//IGNORE_PRIVATE_WARNING["_config", "_value"];
#include "script_component.hpp"

private _increment = getNumber (_config >> "increment");
private _maxTimeSeconds = getNumber (_config >> "maxTimeSeconds");
if (_maxTimeSeconds == 0) then {
    _maxTimeSeconds = 60 * 60 * 2.5
};

private _slider = _this controlsGroupCtrl IDC_SLIDER_TIME_SLIDER;

_slider sliderSetSpeed [1, 1, _increment];
_slider sliderSetRange [0, _maxTimeSeconds];
_slider sliderSetPosition _value;

_slider setVariable [QGVAR(value), _value];

[_slider, _value] call FUNC(sliderTime_onSliderPosChanged);

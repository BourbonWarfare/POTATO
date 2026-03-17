#include "script_component.hpp"

private _slider = (_this controlsGroupCtrl IDC_SLIDER_TIME_SLIDER);
_slider getVariable [QGVAR(value), sliderPosition _slider]

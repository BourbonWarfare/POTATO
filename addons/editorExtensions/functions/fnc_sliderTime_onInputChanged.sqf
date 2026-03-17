#include "script_component.hpp"

params ["_input"];

private _parent = ctrlParentControlsGroup _input;

private _ctrlSlider = _parent controlsGroupCtrl IDC_SLIDER_TIME_SLIDER;
private _ctrlHours = _parent controlsGroupCtrl IDC_SLIDER_TIME_HOUR;
private _ctrlMinutes = _parent controlsGroupCtrl IDC_SLIDER_TIME_MINUTE;
private _ctrlSeconds = _parent controlsGroupCtrl IDC_SLIDER_TIME_SECOND;

private _valueHours = 0 max (99 min parseNumber ctrlText _ctrlHours);
private _valueMinutes = 0 max ((parseNumber ctrlText _ctrlMinutes) % 60);
private _valueSeconds = 0 max ((parseNumber ctrlText _ctrlSeconds) % 60);

private _value = _valueSeconds + 60 * _valueMinutes + 60 * 60 * _valueHours;

_ctrlHours ctrlSetText format ["%1%2", ["", "0"] select (_valueHours < 10), _valueHours];
_ctrlHours ctrlSetTextSelection [0, 0];

_ctrlMinutes ctrlSetText format ["%1%2", ["", "0"] select (_valueMinutes < 10), _valueMinutes];
_ctrlMinutes ctrlSetTextSelection [0, 0];

_ctrlSeconds ctrlSetText format ["%1%2", ["", "0"] select (_valueSeconds < 10), _valueSeconds];
_ctrlSeconds ctrlSetTextSelection [0, 0];

_ctrlSlider sliderSetPosition _value;
_ctrlSlider setVariable [QGVAR(value), _value];

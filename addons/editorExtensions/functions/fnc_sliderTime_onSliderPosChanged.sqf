#include "script_component.hpp"

params ["_slider", "_value"];

private _valueHours = floor (_value / 3600);
private _valueMinutes = floor (_value / 60) % 60;
private _valueSeconds = _value % 60;

_slider setVariable [QGVAR(value), _value];

private _parent = ctrlParentControlsGroup _slider;

private _ctrlHours = _parent controlsGroupCtrl IDC_SLIDER_TIME_HOUR;
private _ctrlMinutes = _parent controlsGroupCtrl IDC_SLIDER_TIME_MINUTE;
private _ctrlSeconds = _parent controlsGroupCtrl IDC_SLIDER_TIME_SECOND;

_ctrlHours ctrlSetText format ["%1%2", ["", "0"] select (_valueHours < 10), _valueHours];
_ctrlHours ctrlSetTextSelection [0, 0];

_ctrlMinutes ctrlSetText format ["%1%2", ["", "0"] select (_valueMinutes < 10), _valueMinutes];
_ctrlMinutes ctrlSetTextSelection [0, 0];

_ctrlSeconds ctrlSetText format ["%1%2", ["", "0"] select (_valueSeconds < 10), _valueSeconds];
_ctrlSeconds ctrlSetTextSelection [0, 0];

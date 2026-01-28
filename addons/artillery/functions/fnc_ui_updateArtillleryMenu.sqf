#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles updating slider text for the artillery menu.
 *
 * Arguments:
 * _args - An array wit the control and new value for the control. ARRAY
 * _sliderUpdate - The slider IDC that is being updated. SCALAR, default -1
 *
 * Return:
 * None
 *
 * Example:
 * Only called via callback
 *
 * Public: No
 */
params ["_args", ["_sliderUpdate", -1]];
_args params ["_ctrl", "_newValue"];

private _display = ctrlParent _ctrl;
private _dims = _display getVariable [QGVAR(pos), [[0, 0, 0], 60, 0]];
switch (_sliderUpdate) do {
    case IDC_ARTILLERY_DISPERSION: {
        private _textCtrl = _display displayCtrl IDC_ARTILLERY_DISPERSIONTXT;
        _textCtrl ctrlSetText format ["Round Dispersion: %1m", round _newValue];
        _dims set [1, _newValue/2];
    };
    case IDC_ARTILLERY_ROTATION: {
        private _textCtrl = _display displayCtrl IDC_ARTILLERY_ROTATIONTXT;
        _textCtrl ctrlSetText format ["Mission Rotation: %1", round _newValue];
        _dims set [2, _newValue];
    };
    case IDC_ARTILLERY_MISSIONTYPE;
    case IDC_ARTILLERY_MISSIONGLENGTH: {
        private _textCtrl = _display displayCtrl IDC_ARTILLERY_MISSIONGLENGTHTXT;
        private _baseText = "Rounds per gun (1-16): ";
        if (_sliderUpdate != IDC_ARTILLERY_MISSIONGLENGTH) then {
            _newValue = sliderPosition (_display displayCtrl IDC_ARTILLERY_MISSIONGLENGTH);
        };
        private _missionTypeIdx = lbCurSel (_display displayCtrl IDC_ARTILLERY_MISSIONTYPE);
        if (_missionTypeIdx in
            [ARTILLERY_MISSIONTYPE_LINEAR, ARTILLERY_MISSIONTYPE_CREEPING, ARTILLERY_MISSIONTYPE_LINEAR_WITH_WALK]) then {
            _newValue = _newValue * 2;
            _baseText = "Rounds per gun (2-32): ";
        };
        if (_missionTypeIdx in [ARTILLERY_MISSIONTYPE_SLOW, ARTILLERY_MISSIONTYPE_SLOW_WITH_WALK]) then {
            (_display displayCtrl IDC_ARTILLERY_MISSIONGLENGTHTIME) ctrlEnable true;
        } else {
            (_display displayCtrl IDC_ARTILLERY_MISSIONGLENGTHTIME) ctrlEnable false;
        };
        private _newValueStr = str _newValue;
        if (_newValue < 10) then {
            _newValueStr = "0" + _newValueStr;
        };
        _newValueStr = _baseText + _newValueStr;
        _textCtrl ctrlSetText _newValueStr;
    };
    case IDC_ARTILLERY_MISSIONGDELAY: {
        private _textCtrl = _display displayCtrl IDC_ARTILLERY_MISSIONGDELAYTXT;
        private _minutes = floor (_newValue / 60);
        private _seconds = floor (_newValue mod 60);
        if (_minutes < 10) then {_minutes = "0" + str _minutes} else {str _minutes};
        if (_seconds < 10) then {_seconds = "0" + str _seconds} else {str _seconds};
        _textCtrl ctrlSetText format ["Mission delay: %1:%2", _minutes, _seconds];
    };
    case IDC_ARTILLERY_MISSIONGLENGTHTIME: {
        private _textCtrl = _display displayCtrl IDC_ARTILLERY_MISSIONGLENGTHTIMETXT;
        private _minutes = floor (_newValue / 60);
        private _seconds = floor (_newValue mod 60);
        if (_minutes < 10) then {_minutes = "0" + str _minutes} else {str _minutes};
        if (_seconds < 10) then {_seconds = "0" + str _seconds} else {str _seconds};
        _textCtrl ctrlSetText format ["Mission length: %1:%2", _minutes, _seconds];
    };
    default {};
};

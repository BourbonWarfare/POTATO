#include "..\..\script_component.hpp"
/**************************************************************//*
* Updates designated artillery marker
*
* Arguments:
* None
*
* Example:
* [] call lmd_fnc_ui_updateCircleSpawnMenu
*//**************************************************************/
params ["_args", ["_sliderUpdate", -1]];
_args params ["_ctrl", "_newValue"];

private _display = ctrlParent _ctrl;
switch (_sliderUpdate) do {
    case CIRCLESPAWN_PARAM_LNGTH_PARAM_RAD: {
        private _textCtrl = _display displayCtrl IDC_CIRCLESPAWN_RAD_TEXT;
        _textCtrl ctrlSetText format ["Max Radius: %1m", _newValue toFixed 0];
        GVAR(cirlceSpawnMarkInfo) set [0, _newValue];
    };
    case CIRCLESPAWN_PARAM_LNGTH_PARAM_LNGTH: {
        private _textCtrl = _display displayCtrl IDC_CIRCLESPAWN_LENGTH_TEXT;
        _textCtrl ctrlSetText format ["Spawner Length: %1s", _newValue toFixed 0];
    };
    case CIRCLESPAWN_PARAM_UNIT_PARAM_CNT: {
        private _textCtrl = _display displayCtrl IDC_CIRCLESPAWN_CNT_TEXT;
        _textCtrl ctrlSetText format ["Goal Unit Count: %1", _newValue toFixed 0];
    };
    case CIRCLESPAWN_PARAM_UNIT_PARAM_MIN: {
        private _textCtrl = _display displayCtrl IDC_CIRCLESPAWN_MIN_TEXT;
        _textCtrl ctrlSetText format ["Min Unit Count: %1", _newValue toFixed 0];
    };
    case CIRCLESPAWN_PARAM_UNIT_PARAM_MAX: {
        private _textCtrl = _display displayCtrl IDC_CIRCLESPAWN_MAX_TEXT;
        _textCtrl ctrlSetText format ["Max Unit Count: %1", _newValue toFixed 0];
    };
    case CIRCLESPAWN_PARAM_UNIT_PARAM_PRD: {
        private _textCtrl = _display displayCtrl IDC_CIRCLESPAWN_PRD_TEXT;
        _textCtrl ctrlSetText format ["Period: %1s", _newValue toFixed 0];
    };
};

/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlInfo","_isSlider"];

if (_isSlider) then {
    _ctrlInfo params ["_ctrlSlider", "_value"];

    private _roundedValue = floor (_value * 100);
    GVAR(terrainInterference) = _roundedValue / 100;

    private _ctrlEdit = (ctrlParentControlsGroup _ctrlSlider) controlsGroupCtrl CFG_G_TI_EDIT_IDC;
    _ctrlEdit ctrlSetText (format ["%1 %2", _roundedValue, "%"]);
} else {
    _ctrlInfo params ["_ctrlEdit"];

    private _value = ((parseNumber (ctrlText _ctrlEdit)) max 0) min 100;
    private _roundedReducedValue = (floor _value) / 100;
    GVAR(terrainInterference) = _roundedReducedValue;

    private _ctrlSlider = (ctrlParentControlsGroup _ctrlEdit) controlsGroupCtrl CFG_G_TI_SLIDER_IDC;
    _ctrlSlider sliderSetPosition _roundedReducedValue;
};

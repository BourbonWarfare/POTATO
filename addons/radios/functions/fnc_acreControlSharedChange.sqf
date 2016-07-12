/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);
params ["_ctrlCheckbox","_isChecked","_isLR"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlCheckbox;
private _crtlSide = _ctrlGroup controlsGroupCtrl CFG_SIDE_IDC;

switch (lbCurSel _crtlSide) do {
    case (0): {
        if (_isLR) then {
            GVAR(addCommonChannelWestLR) = (_isChecked == 1);
        } else {
            GVAR(addCommonChannelWestMR) = (_isChecked == 1);
        };
    };
    case (1): {
        if (_isLR) then {
            GVAR(addCommonChannelEastLR) = (_isChecked == 1);
        } else {
            GVAR(addCommonChannelEastMR) = (_isChecked == 1);
        };
    };
    case (2): {
        if (_isLR) then {
            GVAR(addCommonChannelIndyLR) = (_isChecked == 1);
        } else {
            GVAR(addCommonChannelIndyMR) = (_isChecked == 1);
        };
    };
    default {
        if (_isLR) then {
            GVAR(addCommonChannelCivLR) = (_isChecked == 1);
        } else {
            GVAR(addCommonChannelCivMR) = (_isChecked == 1);
        };
    };
};

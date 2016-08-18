/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);
params ["_ctrlInfo","_isLR"];
_ctrlInfo params ["_ctrl","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrl;
private _crtlSide = _ctrlGroup controlsGroupCtrl CFG_S_SIDE_IDC;

switch (lbCurSel _crtlSide) do {
    case (0): {
        if (_isLR) then {
            GVAR(addCommonChannelWestLR) = ([_index] call CFUNC(parseBool));
        } else {
            GVAR(addCommonChannelWestMR) = ([_index] call CFUNC(parseBool));
        };
    };
    case (1): {
        if (_isLR) then {
            GVAR(addCommonChannelEastLR) = ([_index] call CFUNC(parseBool));
        } else {
            GVAR(addCommonChannelEastMR) = ([_index] call CFUNC(parseBool));
        };
    };
    case (2): {
        if (_isLR) then {
            GVAR(addCommonChannelIndyLR) = ([_index] call CFUNC(parseBool));
        } else {
            GVAR(addCommonChannelIndyMR) = ([_index] call CFUNC(parseBool));
        };
    };
    default {
        if (_isLR) then {
            GVAR(addCommonChannelCivLR) = ([_index] call CFUNC(parseBool));
        } else {
            GVAR(addCommonChannelCivMR) = ([_index] call CFUNC(parseBool));
        };
    };
};

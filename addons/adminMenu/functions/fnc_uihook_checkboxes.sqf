#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Handles checkbox changes on the admin menu
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * [checkbox_IDC, true] call potato_safeStart_fnc_forceEndSafeStart;
 *
 * Public: No
 */

TRACE_1("params",_this);

params ["_control", "_checked", ["_propagate", true, [true]]];

// CBA doesn't like to transfer controls
// Instead we extract the IDC or recreate the control
private _controlIDC = if (_control isEqualType 0) then {
    private _valueStorage = _control;
    _control = (uiNamespace getVariable [QGVAR(adminMenuDialog), displayNull]) displayCtrl _control;
    _valueStorage
} else {
    ctrlIDC _control
};

private _checkedBool = _checked == 1;

switch (_controlIDC) do {
    case IDC_CHECKBOX_SAFESTARTSAFETY: {
        EGVAR(safeStart,safeStartSafetyOn) = _checkedBool;
        _control cbSetChecked _checkedBool;
    };
    default {
        _propagate = false;
    };
};

if (_propagate) then {
    [QGVAR(sync_checkbox), [IDC_CHECKBOX_SAFESTARTSAFETY, _checked, false]] call CBA_fnc_globalEventJIP;
};

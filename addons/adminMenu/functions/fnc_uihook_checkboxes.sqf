#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Handles all check box changes on the admin menu. It takes either a control
 * or a control IDC and create both, then completes a set of code based on
 * the control's IDC. If the setting should be propagated to other clients.
 *
 * Arguments:
 * 0: The control or the control ID of the check box checked (NUMBER/CONTROL)
 * 1: Whether the box was checked, 1 for checked and 0 for not (NUMBER)
 * 2: Should this change propagate to the rest of the users (BOOL)
 *
 * Return Value:
 * None
 *
 * Examples:
 * [checkbox_IDC, 0] call potato_safeStart_fnc_forceEndSafeStart;
 * [checkbox_control, 1, false] call potato_safeStart_fnc_forceEndSafeStart;
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

// Handlers for each IDC
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

// Propagate to other clients, this will cause this function to be called twice
if (_propagate) then {
    [QGVAR(sync_checkbox), [IDC_CHECKBOX_SAFESTARTSAFETY, _checked, false]] call CBA_fnc_globalEventJIP;
};

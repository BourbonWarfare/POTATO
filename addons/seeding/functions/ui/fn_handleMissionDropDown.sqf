#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This fucntion handles combo or "drop down" menus being changed.
*
* Arguments:
* BIS onLBSelChanged EH changed
*
* Only called via callback
*//***************************************************************************/
params ["_control", "_lbCurSel", "_lbSelection"];

private _controlIDC = ctrlIDC _control;

switch (_controlIDC) do {
    case IDC_MISSION_OPERATIONTYPE: {
        private _display = ctrlParent _control;
        if (_lbCurSel != GET_MENU_OPTION(operationType)) then {
            SET_MENU_OPTION(operationType,_lbCurSel);
            [_display] call FUNC(updateMenuOptions);
        };
    };
    case IDC_MISSION_ENEMYTYPE: {
        SET_MENU_OPTION(enemyType,_lbCurSel);
    };
    case IDC_MISSION_DROPDOWN: {
        SET_MENU_OPTION(density,_lbCurSel);
    };
    default {
        diag_log formatText ["[SEED][Mission] COMBO ERROR: Invalid control IDC: %1", _controlIDC];
    };
};

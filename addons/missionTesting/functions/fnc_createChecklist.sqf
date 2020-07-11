/*
 * Author: BadWolf
 * Function called to create the checklist array if it does not already exist and update it with the contents of controls in the checklist menu.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_createChecklist;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

private _parentCtrl = MENU_DISPLAY displayCtrl 9991;
private _ctrls = allControls MENU_DISPLAY select {ctrlParentControlsGroup _x isEqualTo _parentCtrl && (ctrlClassName _x isEqualTo "RscStructuredText" || ctrlClassName _x isEqualTo "RscCombo" || ctrlClassName _x isEqualTo "RscCheckBox" ||  ctrlClassName _x isEqualTo "RscEdit" ||  ctrlClassName _x isEqualTo "RscEditMulti");};
private _contents = nil;
{
    private _class = ctrlClassName _x;
    private _idc = ctrlIDC _x;
    switch (_class) do {
        case "RscCheckBox": {
        _contents = cbChecked _x;
        };
        case "RscCombo": {
        _contents = lbCurSel _x;
        };
        default {
        _contents = ctrlText _x;
        };
    };
    GVAR(checklist) pushBack [_contents,_idc,_class];
}forEach _ctrls;

/*
 * Author: BadWolf
 * Function called to store updates to the checklist array with the contents of controls in the checklist menu.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_storeResults;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

GVAR(checklist) = [];

if (count GVAR(checklist) == 0) exitWith {[] call FUNC(createChecklist)};
{
    private _contents = _x select 0;
    private _idc = _x select 1;
    private _type = _x select 2;
    private _ctrl = MENU_DISPLAY displayCtrl _idc;
    TRACE_1("In",_x);
    switch (_type) do {
        case "RscCombo": {
        _contents = lbCurSel _idc;
        };
        case "RscCheckBox": {
        _contents = cbChecked _ctrl;
        };
        case "RscStructuredText": {
        _contents;
        };
        default {
        _contents = ctrlText _idc;
        };
    };
    _x set [0,_contents];
    GVAR(checklist) set [_forEachIndex,_x];
    TRACE_1("Out",_x);
} forEach GVAR(checklist);


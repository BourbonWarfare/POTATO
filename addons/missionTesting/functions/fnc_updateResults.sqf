/*
 * Author: BadWolf
 * Function called when Mission Test Tab is selected to latest saved data.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_updateResults;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

{
    private _contents = _x select 0;
    private _idc = _x select 1;
    private _class = _x select 2;
    private _ctrl = MENU_DISPLAY displayCtrl _idc;
    switch (_class) do {
        case "RscCombo": {
        TRACE_1("RscCombo",_class);
        _ctrl lbSetCurSel _contents;
        };
        case "RscCheckBox": {
        TRACE_1("RscCheckBox",_class);
        _ctrl cbSetChecked _contents;
        };
        default {
        TRACE_1("default",_class);
        ctrlSetText [_idc,_contents];
        };
    };
} forEach GVAR(checklist);

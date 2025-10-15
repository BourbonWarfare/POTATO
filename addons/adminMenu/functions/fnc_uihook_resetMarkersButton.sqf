#include "script_component.hpp"

params [["_mode", UI_TAB, [UI_TAB]]];
TRACE_2("params",_this,_mode);

private _selectedUnit = switch (_mode) do {
    case MARKERS_TAB: {
        missionNamespace getVariable [
            UI_TAB_MARKERS_PLAYERS lbData (lbCurSel UI_TAB_MARKERS_PLAYERS),
            objNull
        ];
    };
    default {
        missionNamespace getVariable [
            UI_TAB_FIX_UNIT_LIST lbData (lbCurSel UI_TAB_FIX_UNIT_LIST),
            objNull
        ];
    };
};

TRACE_1("Selected unit: ",_selectedUnit);

if (isNull _selectedUnit) exitWith {
    systemChat "POTATO [Menu>You]:Error restting markers, no unit found";
    WARNING_1("Bad unit [%1] disconnect?",_selectedUnit);
};

[false] remoteExecCall [QEFUNC(markers,reinitMarkerHash), _selectedUnit];

["potato_adminMsg", [format ["Resetting markers on %1", [_selectedUnit] call ACEFUNC(common,getName)], profileName]] call CBA_fnc_globalEvent;

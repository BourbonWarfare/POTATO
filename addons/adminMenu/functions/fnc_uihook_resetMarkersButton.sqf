#include "script_component.hpp"

TRACE_1("params",_this);
params [["_mode", UI_TAB, [UI_TAB]]];

private _selectedUnit = switch (_mode) do {
    case MARKERS_TAB: {
        missionNamespace getVariable [
            UI_TAB_FIX_UNIT_LIST lbData (lbCurSel UI_TAB_FIX_UNIT_LIST),
            objNull
        ];
    };
    default {
        missionNamespace getVariable [
            UI_TAB_MARKERS_PLAYERS lbData (lbCurSel UI_TAB_MARKERS_PLAYERS),
            objNull
        ];
    };
};

TRACE_1("Selected unit: ",_selectedUnit);

if (isNull _selectedUnit) exitWith {WARNING_1("Bad unit [%1] disconnect?",_selectedUnit);};

[false] remoteExecCall [QEFUNC(markers,reinitMarkerHash), _selectedUnit];

["potato_adminMsg", [format ["Resetting markers on %1", [_selectedUnit] call ACEFUNC(common,getName)], profileName]] call CBA_fnc_globalEvent;

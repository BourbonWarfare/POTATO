#include "script_component.hpp"

TRACE_1("params",_this);

private _selectedUnit = missionNamespace getVariable [
    UI_TAB_FIX_UNIT_LIST lbData (lbCurSel UI_TAB_FIX_UNIT_LIST),
    objNull
];

TRACE_1("Selected unit: ",_selectedUnit);

if (isNull _selectedUnit) exitWith {WARNING_1("Bad unit [%1] disconnect?",_selectedUnit);};

["potato_adminMsg", [format ["Fixing speaker on %1 [%2]", [_selectedUnit] call ACEFUNC(common,getName), speaker _selectedUnit], profileName]] call CBA_fnc_globalEvent;
[QGVAR(fixSpeaker), [_selectedUnit], _selectedUnit] call CBA_fnc_targetEvent;

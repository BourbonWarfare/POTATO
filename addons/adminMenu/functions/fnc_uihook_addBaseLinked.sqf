#include "script_component.hpp"

TRACE_1("params",_this);

private _selectedUnit = missionNamespace getVariable [
    UI_TAB_FIX_UNIT_LIST lbData (lbCurSel UI_TAB_FIX_UNIT_LIST),
    objNull
];

TRACE_1("Selected unit: ",_selectedUnit);

if (isNull _selectedUnit) exitWith {WARNING_1("Bad unit [%1] disconnect?",_selectedUnit);};

_selectedUnit linkItem "ItemWatch";
_selectedUnit linkItem "ItemCompass";
_selectedUnit linkItem "ItemMap";

["potato_adminMsg", [format ["Adding base linked items to %1", [_selectedUnit] call ACEFUNC(common,getName)], profileName]] call CBA_fnc_globalEvent;

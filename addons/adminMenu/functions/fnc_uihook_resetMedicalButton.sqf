#include "script_component.hpp"

TRACE_1("params",_this);

private _selectedUnit = missionNamespace getVariable [
    UI_TAB_FIX_UNIT_LIST lbData (lbCurSel UI_TAB_FIX_UNIT_LIST),
    objNull
];

TRACE_1("Selected unit: ",_selectedUnit);

if (isNull _selectedUnit) exitWith {WARNING_1("Bad unit, disconnect?", _selectedUnit);};

if (!alive _selectedUnit) exitWith {hint "No zombies!";};

[QACEGVAR(medical_treatment,fullHealLocal), [_selectedUnit, _selectedUnit], _selectedUnit] call CBA_fnc_targetEvent;
["potato_adminMsg", [format ["Fully healed %1", (name _selectedUnit)], profileName]] call CBA_fnc_globalEvent;

#include "script_component.hpp"

TRACE_1("params",_this);
params [["_mode", false, [false, 0]]];

private _selectedUnit = missionNamespace getVariable [
    UI_TAB_FIX_UNIT_LIST lbData (lbCurSel UI_TAB_FIX_UNIT_LIST),
    objNull
];

TRACE_1("Selected unit: ",_selectedUnit);

if (isNull _selectedUnit) exitWith {WARNING_1("Bad unit [%1] disconnect?",_selectedUnit);};

if (!alive _selectedUnit) exitWith {hint "No zombies!";};
switch (_mode) do {
    case false: { // Full Heal
    {
        [QACEGVAR(medical_treatment,fullHealLocal), [_x, _x], _x] call CBA_fnc_targetEvent;
    } forEach units group _selectedUnit;
    ["potato_adminMsg", [format ["Fully healed %1's group (%2 %3)", name _selectedUnit, side group _selectedUnit, groupId group _selectedUnit], profileName]] call CBA_fnc_globalEvent;
    };
    case true: {
    [QACEGVAR(medical_treatment,fullHealLocal), [_selectedUnit, _selectedUnit], _selectedUnit] call CBA_fnc_targetEvent;
    ["potato_adminMsg", [format ["Fully healed %1", name _selectedUnit], profileName]] call CBA_fnc_globalEvent;
    };
    case 2: {
    [QGVAR(medical_stabilize), [_selectedUnit], _selectedUnit] call CBA_fnc_targetEvent;
    ["potato_adminMsg", [format ["Stabilized %1", name _selectedUnit], profileName]] call CBA_fnc_globalEvent;
    };
};

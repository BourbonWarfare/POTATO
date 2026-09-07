#include "script_component.hpp"

TRACE_1("params",_this);

private _selectedUnit = missionNamespace getVariable [
    UI_TAB_FIX_UNIT_LIST lbData (lbCurSel UI_TAB_FIX_UNIT_LIST),
    objNull
];

TRACE_1("Selected unit: ",_selectedUnit);

if (isNull _selectedUnit) exitWith {WARNING_1("Bad unit [%1] disconnect?",_selectedUnit);};
if !(isPlayer _selectedUnit) exitWith {WARNING_1("Cannot whitelist non-player [%1]",_selectedUnit);};
["potato_adminMsg", [format ["Whitelisting member '%1'", [_selectedUnit] call ACEFUNC(common,getName)], profileName]] call CBA_fnc_globalEvent;
[QEGVAR(recruits,whitelistMember), [getPlayerUID _selectedUnit]] call CBA_fnc_serverEvent;

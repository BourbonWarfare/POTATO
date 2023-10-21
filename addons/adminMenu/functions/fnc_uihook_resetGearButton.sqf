#include "script_component.hpp"

TRACE_1("uihook_resetGearButton",_this);

private _listGear = UI_TAB_FIX_UNIT_GEAR;
private _selectedLoadout = _listGear lbData (0 max lbCurSel _listGear);

private _selectedUnit = missionNamespace getVariable [
    UI_TAB_FIX_UNIT_LIST lbData (lbCurSel UI_TAB_FIX_UNIT_LIST),
    objNull
];

TRACE_2("",_selectedUnit,_selectedLoadout);

if (isNull _selectedUnit) exitWith { WARNING_1("Bad unit - disconnect?", _selectedUnit); };

if (_selectedLoadout == "") then {
    _selectedUnit setVariable ["F_Gear", nil, true];
} else {
    _selectedUnit setVariable ["F_Gear", _selectedLoadout, true];
};

[QGVAR(resetGear), [_selectedUnit], [_selectedUnit]] call CBA_fnc_targetEvent;

["potato_adminMsg", [format ["Resetting gear on %1", (name _selectedUnit)], profileName]] call CBA_fnc_globalEvent;

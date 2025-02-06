#include "script_component.hpp"

TRACE_1("uihook_resetGearButton",_this);

private _listGear = UI_TAB_FIX_UNIT_GEAR;
private _selectedLoadout = _listGear lbData (0 max lbCurSel _listGear);

private _selectedUnit = missionNamespace getVariable [
    UI_TAB_FIX_UNIT_LIST lbData (lbCurSel UI_TAB_FIX_UNIT_LIST),
    objNull
];

TRACE_2("",_selectedUnit,_selectedLoadout);

if (isNull _selectedUnit) exitWith { WARNING_1("Bad unit [%1] - disconnect?",_selectedUnit); };

if (_selectedLoadout == "") then {
    _selectedUnit setVariable ["F_Gear", nil, true];
} else {
    _selectedUnit setVariable ["F_Gear", _selectedLoadout, true];
};

if (_selectedLoadout == "sm") then {
    _selectedUnit setVariable [QACEGVAR(medical,medicClass), 1, true];
} else {
    _selectedUnit setVariable [QACEGVAR(medical,medicClass), 0, true];
};

if (_selectedLoadout in ["eng","vicc","vicl","vicd","pilot"]) then {
    _selectedUnit setVariable ["ACE_isEngineer", true, true];
} else {
    _selectedUnit setVariable ["ACE_isEngineer", false, true];
};

[QGVAR(resetGear), [_selectedUnit], [_selectedUnit]] call CBA_fnc_targetEvent;

["potato_adminMsg", [format ["Resetting gear on %1", (name _selectedUnit)], profileName]] call CBA_fnc_globalEvent;

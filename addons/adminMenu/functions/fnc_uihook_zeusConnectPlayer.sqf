#include "script_component.hpp"

TRACE_1("params",_this);

private _selectedUnit = missionNamespace getVariable [
    UI_TAB_ZEUS_PLAYERS lbData (lbCurSel UI_TAB_ZEUS_PLAYERS),
    objNull
];

TRACE_1("Selected unit: ",_selectedUnit);

if (isNull _selectedUnit) exitWith {WARNING_1("Bad unit,disconnect?",_selectedUnit);};

private _giveZeus = isNull getAssignedCuratorLogic _selectedUnit;

[_selectedUnit, _giveZeus] remoteExecCall [QFUNC(zeusConnectCurator), SERVER_CLIENT_ID];

private _debugMsg = if (_giveZeus) then {
    format ["Enabling ZEUS for %1", name _selectedUnit];
} else {
    format ["Disabling ZEUS for %1", name _selectedUnit];
};

["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;

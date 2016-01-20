#include "script_component.hpp"

// params [""];

_selectedIndex = lbCurSel UI_TAB_ZEUS_PLAYERS;
if ((_selectedIndex < 0) || (_selectedIndex >= (count GVAR(ui_zeusTargets)))) exitWith {TRACE_1("Bad Index",_selectedIndex);};

_selectedPlayer = GVAR(ui_zeusTargets) select _selectedIndex;
if (isNull _selectedPlayer) exitWith {TRACE_1("null",_selectedPlayer);};

_giveZeus = isNull getAssignedCuratorLogic _selectedPlayer;

[_selectedPlayer, _giveZeus] remoteExecCall [QFUNC(zeusConnectCurator), 2];

_debugMsg = if (_giveZeus) then {
    format ["%1 is enableing ZEUS for %2", (profileName), (name _selectedPlayer)];
} else {
    format ["%1 is disabling ZEUS for %2", (profileName), (name _selectedPlayer)];
};

["potato_adminMsg", [_debugMsg]] call ACEFUNC(common,globalEvent);
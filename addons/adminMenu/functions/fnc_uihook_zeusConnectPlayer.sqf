#include "script_component.hpp"

TRACE_1("params",_this);

private _selectedIndex = lbCurSel UI_TAB_ZEUS_PLAYERS;
if (_selectedIndex < 0 || {_selectedIndex >= count GVAR(ui_zeusTargets)}) exitWith {TRACE_1("Bad Index",_selectedIndex);};

private _selectedPlayer = GVAR(ui_zeusTargets) select _selectedIndex;
if (isNull _selectedPlayer) exitWith {TRACE_1("null",_selectedPlayer);};

private _giveZeus = isNull getAssignedCuratorLogic _selectedPlayer;

[_selectedPlayer, _giveZeus] remoteExecCall [QFUNC(zeusConnectCurator), 2];

private _debugMsg = if (_giveZeus) then {
    format ["Enableing ZEUS for %1", (name _selectedPlayer)];
} else {
    format ["Disabling ZEUS for %1", (name _selectedPlayer)];
};

["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;

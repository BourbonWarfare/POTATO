//potato_adminMenu_fnc_uiHook_openEndMission

#include "script_component.hpp"
TRACE_1("params",_this);

private _debugMsg = format ["Unlocking End Mission"];
["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;

GVAR(openEndMission) = true;

["", 2] call FUNC(uihook_tabChange); //refresh the tab

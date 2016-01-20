//potato_adminMenu_fnc_uiHook_openEndMission

#include "script_component.hpp"
TRACE_1("params",_this);

_debugMsg = format ["%1 is unlocking end mission", profileName];
["potato_adminMsg", [_debugMsg]] call ACEFUNC(common,globalEvent);

GVAR(openEndMission) = true;

["", 2] call FUNC(uihook_tabChange); //refresh the tab

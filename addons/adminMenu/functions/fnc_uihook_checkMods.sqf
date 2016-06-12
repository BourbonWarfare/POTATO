#include "script_component.hpp"

TRACE_1("params",_this);

private _debugMsg = format ["Verifying Mods", (profileName)];
["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;

[true] spawn FUNC(checkMods);

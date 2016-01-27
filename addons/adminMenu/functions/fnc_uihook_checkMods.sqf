#include "script_component.hpp"

TRACE_1("params",_this);

private _debugMsg = format ["Verifying Mods", (profileName)];
["potato_adminMsg", [_debugMsg, profileName]] call ACEFUNC(common,globalEvent);

[true] spawn FUNC(checkMods);

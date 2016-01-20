#include "script_component.hpp"

_debugMsg = format ["%1 is verifying mods", (profileName)];
["potato_adminMsg", [_debugMsg]] call ACEFUNC(common,globalEvent);
[true] spawn FUNC(checkMods);

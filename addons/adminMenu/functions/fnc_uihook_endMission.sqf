#include "script_component.hpp"

params ["_side"];
_debugMsg = format ["%1 ending mission for winning side %2", (profileName), _side];

["potato_adminMsg", [_debugMsg, true]] call ACEFUNC(common,globalEvent);

[_side] remoteExecCall [QFUNC(endMission), 0];

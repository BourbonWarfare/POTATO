#include "script_component.hpp"

params ["_side"];
TRACE_1("params",_side);

if (!GVAR(openEndMission)) exitWith {TRACE_1("locked", GVAR(openEndMission));};

_debugMsg = format ["Ending mission for winning side %1", _side];

["potato_adminMsg", [_debugMsg, profileName, true]] call ACEFUNC(common,globalEvent);

[_side] remoteExecCall [QFUNC(endMission), 0];

#include "script_component.hpp"

TRACE_1("params",_this);

[QGVAR(missionTestingAddAction),[""]] call CBA_fnc_globalEvent;

EGVAR(missionTesting,missionTestingActive) = true;

["potato_adminMsg", ["Adding Mission Testing Add action to all Testers"]] call CBA_fnc_globalEvent;

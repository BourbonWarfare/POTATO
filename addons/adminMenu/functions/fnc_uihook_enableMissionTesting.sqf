#include "script_component.hpp"

TRACE_1("params",_this);

[QGVAR(missionTestingAddaction),[]] call CBA_fnc_globalEvent;

["potato_adminMsg", ["Adding Mission Testing Add action to all Testers"]] call CBA_fnc_globalEvent;

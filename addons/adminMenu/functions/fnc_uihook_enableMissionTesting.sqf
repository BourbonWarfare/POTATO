#include "script_component.hpp"

TRACE_1("params",_this);

if (!hasInterface) exitWith {"Cannot be called from server"};

if (EGVAR(missionTesting,missionTestingActive)) then {
    ["potato_adminMsg", ["Mission Testing Menu already enabled."]] call CBA_fnc_globalEvent;
} else {
[QGVAR(missionTestingAddAction),[""]] call CBA_fnc_globalEventJIP;

["potato_adminMsg", ["Adding Mission Testing Add action to all Zues Players"]] call CBA_fnc_globalEvent;
};

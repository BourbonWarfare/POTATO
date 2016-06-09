//potato_safeStart_fnc_makeSafe

#include "script_component.hpp"

if (!isServer) exitWith {};

missionNamespace setVariable [QGVAR(startTime_PV), dayTime, true];
["potato_safeStartOn", []] call CBA_fnc_globalEvent;

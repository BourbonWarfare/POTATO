//potato_safeStart_fnc_makeSafe

#include "script_component.hpp"

if (!isServer) exitWith {};

missionNamespace setVariable [QGVAR(startTime_PV), dayTime, true];
["safeStartOn", []] call ace_common_fnc_globalEvent;

#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

GVAR(draw3DFunctions) = createHashMap;
GVAR(draw3DEH) = -1;
GVAR(fpsAvgCalcEH) = -1;
GVAR(fpsAvgCalc) = [0, [0, 0, 0, 0, 0]];
GVAR(playerFPSCache) = createHashMap;
GVAR(clientsTrackingFPS) = [];

#include "initSettings.inc.sqf"

ADDON = true;

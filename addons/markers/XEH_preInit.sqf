#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

GVAR(drawHash) = [[],[]];
GVAR(nextUpdate) = -9999;
GVAR(settingsInitialized) = false;
GVAR(settingsDelayedFunctions) = [];

ADDON = true;

#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(drawHash) = [[],[]];
GVAR(nextUpdate) = -9999;
GVAR(settingsInitialized) = false;
GVAR(settingsDelayedFunctions) = [];

ADDON = true;

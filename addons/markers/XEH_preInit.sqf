#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(settingsInitialized) = false;
GVAR(settingsDelayedFunctions) = [];

ADDON = true;

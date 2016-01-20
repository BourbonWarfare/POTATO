#include "script_component.hpp"

ADDON = false;

PREP(handleFired);
PREP(makeSafe);
PREP(showTimer);

//We Start game safe at preInit
GVAR(safeStartEnabled) = true;

ADDON = true;

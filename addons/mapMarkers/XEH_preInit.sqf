#include "script_component.hpp"

ADDON = false;

PREP(loadFromConfigFile);

GVAR(enabled) = false;
GVAR(updateInterval) = 5;
GVAR(factionVisibilitySettings) = [] call EFUNC(datastructures,map_create);
GVAR(groupMarkerSettings) = [] call EFUNC(datastructures,map_create);
GVAR(unitMarkerSettings) = [] call EFUNC(datastructures,map_create);

ADDON = true;

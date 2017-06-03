#include "script_component.hpp"

ADDON = false;

PREP(drawMap);
PREP(loadFromConfigFile);
PREP(updateMarkerDrawCache);
PREP(updateGroupMemberDrawCache);

// Settings Variables
GVAR(enabled) = false;
GVAR(updateInterval) = 5;
GVAR(drawOnlyDefinedGroups) = false;
GVAR(factionVisibilitySettings) = [] call EFUNC(datastructures,map_create);
GVAR(groupMarkerSettings) = [] call EFUNC(datastructures,map_create);
GVAR(unitMarkerSettings) = [] call EFUNC(datastructures,map_create);

// Operation Variables
GVAR(drawCache) = [];
GVAR(groupMemberDrawCache) = [];

ADDON = true;

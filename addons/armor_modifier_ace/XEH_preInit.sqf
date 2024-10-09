#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"
GVAR(armorValueHash) = createHashMap;
GVAR(classArmorHash) = createHashMap;
GVAR(defaultArmorHash) = DEFAULT_HASH_SETTINGS;
// CBA Settings
#include "initSettings.inc.sqf"

ADDON = true;

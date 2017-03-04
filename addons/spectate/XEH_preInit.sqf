#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

GVAR(enabled) = (QUOTE(ADDON) in getMissionConfigValue ["respawnTemplates", []]);
GVAR(running) = false;
GVAR(respawnOpen) = false;

diag_log format ["[POTATO-spectate] Enabled: %1", GVAR(enabled)];

ADDON = true;

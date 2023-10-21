#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

GVAR(enabled) = (QUOTE(ADDON) in getMissionConfigValue ["respawnTemplates", []]);
GVAR(running) = false;
GVAR(respawnOpen) = false;

INFO_1("Enabled: %1",GVAR(enabled));
if (GVAR(enabled)) then {
    // Set acex_killtracker to global sync
    ACEGVAR(killtracker,globalSync) = true;
};

ADDON = true;

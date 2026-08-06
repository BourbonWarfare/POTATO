#include "\z\potato\addons\seeding\script_component.hpp"

onLoadName = "BW Seeding V6";

// Disable (0) or enable (1) the automatic GRAD vehicle flag actions
allowGRADFromFlag = 1;
allowFunctionsRecompile = 1;

#ifndef BW_SEEDING_SIDE_OPFOR
#define BW_SEEDING_SIDE_OPFOR "POTATO Seeding OpFor"
#endif
#ifndef BW_SEEDING_SIDE_INDY
#define BW_SEEDING_SIDE_INDY "POTATO Seeding Indy"
#endif

#ifdef BW_SEEDING_POTATO_RESPAWN
usePotatoRespawnSystem = 1;
#else
usePotatoRespawnSystem = 0;
#endif

// Extended Event Handlers:
#include "\z\potato\addons\seeding\CfgEventHandlers.hpp"
// Fortify
#include "\z\potato\addons\seeding\CfgFortify.hpp"
// GRAD
#include "\z\potato\addons\seeding\CfgGrad.hpp"
// Notifications:
#include "\z\potato\addons\seeding\CfgNotifs.hpp"
// Respawns:
#include "\z\potato\addons\seeding\CfgRespawns.hpp"
// Sounds:
#include "\z\potato\addons\seeding\CfgSounds.hpp"
// Parameters
#include "\z\potato\addons\seeding\Params.hpp"

class CfgDebriefingSections {
    class acex_killTracker {
        title = "ACEX Killed Events";
        variable = "acex_killTracker_outputText";
    };
};

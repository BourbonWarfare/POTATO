#include "\z\potato\addons\seeding\script_component.hpp"

onLoadName = "BW Seeding V6";

// Disable (0) or enable (1) the automatic GRAD vehicle flag actions
allowGRADFromFlag = 1;
allowFunctionsRecompile = 1;


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

#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(zeus_missionHint), QGVAR(zeus_globalSetSkill), QGVAR(sideMarker), QGVAR(zeus_banziCharge), QGVAR(zeus_bodyBag), QGVAR(moveHcsToModule), QGVAR(identity_module), QGVAR(zeus_resupplyBoxes), QGVAR(zeus_printATCount), QGVAR(safeStartTeleport), QGVAR(objectTeleport), QGVAR(boxBrief_cfgLoadouts), QGVAR(boxBrief_sync)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgNotifications.hpp"
#include "CfgSounds.hpp"
#include "CfgVehicles.hpp"
#include "Displays.hpp"

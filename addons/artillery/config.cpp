#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(addArtilleryAmmo),QGVAR(registerArtillery),QGVAR(openMissionDialog)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_missionModules"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Lambda.Tiger"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "Cfg3DEN.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgMagazines.hpp"
#include "CfgNotifications.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgUI.hpp"

#include "script_component.hpp"

class CfgPatches {
    class COMPONENT {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "ace_missileguidance",
            "gm_weapons_launchers_milan"
        };
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        url = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
        addonRootClass = QUOTE(ADDON);
    };
};

#include "ACE_CSW_Groups.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

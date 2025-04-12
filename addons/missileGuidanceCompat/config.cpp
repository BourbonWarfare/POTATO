#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "ace_missileguidance"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Dani (TCVM)"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgMissileTypesWarsaw.hpp"
#include "CfgMissileTypesNato.hpp"
#include "ACE_GuidanceConfig.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
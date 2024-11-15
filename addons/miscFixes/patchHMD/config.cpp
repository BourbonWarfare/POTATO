#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchHMD

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "Kimi_Weapons_Helos" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class cfgWeapons {
    class Default;
    class CannonCore: Default {};
    class gatling_20mm: CannonCore {
        cursorAim = "mg";
        ballisticsComputer = "1 + 2 + 16";
        magazines[] = {"2000Rnd_20mm_shells","1000Rnd_20mm_shells","300Rnd_20mm_shells","PylonWeapon_300Rnd_20mm_shells","ACE_500Rnd_20mm_shells_Comanche"};
    };
};
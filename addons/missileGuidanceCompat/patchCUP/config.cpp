#include "\z\potato\addons\missileGuidanceCompat\script_component.hpp"
#undef COMPONENT
#define COMPONENT missileGuidanceCompat_patchCUP

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_missileGuidanceCompat", "CUP_Weapons_LoadOrder"};
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "..\CfgMissileTypesWarsaw.hpp"
#include "..\CfgMissileTypesNato.hpp"

class CfgMagazines {
    class CA_LauncherMagazine;
    class CUP_Dragon_EP1_M: CA_LauncherMagazine {
        ammo = "ace_dragon_super";
        initSpeed = 120;
    };
};

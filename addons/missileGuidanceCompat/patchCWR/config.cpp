#include "\z\potato\addons\missileGuidanceCompat\script_component.hpp"
#undef COMPONENT
#define COMPONENT missileGuidanceCompat_patchCWR

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_missileGuidanceCompat", "gm_weapons_launchers_fim43", "cwr3_weapon_config"};
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};


class CfgMagazines {
    class CA_LauncherMagazine;
    class cwr3_redeye_m: CA_LauncherMagazine {
        ammo = "gm_rocket_70mm_HE_m585";
    };
};

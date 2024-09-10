#include "\z\potato\addons\missileGuidanceCompat\script_component.hpp"
#undef COMPONENT
#define COMPONENT missileGuidanceCompat_patchMELB

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_missileGuidanceCompat", "MELB" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};


class CfgAmmo {
    class ACEGVAR(missileguidance,type_Hellfire);
    class Missile_AGM_02_F;
    class MELB_AGM_114K: Missile_AGM_02_F {
        irLock = 0;
        laserLock = 0;
        manualControl = 0;

        ACE_MISSILE(Hellfire);
    };
};

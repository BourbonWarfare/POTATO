#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchRHSAFRF

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core",
            "potato_miscFixes",
            "rhs_main_loadorder",
            "ace_compat_rhs_afrf3_missileguidance"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class RHS_Missile2 {
    class Missile2 {
        type = "Missile2_vanilla";
    };
    class Missile2Med {
        type = "Missile2Med_vanilla";
    };
};

class RHS_Missile3 {
    class Missile3 {
        type = "Missile3_vanilla";
    };
    class Missile3Med {
        type = "Missile3Med_vanilla";
    };
};

#include "CfgAmmo.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

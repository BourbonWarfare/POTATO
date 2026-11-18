#include "\z\potato\addons\missileGuidanceCompat\script_component.hpp"
#undef COMPONENT
#define COMPONENT missileGuidanceCompat_patchEMB312

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_missileGuidanceCompat", "FA_EMB312"};
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "\z\potato\addons\missileGuidanceCompat\CfgMissileTypesNato.hpp"

class CfgVehicles {
    class Plane_Base_F;
    class FA_EMB312_BASE: Plane_Base_F {
        ACEGVAR(missileguidance,useTurretDirectionForTargeting) = 1;
    };
    class FA_EMB312_AT27M35_AAF: FA_EMB312_BASE {
        class pilotCamera;
    };
    class FA_EMB312_AT27M35S_LDF: FA_EMB312_AT27M35_AAF {
        ACEGVAR(missileguidance,useTurretDirectionForTargeting) = 0;
        class pilotCamera: pilotCamera {
            ACEGVAR(missileguidance,usePilotCameraForTargeting) = 1;
        };
    };
};

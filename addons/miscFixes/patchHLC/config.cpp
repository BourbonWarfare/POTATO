#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchHLC

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "hlcweapons_G36" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    // add zeroing to iron sighted G36es
    class hlc_G36_base;
    class hlc_rifle_G36V : hlc_G36_base {
        discreteDistance[] = {100, 200, 300, 400, 500};
        discreteDistanceInitIndex = 1;
    };
};

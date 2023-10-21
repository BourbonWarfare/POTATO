#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchMAA

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "MAAMod" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgMagazines {
    class MRAWS_HE_F;
    class MAA_MAAWS_ADM401: MRAWS_HE_F { // spawns a thousand bullets
        displayName = "MAAWS ADM 401 Round [Don't Use This]";
    };
};

#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchEMCUP

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "za_enhancedmaawsCUP" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    class Launcher_Base_F;
    class CUP_launch_MAAWS: Launcher_Base_F {
        ACEGVAR(overpressure,angle) = 45; // they overrride ace because they hate us
    };
};

class CfgMagazines {
    class CA_LauncherMagazine;
    class MRAWS_HEAT_F: CA_LauncherMagazine {\
        ACEGVAR(arsenal,hide) = 0;
        scope = 2;
    };
};

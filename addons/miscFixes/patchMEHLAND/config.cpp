#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchMEHLAND

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "mehland", "rnc_main", "rnc_misc" }; // mehland and Really Useless Objects Pack
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

// fix broken XEH
class CfgVehicles {
    class thing;
    class Rnc_Particle_BigFire_F: thing { XEH_ENABLED; }; // "" 2954960408
};

// try to fix main menu being violated
class RscMainMenuSpotlight;
class RscStandardDisplay;
class RscDisplayMain: RscStandardDisplay {
    enableDisplay = 1;
    class controls {
        class Spotlight3: RscMainMenuSpotlight {
            idc=1022;
            x="0.5 + (0.5 * 	10) * 	(pixelW * pixelGridNoUIScale * 2) + 	(2 * pixelW)";
        };
    };
};

#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchNDS

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "NDS_M224_mortar" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

// fix broken XEH
class CBA_Extended_EventHandlers;
class CfgVehicles {
    class Mortar_01_base_F;
    class NDS_M224_mortar_base: Mortar_01_base_F { XEH_ENABLED; }; // "M224 Mortar base" 2472780935
    class NDS_M224_mortar;
    class NDS_M224_mortar_AI: NDS_M224_mortar { XEH_ENABLED; }; // "M224 60mm Mortar - AI" 2472780935
};

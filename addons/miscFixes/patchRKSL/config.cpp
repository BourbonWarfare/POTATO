#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchRKSL

class CfgPatches {
    class ADDON {
        weapons[] = {};
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "rksla3_foxhound_lppv" };
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
class CfgVehicles {
    class Car_F;
    class rksla3_foxhound_lppv_base: Car_F { XEH_ENABLED; }; // "Foxhound LPPV" 1243862899
};

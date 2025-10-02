#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchCelle

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "mbg_celle2", "mbg_celle2_objects" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class House;
    class Land_MBG_GER_HUS_1: House {
        armor = 800;
    };
    class Land_MBG_GER_RHUS_1: House {
        armor = 600;
    };
    class Land_MBG_GER_ESTATE_1: House {
        armor = 750;
    };
    class Land_mbg_hangar_1: House {
        armor = 800;
    };
    class Land_mbg_companybuilding_1: House {
        armor = 1000;
    };
    class LAND_MBG_Fachwerk_A: House {
        armor = 1000;
    };
};

// Fix CELLE font error: (reqAddon: "mbg_celle2")
class CfgLocationTypes {
    class MBG_celle2_icon_A7 {
        font = "PuristaMedium";
    };
};

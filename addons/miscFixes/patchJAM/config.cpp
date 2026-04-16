#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchJAM

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "JAM_Supplies_AE_Bags", "JAM_Weapons_AE_Launchers_DZJ08" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class Land_JAM_AE_Prop_RallyPoint_PLA_t99;
    class JAM_AE_B_RallyPoint_t99: Land_JAM_AE_Prop_RallyPoint_PLA_t99 { XEH_ENABLED; }; // "Rally Point [PLA] (Woodland)" 3460736810
    class Land_JAM_AE_Prop_RallyPoint_PLA_t07;
    class JAM_AE_B_RallyPoint_t07: Land_JAM_AE_Prop_RallyPoint_PLA_t07 { XEH_ENABLED; }; // "Rally Point [PLA]" 3460736810
    class Land_JAM_AE_Prop_RallyPoint_PLA_t07_des;
    class JAM_AE_B_RallyPoint_t07_des: Land_JAM_AE_Prop_RallyPoint_PLA_t07_des { XEH_ENABLED; }; // "Rally Point [PLA] (Desert)" 3460736810
    class Land_JAM_AE_Prop_RallyPoint_ROCA;
    class JAM_AE_B_RallyPoint_ROCA: Land_JAM_AE_Prop_RallyPoint_ROCA { XEH_ENABLED; }; // "Rally Point [ROCA]" 3460736810
};

class CfgWeapons {
    class Launcher_Base_f;
    class JAM_AE_Launch_DZAII_grn_F: Launcher_Base_f {
        // not right, but gets rid of the error
        picture = "\A3\Weapons_F\launchers\RPG32\data\UI\gear_RPG32_X_CA.paa";
    };
};

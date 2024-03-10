#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchPTV

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "ptv_vehicles", "ptv_characters_cfg" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};



class CBA_Extended_EventHandlers;
class CfgVehicles {
    // Fix XEH: "[CBA] (xeh) WARNING: ptv_Pnd_Base_F does not support Extended Event Handlers! Addon: 3092130870"
    class B_APC_Wheeled_03_cannon_F;
    class ptv_Pnd_Base_F: B_APC_Wheeled_03_cannon_F {
        class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; };
    };
    class I_APC_tracked_03_cannon_F;
    class ptv_Warrior_Base_F: I_APC_tracked_03_cannon_F {
        class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; };
    };


    // Increase storage capacity of Contact DLC Radio Backpack to hold ACRE radios and radio accessories.
    class B_RadioBag_01_base_F;
    class ptv_RadioBag_01_Desert: B_RadioBag_01_base_F {maximumLoad=300;}; // from Project True Viking
    class ptv_RadioBag_01_Woodland: B_RadioBag_01_base_F {maximumLoad=300;};
};

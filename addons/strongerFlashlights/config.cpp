#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        weapons[] = {
//Base
            QGVAR(Vanilla_HG_LED_flashlight_Flood),
            QGVAR(Vanilla_HG_LED_flashlight_Beam),
            QGVAR(Vanilla_HG_LED_flashlight),
//CUP flashlight
            QGVAR(CUP_LED_flashlight_Flood),
            QGVAR(CUP_LED_flashlight_Beam),
            QGVAR(CUP_LED_flashlight),
            GENERIC_CUP_ADAPTED_FLASHLIGHT_LMD(02),
            GENERIC_CUP_ADAPTED_FLASHLIGHT_LMD(03),
            GENERIC_CUP_ADAPTED_FLASHLIGHT_LMD(04),
            GENERIC_CUP_ADAPTED_FLASHLIGHT_LMD(05),
            GENERIC_CUP_ADAPTED_FLASHLIGHT_LMD(06)
        };
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"CUP_Weapons_East_Attachments", "CUP_Weapons_West_Attachments", "ace_laserpointer"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Carl", "Chesheire", "Lambda.Tiger"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"

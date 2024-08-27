#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchW28

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "tweed_uaf_21_cfg" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    class VestItem;
    class Vest_Camo_Base;
    // Normalizes W28 vest armor values to be in line with vanilla/CUP armor values
    class V_tweed_iotv_mk4_base: Vest_Camo_Base {
        class ItemInfo: VestItem {
            class HitpointsProtectionInfo {
                class Chest {
                    hitpointName = "HitChest";
                    armor = 16; // was 30
                    passThrough = 0.3; // was 0.2
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 16; // was 30
                    passThrough = 0.3; // was 0.2
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16; // was 30
                    passThrough = 0.3; // was 0.2
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3; // was 0.2
                };
            };
        };
    };
};
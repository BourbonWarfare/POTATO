#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchWBK

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "WBK_Zombies" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgFaces {
    class Default {
        class Default {};
        class Custom {};
    };
    class Man_A3: Default {
        class Default {};
        class WBK_DecapatedHead_Zombies_Normal: Default {
            disabled = 1;
        };
        class WBK_DosHead_Normal_1: Default {
            disabled = 1;
        };
        class WBK_DosHead_Normal_2: Default {
            disabled = 1;
        };
        class WBK_DosHead_Normal_3: Default {
            disabled = 1;
        };
        class WBK_DosHead_FrontHole: Default {
            disabled = 1;
        };
        class WBK_DosHead_BackHole: Default {
            disabled = 1;
        };
        class WBK_DosHead_Corrupted: Default {
            disabled = 1;
        };
        class WBK_ZombieFace_blood_1: Default {
            disabled = 1;
        };
        class WBK_ZombieFace_blood_2: Default {
            disabled = 1;
        };
        class WBK_ZombieFace_blood_3: Default {
            disabled = 1;
        };
        class WBK_ZombieFace_blood_4: Default {
            disabled = 1;
        };
        class WBK_ZombieFace_1: Default {
            disabled = 1;
        };
        class WBK_ZombieFace_2: Default {
            disabled = 1;
        };
        class WBK_ZombieFace_3: Default {
            disabled = 1;
        };
        class WBK_ZombieFace_4: Default {
            disabled = 1;
        };
        class WBK_ZombieFace_5: Default {
            disabled = 1;
        };
        class WBK_ZombieFace_6: Default {
            disabled = 1;
        };
    };
};
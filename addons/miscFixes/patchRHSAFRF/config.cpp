#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchRHSAFRF

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "rhs_main_loadorder" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    class ItemCore;
    class Vest_Camo_Base: ItemCore {
        class ItemInfo;
    };
    class rhs_vydra_3m: Vest_Camo_Base {
        class ItemInfo: ItemInfo {};
    };
    class rhs_vydra_3m_bwArmorMod: rhs_vydra_3m {
        displayName = "Vydra-3M [coop plot armor]";
        descriptionShort = "Armor Level IV";
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };
    class rhs_6b23: Vest_Camo_Base {
        descriptionShort = "GOST Armor Level 4"; // was "Armor Level 4"
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Neck {
                    HitpointName = "HitNeck";
                    armor = 8;
                    PassThrough = 0.4;
                };
                class Chest {
                    HitpointName = "HitChest";
                    armor = 16; // was 22
                    PassThrough = 0.3;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 16; // was 22
                    PassThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16; // was 22
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class rhs_6b23_6sh92: rhs_6b23 {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Neck {
                    HitpointName = "HitNeck";
                    armor = 10; // was 12
                    PassThrough = 0.3;
                };
                class Chest {
                    HitpointName = "HitChest";
                    armor = 16; // was 22
                    PassThrough = 0.3;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 16; // was 22+3
                    PassThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16; // was 22+3
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class rhs_6b23_6sh92_radio: rhs_6b23_6sh92 {};
    class rhs_6b23_digi_6sh92_Spetsnaz: rhs_6b23_6sh92_radio {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Neck {
                    HitpointName = "HitNeck";
                    armor = 8;
                    PassThrough = 0.4;
                };
                class Chest {
                    HitpointName = "HitChest";
                    armor = 16; // was 22
                    PassThrough = 0.3;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 16; // was 22+3
                    PassThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16; // was 22+3
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class rhs_6b23_vydra_3m: rhs_6b23_6sh92 {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Neck {
                    HitpointName = "HitNeck";
                    armor = 8;
                    PassThrough = 0.4;
                };
                class Chest {
                    HitpointName = "HitChest";
                    armor = 16; // was 22
                    PassThrough = 0.3;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 16; // was 22+3
                    PassThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16; // was 22+3
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class rhs_6b23_digi: rhs_6b23 {};
    class rhs_6b23_6sh116: rhs_6b23_digi {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Neck {
                    HitpointName = "HitNeck";
                    armor = 10; // was 12
                    PassThrough = 0.3;
                };
                class Chest {
                    HitpointName = "HitChest";
                    armor = 16; // was 22
                    PassThrough = 0.3;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 16; // was 22+3
                    PassThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16; // was 22+3
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class rhs_6b13: rhs_6b23 {
        descriptionShort = "GOST Armor Level 6"; // was"Armor Level 6"
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Neck {
                    HitpointName = "HitNeck";
                    armor = 12; // was 16
                    PassThrough = 0.3;
                };
                class Chest {
                    HitpointName = "HitChest";
                    armor = 18; // was 28
                    PassThrough = 0.3; // was 0.1
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 18; // was 28
                    PassThrough = 0.3; // was 0.1
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 18; // was 22
                    passThrough = 0.3; 
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class rhs_6b13_6sh92: rhs_6b13 {
        descriptionShort = "GOST Armor Level 6"; // was "Armor Level 6"
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Neck {
                    HitpointName = "HitNeck";
                    armor = 12; // was 16
                    PassThrough = 0.3;
                };
                class Chest {
                    HitpointName = "HitChest";
                    armor = 18; // was 28+3
                    PassThrough = 0.3; // was 0.1
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 18; // was 28+3
                    PassThrough = 0.3; // was 0.1
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 18; // was 22
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class rhs_6b2: Vest_Camo_Base {
        descriptionShort = "GOST Armor Level 1"; // was "Armor Level 1"
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 8; // was 12 
                    PassThrough = 0.4;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 8; // was 12
                    PassThrough = 0.4;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 8; // was 12
                    passThrough = 0.4;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.4;
                };
            };
        };
    };
    class rhs_6b3: rhs_6b2 {
        descriptionShort = "GOST Armor Level 3"; // was "Armor Level 3"
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 12; // was 22
                    PassThrough = 0.3;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 12; // was 22
                    PassThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 12; // was 22
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };
    class rhs_6b5: rhs_6b23 {
        descriptionShort = "GOST Armor Level 5"; // was "Armor Level 5"
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Neck {
                    HitpointName = "HitNeck";
                    armor = 8;
                    PassThrough = 0.5;
                };
                class Chest {
                    HitpointName = "HitChest";
                    armor = 16; // was 25
                    PassThrough = 0.3; // was 0.2
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 16; // was 25
                    PassThrough = 0.3; // was 0.2
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 16; // was 25
                    passThrough = 0.3; // was 0.2
                };
                class Body {
                    hitpointName = "HitBody";
                    armor = 8;
                    passThrough = 0.5;
                };
            };
        };
    };
};

class CfgVehicles {
    class B_AssaultPack_Base;
    class rhs_medic_bag: B_AssaultPack_Base {};
    class rhs_medic_bag_XL: rhs_medic_bag {
        author = "RHS & AChesheireCat";
        displayName = "Medic Bag (Large)";
        maximumLoad = 240; 
    };
};
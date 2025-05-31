class CfgWeapons {
    class gm_vest_base;
    class gm_vest_armored_base: gm_vest_base {
        class ItemInfo;
    };
    class gm_gc_vest_bespa_utv_90_base: gm_vest_armored_base {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Abdomen {
                    armor = 16;
                    hitpointName = "HitAbdomen";
                    passThrough = 0.85;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.85;
                };
                class Chest {
                    armor = 16;
                    HitpointName = "HitChest";
                    passThrough = 0.85;
                };
                class Diaphragm {
                    armor = 16;
                    HitpointName = "HitDiaphragm";
                    passThrough = 0.85;
                };
            };
        };
    };
    class gm_gc_vest_bespa_80_base: gm_vest_armored_base {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Abdomen {
                    armor = 16;
                    hitpointName = "HitAbdomen";
                    passThrough = 0.85;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.85;
                };
                class Chest {
                    armor = 16;
                    HitpointName = "HitChest";
                    passThrough = 0.85;
                };
                class Diaphragm {
                    armor = 16;
                    HitpointName = "HitDiaphragm";
                    passThrough = 0.85;
                };
            };
        };
    };
    class gm_dk_vest_m00_base: gm_vest_armored_base {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Abdomen {
                    armor = 16;
                    explosionShielding = 0.1;
                    hitpointName = "HitAbdomen";
                    passThrough = 0.9;
                };
                class Body {
                    explosionShielding = 0.1;
                    hitpointName = "HitBody";
                    passThrough = 0.9;
                };
                class Chest {
                    armor = 16;
                    explosionShielding = 0.1;
                    HitpointName = "HitChest";
                    passThrough = 0.9;
                };
                class Diaphragm {
                    armor = 16;
                    explosionShielding = 0.1;
                    HitpointName = "HitDiaphragm";
                    passThrough = 0.9;
                };
            };
        };
    };
    class gm_ge_vest_armor_90_base: gm_vest_armored_base {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Abdomen {
                    armor = 16;
                    explosionShielding = 0.1;
                    hitpointName = "HitAbdomen";
                    passThrough = 0.9;
                };
                class Body {
                    explosionShielding = 0.1;
                    hitpointName = "HitBody";
                    passThrough = 0.9;
                };
                class Chest {
                    armor = 16;
                    explosionShielding = 0.1;
                    HitpointName = "HitChest";
                    passThrough = 0.9;
                };
                class Diaphragm {
                    armor = 16;
                    explosionShielding = 0.1;
                    HitpointName = "HitDiaphragm";
                    passThrough = 0.9;
                };
                class Neck {
                    armor = 8;
                    explosionShielding = 0.1;
                    hitpointName = "HitNeck";
                    passThrough = 0.9;
                };
            };
        };
    };
    class gm_ge_vest_armor_90_flk: gm_ge_vest_armor_90_base {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo: HitpointsProtectionInfo {
                class Abdomen {
                    armor = 16;
                    explosionShielding = 0.1;
                    hitpointName = "HitAbdomen";
                    passThrough = 0.9;
                };
                class Body {
                    explosionShielding = 0.1;
                    hitpointName = "HitBody";
                    passThrough = 0.9;
                };
                class Chest {
                    armor = 16;
                    explosionShielding = 0.1;
                    HitpointName = "HitChest";
                    passThrough = 0.9;
                };
                class Diaphragm {
                    armor = 16;
                    explosionShielding = 0.1;
                    HitpointName = "HitDiaphragm";
                    passThrough = 0.9;
                };
                class Neck {
                    armor = 8;
                    explosionShielding = 0.1;
                    hitpointName = "HitNeck";
                    passThrough = 0.9;
                };
            };
        };
    };
    class gm_pl_vest_armor_01_akm_80_base: gm_vest_armored_base {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Abdomen {
                    armor = 16;
                    hitpointName = "HitAbdomen";
                    passThrough = 0.85;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.85;
                };
                class Chest {
                    armor = 16;
                    HitpointName = "HitChest";
                    passThrough = 0.85;
                };
                class Diaphragm {
                    armor = 16;
                    HitpointName = "HitDiaphragm";
                    passThrough = 0.85;
                };
            };
        };
    };
    class gm_ge_vest_type18_base: gm_vest_armored_base {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Abdomen {
                    armor = 24;
                    hitpointName = "HitAbdomen";
                    passThrough = 0.3;
                };
                class Body {
                    armor = 4;
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
                class Chest {
                    armor = 24;
                    HitpointName = "HitChest";
                    passThrough = 0.3;
                };
                class Diaphragm {
                    armor = 24;
                    HitpointName = "HitDiaphragm";
                    passThrough = 0.3;
                };
            };
        };
    };
    class gm_ge_vest_type3_base: gm_vest_armored_base {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Abdomen {
                    armor = 16;
                    hitpointName = "HitAbdomen";
                    passThrough = 0.6;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.6;
                };
                class Chest {
                    armor = 16;
                    HitpointName = "HitChest";
                    passThrough = 0.6;
                };
                class Diaphragm {
                    armor = 16;
                    HitpointName = "HitDiaphragm";
                    passThrough = 0.6;
                };
            };
        };
    };

    // Unarmored Armored Armor
    class gm_vest_unarmored_base: gm_vest_base {
        class ItemInfo;
    };
    class gm_ge_vest_sov_armor_80_base: gm_vest_unarmored_base {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Abdomen {
                    armor = 16;
                    hitpointName = "HitAbdomen";
                    passThrough = 0.6;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.6;
                };
                class Chest {
                    armor = 16;
                    HitpointName = "HitChest";
                    passThrough = 0.6;
                };
                class Diaphragm {
                    armor = 16;
                    HitpointName = "HitDiaphragm";
                    passThrough = 0.6;
                };
            };
        };
    };
};

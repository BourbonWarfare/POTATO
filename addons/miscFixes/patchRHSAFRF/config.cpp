#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchHLC

#ifdef POTATO_LEAN_RHS_CUP_HLC
#define PATCH_SKIP POTATO_LEAN_RHS_CUP_HLC
#endif
#if __has_include("\rhsafrf\addons\rhs_main\config.bin")
#else
#define PATCH_SKIP "RHS AFRF"
#endif

#ifdef PATCH_SKIP
POTATO_PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "rhs_main_loadorder" };
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgWeapons {
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
};

#endif

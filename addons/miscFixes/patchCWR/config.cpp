#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchCWR

#if __has_include("\cwr3\general\cwr3_intro\config.bin")
#else
#define PATCH_SKIP "CWR3"
#endif

#ifdef PATCH_SKIP
POTATO_PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "cwr3_intro", "cwr3_vehicle_m41", "cwr3_soldiers_us" };
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMain {
        cwr3_intro = ""; // CWR gets rid of the editor/multiplayer/campaign buttons for some reason
    };
};

class CfgVehicles {
    class Tank_F;
    class cwr3_m41_base: Tank_F {
        ACEGVAR(vehicle_damage,hullDetonationProb) = 0.5;
        ACEGVAR(vehicle_damage,turretDetonationProb) = 0.5;
        ACEGVAR(vehicle_damage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,hullFireProb) = 0.2;
        ACEGVAR(vehicle_damage,turretFireProb) = 0.2;
        ACEGVAR(vehicle_damage,engineFireProb) = 0.5;
        ACEGVAR(vehicle_damage,detonationDuringFireProb) = 0.5;
        ACEGVAR(vehicle_damage,canHaveFireRing) = 1;  
    };
};

class CfgGroups {
	class West {
        class CWR3_USA {
            class Infantry80 {
                class cwr3_b_rifle_squad80 {
                    class Unit4 { vehicle = "cwr3_b_soldier80_ar_m16"; };
                };
                class cwr3_b_fire_team80 {
                    class Unit1 { vehicle = "cwr3_b_soldier80_ar_m16"; };
                };
                class cwr3_b_support_team80 {
                    class Unit1 { vehicle = "cwr3_b_soldier80_ar_m16"; };
                };
            };
        };
    };
};

#endif

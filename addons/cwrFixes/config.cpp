#include "script_component.hpp"

#ifndef POTATO_LEAN_RHS_CUP_HLC

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "cwr3_intro", "cwr3_vehicle_m41", "cwr3_soldiers_us"};
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"

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

#include "script_component.hpp"

#ifndef POTATO_LEAN_RHS_CUP_HLC

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core", "jsrs_soundmod_cup_weapons", "jsrs_soundmod_cup_vehicles", "jsrs_soundmod_rhs_afrf_weapons"
        };
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgWeapons.hpp"

#endif

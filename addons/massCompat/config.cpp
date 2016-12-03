#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core", "potato_miscFixes",
            "BWA3_AssaultRifles", "BWA3_MachineGuns",
            "rhs_c_weapons", "rhsgref_c_weapons", "rhsusf_c_weapons",
            "CUP_Weapons_ACE_compat",
            "CUP_Weapons_M16", "CUP_Weapons_AK", "CUP_Weapons_PK",
            "CUP_Weapons_M249", "CUP_Weapons_M240", "CUP_Weapons_M60E4",
            "CUP_Weapons_L85", "CUP_Weapons_L110", "CUP_Weapons_UK59",
            "CUP_Weapons_SCAR", "CUP_Weapons_XM8", "CUP_Weapons_G36",
            "CUP_Weapons_MP5", "CUP_Weapons_L129", "CUP_Weapons_M14",
            "CUP_Weapons_M14_DMR", "CUP_Weapons_Mk48", "CUP_Weapons_AWM",
            "CUP_Weapons_M107", "CUP_Weapons_M24", "CUP_Weapons_SVD",
            "hlcweapons_mp5", "hlcweapons_core",
            "UK3CB_BAF_Weapons_SmallArms"
        };
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"

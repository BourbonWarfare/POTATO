#include "script_component.hpp"

#ifndef POTATO_LEAN_CONFIGS

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "A3_Weapons_F", "A3_Weapons_F_Exp", "A3_Weapons_F_Mark", "hlcweapons_core", "hlcweapons_g3", "hlcweapons_mp5", "hlcweapons_stgw57", "rhs_c_weapons", "rhsgref_c_weapons", "rhsusf_c_weapons", "CUP_Weapons_AA12", "CUP_Weapons_AK", "CUP_Weapons_AS50", "CUP_Weapons_AWM", "CUP_Weapons_Bizon", "CUP_Weapons_Colt1911", "CUP_Weapons_Compact", "CUP_Weapons_CZ750", "CUP_Weapons_CZ805", "CUP_Weapons_Duty", "CUP_Weapons_Evo", "CUP_Weapons_FNFAL", "CUP_Weapons_G36", "CUP_Weapons_GrenadeLaunchers", "CUP_Weapons_Grenades", "CUP_Weapons_Huntingrifle", "CUP_Weapons_Igla", "CUP_Weapons_Items", "CUP_Weapons_Javelin", "CUP_Weapons_KSVK", "CUP_Weapons_L85", "CUP_Weapons_L110", "CUP_Weapons_L129", "CUP_Weapons_LeeEnfield", "CUP_Weapons_M9", "CUP_Weapons_M14", "CUP_Weapons_M14_DMR", "CUP_Weapons_M16", "CUP_Weapons_M24", "CUP_Weapons_M47", "CUP_Weapons_M60E4", "CUP_Weapons_M72A6", "CUP_Weapons_M107", "CUP_Weapons_M110", "CUP_Weapons_M136", "CUP_Weapons_M240", "CUP_Weapons_M249", "CUP_Weapons_M1014", "CUP_Weapons_MAAWS", "CUP_Weapons_Makarov", "CUP_Weapons_Metis_AT_13", "CUP_Weapons_MicroUZI", "CUP_Weapons_Mk48", "CUP_Weapons_MP5", "CUP_Weapons_NLAW", "CUP_Weapons_PB_6P9", "CUP_Weapons_Phantom", "CUP_Weapons_PK", "CUP_Weapons_Revolver", "CUP_Weapons_RPG7", "CUP_Weapons_RPG18", "CUP_Weapons_SA58", "CUP_Weapons_SA61", "CUP_Weapons_Saiga12K", "CUP_Weapons_SCAR", "CUP_Weapons_Shield", "CUP_Weapons_SMAW", "CUP_Weapons_Stinger", "CUP_Weapons_Strela_2", "CUP_Weapons_SVD", "CUP_Weapons_UK59", "CUP_Weapons_VSS", "CUP_Weapons_XM8"};
        author = "Potato";
        authors[] = {"Brandon (TCVM)"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgWeapons.hpp"

#endif


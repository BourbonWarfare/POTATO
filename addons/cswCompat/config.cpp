#include "script_component.hpp"

#ifndef POTATO_LEAN_RHS_CUP_HLC

class CfgPatches {
    class ADDON {
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_csw", "CUP_Weapons_StaticWeapons", "CUP_Creatures_StaticWeapons"};
        author = "Potato";
        authors[] = {"Brandon"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineGroups.hpp"

#endif

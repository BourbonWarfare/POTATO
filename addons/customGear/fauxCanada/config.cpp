#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_fauxCanada

class CfgPatches {
    class ADDON {
        weapons[] = {QGVARMAIN(c5_carry)};
        units[] = {
            QGVARMAIN(ca_army_c5_low),
            QGVARMAIN(ca_army_c5_high),
            QGVARMAIN(ca_army_iltis),
            QGVARMAIN(ca_army_Leopard_c1),
            QGVARMAIN(ca_army_m113a1_apc)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core",
            "CUP_Weapons_LoadOrder",
            "CUP_Vehicles_LoadOrder",
            "gm_vehicles_land_tracked_leopard1_ge_army_leopard1",
            "gm_vehicles_land_wheeled_iltis_ge_army_iltis",
            "gm_vehicles_land_tracked_m113_dk_army_m113",
            "static_f_vietnam_c",
            "weapons_v_f_vietnam_c"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authors[] = {"Lambda.Tiger"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgFunctions.hpp"
#include "CfgInsignia.hpp"
#include "CfgMagazineGroups.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineWells.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

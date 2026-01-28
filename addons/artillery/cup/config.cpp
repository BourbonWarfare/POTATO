#include "\z\potato\addons\artillery\script_component.hpp"
#undef COMPONENT
#define COMPONENT artillery_cup


class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"CUP_Weapons_VehicleWeapons"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Lambda.Tiger"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineWells.hpp"
#include "CfgWeapons.hpp"

#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_launchers
#define WEAPONS_PATCHES(var1) QWEAPON(TRIPLES(launch,var1,Loaded)),\
QWEAPON(DOUBLES(launch,var1)),\
QWEAPON(TRIPLES(launch,var1,Used))

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {
            WEAPONS_PATCHES(M136A1_CS),
            WEAPONS_PATCHES(AT4CS_LMAW),
            WEAPONS_PATCHES(AT4CS_HP),
            WEAPONS_PATCHES(M72A7),
            WEAPONS_PATCHES(M72A8),
            WEAPONS_PATCHES(M72A9),
            WEAPONS_PATCHES(M72A10)
        };
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "CUP_Weapons_LoadOrder"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"AChesheireCat", "Lambda.Tiger"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgDisposableLaunchers.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgMagazineWells.hpp"

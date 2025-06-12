#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_launchers

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {
            QWEAPON(launch_M136A1_CS_Loaded),
            QWEAPON(launch_M136A1_CS),
            QWEAPON(launch_M136A1_CS_Used),
            QWEAPON(launch_M72A9_Loaded),
            QWEAPON(launch_M72A9),
            QWEAPON(launch_M72A9_Used)
        };
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "CUP_Weapons_LoadOrder"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"AChesheireCat"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};


#include "CfgAmmo.hpp"
#include "CfgDisposableLaunchers.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"

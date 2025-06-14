#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_launchers

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {
            "potato_launch_M136A1_CS_Loaded",
            "potato_launch_M136A1_CS",
            "potato_launch_M136A1_CS_Used",
            "potato_launch_M72A9_Loaded",
            "potato_launch_M72A9",
            "potato_launch_M72A9_Used"
        };
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "CUP_Weapons_LoadOrder", "jsrs_soundmod_complete_edition", "jsrs_soundmod_complete_edition_soundFiles" };
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"AChesheireCat"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CBA_DisposableLaunchers {
    potato_launch_M136A1_CS_Loaded[] = {"potato_launch_M136A1_CS","potato_launch_M136A1_CS_Used"};
    potato_launch_M72A9_Loaded[] = {"potato_launch_M72A9","potato_launch_M72A9_Used"};
};

#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        weapons[] = {
            QGVAR(c7),
            QGVAR(c7GL),
            QGVAR(c7a2),
            QGVAR(c7a2GL)
        };
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "CUP_Weapons_LoadOrder", "jsrs_soundmod_cup_weapons"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Chesheire"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"

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
        requiredVersion = REQUIRED_VERSION
        requiredAddons[] = {"CUP_Weapons_M16","CUP_Weapons_WeaponsCore","CUP_Weapons_Ammunition","CUP_Weapons_West_Attachments","CUP_Weapons_WeaponsData","CUP_Weapons_Sounds"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Chesheire"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
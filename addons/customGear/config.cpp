#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = { "potato_fauxMG5_MG5" };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core" };
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"

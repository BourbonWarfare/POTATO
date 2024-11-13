#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = { "potato_fauxC7_c7", "potato_fauxC7_c7GL", "potato_fauxC7_c7a2", "potato_fauxC7_c7a2GL", "potato_fauxMG5_MG5" };
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core" };
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
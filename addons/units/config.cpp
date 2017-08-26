#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {
            #include "subStrings\usmc.hpp"
            #include "subStrings\msv.hpp"
            #include "subStrings\air.hpp"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "A3_Characters_F" };
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"

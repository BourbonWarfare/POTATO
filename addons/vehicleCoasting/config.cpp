#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"CBA_main", "CBA_xeh", "CBA_xeh_a3"};
        author = "Potato";
        authors[] = {"Lambda.Tiger"};
        skipWhenMissingDependencies = 1;
    };
};

#include "cfgEventhandlers.hpp"

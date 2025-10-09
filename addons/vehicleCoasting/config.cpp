#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_main", "cba_xeh", "cba_xeh_a3"};
        author = "Potato";
        authors[] = {"Lambda.Tiger"};
        skipWhenMissingDependencies = 1;
    };
};

#include "cfgEventhandlers.hpp"

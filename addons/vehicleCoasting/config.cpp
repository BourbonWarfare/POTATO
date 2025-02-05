#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = "LMD vehicle coasting";
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"CBA_main", "CBA_xeh", "CBA_xeh_a3"};
        author = "Lambda.Tiger";
        skipWhenMissingDependencies = 1;
    };
};

#include "cfgEventhandlers.hpp"

#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {"potato_cheezItBoxPlaceable"};
        weapons[] = {"potato_cheezItBox"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

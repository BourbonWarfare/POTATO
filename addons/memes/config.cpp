#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {"potato_cheezItBoxPlaceable", "potato_serverPlaceable", "potato_gamestopPlaceable"};
        weapons[] = {"potato_cheezItBox", "potato_serverBox", "potato_funGun_red", "potato_funGun_green", "potato_gamestop", "potato_whistle"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "CfgLeaflets.hpp"
#include "CfgSounds.hpp"

#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(zeus_cargoDrop)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"Bailey <3"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "Displays.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
#include "CfgEventHandlers.hpp"

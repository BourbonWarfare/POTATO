#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(factory), QGVAR(attackBeacon), QGVAR(place_fireteam), QGVAR(place_squad)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
#include "UI_RscAttributes.hpp"

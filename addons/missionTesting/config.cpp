#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"BadWolf"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class GVAR(display) {
    idd = 9999;
    movingEnable = 1;
    enableSimulation = 1;
    enableDisplay = 1;
};

#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"

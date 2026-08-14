#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "Cfg3DEN.hpp"
class Extended_DisplayLoad_EventHandlers {
    class Display3DENEditAttributes {
        ADDON = QUOTE(call compileScript [QUOTE(QPATHTOF(functions\fnc_displayLoad_intel.sqf))]);
    };
};

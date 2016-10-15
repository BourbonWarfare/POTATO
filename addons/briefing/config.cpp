#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "3den"};
        author = "Potato";
        authors[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"

class ACE_Settings {
    class GVAR(brief_addCredits) {
        value = 0;
        typeName = "BOOL";
    };
    class GVAR(brief_addOrbat) {
        value = 1;
        typeName = "BOOL";
    };
};

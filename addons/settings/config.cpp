#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core","ace_laserPointer","ace_map","ace_zeus","ace_hearing",
            "ace_overheating","ace_gforces","ace_goggles","ace_frag",
            "ace_medical_ai","ace_advanced_fatigue", "ace_cookoff", "STUI_GroupHUD"
        };
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

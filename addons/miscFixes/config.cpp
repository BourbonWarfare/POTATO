#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = { "potato_fakeNVG" };
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core", "ace_ui", "ace_fortify", "ace_missileguidance"
        };
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
    BWC_CONFIG(potato_fortify);
};


// Undo ACE's changes to system messages text brightness
class RscChatListDefault {
    colorBackground[] = {0,0,0,0.3};
    colorMessageProtocol[] = {0.65,0.65,0.65,0.9};
};

class ace_missileguidance_SeekerTypes {
    class SACLOS {
        functionName = QFUNC(seekerType_SACLOS_fix);
    };
};


#include "CfgAmmo.hpp"
#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "CfgFontFamilies.hpp"

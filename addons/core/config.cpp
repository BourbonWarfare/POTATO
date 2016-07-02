#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ACE_COMMON"};
        author = "Potato";
        authors[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "ACE_Settings.hpp"

class CfgMods {
    class PREFIX {
        dir = "@POTATO";
        name = "POTATO";
        picture = QUOTE(PATHTOF(potato_icon_ca.paa));
        hidePicture = "false";
        hideName = "false";
        actionName = "Website";
        action = "https://github.com/BourbonWarfare/POTATO";
        description = "";
    };
};

class ACE_newEvents {
    // potato_adminMsg = "potato_adminMsg";
    // potato_becomeZeus = "potato_becomeZeus";
    // potato_missionHint = "potato_missionHint";
    // potato_becomeZeus = "potato_becomeZeus";
    hcSetIndex = "potato_hcSetIndex";
    safeStartOn = "potato_safeStartOn";
};

class ctrlMenuStrip;
class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                items[] += {QUOTE(PREFIX)}; // += must be used; you want to expand the array, not override it!
                class PREFIX {
                    text = "POTATO"; // Item text
                    items[] = {};
                };
            };
        };
    };
};

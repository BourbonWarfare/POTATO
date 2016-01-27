#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ACE_COMMON"};
        author[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"

class CfgMods {
    class PREFIX {
        dir = "@BourbonMods";
        name = "Bourbon Mods";
        picture = QUOTE(PATHTOF(potato_icon_ca.paa));
        hidePicture = "false";
        hideName = "false";
        actionName = "Website";
        action = "https://github.com/PabstMirror";
        description = "";
    };
};

class ACE_Settings {
    class GVAR(showNotifcations) {
        category = QUOTE(PREFIX);
        displayName = "Potato: Show SystemChat Notifcations";
        description = "False should disable most Notifcations, can use to make clean recordings.";
        typeName = "BOOL";
        value = 1;
        isClientSettable = 1;
    };
};

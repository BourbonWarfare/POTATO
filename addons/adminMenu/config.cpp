#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author[] = {"PabstMirror"};
        authorUrl = "https://github.com/PabstMirror";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "pabst_adminMenu.hpp"

class ACE_Settings {
    class GVAR(showNotifcations) {
        displayName = "POTATO: Show Notifcations";
        description = "False should disable *most* Notifcations - to make clean recordings";
        typeName = "BOOL";
        value = 1;
        isClientSettable = 1;
    };
};

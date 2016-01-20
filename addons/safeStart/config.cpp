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
#include "gui_safeStart.hpp"

class ACE_Settings {
    class GVAR(showTimer) {
        displayName = "AdminMenu: Show Timer";
        description = "Show the safe start timer";
        typeName = "BOOL";
        value = 1;
        isClientSettable = 1;
    };
};

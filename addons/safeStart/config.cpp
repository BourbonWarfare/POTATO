#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "gui_safeStart.hpp"

class ACE_Settings {
    class GVAR(showTimer) {
        category = QUOTE(PREFIX);
        displayName = "Potato: Show SafeStart Timer";
        description = "Show the safe start timer";
        typeName = "BOOL";
        value = 1;
        isClientSettable = 1;
    };
};

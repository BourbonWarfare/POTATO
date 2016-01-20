#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ACE_COMMON"};
        author[] = {"PabstMirror"};
        authorUrl = "https://github.com/PabstMirror";
        VERSION_CONFIG;
    };
};

class CfgMods {
    class PREFIX {
        dir = "@BourbonMods";
        name = "Bourbon Mods";
        picture = QUOTE(PATHTOF(pabst_logo.paa));
        hidePicture = "false";
        hideName = "false";
        actionName = "Website";
        action = "https://github.com/PabstMirror";
        description = "";
    };
};


#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ACE_COMMON"};
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
    class AchillesEffects {
        units[] = {};
        weapons[] = {};
        author = "x";
        requiredVersion = 1.0;
        requiredAddons[] = {};
    };
    class achilles_modules_f_achilles {
        units[] = {"ModulePersistentSmokePillar_F"};
        weapons[] = {};
        author = "x";
        requiredVersion = 1.0;
        requiredAddons[] = {};
    };
};

class CfgVehicles {
    class Logic;
    class ModulePersistentSmokePillar_F: Logic {
        scope = 1;
        displayName = "Delete Me (ModulePersistentSmokePillar_F)";
        class CfgEventHandlers {
            init = "if (isServer) then { diag_log str _this; deleteVehicle (_this select 0); };";
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgEden.hpp"

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"

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

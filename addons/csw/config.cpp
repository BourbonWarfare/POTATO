#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
		author = "Potato";
        authors[] = {"Brandon"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineGroups.hpp"


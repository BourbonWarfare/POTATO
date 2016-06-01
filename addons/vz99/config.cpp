#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(mortar), QGVAR(box)};
        weapons[] = {QGVAR(carryWeapon)};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = {"Potato"};
        authors[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"

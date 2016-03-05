#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {
            QGVAR(east_fireteam),
            QGVAR(east_squad),
            QGVAR(east_heliAttack),
            QGVAR(east_tankModern),

            QGVAR(west_fireteam),
            QGVAR(west_squad),
            QGVAR(west_heliAttack),
            QGVAR(west_tankModern),

            QGVAR(ind_fireteam),
            QGVAR(ind_squad),
            QGVAR(ind_heliAttack),
            QGVAR(ind_tankModern),

            QGVAR(msv_fireteam),
            QGVAR(msv_squad),
            QGVAR(msv_heliAttack),
            QGVAR(msv_tankModern)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgFactionClasses.hpp"

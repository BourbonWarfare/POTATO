#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {
            QGVAR(east_fireteam),
            QGVAR(east_squad),
            QGVAR(east_heliAttack),
            QGVAR(east_tankModern),
            QGVAR(east_rhsBTR60),
            QGVAR(east_rhsBTR70),
            QGVAR(east_rhsBTR80A),
            QGVAR(east_rhsBRM1k),
            QGVAR(east_rhsT72),

            QGVAR(west_fireteam),
            QGVAR(west_squad),
            QGVAR(west_heliAttack),
            QGVAR(west_tankModern),
            QGVAR(west_rhsM113),
            QGVAR(west_rhsBradly),
            QGVAR(west_rhsM1A1),
            QGVAR(west_rhsHMMWV),

            QGVAR(ind_fireteam),
            QGVAR(ind_squad),
            QGVAR(ind_heliAttack),
            QGVAR(ind_tankModern),
            QGVAR(ind_technical),
            QGVAR(ind_rhsBTR60),

            QGVAR(msv_fireteam),
            QGVAR(msv_squad),
            QGVAR(msv_heliAttack),
            QGVAR(msv_rhsBTR60),
            QGVAR(msv_rhsBTR70),
            QGVAR(msv_rhsBTR80A),
            QGVAR(msv_rhsBRM1k),
            QGVAR(msv_rhsT72),
            QGVAR(msv_rhsT80)
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

#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {
            QGVAR(east_ftl),
            QGVAR(east_ar),
            QGVAR(east_rat),
            QGVAR(east_rifleman),
            QGVAR(east_fireteam),
            QGVAR(east_squad),
            QGVAR(east_apcModern),
            QGVAR(east_carOffroad),
            QGVAR(east_carModernGmg),
            QGVAR(east_carModernHmg),
            QGVAR(east_heliAttackHeavy),
            QGVAR(east_heliAttack),
            QGVAR(east_ifvModern),
            QGVAR(east_tankModern),

            QGVAR(west_ftl),
            QGVAR(west_ar),
            QGVAR(west_rat),
            QGVAR(west_rifleman),
            QGVAR(west_fireteam),
            QGVAR(west_squad),
            QGVAR(west_apcModern),
            QGVAR(west_rhsM113GmgD),
            QGVAR(west_rhsM113HmgD),
            QGVAR(west_rhsM113GmgW),
            QGVAR(west_rhsM113HmgW),
            QGVAR(west_strykerGmgD),
            QGVAR(west_strykerHmgD),
            QGVAR(west_strykerGmgW),
            QGVAR(west_strykerHmgW),
            QGVAR(west_rhsHmmwvGmgD),
            QGVAR(west_rhsHmmwvHmgD),
            QGVAR(west_rhsHmmwvGmgW),
            QGVAR(west_rhsHmmwvHmgW),
            QGVAR(west_carModernGmg),
            QGVAR(west_carModernHmg),
            QGVAR(west_carOffroad),
            QGVAR(west_heliAttackHeavy),
            QGVAR(west_heliAttack),
            QGVAR(west_rhsBradly),
            QGVAR(west_ifvModern),
            QGVAR(west_rhsM1A1D),
            QGVAR(west_rhsM1A1W),
            QGVAR(west_tankModern),

            QGVAR(ind_ftl),
            QGVAR(ind_ar),
            QGVAR(ind_rat),
            QGVAR(ind_rifleman),
            QGVAR(ind_fireteam),
            QGVAR(ind_squad),
            QGVAR(ind_rhsBTR60),
            QGVAR(ind_carModernGmg),
            QGVAR(ind_carModernHmg),
            QGVAR(ind_technical),
            QGVAR(ind_rhsUazGmg),
            QGVAR(ind_rhsUazHmg),
            QGVAR(ind_rhsUazSpg),
            QGVAR(ind_heliAttack),
            QGVAR(ind_rhsBmd),
            QGVAR(ind_rhsBmp),
            QGVAR(ind_ifvModern),
            QGVAR(ind_tankModern),
            QGVAR(ind_rhsT72),

            QGVAR(msv_ftl),
            QGVAR(msv_ar),
            QGVAR(msv_rat),
            QGVAR(msv_rifleman),
            QGVAR(msv_fireteam),
            QGVAR(msv_squad),
            QGVAR(msv_rhsBTR60),
            QGVAR(msv_rhsBTR70),
            QGVAR(msv_carBrdm),
            QGVAR(msv_carBrdmAtgm),
            QGVAR(msv_rhsUazGmg),
            QGVAR(msv_rhsUazHmg),
            QGVAR(msv_rhsUazSpg),
            QGVAR(msv_heliAttackHeavy),
            QGVAR(msv_heliAttack),
            QGVAR(msv_rhsBTR80A),
            QGVAR(msv_rhsBmd1),
            QGVAR(msv_rhsBmd2),
            QGVAR(msv_rhsBmd4),
            QGVAR(msv_rhsBmp1),
            QGVAR(msv_rhsBmp2),
            QGVAR(msv_rhsBmp3),
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

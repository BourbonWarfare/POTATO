#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {
            QGVAR(east_ftl),
            QGVAR(east_ar),
            QGVAR(east_rat),
            QGVAR(east_rifleman),
            QGVAR(east_manpad),
            QGVAR(east_manpadTeam),
            QGVAR(east_matTeam),
            QGVAR(east_patrol),
            QGVAR(east_fireteam),
            QGVAR(east_squad),
            QGVAR(east_aaModern),
            QGVAR(east_apcModern),
            QGVAR(east_carOffroad),
            QGVAR(east_carModernGmg),
            QGVAR(east_carModernHmg),
            QGVAR(east_heliAttackHeavy),
            QGVAR(east_heliAttack),
            QGVAR(east_ifvModern),
            QGVAR(east_tankModern),
            QGVAR(east_dismounts),

            QGVAR(west_ftl),
            QGVAR(west_ar),
            QGVAR(west_rat),
            QGVAR(west_rifleman),
            QGVAR(west_manpad),
            QGVAR(west_manpadTeam),
            QGVAR(west_matTeam),
            QGVAR(west_patrol),
            QGVAR(west_fireteam),
            QGVAR(west_squad),
            QGVAR(west_aaModern),
            QGVAR(west_rhsLinebackerD),
            QGVAR(west_rhsLinebackerW),
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
            QGVAR(west_rhsBradleyD),
            QGVAR(west_rhsBradleyW),
            QGVAR(west_ifvModern),
            QGVAR(west_rhsM1A1D),
            QGVAR(west_rhsM1A1W),
            QGVAR(west_tankModern),
            QGVAR(west_dismounts),

            QGVAR(ind_ftl),
            QGVAR(ind_ar),
            QGVAR(ind_rat),
            QGVAR(ind_rifleman),
            QGVAR(ind_manpad),
            QGVAR(ind_manpadTeam),
            QGVAR(ind_matTeam),
            QGVAR(ind_patrol),
            QGVAR(ind_fireteam),
            QGVAR(ind_squad),
            QGVAR(ind_rhsZsu),
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
            QGVAR(ind_ifvModern2),
            QGVAR(ind_tankModern),
            QGVAR(ind_rhsT72),
            QGVAR(ind_dismounts),

            QGVAR(msv_ftl),
            QGVAR(msv_ar),
            QGVAR(msv_rat),
            QGVAR(msv_rifleman),
            QGVAR(msv_manpad),
            QGVAR(msv_patrol),
            QGVAR(msv_fireteam),
            QGVAR(msv_squad),
            QGVAR(msv_rhsZsu),
            QGVAR(msv_rhsBTR60),
            QGVAR(msv_rhsBTR70),
            QGVAR(msv_rhsBTR80),
            QGVAR(msv_carBrdm),
            QGVAR(msv_carBrdmAtgm),
            QGVAR(msv_rhsGazGmgMmg),
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
            QGVAR(msv_rhsT80),
            QGVAR(msv_dismounts),

            QGVAR(ungarrison_all_groups),
            QGVAR(ungarrison_nearest_group),
            QGVAR(move_all_to_hc),
            QGVAR(fix_nearest_group),

            QGVAR(build_a_group),
            QGVAR(spawn_a_vehicle),
            QGVAR(garrison)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "ACE_Settings.hpp"
#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgGarrison.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
#include "Displays.hpp"

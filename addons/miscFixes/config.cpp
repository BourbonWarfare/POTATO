#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {
            QUSMC(rifleman),QUSMC(rifleman_02),QUSMC(rifleman_03),QUSMC(rifleman_04),QUSMC(sf_rifleman),
            QUSMC(sniper),QUSMC(aar),QUSMC(sf_aar),QUSMC(mmgag),QUSMC(hmgag),QUSMC(matag),
            QUSMC(hatag),QUSMC(msamag),QUSMC(mtrag),QUSMC(mtrg),QUSMC(ar),QUSMC(sf_ar),
            QUSMC(mmgg),QUSMC(hmgg),QUSMC(lat),QUSMC(sf_lat),QUSMC(matg),QUSMC(hatg),QUSMC(msamg),
            QUSMC(coy),QUSMC(xo),QUSMC(fac),QUSMC(plt),QUSMC(sgt),QUSMC(sl),QUSMC(sf_sl),
            QUSMC(mmgl),QUSMC(hmgl),QUSMC(matl),QUSMC(hatl),QUSMC(msaml),QUSMC(mtrl),QUSMC(stl),
            QUSMC(ftl),QUSMC(sf_ftl),QUSMC(vicl),QUSMC(cm),QUSMC(plm),QUSMC(sm),QUSMC(sf_sm),
            QUSMC(eodl),QUSMC(eod),QUSMC(vicc),QUSMC(vicd),QUSMC(pilot),QUSMC(cc)
        };
        weapons[] = {"potato_fakeNVG"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "mbg_celle2", "ace_ui", "rhs_c_weapons", "Taliban_fighters"};
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

// Fix CELLE font error:
class CfgLocationTypes {
    class MBG_celle2_icon_A7 {
        font = "PuristaMedium";
    };
};

// Undo ACE's changes to system messages text brightness
class RscChatListDefault {
    colorMessageProtocol[] = {0.65,0.65,0.65,1};
};

#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

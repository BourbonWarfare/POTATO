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
            QUSMC(eodl),QUSMC(eod),QUSMC(vicc),QUSMC(vicd),QUSMC(pilot),QUSMC(cc),
            QMSV(rifleman),QMSV(rifleman_02),QMSV(rifleman_03),QMSV(rifleman_04),QMSV(sf_rifleman),
            QMSV(marksman),QMSV(sf_marksman),QMSV(aar),QMSV(sf_aar),QMSV(ag),QMSV(mmgag),QMSV(hmgag),
            QMSV(matag),QMSV(hatag),QMSV(msamag),QMSV(mtrag),QMSV(mtrg),QMSV(ar),QMSV(sf_ar),QMSV(mmgg),
            QMSV(hmgg),QMSV(g),QMSV(sf_g),QMSV(matg),QMSV(hatg),QMSV(msamg),QMSV(coy),QMSV(acoy),QMSV(pol),
            QMSV(fac),QMSV(plt),QMSV(aplt),QMSV(sl),QMSV(sf_sl),QMSV(sf_ftl),QMSV(mmgl),QMSV(hmgl),
            QMSV(matl),QMSV(hatl),QMSV(msaml),QMSV(mtrl),QMSV(stl),QMSV(sr),QMSV(vicl),QMSV(engl),QMSV(cm),
            QMSV(plm),QMSV(sm),QMSV(sf_sm),QMSV(eng),QMSV(demo),QMSV(vicc),QMSV(vicd),QMSV(pilot),QMSV(cc),
            QAIR(rifleman),QAIR(rifleman_02),QAIR(rifleman_03),QAIR(rifleman_04),QAIR(sf_rifleman),
            QAIR(sniper),QAIR(aar),QAIR(sf_aar),QAIR(mmgag),QAIR(hmgag),QAIR(matag),
            QAIR(hatag),QAIR(msamag),QAIR(mtrag),QAIR(mtrg),QAIR(ar),QAIR(sf_ar),
            QAIR(mmgg),QAIR(hmgg),QAIR(lat),QAIR(sf_lat),QAIR(matg),QAIR(hatg),QAIR(msamg),
            QAIR(coy),QAIR(xo),QAIR(fac),QAIR(plt),QAIR(sgt),QAIR(sl),QAIR(sf_sl),
            QAIR(mmgl),QAIR(hmgl),QAIR(matl),QAIR(hatl),QAIR(msaml),QAIR(mtrl),QAIR(stl),
            QAIR(ftl),QAIR(sf_ftl),QAIR(vicl),QAIR(cm),QAIR(plm),QAIR(sm),QAIR(sf_sm),
            QAIR(engl),QAIR(eng),QAIR(demo),QAIR(vicc),QAIR(vicd),QAIR(pilot),QAIR(cc)
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

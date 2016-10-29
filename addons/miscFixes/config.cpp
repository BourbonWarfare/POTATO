#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {"potato_fakeNVG"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "mbg_celle2", "ace_ui", "rhs_c_weapons", "Taliban_fighters", "BWA3_Common"};
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

// fix popup error when editing units
class CfgUnitInsignia {
    delete BWA3_insignia_name_Ghost;
    delete BWA3_insignia_name_Kickapoo;
    delete BWA3_insignia_name_Tonic;
};

#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {"potato_fakeNVG"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "mbg_celle2", "ace_ui"};
        author = "Potato";
        authors[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };

    //MELB -> RHS Patch [Keep until August]:
    class MELB {
        units[] = {"MELB_H6M","MELB_AH6M_L","MELB_AH6M_M","MELB_AH6M_H","MELB_MH6M"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"rhsusf_c_melb"};
    };
};


//Fix CELLE font error:
class CfgLocationTypes {
    class MBG_celle2_icon_A7 {
        font = "PuristaMedium";
    };
};

//Undo ACE's changes to system messages text brightness
class RscChatListDefault {
    colorMessageProtocol[] = {0.65,0.65,0.65,1};
};

class CfgVehicles {
    class LandVehicle;
    class StaticWeapon: LandVehicle {
        insideSoundCoef = 0; //ACRE uses this for vehicle sound attenuation (makes it easy to hear mortar gunners)
    };


    //MELB -> RHS Patch:
    class RHS_MELB_H6M;
    class MELB_H6M: RHS_MELB_H6M {
        displayName = "OH-6M [Replace With RHS Version]";
    };
    class RHS_MELB_AH6M_L;
    class MELB_AH6M_L: RHS_MELB_AH6M_L {
        displayName = "AH-6M-L [Replace With RHS Version]";
    };
    class RHS_MELB_AH6M_M;
    class MELB_AH6M_M: RHS_MELB_AH6M_M {
        displayName = "AH-6M-M [Replace With RHS Version]";
    };
    class RHS_MELB_AH6M_H;
    class MELB_AH6M_H: RHS_MELB_AH6M_H {
        displayName = "AH-6M-H [Replace With RHS Version]";
    };
    class RHS_MELB_MH6M;
    class MELB_MH6M: RHS_MELB_MH6M {
        displayName = "MH-6M [Replace With RHS Version]";
    };


    class Box_NATO_Support_F;
    class GVAR(smawBox): Box_NATO_Support_F {
        scope = 1;
        displayName = "SMAW Weapon Box";
        transportMaxWeapons = 9001;
        transportMaxMagazines = 9001;
        transportMaxItems = 9001;
        maximumload = 1000;

        class TransportWeapons {
            MACRO_ADDWEAPON(rhs_weap_smaw,1);
        };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEAA,2);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEDP,2);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_SR,4);
        };
        class TransportItems {};
        class TransportBackpacks {};
    };
};


class CfgWeapons {
    class NVGoggles;
    class potato_fakeNVG: NVGoggles {
        author = "pabst";
        modelOptics = QUOTE(PATHTOF(models\plotNVGs));
        model = "\A3\weapons_f\empty";
        displayName = "Fake NVGs (AI Only)";
        descriptionShort = "[Plot Googles] Do not attempt to use as a player, only to allow AI to have better vision";
        class ItemInfo {
            type = 616;
            hmdType = 0;
            uniformModel = "\A3\weapons_f\empty";
            modelOff = "\A3\weapons_f\empty";
            mass = 20;
        };
    };
};

class CfgInGameUI {
    class SquadRadar {
        //78-64-40
        // backgroundTexture = "";
        compassBackgroundTexture = QUOTE(PATHTOF(ui\squadRadarBackground_Darker_ca.paa));
    };
};

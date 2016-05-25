#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "mbg_celle2", "ace_ui"};
        author[] = {"PabstMirror"};
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


    //CUP/AiA Terrain Dummies:
    class CUP_Structures_Config {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"AiA_Structures_Config", "CAStructures"};
    };
    class CUP_CA_Data: CUP_Structures_Config {
        requiredAddons[] = {"AiA_CA_Data"};
    };
    class CUP_CA_Plants2: CUP_Structures_Config {
        requiredAddons[] = {"AiA_Plants_Data"};
    };
    class CUP_CAStructures_Misc_Armory: CUP_Structures_Config {
        requiredAddons[] = {"AiA_Buildings_Config", "CABuildings", "AiA_Buildings2_Config", "CABuildings2"};
    };
    class CUP_A2_EditorObjects: CUP_Structures_Config {
        requiredAddons[] = {"AiA_Buildings_Config", "CABuildings", "AiA_Buildings2_Config", "CABuildings2"};
    };
    class CUP_CAStructures_Misc: CUP_Structures_Config {
        requiredAddons[] = {"AiA_Buildings_Config", "CABuildings", "AiA_Buildings2_Config", "CABuildings2"};
    };
    class CUP_Buildings_Config: CUP_Structures_Config {
        requiredAddons[] = {"AiA_Buildings_Config", "CABuildings", "AiA_Buildings2_Config", "CABuildings2"};
    };
    class CUP_CABuildings_Misc: CUP_Structures_Config {
        requiredAddons[] = {"AiA_Buildings_Config", "CABuildings", "AiA_Buildings2_Config", "CABuildings2"};
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
};

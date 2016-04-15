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

    //CUP/AiA Terrain Dummies:
    class CUP_Structures_Config {
        requiredAddons[] = {"AiA_Structures_Config", "CAStructures"};
    };
    class CUP_CA_Data {
        requiredAddons[] = {"AiA_CA_Data"};
    };
    class CUP_CA_Plants2 {
        requiredAddons[] = {"AiA_Plants_Data"};
    };
    class CUP_CAStructures_Misc_Armory {
        requiredAddons[] = {"AiA_Buildings_Config", "CABuildings", "AiA_Buildings2_Config", "CABuildings2"};
    };
    class CUP_A2_EditorObjects {
        requiredAddons[] = {"AiA_Buildings_Config", "CABuildings", "AiA_Buildings2_Config", "CABuildings2"};
    };
    class CUP_CAStructures_Misc {
        requiredAddons[] = {"AiA_Buildings_Config", "CABuildings", "AiA_Buildings2_Config", "CABuildings2"};
    };
    class CUP_Buildings_Config {
        requiredAddons[] = {"AiA_Buildings_Config", "CABuildings", "AiA_Buildings2_Config", "CABuildings2"};
    };
    class CUP_CABuildings_Misc {
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
};

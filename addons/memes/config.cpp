#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {"potato_cheezItBoxPlaceable", "potato_serverPlaceable", "potato_gamestopPlaceable"};
        weapons[] = {"potato_cheezItBox", "potato_serverBox"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
    class Pabst_funGun {
        units[]={};
        weapons[]={"potato_funGun_red", "potato_funGun_green"};
        requiredVersion=0.1;
        requiredAddons[]={"A3_Weapons_F", "A3_Weapons_F_Exp_SMGs_SMG_05"};
    };
};

class CfgWeapons {
    class SMG_05_F;

    class potato_funGun_red: SMG_05_F {
        author = "Pabst";
        scope = 1; // Keep hidden
        scopeCurator = 0;
        displayName = "Candy Cane 9mm (Red)";
        model = "\z\potato\addons\memes\data\funGun_red.p3d";
        selectionFireAnim = "muzzleFlash";
        handAnim[] = {"OFP2_ManSkeleton","\A3\Weapons_F\Rifles\MX\data\Anim\mx.rtm"};
    };
    class potato_funGun_green: SMG_05_F {
        author = "Pabst";
        scope = 1; // Keep hidden
        scopeCurator = 0;
        displayName = "Candy Cane 9mm (Green)";
        model = "\z\potato\addons\memes\data\funGun_green.p3d";
        selectionFireAnim = "muzzleFlash";
        handAnim[] = {"OFP2_ManSkeleton","\A3\Weapons_F\Rifles\MX\data\Anim\mx.rtm"};
    };
};

#include "CfgVehicles.hpp"
#include "CfgLeaflets.hpp"
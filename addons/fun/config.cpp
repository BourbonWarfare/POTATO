class CfgPatches
{
    class Pabst_funGun {
        units[]={};
        weapons[]={"potato_funGun_red", "potato_funGun_green"};
        requiredVersion=0.1;
        requiredAddons[]={"A3_Weapons_F", "A3_Weapons_F_Rifles_MX"};
    };
};

class CfgWeapons {
    class arifle_MX_F;

    class potato_funGun_red: arifle_MX_F {
        author = "Pabst";
        scope = 1; // Keep hidden
        scopeCurator = 0;
        displayName = "Candy Cane 6.5mm (Red)";
        model = "\z\potato\addons\fun\data\funGun_red.p3d";
        selectionFireAnim = "muzzleFlash";
    };
    class potato_funGun_green: arifle_MX_F {
        author = "Pabst";
        scope = 1; // Keep hidden
        scopeCurator = 0;
        displayName = "Candy Cane 6.5mm (Green)";
        model = "\z\potato\addons\fun\data\funGun_green.p3d";
        selectionFireAnim = "muzzleFlash";
    };
};


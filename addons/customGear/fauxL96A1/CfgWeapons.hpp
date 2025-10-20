class CfgWeapons {
    class Rifle_Base_F;
    class Rifle_Long_Base_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class CUP_srifle_AWM_Base: Rifle_Long_Base_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {};
    };
    class potato_srifle_L96A1: CUP_srifle_AWM_Base { // ONLY CAME IN GREEN :(
        author = "Potato (CUP Model)";
        magazines[] = {"potato_10Rnd_762x51"};
        magazineWell[] = {"CBA_762x51_1rnd","CBA_762x51_2rnds","CBA_762x51_3rnds","CBA_762x51_4rnds","CBA_762x51_5rnds"};
        scope = 2;
        scopeArsenal = 2;
        descriptionShort = "Sniper Rifle <br/>Caliber: 7.62x51mm NATO";
        displayName = "L96A1 PM";
        model = "CUP\Weapons\CUP_Weapons_AWM\CUP_awm.p3d";
		picture = "\CUP\Weapons\CUP_Weapons_AWM\data\UI\gear_awm_w_x_ca.paa";
        hiddenSelections[] = {"camo","camo2","camo3"};
        hiddenSelectionsTextures[] = {"\cup\weapons\cup_weapons_awm\data\awcstock_OD_co.paa","\cup\weapons\cup_weapons_awm\data\AWC_Scope_co.paa","\cup\weapons\cup_weapons_awm\data\magnumbits_co.paa"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 143.1;
        };
    };
};

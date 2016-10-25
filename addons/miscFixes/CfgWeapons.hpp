class CfgWeapons {
    // Add invisible NVGs for AI purposes
    class NVGoggles;
    class potato_fakeNVG: NVGoggles {
        author = "PabstMirror";
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

    // create lighter SMAWs for playability
    class Launcher;
    class Launcher_Base_F: Launcher {
        class WeaponSlotsInfo;
    };
    class rhs_weap_smaw : Launcher_Base_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 70;
        };
    };

    // Manually list all mags for HLC/RHS compat
    class rhs_weap_ak74m;
    class rhs_weap_akm : rhs_weap_ak74m {
        magazines[] = {"rhs_30Rnd_762x39mm", "rhs_30Rnd_762x39mm_tracer", "rhs_30Rnd_762x39mm_89", "rhs_30Rnd_762x39mm_U", "hlc_30Rnd_762x39_b_ak", "hlc_30Rnd_762x39_t_ak", "hlc_45Rnd_762x39_m_rpk", "HLC_45rnd_762x39_T_RPK", "hlc_30rnd_762x39_s_ak"};
    };

    // shim the bugged uniform
    class InventoryItem_Base_F;
    class UniformItem: InventoryItem_Base_F {
        type = 801;
    };

    class Uniform_Base;
    class U_Afghan06: Uniform_Base {
        author = "EricJ";
        scope = 2;
        displayName = "Afghan Clothes 6";
        picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
        model = "\Taliban_Fighters\Uniforms\Afghan_06NH.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"Taliban_Fighters\data\tak_civil06_1_co.paa"};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "TBan_Fighter6NH";
            armor = 0;
            passThrough = 1;
            containerClass = "Supply30";
            mass = 30;
        };
    };
};

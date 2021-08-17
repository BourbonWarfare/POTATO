class CfgWeapons {
    /*

    */
    class Rifle_Base_F;
    class arifle_TRG20_F;
    class arifle_TRG21_F;
    class CUP_arifle_X95;
    class CUP_arifle_X95_Grippod;
    class CUP_arifle_AK104;
    class CUP_CZ_BREN2_Base;
    class Pistol_Base_F;
    class Rifle_Long_Base_F;
    class Rifle_Short_Base_F;

    class arifle_MSBS65_base_F: Rifle_Base_F {
        magazineWell[] += { "CBA_65x39_MX" };
    };

    class CUP_arifle_FNFAL: Rifle_Base_F {
        magazineWell[] += { "CBA_762x51_FAL_L", "CBA_762x51_FAL_XL" };
    };

    class CUP_arifle_Fort221: arifle_TRG20_F {
        magazineWell[] += { QGVAR(magwell_545x39) };
    };

    class CUP_arifle_Fort222: arifle_TRG21_F {
        magazineWell[] += { QGVAR(magwell_545x39) };
    };

    class CUP_arifle_Fort224: CUP_arifle_X95 {
        magazineWell[] += { QGVAR(magwell_545x39) };
    };

    class CUP_arifle_Fort224_Grippod: CUP_arifle_X95_Grippod {
        magazineWell[] += { QGVAR(magwell_545x39) };
    };

    class CUP_arifle_GALIL_BASE: Rifle_Base_F {
        magazineWell[] += { "CBA_762x51_GALIL" };
    };

    class CUP_arifle_Galil_556_black: CUP_arifle_GALIL_BASE {
        magazineWell[] = { "CBA_556x45_GALIL" };
    };

    class CUP_arifle_Galil_556_SAR_black: CUP_arifle_GALIL_BASE {
        magazineWell[] = { "CBA_556x45_GALIL" };
    };

    class CUP_arifle_SAIGA_MK03: CUP_arifle_AK104 {
        magazineWell[] += { QGVAR(magwell_545x39) };
    };

    class CUP_CZ_BREN2_762_Base: CUP_CZ_BREN2_Base {
        magazineWell[] += { "CBA_762x51_AR10", "CBA_762x51_AR10_L", "CBA_762x51_AR10_XL" };
    };

    class CUP_Famas_Base: Rifle_Base_F {
        magazineWell[] += { "CBA_556x45_FAMAS" };
    };

    class CUP_hgun_CZ75: Pistol_Base_F {
        magazineWell[] += { "CBA_9x19_CZ75_Full" };
    };

    class CUP_hgun_Deagle: Pistol_Base_F {
        magazineWell[] += { QGVAR(magwell_50ae) };
    };

    class CUP_hgun_M17_Coyote: Pistol_Base_F {
        magazineWell[] += { QGVAR(magwell_9x19_m17) };
    };

    class CUP_Mac10_Base: Rifle_Base_F {
        magazineWell[] += { QGVAR(magwell_45acp_m10) };
    };

    class CUP_hgun_Mac10_Base: Pistol_Base_F {
        magazineWell[] += { QGVAR(magwell_45acp_m10) };
    };

    class CUP_hgun_Mk23: Pistol_Base_F {
        magazineWell[] += { QGVAR(magwell_45acp_mk23) };
    };

    class CUP_hgun_TaurusTracker455: Pistol_Base_F {
        magazineWell[] += { "Cylinder_45ACP" };
    };

    class CUP_hgun_TEC9: Pistol_Base_F {
        magazineWell[] += { QGVAR(magwell_9x19_tec9) };
    };

    class CUP_lmg_MG3: Rifle_Long_Base_F {
        magazineWell[] += { "CBA_762x51_LINKS" };
    };

    class CUP_SKS: Rifle_Base_F {
        magazineWell[] += { "CBA_762x39_SKS", "CBA_762x39_SKS_Clip" };
    };

    class CUP_srifle_CZ550_base: Rifle_Base_F {
        magazineWell[] += { QGVAR(magwell_22lr_cz550) };
    };

    class hgun_P07_F: Pistol_Base_F {
        magazineWell[] += { "CBA_9x19_CZP07" };
    };

    class pdw2000_base_F: Rifle_Short_Base_F {
        magazineWell[] += { QGVAR(magwell_9x19_pdw) };
    };

    class hgun_Pistol_01_F: Pistol_Base_F {
        magazineWell[] += { "CBA_9x21_SR1M" };
    };

    class hgun_Pistol_heavy_01_F: Pistol_Base_F {
        magazineWell[] += { "CBA_45ACP_Glock_Cpct" };
    };

    class hgun_Rook40_F: Pistol_Base_F {
        magazineWell[] += { "CBA_9x19_MP443" };
    };

    class DMR_02_base_F: Rifle_Long_Base_F {
        magazineWell[] += { "CBA_338LM_AI" };
    };

    class DMR_07_base_F: Rifle_Long_Base_F {
        magazineWell[] += { QGVAR(magwell_65x39_dmr07) };
    };
};
class CfgWeapons {
    class ItemCore;
    class Uniform_Base;
    class UniformItem;
    
    class jasons_indfor_uniform_base: ItemCore {
        allowedSlots[] = {901};
        author = "Colonel Jason";
        displayName = "Jason INDFOR Uniform Base";
        dlc="";
        model = "\a3\characters_f\common\suitpacks\suitpack_universal_f.p3d";
        picture = "";
        hiddenSelections[]={"camo"};
        scope = 1;
        scopeCurator = 1;
        scopeArsenal = 1; 
        class ItemInfo : UniformItem {
            containerClass = "Supply40";
            mass = 20;
            uniformClass = "";
            uniformModel = "-";
        };
    };
    
    class potato_jehlici: jasons_indfor_uniform_base {
        displayName = "ČSLA M69 (Jehlici)";
        picture = "\cwr3\humans\cwr3_soldiers_rus\ui\cwr3_u_m82_ca.paa";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\czech_needle_uniform_1_co.paa)
        };
        scope = 2;          
        scopeCurator = 1;
        scopeArsenal = 2;
        class ItemInfo : UniformItem {
            containerClass = "Supply40";
           mass = 20;
           uniformClass = "potato_jehlici_uniform_base"; 
           uniformModel = "-";
        };
    };
    
    class potato_tan_jehlici: potato_jehlici {
        displayName = "ČSLA M69 (Jehlici, Tan)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\czech_needle_brown_uniform_1_co.paa)
        };
        scope = 2;          
        scopeCurator = 1;
        scopeArsenal = 2;
        class ItemInfo : UniformItem {
            containerClass = "Supply40";
           mass = 20;
           uniformClass = "potato_jehlici_uniform_tan"; 
           uniformModel = "-";
        };
    };
    
    // PTV 2.0 retextures
    
    class ptv_u_m08: Uniform_Base {};
    class potato_u_g3cw_serp_m05wdl_v2: ptv_u_m08 {
        author = "HOBO/LYYAMAO/AMF & PTV/Chesheire";
        scope = 2;
        displayName = "Särmä TST L6 Hardshell Jacket (M05 Wdl) + flag";
        picture = "\ptv_characters\data\ui\icon_u_ptv_uniform_03_ca.paa";
        model = "\ptv_characters\uniforms\ptv_suitpack_uni_02";
        hiddenSelections[] = {
            "camo",
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            "\ptv_characters\uniforms\data\G3_SHIRT_SERP_CO.paa",
            QPATHTOEF(customGear,uniforms\data\G3_PANT_M05_v2_CO.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_s_g3cw_serp_m05wdl_v2";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class potato_u_g3cw_serp_m05wdl_v3: ptv_u_m08 {
        author = "HOBO/LYYAMAO/AMF & PTV/Chesheire";
        scope = 2;
        displayName = "Särmä TST L6 Hardshell Jacket (M05 Wdl)";
        picture = "\ptv_characters\data\ui\icon_u_ptv_uniform_03_ca.paa";
        model = "\ptv_characters\uniforms\ptv_suitpack_uni_02";
        hiddenSelections[] = {
            "camo",
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            "\ptv_characters\uniforms\data\G3_SHIRT_SERP_CO.paa",
            QPATHTOEF(customGear,uniforms\data\G3_PANT_M05_v2_CO.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_s_g3cw_serp_m05wdl_v3";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class potato_u_g3cw_serp_m05wdlwint: ptv_u_m08 {
        author = "HOBO/LYYAMAO/AMF & PTV/Chesheire";
        scope = 2;
        displayName = "Särmä TST L6 Hardshell Jacket (M05 Wdl/Wint)";
        picture = "\ptv_characters\data\ui\icon_u_ptv_uniform_03_ca.paa";
        model = "\ptv_characters\uniforms\ptv_suitpack_uni_02";
        hiddenSelections[] = {
            "camo",
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            "\ptv_characters\uniforms\data\G3_SHIRT_SERP_CO.paa",
            QPATHTOEF(customGear,uniforms\data\G3_PANT_M05Wint_CO.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_s_g3cw_serp_m05wdlwint";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class potato_u_g3cw_serp_m05wdlwint_v2: ptv_u_m08 {
        author = "HOBO/LYYAMAO/AMF & PTV/Chesheire";
        scope = 2;
        displayName = "Särmä TST L6 Hardshell Jacket (M05 Wdl/Wint) v2";
        picture = "\ptv_characters\data\ui\icon_u_ptv_uniform_03_ca.paa";
        model = "\ptv_characters\uniforms\ptv_suitpack_uni_02";
        hiddenSelections[] = {
            "camo",
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            "\ptv_characters\uniforms\data\G3_SHIRT_SERP_CO.paa",
            QPATHTOEF(customGear,uniforms\data\G3_PANT_M05Wint_v2_CO.paa)
        };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_s_g3cw_serp_m05wdlwint_v2";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    
    // CUP Crye G3 retextures
    
    class potato_U_CRYE_G3C_MARWDL_v8_US: ItemCore { // I think it's this one that's the best one iirc
        author = "AChesheireCat";
        scope = 2;
        allowedSlots[] = {901};
        displayName = "Crye Gen 3  (MARPAT Woodland v1)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USArmy\data\ui\icon_CUP_CRYE_V1_Full.paa";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_CRYE_G3C_MARWDL_v8_US";
            containerClass = "Supply40";
            mass = 20;
        };
    };
    class potato_U_CRYE_G3C_MARWDL_v9_US: ItemCore {
        author = "AChesheireCat";
        scope = 2;
        allowedSlots[] = {901};
        displayName = "Crye Gen 3  (MARPAT Woodland v2)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USArmy\data\ui\icon_CUP_CRYE_V1_Full.paa";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_CRYE_G3C_MARWDL_v9_US";
            containerClass = "Supply40";
            mass = 20;
        };
    };
    
    // RHS 6B28 retextures
    
    class H_HelmetB: ItemCore {};
    class rhs_6b27m: H_HelmetB {};
    class rhs_6b28: rhs_6b27m {};
    class rhs_6b28_green: rhs_6b28 {};
    class rhs_6b28_ess: rhs_6b28 {};
    class rhs_6b28_green_ess: rhs_6b28_ess {};
    class potato_helmet_6b28_irreg: rhs_6b28_green {
        author = "AChesheireCat";
        scope = 2;
        hiddenSelectionsTextures[] = {QPATHTOEF(customGear,uniforms\data\potato_6b28_2_irreg_co.paa)};
    };
    class potato_helmet_6b28_irreg_ess: rhs_6b28_green_ess {
        author = "AChesheireCat";
        scope = 2;
        hiddenSelectionsTextures[] = {QPATHTOEF(customGear,uniforms\data\potato_6b28_2_irreg_co.paa)};
    };
    
    // CWRIII LBV retextures
    
    class cwr3_b_vest_base: ItemCore {};
    class cwr3_b_vest_alice: cwr3_b_vest_base {};
    class cwr3_b_vest_lbv: cwr3_b_vest_alice {};
    class potato_vest_grad2: cwr3_b_vest_lbv {
        author = "AChesheireCat";
        scope = 2;
        allowedSlots[] = {901};
        displayName = "Grad-2";
        hiddenSelections[] = {"hs_vest1","hs_vest2","hs_vest3"};
        hiddenSelectionsTextures[] = {QPATHTOEF(customGear,uniforms\data\potato_grad2_co.paa),"\cwr3\humans\cwr3_soldiers_usa\vests\data\ssgear_alice_co.paa","\cwr3\humans\cwr3_soldiers_usa\vests\data\ssgear_alice_banci_co.paa"};
    };
};

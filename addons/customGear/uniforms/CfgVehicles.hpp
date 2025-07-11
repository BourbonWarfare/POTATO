class CfgVehicles {
    class B_Soldier_base_F;
    class potato_jehlici_uniform_base: B_Soldier_base_F {
        model = "\cwr3\humans\cwr3_soldiers_rus\uniforms\cwr3_uniform_m69.p3d";
        scope = 1;
        scopeCurator = 1;
        uniformClass = "potato_jehlici";
        hiddenSelections[] = {
            "hs_camo1",
            "hs_camo2",
            "hs_camo3",
            "insignia"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\czech_needle_uniform_1_co.paa),
            QPATHTOEF(customGear,uniforms\data\czech_needle_uniform_2_co.paa),
            "",
            "",
            ""
        };
    };
    class potato_jehlici_uniform_tan: potato_jehlici_uniform_base {
        uniformClass = "potato_tan_jehlici";
        hiddenSelections[] = {
            "hs_camo1",
            "hs_camo2",
            "hs_camo3",
            "insignia"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\czech_needle_brown_uniform_1_co.paa),
            QPATHTOEF(customGear,uniforms\data\czech_needle_brown_uniform_2_co.paa),
            "",
            "",
            ""
        };
    };
    
    // PTV 2.0 retextures
    
    class ptv_s_m08: B_Soldier_base_F {};
    class potato_s_g3cw_serp_m05wdl_v2: ptv_s_m08 {
        author = "AMF/VityaB/Siege-A & PTV/Chesheire";
        scope = 1;
        model = "\ptv_characters\uniforms\ptv_Uniform_07.p3d";
        modelSides[] = {3,1};
        nakedUniform = "U_BasicBody";
        uniformClass = "potato_u_g3cw_serp_m05wdl_v2";
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "Camo4",
            "noglove",
            "grade",
            "sang",
            "drapeau",
            "insignia",
            "clan"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\ptv_jacket_m05_v2_co.paa),
            QPATHTOEF(customGear,uniforms\data\G3_PANT_M05_v2_CO.paa),
            "\ptv_characters\uniforms\Data\m77_co.paa",
            "\ptv_characters\uniforms\data\usp_gloves_co.paa",
            "",
            ""
        };
        hiddenSelectionsMaterials[] = {"\ptv_characters\uniforms\data\jacket_summer.rvmat"};
    };
    class potato_s_g3cw_serp_m05wdl_v3: ptv_s_m08 {
        author = "AMF/VityaB/Siege-A & PTV/Chesheire";
        scope = 1;
        model = "\ptv_characters\uniforms\ptv_Uniform_07.p3d";
        modelSides[] = {3,1};
        nakedUniform = "U_BasicBody";
        uniformClass = "potato_u_g3cw_serp_m05wdl_v3";
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "Camo4",
            "noglove",
            "grade",
            "sang",
            "drapeau",
            "insignia",
            "clan"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\ptv_jacket_m05_v3_co.paa),
            QPATHTOEF(customGear,uniforms\data\G3_PANT_M05_v2_CO.paa),
            "\ptv_characters\uniforms\Data\m77_co.paa",
            "\ptv_characters\uniforms\data\usp_gloves_co.paa",
            "",
            ""
        };
        hiddenSelectionsMaterials[] = {"\ptv_characters\uniforms\data\jacket_summer.rvmat"};
    };
    class potato_s_g3cw_serp_m05wdlwint: ptv_s_m08 {
        author = "AMF/VityaB/Siege-A & PTV/Chesheire";
        scope = 1;
        model = "\ptv_characters\uniforms\ptv_Uniform_07.p3d";
        modelSides[] = {3,1};
        nakedUniform = "U_BasicBody";
        uniformClass = "potato_u_g3cw_serp_m05wdlwint";
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "Camo4",
            "noglove",
            "grade",
            "sang",
            "drapeau",
            "insignia",
            "clan"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\ptv_jacket_m05_v2_co.paa),
            QPATHTOEF(customGear,uniforms\data\G3_PANT_M05Wint_CO.paa),
            "\ptv_characters\uniforms\Data\m77_co.paa",
            "\ptv_characters\uniforms\data\usp_gloves_co.paa",
            "",
            ""
        };
        hiddenSelectionsMaterials[] = {"\ptv_characters\uniforms\data\jacket_summer.rvmat"};
    };
    class potato_s_g3cw_serp_m05wdlwint_v2: ptv_s_m08 {
        author = "AMF/VityaB/Siege-A & PTV/Chesheire";
        scope = 1;
        model = "\ptv_characters\uniforms\ptv_Uniform_07.p3d";
        modelSides[] = {3,1};
        nakedUniform = "U_BasicBody";
        uniformClass = "potato_u_g3cw_serp_m05wdlwint_v2";
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "Camo4",
            "noglove",
            "grade",
            "sang",
            "drapeau",
            "insignia",
            "clan"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\ptv_jacket_m05_v3_co.paa),
            QPATHTOEF(customGear,uniforms\data\G3_PANT_M05Wint_v2_CO.paa),
            "\ptv_characters\uniforms\Data\m77_co.paa",
            "\ptv_characters\uniforms\data\usp_gloves_co.paa",
            "",
            ""
        };
        hiddenSelectionsMaterials[] = {"\ptv_characters\uniforms\data\jacket_summer.rvmat"};
    };
    
    // CUP Crye G3 retextures
    
    class CUP_B_USMC_Soldier_02;
    class potato_CRYE_G3C_MARWDL_v8_US: CUP_B_USMC_Soldier_02 { // I think it's this one that's the best one iirc
        author = "AChesheireCat";
        scope = 1;
        scopeCurator = 0;
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\CUP_U_crye_g3c.p3d";
        uniformClass = "potato_U_CRYE_G3C_MARWDL_v8_US";
        hiddenSelections[] = {"Camo","Camo1","Camo2","Camo4","insignia"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\gen3_marpatw_v8_us_co.paa),
            QPATHTOEF(customGear,uniforms\data\gen3_marpatw_v8_us_co.paa),
            "CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\data\g3\fer_blk_co.paa",
            "CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\data\g3\Mechanix_tan_co.paa"
        };
    };
    class potato_CRYE_G3C_MARWDL_v9_US: CUP_B_USMC_Soldier_02 {
        author = "AChesheireCat";
        scope = 1;
        scopeCurator = 0;
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\CUP_U_crye_g3c.p3d";
        uniformClass = "potato_U_CRYE_G3C_MARWDL_v9_US";
        hiddenSelections[] = {"Camo","Camo1","Camo2","Camo4","insignia"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\gen3_marpatw_v9_us_co.paa),
            QPATHTOEF(customGear,uniforms\data\gen3_marpatw_v9_us_co.paa),
            "CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\data\g3\fer_blk_co.paa",
            "CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\data\g3\Mechanix_tan_co.paa"
        };
    };
    
    // RHS 6B28 retextures
    
    class Item_rhs_6b28_green;
    class potato_6b28_irreg: Item_rhs_6b28_green {
        scope = 1;
        scopeCurator = 1;
        author = "AChesheireCat";
        class TransportItems {
            class potato_helmet_6b28_irreg {
                name = "potato_helmet_6b28_irreg";
                count = 1;
            };
        };
    };
    class Item_rhs_6b28_green_ess;
    class potato_6b28_irreg_ess: Item_rhs_6b28_green_ess {
        scope = 1;
        scopeCurator = 1;
        author = "AChesheireCat";
        class TransportItems {
            class potato_helmet_6b28_irreg_ess {
                name = "potato_helmet_6b28_irreg_ess";
                count = 1;
            };
        };
    };
};

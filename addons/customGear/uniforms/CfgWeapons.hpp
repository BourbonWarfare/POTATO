class CfgWeapons {
    class InventoryItem_Base_F;
    class ItemCore;
    class Uniform_Base;
    class UniformItem: InventoryItem_Base_F {};
    class VestItem: InventoryItem_Base_F {};
    
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
    
    class rhs_6b28_green;
    class potato_helmet_6b28_irreg: rhs_6b28_green {
        author = "AChesheireCat";
        scope = 2;
        hiddenSelectionsTextures[] = {QPATHTOEF(customGear,uniforms\data\potato_6b28_2_irreg_co.paa)};
    };
    class rhs_6b28_green_ess;
    class potato_helmet_6b28_irreg_ess: rhs_6b28_green_ess {
        author = "AChesheireCat";
        scope = 2;
        hiddenSelectionsTextures[] = {QPATHTOEF(customGear,uniforms\data\potato_6b28_2_irreg_co.paa)};
    };
    
    // CWRIII LBV retextures
    class cwr3_b_vest_lbv;
    class potato_vest_grad2: cwr3_b_vest_lbv {
        author = "AChesheireCat";
        scope = 2;
        allowedSlots[] = {901};
        displayName = "Grad-2";
        hiddenSelections[] = {"hs_vest1","hs_vest2","hs_vest3"};
        hiddenSelectionsTextures[] = {QPATHTOEF(customGear,uniforms\data\potato_grad2_co.paa),"\cwr3\humans\cwr3_soldiers_usa\vests\data\ssgear_alice_co.paa","\cwr3\humans\cwr3_soldiers_usa\vests\data\ssgear_alice_banci_co.paa"};
    };
    
    // CUP M88 retextures
    class potato_U_M88_kamysh: ItemCore {
        author = "AChesheireCat";
        scope = 2;
        allowedSlots[] = {901};
        displayName = "Uniform M88 (Blue Kamysh)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Russia\data\ui\icon_U_O_RUS_M88_MSV_ca.paa";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_M88_kamysh";
            containerClass = "Supply60";
            mass = 20;
        };
    };
    class potato_U_M88_kamysh_rolled: ItemCore {
        author = "AChesheireCat";
        scope = 2;
        allowedSlots[] = {901};
        displayName = "Uniform M88 (Blue Kamysh/Rolled)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Russia\data\ui\icon_U_O_RUS_M88_MSV_ca.paa";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_M88_kamysh_rolled";
            containerClass = "Supply60";
            mass = 20;
        };
    };
    class potato_U_M88_kamysh_rolled_gloves: ItemCore {
        author = "AChesheireCat";
        scope = 2;
        allowedSlots[] = {901};
        displayName = "Uniform M88 (Blue Kamysh/Rolled/Gloves)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Russia\data\ui\icon_U_O_RUS_M88_MSV_ca.paa";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_M88_kamysh_rolled_gloves";
            containerClass = "Supply60";
            mass = 20;
        };
    };
    class potato_U_M88_OREL: ItemCore {
        author = "AChesheireCat";
        scope = 2;
        allowedSlots[] = {901};
        displayName = "OREL Field Uniform";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Russia\data\ui\icon_U_O_RUS_M88_MSV_ca.paa";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_M88_OREL";
            containerClass = "Supply60";
            mass = 20;
        };
    };
    class potato_U_M88_OREL_rolled: ItemCore {
        author = "AChesheireCat";
        scope = 2;
        allowedSlots[] = {901};
        displayName = "OREL Field Uniform (Rolled)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Russia\data\ui\icon_U_O_RUS_M88_MSV_ca.paa";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_M88_OREL_rolled";
            containerClass = "Supply60";
            mass = 20;
        };
    };
    class potato_U_M88_OREL_rolled_gloves: ItemCore {
        author = "AChesheireCat";
        scope = 2;
        allowedSlots[] = {901};
        displayName = "OREL Field Uniform (Rolled, Gloves)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Russia\data\ui\icon_U_O_RUS_M88_MSV_ca.paa";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "potato_M88_OREL_rolled_gloves";
            containerClass = "Supply60";
            mass = 20;
        };
    };
    
    // CUP German Vest retextures
    class potato_V_ORELVest_R_Black: ItemCore {
        author = "AChesheireCat";
        dlc = "";
        scope = 2;
        displayName = "Heavy Tactical Vest (Black)";
        descriptionShort = "$STR_A3_SP_AL_III";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\data\ui\icon_v_carrier_vest_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_Ger_ProtectionVest2.p3d";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4","_pistol","_pistol_cartridge_pouches","_pistol_holster"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\orel_vest_noinsignia_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_cartridge_pouch_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_vest_backpack_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_aid_pouch_co.paa)
        };
        class ItemInfo: VestItem {
            uniformModel = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_Ger_ProtectionVest2.p3d";
            containerClass = "Supply220";
            mass = 90;
            hiddenSelections[] = {"camo1","camo2","camo3","camo4","_pistol","_pistol_cartridge_pouches","_pistol_holster"};
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };
    class potato_V_ORELVest_R_Black_lite: ItemCore {
        author = "AChesheireCat";
        dlc = "";
        scope = 2;
        displayName = "Heavy Tactical Vest (Black, Light)";
        descriptionShort = "$STR_A3_SP_AL_III";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\data\ui\icon_v_carrier_vest_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_Ger_ProtectionVest2.p3d";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4","_backpack","_cartridge_pouches","_first_aid","_pistol","_pistol_cartridge_pouches","_pistol_holster"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\orel_vest_noinsignia_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_cartridge_pouch_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_vest_backpack_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_aid_pouch_co.paa)
        };
        class ItemInfo: VestItem {
            uniformModel = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_Ger_ProtectionVest2.p3d";
            containerClass = "Supply180";
            mass = 80;
            hiddenSelections[] = {"camo1","camo2","camo3","camo4","_cartridge_pouches","_first_aid","_pistol","_pistol_cartridge_pouches","_pistol_holster","_backpack"};
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };
    class potato_V_ORELVest_Med_Black: potato_V_ORELVest_R_Black {
        displayName = "Heavy Tactical Vest (Black, Medic)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\data\ui\icon_v_carrier_vest_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_Med.p3d";
        hiddenSelections[] = {"camo1","camo2","camo3","_cartridge_pouches"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\orel_aid_pouch_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_vest_noinsignia_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_vest_backpack_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_cartridge_pouch_co.paa)
        };
        class ItemInfo: VestItem {
            uniformModel = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_Med.p3d";
            containerClass = "Supply220";
            mass = 90;
            hiddenSelections[] = {"camo1","camo2","camo3","_cartridge_pouches"};
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };
    class potato_V_ORELVest_Med_Black_lite: potato_V_ORELVest_R_Black_lite {
        displayName = "Heavy Tactical Vest (Black, Medic, Light)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\data\ui\icon_v_carrier_vest_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_Med.p3d";
        hiddenSelections[] = {"camo1","camo2","camo3","_cartridge_pouches"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\orel_aid_pouch_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_vest_noinsignia_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_cartridge_pouch_co.paa)
        };
        class ItemInfo: VestItem {
            uniformModel = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_Med.p3d";
            containerClass = "Supply180";
            mass = 80;
            hiddenSelections[] = {"camo1","camo2","_cartridge_pouches","_backpack"};
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };
    class potato_V_ORELVest_TL_Black: potato_V_ORELVest_R_Black {
        displayName = "Heavy Tactical Vest (Black, Teamleader)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\data\ui\icon_v_carrier_vest_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_TL.p3d";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\orel_vest_noinsignia_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_cartridge_pouch_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_vest_backpack_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_aid_pouch_co.paa)
        };
        class ItemInfo: VestItem {
            uniformModel = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_TL.p3d";
            containerClass = "Supply220";
            mass = 90;
            hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };
    class potato_V_ORELVest_TL_Black_lite: potato_V_ORELVest_R_Black_lite {
        displayName = "Heavy Tactical Vest (Black, Teamleader, Light)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\data\ui\icon_v_carrier_vest_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_TL.p3d";
        hiddenSelections[] = {"camo1","camo2","camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\orel_vest_noinsignia_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_cartridge_pouch_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_aid_pouch_co.paa)
        };
        class ItemInfo: VestItem {
            uniformModel = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_TL.p3d";
            containerClass = "Supply180";
            mass = 80;
            hiddenSelections[] = {"camo1","camo2","camo4","_backpack"};
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };
    class potato_V_ORELVest_R_Black_insignia: potato_V_ORELVest_R_Black {
        author = "AChesheireCat";
        scope = 2;
        displayName = "OREL Heavy Tactical Vest (Black)";
        descriptionShort = "$STR_A3_SP_AL_III";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\data\ui\icon_v_carrier_vest_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_Ger_ProtectionVest2.p3d";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4","_pistol","_pistol_cartridge_pouches","_pistol_holster"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\orel_vest_insignia_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_cartridge_pouch_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_vest_backpack_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_aid_pouch_co.paa)
        };
        class ItemInfo: VestItem {
            uniformModel = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_Ger_ProtectionVest2.p3d";
            containerClass = "Supply220";
            mass = 90;
            hiddenSelections[] = {"camo1","camo2","camo3","camo4","_pistol","_pistol_cartridge_pouches","_pistol_holster"};
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };
    class potato_V_ORELVest_Med_Black_insignia: potato_V_ORELVest_R_Black {
        displayName = "OREL Heavy Tactical Vest (Black, Medic)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\data\ui\icon_v_carrier_vest_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_Med.p3d";
        hiddenSelections[] = {"camo1","camo2","camo3","_cartridge_pouches"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\orel_aid_pouch_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_vest_insignia_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_vest_backpack_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_cartridge_pouch_co.paa)
        };
        class ItemInfo: VestItem {
            uniformModel = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_Med.p3d";
            containerClass = "Supply220";
            mass = 90;
            hiddenSelections[] = {"camo1","camo2","camo3","_cartridge_pouches"};
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };
    class potato_V_ORELVest_TL_Black_insignia: potato_V_ORELVest_R_Black {
        displayName = "OREL Heavy Tactical Vest (Black, Teamleader)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\data\ui\icon_v_carrier_vest_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_TL.p3d";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOEF(customGear,uniforms\data\orel_vest_insignia_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_cartridge_pouch_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_vest_backpack_co.paa),
            QPATHTOEF(customGear,uniforms\data\orel_aid_pouch_co.paa)
        };
        class ItemInfo: VestItem {
            uniformModel = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Germany\CUP_V_Ger_TL.p3d";
            containerClass = "Supply220";
            mass = 90;
            hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };
    class potato_V_TacVest_blk_OREL: ItemCore {
        author = "AChesheireCat";
        scope = 2;
        displayName = "Tactical Vest (OREL)";
        descriptionShort = "Armor Level II";
        picture = "\A3\characters_f\Data\UI\icon_V_TacVest_blk_police_CA.paa";
        model = "A3\Characters_F\Common\equip_tacticalvest";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {QPATHTOEF(customGear,uniforms\data\OREL_tacvest_black_mid_co.paa)};
        class ItemInfo: VestItem {
            uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
            containerClass = "Supply120";
            mass = 50;
            hiddenSelections[] = {"camo"};
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 12;
                    PassThrough = 0.4;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 12;
                    PassThrough = 0.4;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 12;
                    passThrough = 0.4;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.4;
                };
            };
        };
    };
    
    // GM Type 7 vest recolor
    class gm_ge_vest_type3_base;
    class gm_ge_bgs_vest_type3_gry: gm_ge_vest_type3_base {
        class ItemInfo;
    };
    class gmx_csgo_vest_type3_cream: gm_ge_bgs_vest_type3_gry {
        scope = 2;
        scopeArsenal = 2;
        isgmContent = 1;
        author = "AChesheireCat";
        displayName = "Type 3 Vest (Cream)";
        hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.768627,0.701960,0.6,1.0,CO)",""};
        class ItemInfo: ItemInfo {
            hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.768627,0.701960,0.6,1.0,CO)",""};
        };
    };
};

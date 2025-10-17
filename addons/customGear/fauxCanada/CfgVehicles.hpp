class CfgVehicles {
    //// M113A1
    class gm_dk_army_m113a1dk_apc_base;
    class gm_dk_army_m113a1dk_apc: gm_dk_army_m113a1dk_apc_base {
        class AnimationSources;
        class TextureSources;
    };
    class GVARMAIN(ca_army_m113a1_apc): gm_dk_army_m113a1dk_apc {
        crew = "potato_w_vicc";
        displayName = "M113A1";
        displayNameShort = "M113A1";
        faction = "gm_fc_ca";
        gm_InsigniasDefaultNation = QGVAR(insignia_ca_01);
        gm_LicensePlate = "gm_licenseplate_none";
        gm_LicensePlateDefaultDigits = "";
        gm_InsigniasSelectionNation = "Insignia_nation_01";
        gm_TacticalNumbersDefaultNumber = "##$";
        gm_TacticalNumbersFontNumbers = "gm_ge_schablonier_blk";
        hiddenSelectionsTextures[] = {
            "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\m113a1_camo_01_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\m113a1_camo_03_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
            "\gm\gm_core\data\camo\gm_camonet_01_nato_wdl_ca.paa"
        };
        class AnimationSources: AnimationSources {
            class MachineGunTurret_01_addonarmor_01_unhide {
                animPeriod = 1;
                displayname = "Add Addon Armor - Gun";
                initPhase = 0;
                source = "user";
            };
            class MachineGunTurret_01_addonarmor_02_unhide {
                animPeriod = 1;
                displayname = "Add Addon Armor - Turret";
                initPhase = 0;
                source = "user";
            };
        };
        class TextureSources: TextureSources {
            class GVARMAIN(ca_forestGreen) {
                author = "Bourbon Warfare";
                displayname = "Canada (Forest Green)";
                factions[] = {};
                textures[] = {
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\gm\gm_core\data\camo\gm_camonet_01_nato_wdl_ca.paa"
                };
            };
            class GVARMAIN(ca_green) {
                author = "Bourbon Warfare";
                displayname = "Canada (Green)";
                factions[] = {};
                textures[] = {
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\gm\gm_core\data\camo\gm_camonet_01_nato_wdl_ca.paa"
                };
            };
            class GVARMAIN(ca_camo) {
                author = "Bourbon Warfare";
                displayname = "Canada (Camo)";
                factions[] = {};
                textures[] = {
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\m113a1_camo_01_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\m113a1_camo_03_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\gm\gm_core\data\camo\gm_camonet_01_nato_wdl_ca.paa"
                };
            };
        };
    };
    //// Leopard C1
    class gm_ge_army_Leopard1a3a1_base;
    class gm_ge_army_Leopard1a3a1: gm_ge_army_Leopard1a3a1_base {
        class Turrets;
    };
    class GVARMAIN(ca_army_Leopard_base_01): gm_ge_army_Leopard1a3a1 {
        crew = "potato_w_vicc";
        scope = 1;
        scopeCurator = 1;
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class GVARMAIN(ca_army_Leopard_base_02): GVARMAIN(ca_army_Leopard_base_01) {
        crew = "potato_w_vicc";
        scope = 1;
        scopeCurator = 1;
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets;
            };
        };
    };
    class GVARMAIN(ca_army_Leopard_base_03): GVARMAIN(ca_army_Leopard_base_02) {
        crew = "potato_w_vicc";
        scope = 1;
        scopeCurator = 1;
        class TextureSources;
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderTurret;
                    class LoaderTurret;
                    class MachineGunTurret_01;
                };
            };
        };
    };
    class GVARMAIN(ca_army_Leopard_c1): GVARMAIN(ca_army_Leopard_base_03) {
        displayName = "Leopard C1";
        displayNameShort = "Leopard C1";
        faction = "gm_fc_ca";
        gm_InsigniasDefaultNation = "gm_insignia_none";
        gm_LicensePlate = "gm_licenseplate_none";
        gm_LicensePlateDefaultDigits = "";
        gm_TacticalNumbersDefaultNumber = "";
        gm_TacticalNumbersFontNumbers = "gm_ge_schablonier_blk";
        scope = 2;
        scopeCurator = 2;
        hiddenSelectionsTextures[] = {
            "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_01_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_02_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_04_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
            "\gm\gm_core\data\camo\gm_camonet_01_east_wdl_ca.paa"
        };
        class TextureSources: TextureSources {
            class GVARMAIN(ca_forestGreen) {
                author = "Bourbon Warfare";
                displayname = "Canada (Forest Green)";
                factions[] = {};
                textures[] = {
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_01_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_02_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_04_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\gm\gm_core\data\camo\gm_camonet_01_east_wdl_ca.paa"
                };
            };
            class GVARMAIN(ca_green) {
                author = "Bourbon Warfare";
                displayname = "Canada (Green)";
                factions[] = {};
                textures[] = {
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_camo_01_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_camo_02_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_camo_04_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\gm\gm_core\data\camo\gm_camonet_01_east_wdl_ca.paa"
                };
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderTurret: CommanderTurret {};
                    class LoaderTurret: LoaderTurret {};
                    class MachineGunTurret_01: MachineGunTurret_01 {
                        magazines[] = {
                            "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                            "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                            "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                            "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M"
                        };
                        weapons[] = {QGVARMAIN(Vlmg_C6A1_veh)};
                    };
                };
                discreteDistanceInitindex = 1;
                magazines[] = {
                    QGVARMAIN(25Rnd_105x617mm_apfsds_t_dm33),
                    "gm_30Rnd_105x617mm_heat_mp_t_dm12",
                    QGVARMAIN(5Rnd_105x617mm_wp_t_m416),
                    "CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M",
                    "CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M",
                    "CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M"
                };
                weapons[] = {"gm_105mm_l7a3", QGVARMAIN(Vlmg_C6A1_veh_coax)};
            };
        };
    };
    //// Leopard C2
    class gm_ge_army_Leopard1a5_base;
    class gm_ge_army_Leopard1a5: gm_ge_army_Leopard1a5_base {
        class Turrets;
    };
    class GVARMAIN(ca_army_Leopard_C2_base_01): gm_ge_army_Leopard1a5 {
        crew = "potato_w_vicc";
        scope = 1;
        scopeCurator = 1;
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class GVARMAIN(ca_army_Leopard_C2_base_02): GVARMAIN(ca_army_Leopard_C2_base_01) {
        crew = "potato_w_vicc";
        scope = 1;
        scopeCurator = 1;
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets;
            };
        };
    };
    class GVARMAIN(ca_army_Leopard_C2_base_03): GVARMAIN(ca_army_Leopard_C2_base_02) {
        crew = "potato_w_vicc";
        scope = 1;
        scopeCurator = 1;
        class TextureSources;
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderTurret;
                    class LoaderTurret;
                    class MachineGunTurret_01;
                };
            };
        };
    };
    class GVARMAIN(ca_army_Leopard_c2): GVARMAIN(ca_army_Leopard_C2_base_03) {
        displayName = "Leopard C2";
        displayNameShort = "Leopard C2";
        faction = "gm_fc_ca";
        gm_InsigniasDefaultNation = "gm_insignia_none";
        gm_LicensePlate = "gm_licenseplate_none";
        gm_LicensePlateDefaultDigits = "";
        gm_TacticalNumbersDefaultNumber = "";
        gm_TacticalNumbersFontNumbers = "gm_ge_schablonier_blk";
        scope = 2;
        scopeCurator = 2;
        hiddenSelectionsTextures[] = {
            "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_01_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_02_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_04_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\gm\gm_core\data\camo\gm_camonet_01_east_wdl_ca.paa"
        };
        class TextureSources: TextureSources {
            class GVARMAIN(ca_forestGreen) {
                author = "Bourbon Warfare";
                displayname = "Canada (Forest Green)";
                factions[] = {};
                textures[] = {
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_01_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_02_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_paint_04_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\gm\gm_core\data\camo\gm_camonet_01_east_wdl_ca.paa"
                };
            };
            class GVARMAIN(ca_green) {
                author = "Bourbon Warfare";
                displayname = "Canada (Green)";
                factions[] = {};
                textures[] = {
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_camo_01_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_camo_02_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\leopardc1_camo_04_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\gm\gm_core\data\camo\gm_camonet_01_east_wdl_ca.paa"
                };
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderTurret: CommanderTurret {};
                    class LoaderTurret: LoaderTurret {};
                    class MachineGunTurret_01: MachineGunTurret_01 {
                        magazines[] = {
                            "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                            "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                            "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                            "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M"
                        };
                        weapons[] = {QGVARMAIN(Vlmg_C6A1_veh)};
                    };
                };
                discreteDistanceInitindex = 1;
                magazines[] = {
                    QGVARMAIN(25Rnd_105x617mm_apfsds_t_dm33),
                    "gm_30Rnd_105x617mm_heat_mp_t_dm12",
                    QGVARMAIN(5Rnd_105x617mm_wp_t_m416),
                    "CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M",
                    "CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M",
                    "CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M"
                };
                weapons[] = {"gm_105mm_l7a3", QGVARMAIN(Vlmg_C6A1_veh_coax)};
            };
        };
    };
    //// Iltis
    class gm_ge_army_iltis_cargo_base;
    class gm_ge_army_iltis_cargo: gm_ge_army_iltis_cargo_base {
        class AnimationSources;
        class TextureSources;
    };
    class GVARMAIN(ca_army_iltis): gm_ge_army_iltis_cargo {
        crew = "potato_w_rifleman";
        displayName = "VW Iltis 0.5t Truck";
        displayNameShort = "Iltis";
        faction = "gm_fc_ca";
        gm_InsigniasDefaultNation = QGVAR(insignia_ca_01);
        gm_LicensePlate = "gm_licenseplate_default";
        gm_LicensePlateDefaultDigits = "####$";
        hiddenSelectionsTextures[] = {
            "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
            "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa"
        };
        class AnimationSources: AnimationSources {
            class cover_doors_unhide {
                animPeriod = 1;
                displayname = "Add Doors";
                initPhase = 0;
                source = "user";
            };
            class cover_hoops_unhide {
                animPeriod = 1;
                displayname = "Add Cover";
                forceAnimate[] = {"windshield", 0};
                forceAnimatePhase = 1;
                initPhase = 0;
                // oh god, the onPhaseChanged script
                onPhaseChanged = "if ((_this select 1) == 1) then {_this select 0 animateDoor ['cover_hide',0,true];_this select 0 animateSource ['windshield',0,true]; _this select 0 animateDoor ['windshield_source',0,true];} else {_this select 0 animateDoor ['cover_hide',1,true]; _this select 0 animateSource ['cover_doors_unhide',0,true];};";
                source = "user";
            };
        };
        class TextureSources: TextureSources {
            class GVARMAIN(ca_forestGreen) {
                author = "Bourbon Warfare";
                displayname = "Canada (Forest Green)";
                factions[] = {};
                textures[] = {
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\basePaint_co.paa",
                    "\gm\gm_core\data\camo\gm_camonet_01_nato_wdl_ca.paa"
                };
            };
            class GVARMAIN(ca_green) {
                author = "Bourbon Warfare";
                displayname = "Canada (Green)";
                factions[] = {};
                textures[] = {
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\z\potato\addons\customGear\fauxCanada\data\baseCamo_co.paa",
                    "\gm\gm_core\data\camo\gm_camonet_01_nato_wdl_ca.paa"
                };
            };
        };
    };
    //// M151 C5 - SOG
    class vn_wheeled_m151_mg_01_base;
    class vn_b_wheeled_m151_mg_01_rok_army: vn_wheeled_m151_mg_01_base {
        class Turrets;
    };
    class GVARMAIN(ca_army_m151_c5_base): vn_b_wheeled_m151_mg_01_rok_army {
        scope = 1;
        crew = "potato_w_rifleman";
        displayName = "M151A1 (C5)";
        editorSubcategory = "EdSubcat_Cars";
        faction = "gm_fc_ca";
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class GVARMAIN(ca_army_m151_c5): GVARMAIN(ca_army_m151_c5_base) {
        scope = 2;
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                gunnerType = "potato_w_rifleman";
                magazines[] = {QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M),QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M),QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M)};
                weapons[] = {QGVARMAIN(c5_gpmg_veh_m151)};
            };
        };
    };
    //// C5 GPMG (7.62x51 M1919A4)
    // High
    class vn_static_m1919a4_high_base;
    class vn_b_sf_static_m1919a4_high: vn_static_m1919a4_high_base {
        class Turrets;
    };
    class GVARMAIN(ca_army_c5_high_base): vn_b_sf_static_m1919a4_high {
        crew = "potato_w_rifleman";
        displayName = "C5 GPMG (High)";
        displayNameShort = "C5 (High)";
        editorSubcategory = "EdSubcat_Turrets";
        faction = "gm_fc_ca";
        class ace_csw;
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class GVARMAIN(ca_army_c5_high): GVARMAIN(ca_army_c5_high_base) {
        class ace_csw: ace_csw {
            enabled = 1;
            disassembleWeapon = QGVARMAIN(c5_carry);
            proxyWeapon = QGVARMAIN(c5_gpmg_static);
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = {QGVARMAIN(c5_gpmg_static)};
                magazines[] = {
                    QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M),
                    QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M),
                    QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M),
                    QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M),
                    QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M)
                };
            };
        };
    };
    // Low
    class vn_static_m1919a4_low_base;
    class vn_b_sf_static_m1919a4_low: vn_static_m1919a4_low_base {
        class Turrets;
    };
    class GVARMAIN(ca_army_c5_low_base): vn_b_sf_static_m1919a4_low {
        crew = "potato_w_rifleman";
        displayName = "C5 GPMG (Low)";
        displayNameShort = "C5 (Low)";
        editorSubcategory = "EdSubcat_Turrets";
        faction = "gm_fc_ca";
        class ace_csw;
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class GVARMAIN(ca_army_c5_low): GVARMAIN(ca_army_c5_low_base) {
        class ace_csw: ace_csw {
            enabled = 1;
            disassembleWeapon = QGVARMAIN(c5_carry);
            proxyWeapon = QGVARMAIN(c5_gpmg_static);
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = {QGVARMAIN(c5_gpmg_static)};
                magazines[] = {
                    QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M),
                    QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M),
                    QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M),
                    QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M),
                    QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M)
                };
            };
        };
    };
    //// TOW
    class vn_static_tow_base;
    class vn_b_army_static_tow: vn_static_tow_base {
        class AnimationSources;
        class EventHandlers;
    };
    class GVARMAIN(ca_army_static_tow): vn_b_army_static_tow {
        crew = "potato_w_rifleman";
        editorSubcategory = "EdSubcat_Turrets";
        faction = "gm_fc_ca";
        class AnimationSources: AnimationSources {
            class magazineSpare_hide {
                animPeriod = 0.0001;
                initPhase = 1;
                source = "user";
            };
        };
        class EventHandlers: EventHandlers {
            class vn_tow_spareMagUpdate {}; // wipe out reload animation changes
        };
    };
    //// M40A1
    class vn_static_m40a1rr_base;
    class vn_b_army_static_m40a1rr: vn_static_m40a1rr_base {
        class AnimationSources;
    };
    class GVARMAIN(ca_army_static_m40a1): vn_b_army_static_m40a1rr {
        crew = "potato_w_rifleman";
        editorSubcategory = "EdSubcat_Turrets";
        faction = "gm_fc_ca";
        class AnimationSources: AnimationSources {
            class hide_shells {
                animPeriod = 0.0001;
                appId = 1.2277e+06;
                author = "Savage Game Design";
                displayName = "Hide Shells";
                dlc = "VN";
                initPhase = 1;
                source = "user";
            };
        };
    };
};

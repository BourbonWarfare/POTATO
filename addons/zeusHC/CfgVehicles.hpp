class CfgVehicles {
    class Logic;
    class Module_F: Logic {};

    //------------ Base module ----------
    class GVAR(base_module): Module_F {
        author = QUOTE(PREFIX);
        scope = 1;
        scopeCurator = 1;
        isTriggerActivated = 0;
        isGlobal = 0;
        curatorCost = 0;
        class Arguments {};
        class Attributes {};
    };

    class GVAR(base_prebuilt): GVAR(base_module) {
        function = QFUNC(createEntityZeus);
        GVAR(createVic) = "";
        isTriggerActivated = 1;
    };

    //------------ East ----------
    class GVAR(east_rifleman): GVAR(base_prebuilt) {
        scope = 2;
        scopeCurator = 2;
        displayName = "@Rifleman";
        category = QGVAR(east);
        GVAR(crewAir) = "potato_e_pilot";
        GVAR(crewArmor)= "potato_e_vicc";
        GVAR(createUnits)[] = {"potato_e_rifleman"};
    };
    class GVAR(east_ftl): GVAR(east_rifleman) {
        displayName = "@FTL";
        GVAR(createUnits)[] = {"potato_e_ftl"};
    };
    class GVAR(east_ar): GVAR(east_rifleman) {
        displayName = "@AR";
        GVAR(createUnits)[] = {"potato_e_AR"};
    };
    class GVAR(east_rat): GVAR(east_rifleman) {
        displayName = "@RAT";
        GVAR(createUnits)[] = {"potato_e_LAT"};
    };
    class GVAR(east_manpad): GVAR(east_rifleman) {
        displayName = "@MANPAD";
        GVAR(createUnits)[] = {"potato_e_msamg"};
    };
    class GVAR(east_manpadTeam): GVAR(east_rifleman) {
        displayName = "#MANPAD Team (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_e_msamg","potato_e_msamag"};
    };
    class GVAR(east_matTeam): GVAR(east_rifleman) {
        displayName = "#MAT Team (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_e_matg","potato_e_matag"};
    };
    class GVAR(east_mmgTeam): GVAR(east_rifleman) {
        displayName = "#MMG Team (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_e_mmgg","potato_e_mmgag"};
    };
    class GVAR(east_patrol): GVAR(east_rifleman) {
        displayName = "#Patrol (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_e_rifleman","potato_e_rifleman_02"};
    };
    class GVAR(east_fireteam): GVAR(east_rifleman) {
        displayName = "#Fireteam (4)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_e_ftl","potato_e_AR","potato_e_rifleman","potato_e_LAT"};
    };
    class GVAR(east_squad): GVAR(east_rifleman) {
        displayName = "#Squad (8)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_e_sl","potato_e_ftl","potato_e_ar","potato_e_ar","potato_e_lat","potato_e_rifleman","potato_e_rifleman_02","potato_e_rifleman_03"};
    };
    class GVAR(east_aaModern): GVAR(east_rifleman) {
        displayName = "AA: Tigris (A3)";
        GVAR(createVic) = "O_APC_Tracked_02_AA_F";
    };
    class GVAR(east_rhsZsu): GVAR(east_rifleman) {
        displayName = "AA: ZSU 23 Shilka (RHS)";
        GVAR(createVic) = "rhs_zsu234_aa";
    };
    class GVAR(east_cupZsu): GVAR(east_rifleman) {
        displayName = "AA: ZSU 23 Shilka (CUP)";
        GVAR(createVic) = "CUP_O_ZSU23_SLA";
    };
    class GVAR(east_cupTunguska): GVAR(east_rifleman) {
        displayName = "AA: 2S6M Tunguska (CUP)";
        GVAR(createVic) = "CUP_O_2S6M_RU";
    };
    class GVAR(east_apcModern): GVAR(east_rifleman) {
        displayName = "APC: Otokar GMG/HMG (A3)";
        GVAR(createVic) = "O_APC_Wheeled_02_rcws_F";
    };
    class GVAR(east_rhsBTR60): GVAR(east_rifleman) {
        displayName = "APC: BTR-60 (RHS)";
        GVAR(createVic) = "rhs_btr60_msv";
    };
    class GVAR(east_cupBTR60): GVAR(east_rifleman) {
        displayName = "APC: BTR-60 (CUP)";
        GVAR(createVic) = "CUP_O_BTR60_SLA";
    };
    class GVAR(east_cupMTLB): GVAR(east_rifleman) {
        displayName = "APC: MTLB (CUP)";
        GVAR(createVic) = "CUP_O_MTLB_pk_WDL_RU";
    };
    class GVAR(east_rhsBTR70): GVAR(east_rifleman) {
        displayName = "APC: BTR-70 (RHS)";
        GVAR(createVic) = "rhs_btr70_msv";
    };
    class GVAR(east_rhsBTR80): GVAR(east_rifleman) {
        displayName = "APC: BTR-80 (RHS)";
        GVAR(createVic) = "rhs_btr80_msv";
    };
    class GVAR(east_carOffroad): GVAR(east_rifleman) {
        displayName = "Car: Offroad HMG (A3)";
        GVAR(createVic) = "O_G_Offroad_01_armed_F";
    };
    class GVAR(east_a3QilinHmg): GVAR(east_rifleman) {
        displayName = "Car: Qilin Minigun (A3)";
        GVAR(createVic) = "O_LSV_02_armed_F";
    };
    class GVAR(east_carModernGmg): GVAR(east_rifleman) {
        displayName = "Car: Punisher GMG (A3)";
        GVAR(createVic) = "O_MRAP_02_gmg_F";
    };
    class GVAR(east_carModernHmg): GVAR(east_rifleman) {
        displayName = "Car: Punisher HMG (A3)";
        GVAR(createVic) = "O_MRAP_02_hmg_F";
    };
    class GVAR(east_cupUazGmg): GVAR(east_rifleman) {
        displayName = "Car: UAZ GMG (CUP)";
        GVAR(createVic) = "CUP_O_UAZ_AGS30_RU";
    };
    class GVAR(east_cupUazHmg): GVAR(east_rifleman) {
        displayName = "Car: UAZ HMG (CUP)";
        GVAR(createVic) = "CUP_O_UAZ_MG_RU";
    };
    class GVAR(east_cupUazSpg): GVAR(east_rifleman) {
        displayName = "Car: UAZ SPG-9 (CUP)";
        GVAR(createVic) = "CUP_O_UAZ_SPG9_RU";
    };
    class GVAR(east_cupUazAtgm): GVAR(east_rifleman) {
        displayName = "Car: UAZ Metis (CUP)";
        GVAR(createVic) = "CUP_O_UAZ_METIS_RU";
    };
    class GVAR(east_rhsGazGmgMmg): GVAR(east_rifleman) {
        displayName = "Car: GAZ GMG/MMG (RHS)";
        GVAR(createVic) = "rhs_tigr_sts_msv";
    };
    class GVAR(east_cupVodnikMmg): GVAR(east_rifleman) {
        displayName = "Car: Vodnik MMG (CUP)";
        GVAR(createVic) = "CUP_O_GAZ_Vodnik_PK_RU";
    };
    class GVAR(east_cupVodnikGmgMmg): GVAR(east_rifleman) {
        displayName = "Car: Vodnik GMG/MMG (CUP)";
        GVAR(createVic) = "CUP_O_GAZ_Vodnik_AGS_RU";
    };
    class GVAR(east_cupBrdm): GVAR(east_rifleman) {
        displayName = "Car: BRDM-2 (CUP)";
        GVAR(createVic) = "CUP_O_BRDM2_SLA";
    };
    class GVAR(east_cupBrdmAtgm): GVAR(east_rifleman) {
        displayName = "Car: BRDM-2 Konkers (CUP)";
        GVAR(createVic) = "CUP_O_BRDM2_ATGM_SLA";
    };
    class GVAR(east_heliAttack): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Light): PO-30 Orca (A3)";
        GVAR(createVic) = "O_Heli_Light_02_v2_F";
    };
    class GVAR(east_rhsMi8): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Light): MI-8 (RHS)";
        GVAR(createVic) = "RHS_Mi8MTV3_vvs";
    };
    class GVAR(east_cupMi8): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Light): MI-8 (CUP)";
        GVAR(createVic) = "CUP_O_Mi8_RU";
    };
    class GVAR(east_cupMi24): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Heavy): MI-24P Hind (CUP)";
        GVAR(createVic) = "CUP_O_Mi24_P_RU";
    };
    class GVAR(east_rhsMi28): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Heavy): MI-28 Havok (RHS)";
        GVAR(createVic) = "rhs_mi28n_vvs";
    };
    class GVAR(east_heliAttackHeavy): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Heavy): Mi-48 Kajman (A3)";
        GVAR(createVic) = "O_Heli_Attack_02_F";
    };
    class GVAR(east_cupKa50): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Heavy): Ka-50 (CUP)";
        GVAR(createVic) = "CUP_O_Ka50_RU";
    };
    class GVAR(east_rhsKa52): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Heavy): Ka-52 (RHS)";
        GVAR(createVic) = "RHS_Ka52_vvsc";
    };
    class GVAR(east_cupKa52): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Heavy): Ka-52 (CUP)";
        GVAR(createVic) = "CUP_O_Ka52_RU";
    };
    class GVAR(east_ifvModern): GVAR(east_rifleman) {
        displayName = "IFV: BM-2T Stalker (A3)";
        GVAR(createVic) = "O_APC_Tracked_02_cannon_F";
    };
    class GVAR(east_rhsBTR80A): GVAR(east_rifleman) {
        displayName = "IFV: BTR-80A (RHS)";
        GVAR(createVic) = "rhs_btr80a_msv";
    };
    class GVAR(east_cupBTR90): GVAR(east_rifleman) {
        displayName = "IFV: BTR-90 (CUP)";
        GVAR(createVic) = "CUP_O_BTR90_RU";
    };
    class GVAR(east_rhsBmd1): GVAR(east_rifleman) {
        displayName = "IFV: BMD-1P (RHS)";
        GVAR(createVic) = "rhs_bmd1p";
    };
    class GVAR(east_rhsBmd2): GVAR(east_rifleman) {
        displayName = "IFV: BMD-2 (RHS)";
        GVAR(createVic) = "rhs_bmd2";
    };
    class GVAR(east_rhsBmd4): GVAR(east_rifleman) {
        displayName = "IFV: BMD-4M (RHS)";
        GVAR(createVic) = "rhs_bmd4ma_vdv";
    };
    class GVAR(east_rhsBmp1): GVAR(east_rifleman) {
        displayName = "IFV: BMP-1P (RHS)";
        GVAR(createVic) = "rhs_bmp1p_vdv";
    };
    class GVAR(east_rhsBmp2): GVAR(east_rifleman) {
        displayName = "IFV: BMP-2D (RHS)";
        GVAR(createVic) = "rhs_bmp2d_vdv";
    };
    class GVAR(east_cupBmp2): GVAR(east_rifleman) {
        displayName = "IFV: BMP-2 (CUP)";
        GVAR(createVic) = "CUP_I_BMP2_NAPA";
    };
    class GVAR(east_rhsBmp3): GVAR(east_rifleman) {
        displayName = "IFV: BMP-3 (RHS)";
        GVAR(createVic) = "rhs_bmp3mera_msv";
    };
    class GVAR(east_cupBmp3): GVAR(east_rifleman) {
        displayName = "IFV: BMP-3 (CUP)";
        GVAR(createVic) = "CUP_O_BMP3_RU";
    };
    class GVAR(east_rhsSprut): GVAR(east_rifleman) {
        displayName = "Tank: 2S25 Sprut (RHS)";
        GVAR(createVic) = "rhs_sprut_vdv";
    };
    class GVAR(east_cupT55): GVAR(east_rifleman) {
        displayName = "Tank: T-55 (CUP)";
        GVAR(createVic) = "CUP_O_T55_SLA";
    };
    class GVAR(east_rhsT72): GVAR(east_rifleman) {
        displayName = "Tank: T-72B (RHS)";
        GVAR(createVic) = "rhs_t72bb_tv";
    };
    class GVAR(east_cupT72): GVAR(east_rifleman) {
        displayName = "Tank: T-72 (CUP)";
        GVAR(createVic) = "CUP_O_T72_SLA";
    };
    class GVAR(east_rhsT80): GVAR(east_rifleman) {
        displayName = "Tank: T-80UE (RHS)";
        GVAR(createVic) = "rhs_t80ue1";
    };
    class GVAR(east_rhsT90): GVAR(east_rifleman) {
        displayName = "Tank: T-90A (RHS)";
        GVAR(createVic) = "rhs_t90a_tv";
    };
    class GVAR(east_cupT90): GVAR(east_rifleman) {
        displayName = "Tank: T-90 (CUP)";
        GVAR(createVic) = "CUP_O_T90_RU";
    };
    class GVAR(east_tankModern): GVAR(east_rifleman) {
        displayName = "Tank: T-100 (A3)";
        GVAR(createVic) = "O_MBT_02_cannon_F";
    };
    class GVAR(east_dismounts): GVAR(east_rifleman) {
        curatorCanAttach = 1;
        scope = 1;
        displayName = "#Dismounts (6) [attach]";
        portrait = "\A3\Air_F_Beta\Parachute_01\Data\UI\Portrait_Parachute_01_CA.paa";
        GVAR(createUnits)[] = {"potato_e_sl","potato_e_ar","potato_e_lat","potato_e_rifleman","potato_e_rifleman_02","potato_e_rifleman_03"};
    };

    //------------ West ----------
    class GVAR(west_rifleman): GVAR(base_prebuilt) {
        scope = 2;
        scopeCurator = 2;
        displayName = "@Rifleman";
        category = QGVAR(west);
        GVAR(crewAir) = "potato_w_pilot";
        GVAR(crewArmor)= "potato_w_vicc";
        GVAR(createUnits)[] = {"potato_w_rifleman"};
    };
    class GVAR(west_ftl): GVAR(west_rifleman) {
        displayName = "@FTL";
        GVAR(createUnits)[] = {"potato_w_ftl"};
    };
    class GVAR(west_ar): GVAR(west_rifleman) {
        displayName = "@AR";
        GVAR(createUnits)[] = {"potato_w_ar"};
    };
    class GVAR(west_rat): GVAR(west_rifleman) {
        displayName = "@RAT";
        GVAR(createUnits)[] = {"potato_w_lat"};
    };
    class GVAR(west_manpad): GVAR(west_rifleman) {
        displayName = "@MANPAD";
        GVAR(createUnits)[] = {"potato_w_msamg"};
    };
    class GVAR(west_manpadTeam): GVAR(west_rifleman) {
        displayName = "#MANPAD Team (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_w_msamg","potato_w_msamag"};
    };
    class GVAR(west_matTeam): GVAR(west_rifleman) {
        displayName = "#MAT Team (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_w_matg","potato_w_matag"};
    };
    class GVAR(west_mmgTeam): GVAR(west_rifleman) {
        displayName = "#MMG Team (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_w_mmgg","potato_w_mmgag"};
    };
    class GVAR(west_patrol): GVAR(west_rifleman) {
        displayName = "#Patrol (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_w_rifleman","potato_w_rifleman_02"};
    };
    class GVAR(west_fireteam): GVAR(west_rifleman) {
        displayName = "#Fireteam (4)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_w_ftl","potato_w_ar","potato_w_rifleman","potato_w_lat"};
    };
    class GVAR(west_squad): GVAR(west_rifleman) {
        displayName = "#Squad (8)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_w_sl","potato_w_ftl","potato_w_ar","potato_w_ar","potato_w_lat","potato_w_rifleman","potato_w_rifleman_02","potato_w_rifleman_03"};
    };
    class GVAR(west_cupAvenger): GVAR(west_rifleman) {
        displayName = "AA: Avenger (CUP)";
        GVAR(createVic) = "CUP_B_HMMWV_Avenger_USMC";
    };
    class GVAR(west_cupVADS): GVAR(west_rifleman) {
        displayName = "AA: VADS (CUP)";
        GVAR(createVic) = "CUP_B_M163_USA";
    };
    class GVAR(west_aaModern): GVAR(west_rifleman) {
        displayName = "AA: Bardelas (A3)";
        GVAR(createVic) = "B_APC_Tracked_01_AA_F";
    };
    class GVAR(west_cupLinebackerD): GVAR(west_rifleman) {
        displayName = "AA: M6A2 Linebacker (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_M6LineBacker_USA_D";
    };
    class GVAR(west_cupLinebackerW): GVAR(west_rifleman) {
        displayName = "AA: M6A2 Linebacker (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_M6LineBacker_USA_W";
    };
    class GVAR(west_cupM113HmgW): GVAR(west_rifleman) {
        displayName = "APC: M113 HMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_M113_USA";
    };
    class GVAR(west_cupFV432HmgD): GVAR(west_rifleman) {
        displayName = "APC: FV432 Bulldog HMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_FV432_Bulldog_GB_D_RWS";
    };
    class GVAR(west_cupFV432MmgD): GVAR(west_rifleman) {
        displayName = "APC: FV432 Bulldog MMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_FV432_Bulldog_GB_D";
    };
    class GVAR(west_cupFV432HmgW): GVAR(west_rifleman) {
        displayName = "APC: FV432 Bulldog HMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_FV432_Bulldog_GB_W_RWS";
    };
    class GVAR(west_cupFV432MmgW): GVAR(west_rifleman) {
        displayName = "APC: FV432 Bulldog MMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_FV432_Bulldog_GB_W";
    };
    class GVAR(west_apcModern): GVAR(west_rifleman) {
        displayName = "APC: Namer GMG/HMG (A3)";
        GVAR(createVic) = "B_APC_Tracked_01_rcws_F";
    };
    class GVAR(west_strykerGmgD): GVAR(west_rifleman) {
        displayName = "APC: Stryker GMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_M1126_ICV_MK19_Desert";
    };
    class GVAR(west_strykerHmgD): GVAR(west_rifleman) {
        displayName = "APC: Stryker HMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_M1126_ICV_M2_Desert";
    };
    class GVAR(west_strykerGmgW): GVAR(west_rifleman) {
        displayName = "APC: Stryker GMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_M1126_ICV_MK19_Woodland";
    };
    class GVAR(west_strykerHmgW): GVAR(west_rifleman) {
        displayName = "APC: Stryker HMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_M1126_ICV_M2_Woodland";
    };
    class GVAR(west_cupAAVPW): GVAR(west_rifleman) {
        displayName = "APC: AAVP (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_AAV_USMC";
    };
    class GVAR(west_a3ProwlerHmg): GVAR(west_rifleman) {
        displayName = "Car: Prowler HMG (A3)";
        GVAR(createVic) = "B_LSV_01_armed_F";
    };
    class GVAR(west_cupHmmwvAtgmD): GVAR(west_rifleman) {
        displayName = "Car: HMMWV TOW (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_HMMWV_TOW_USA";
    };
    class GVAR(west_cupHmmwvGmgD): GVAR(west_rifleman) {
        displayName = "Car: HMMWV GMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_HMMWV_MK19_USA";
    };
    class GVAR(west_cupHmmwvHmgD): GVAR(west_rifleman) {
        displayName = "Car: HMMWV HMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_HMMWV_M2_USA";
    };
    class GVAR(west_cupHmmwvAtgmW): GVAR(west_rifleman) {
        displayName = "Car: HMMWV TOW (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_HMMWV_TOW_USMC";
    };
    class GVAR(west_cupHmmwvGmgW): GVAR(west_rifleman) {
        displayName = "Car: HMMWV GMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_HMMWV_MK19_USMC";
    };
    class GVAR(west_cupHmmwvHmgW): GVAR(west_rifleman) {
        displayName = "Car: HMMWV HMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_HMMWV_M2_USMC";
    };
    class GVAR(west_cupLandRoverGmgD): GVAR(west_rifleman) {
        displayName = "Car: Land Rover GMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_LR_Special_GMG_GB_D";
    };
    class GVAR(west_cupLandRoverHmgD): GVAR(west_rifleman) {
        displayName = "Car: Land Rover HMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_LR_Special_M2_GB_D";
    };
    class GVAR(west_cupLandRoverGmgW): GVAR(west_rifleman) {
        displayName = "Car: Land Rover GMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_LR_Special_GMG_GB_W";
    };
    class GVAR(west_cupLandRoverHmgW): GVAR(west_rifleman) {
        displayName = "Car: Land Rover HMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_LR_Special_M2_GB_W";
    };
    class GVAR(west_cupJackalGmgD): GVAR(west_rifleman) {
        displayName = "Car: MWMIK Jackal GMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_Jackal2_GMG_GB_D";
    };
    class GVAR(west_cupJackalHmgD): GVAR(west_rifleman) {
        displayName = "Car: MWMIK Jackal HMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_Jackal2_L2A1_GB_D";
    };
    class GVAR(west_cupJackalGmgW): GVAR(west_rifleman) {
        displayName = "Car: MWMIK Jackal GMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_Jackal2_GMG_GB_W";
    };
    class GVAR(west_cupJackalHmgW): GVAR(west_rifleman) {
        displayName = "Car: MWMIK Jackal HMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_Jackal2_L2A1_GB_W";
    };
    class GVAR(west_cupCoyoteGmgD): GVAR(west_rifleman) {
        displayName = "Car: TSV Coyote GMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_BAF_Coyote_GMG_D";
    };
    class GVAR(west_cupCoyoteHmgD): GVAR(west_rifleman) {
        displayName = "Car: TSV Coyote HMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_BAF_Coyote_L2A1_D";
    };
    class GVAR(west_cupCoyoteGmgW): GVAR(west_rifleman) {
        displayName = "Car: TSV Coyote GMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_BAF_Coyote_GMG_W";
    };
    class GVAR(west_cupCoyoteHmgW): GVAR(west_rifleman) {
        displayName = "Car: TSV Coyote HMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_BAF_Coyote_L2A1_W";
    };
    class GVAR(west_cupRG31GmgD): GVAR(west_rifleman) {
        displayName = "Car: RG-31 Nyala GMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_RG31_Mk19_USMC";
    };
    class GVAR(west_cupRG31HmgD): GVAR(west_rifleman) {
        displayName = "Car: RG-31 Nyala HMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_RG31_M2_USMC";
    };
    class GVAR(west_cupRG31GmgW): GVAR(west_rifleman) {
        displayName = "Car: RG-31 Nyala GMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_RG31_Mk19_OD_USMC";
    };
    class GVAR(west_cupRG31HmgW): GVAR(west_rifleman) {
        displayName = "Car: RG-31 Nyala HMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_RG31_M2_OD_USMC";
    };
    class GVAR(west_carModernGmg): GVAR(west_rifleman) {
        displayName = "Car: M-ATV GMG (A3)";
        GVAR(createVic) = "B_MRAP_01_gmg_F";
    };
    class GVAR(west_carModernHmg): GVAR(west_rifleman) {
        displayName = "Car: M-ATV HMG (A3)";
        GVAR(createVic) = "B_MRAP_01_hmg_F";
    };
    class GVAR(west_carOffroad): GVAR(west_rifleman) {
        displayName = "Car: Offroad HMG (A3)";
        GVAR(createVic) = "B_G_Offroad_01_armed_F";
    };
    class GVAR(west_heliAttackHeavy): GVAR(west_rifleman) {
        displayName = "Heli-Attack (Heavy): RAH-66 Comanche (A3)";
        GVAR(createVic) = "B_Heli_Attack_01_F";
    };
    class GVAR(west_cupHeliAttackHeavy): GVAR(west_rifleman) {
        displayName = "Heli-Attack (Heavy): AH-1Z Viper (CUP)";
        GVAR(createVic) = "CUP_B_AH1Z_USMC";
    };
    class GVAR(west_cupAH64): GVAR(west_rifleman) {
        displayName = "Heli-Attack (Heavy): AH-64D Apache (CUP)";
        GVAR(createVic) = "CUP_B_AH64D_USA";
    };
    class GVAR(west_heliAttack): GVAR(west_rifleman) {
        displayName = "Heli-Attack (Light): AH-9 Littlebird (A3)";
        GVAR(createVic) = "B_Heli_Light_01_armed_F";
    };
    class GVAR(west_cupHeliAttack): GVAR(west_rifleman) {
        displayName = "Heli-Attack (Light): AH-6 Littlebird (CUP)";
        GVAR(createVic) = "CUP_B_AH6J_Escort_USA";
    };
    class GVAR(west_a3Wildcat): GVAR(west_rifleman) {
        displayName = "Heli-Attack (Light): AW-159 Wildcat (A3)";
        GVAR(createVic) = "I_Heli_light_03_F";
    };
    class GVAR(west_cupWildcat): GVAR(west_rifleman) {
        displayName = "Heli-Attack (Light): AW-159 Wildcat (CUP)";
        GVAR(createVic) = "CUP_B_AW159_Cannon_GB";
    };
    class GVAR(west_cupWarriorD): GVAR(west_rifleman) {
        displayName = "IFV: FV510 Warrior (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_FV510_GB_D_SLAT";
    };
    class GVAR(west_cupWarriorW): GVAR(west_rifleman) {
        displayName = "IFV: FV510 Warrior (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_FV510_GB_W_SLAT";
    };
    class GVAR(west_cupLAVD): GVAR(west_rifleman) {
        displayName = "IFV: LAV-25 (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_LAV25M240_desert_USMC";
    };
    class GVAR(west_cupLAVW): GVAR(west_rifleman) {
        displayName = "IFV: LAV-25 (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_LAV25M240_USMC";
    };
    class GVAR(west_cupBradleyD): GVAR(west_rifleman) {
        displayName = "IFV: M2A2 Bradley (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_M2Bradley_USA_D";
    };
    class GVAR(west_cupBradleyW): GVAR(west_rifleman) {
        displayName = "IFV: M2A2 Bradley (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_M2Bradley_USA_W";
    };
    class GVAR(west_ifvModern): GVAR(west_rifleman) {
        displayName = "IFV: Marshall (A3)";
        GVAR(createVic) = "B_APC_Wheeled_01_cannon_F";
    };
    class GVAR(west_cupM1A1D): GVAR(west_rifleman) {
        displayName = "Tank: M1A1 (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_M1A1_DES_US_Army";
    };
    class GVAR(west_cupM1A1W): GVAR(west_rifleman) {
        displayName = "Tank: M1A1 (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_M1A1_Woodland_US_Army";
    };
    class GVAR(west_cupChallengerD): GVAR(west_rifleman) {
        displayName = "Tank: FV4034 Challenger 2 (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_Challenger2_Desert_BAF";
    };
    class GVAR(west_cupChallengerW): GVAR(west_rifleman) {
        displayName = "Tank: FV4034 Challenger 2 (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_Challenger2_Woodland_BAF";
    };
    class GVAR(west_tankModern): GVAR(west_rifleman) {
        displayName = "Tank: Merkava TUSK (A3)";
        GVAR(createVic) = "B_MBT_01_TUSK_F";
    };
    class GVAR(west_dismounts): GVAR(west_rifleman) {
        curatorCanAttach = 1;
        scope = 1;
        displayName = "#Dismounts (6) [attach]";
        portrait = "\A3\Air_F_Beta\Parachute_01\Data\UI\Portrait_Parachute_01_CA.paa";
        GVAR(createUnits)[] = {"potato_w_sl","potato_w_ar","potato_w_lat","potato_w_rifleman","potato_w_rifleman_02","potato_w_rifleman_03"};
    };

    //------------ Independent ----------
    class GVAR(ind_rifleman): GVAR(base_prebuilt) {
        scope = 2;
        scopeCurator = 2;
        displayName = "@Rifleman";
        category = QGVAR(ind);
        GVAR(crewAir) = "potato_i_pilot";
        GVAR(crewArmor)= "potato_i_vicc";
        GVAR(createUnits)[] = {"potato_i_rifleman"};
    };
    class GVAR(ind_ftl): GVAR(ind_rifleman) {
        displayName = "@FTL";
        GVAR(createUnits)[] = {"potato_i_ftl"};
    };
    class GVAR(ind_ar): GVAR(ind_rifleman) {
        displayName = "@AR";
        GVAR(createUnits)[] = {"potato_i_ar"};
    };
    class GVAR(ind_rat): GVAR(ind_rifleman) {
        displayName = "@RAT";
        GVAR(createUnits)[] = {"potato_i_lat"};
    };
    class GVAR(ind_manpad): GVAR(ind_rifleman) {
        displayName = "@MANPAD";
        GVAR(createUnits)[] = {"potato_i_msamg"};
    };
    class GVAR(ind_manpadTeam): GVAR(ind_rifleman) {
        displayName = "#MANPAD Team (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_i_msamg","potato_i_msamag"};
    };
    class GVAR(ind_matTeam): GVAR(ind_rifleman) {
        displayName = "#MAT Team (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_i_matg","potato_i_matag"};
    };
    class GVAR(ind_mmgTeam): GVAR(ind_rifleman) {
        displayName = "#MMG Team (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_i_mmgg","potato_i_mmgag"};
    };
    class GVAR(ind_patrol): GVAR(ind_rifleman) {
        displayName = "#Patrol (2)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_i_rifleman","potato_i_rifleman_02"};
    };
    class GVAR(ind_fireteam): GVAR(ind_rifleman) {
        displayName = "#Fireteam (4)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_i_ftl","potato_i_ar","potato_i_rifleman","potato_i_lat"};
    };
    class GVAR(ind_squad): GVAR(ind_rifleman) {
        displayName = "#Squad (8)";
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(createUnits)[] = {"potato_i_sl","potato_i_ftl","potato_i_ar","potato_i_ar","potato_i_lat","potato_i_rifleman","potato_i_rifleman_02","potato_i_rifleman_03"};
    };
    class GVAR(ind_rhsZsu): GVAR(ind_rifleman) {
        displayName = "AA: ZSU 23 Shilka (RHS)";
        GVAR(createVic) = "rhs_zsu234_aa";
    };
    class GVAR(ind_cupZsu): GVAR(ind_rifleman) {
        displayName = "AA: ZSU 23 Shilka (CUP)";
        GVAR(createVic) = "CUP_B_ZSU23_CDF";
    };
    class GVAR(ind_cupBTR40): GVAR(ind_rifleman) {
        displayName = "APC: BTR-40 (CUP)";
        GVAR(createVic) = "CUP_I_BTR40_MG_TKG";
    };
    class GVAR(ind_cupBTR60): GVAR(ind_rifleman) {
        displayName = "APC: BTR-60 (CUP)";
        GVAR(createVic) = "CUP_B_BTR60_CDF";
    };
    class GVAR(ind_technical): GVAR(ind_rifleman) {
        displayName = "Car: Offroad HMG (A3)";
        GVAR(createVic) = "I_G_Offroad_01_armed_F";
    };
    class GVAR(ind_cupUazGmg): GVAR(ind_rifleman) {
        displayName = "Car: UAZ GMG (CUP)";
        GVAR(createVic) = "CUP_O_UAZ_AGS30_CHDKZ";
    };
    class GVAR(ind_cupUazHmg): GVAR(ind_rifleman) {
        displayName = "Car: UAZ HMG (CUP)";
        GVAR(createVic) = "CUP_O_UAZ_MG_CHDKZ";
    };
    class GVAR(ind_cupUazSpg): GVAR(ind_rifleman) {
        displayName = "Car: UAZ SPG-9 (CUP)";
        GVAR(createVic) = "CUP_O_UAZ_SPG9_CHDKZ";
    };
    class GVAR(ind_cupUazAtgm): GVAR(ind_rifleman) {
        displayName = "Car: UAZ Metis (CUP)";
        GVAR(createVic) = "CUP_O_UAZ_METIS_CHDKZ";
    };
    class GVAR(ind_cupDatsunMmg): GVAR(ind_rifleman) {
        displayName = "Car: Datsun MMG (CUP)";
        GVAR(createVic) = "CUP_I_Datsun_PK_TK_Random";
    };
    class GVAR(ind_cupLandRoverHmg): GVAR(ind_rifleman) {
        displayName = "Car: Land Rover HMG (CUP)";
        GVAR(createVic) = "CUP_I_LR_MG_RACS";
    };
    class GVAR(ind_cupLandRoverSpg): GVAR(ind_rifleman) {
        displayName = "Car: Land Rover SPG-9 (CUP)";
        GVAR(createVic) = "CUP_O_LR_SPG9_TKA";
    };
    class GVAR(ind_cupSuvMinigun): GVAR(ind_rifleman) {
        displayName = "Car: SUV Minigun (CUP)";
        GVAR(createVic) = "CUP_I_SUV_Armored_ION";
    };
    class GVAR(ind_cupBrdm): GVAR(ind_rifleman) {
        displayName = "Car: BRDM-2 (CUP)";
        GVAR(createVic) = "CUP_B_BRDM2_CDF";
    };
    class GVAR(ind_cupBrdmAtgm): GVAR(ind_rifleman) {
        displayName = "Car: BRDM-2 Konkers (CUP)";
        GVAR(createVic) = "CUP_B_BRDM2_ATGM_CDF";
    };
    class GVAR(ind_carModernGmg): GVAR(ind_rifleman) {
        displayName = "Car: Fennek GMG (A3)";
        GVAR(createVic) = "I_MRAP_03_gmg_F";
    };
    class GVAR(ind_carModernHmg): GVAR(ind_rifleman) {
        displayName = "Car: Fennek HMG (A3)";
        GVAR(createVic) = "I_MRAP_03_hmg_F";
    };
    class GVAR(ind_cupDingoGmgD): GVAR(ind_rifleman) {
        displayName = "Car: Dingo 2 GMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_Dingo_GL_CZ_Des";
    };
    class GVAR(ind_cupDingoGmgW): GVAR(ind_rifleman) {
        displayName = "Car: Dingo 2 GMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_Dingo_GL_CZ_Wdl";
    };
    class GVAR(ind_cupDingoHmgD): GVAR(ind_rifleman) {
        displayName = "Car: Dingo 2 HMG (Desert) (CUP)";
        GVAR(createVic) = "CUP_B_Dingo_CZ_Des";
    };
    class GVAR(ind_cupDingoHmgW): GVAR(ind_rifleman) {
        displayName = "Car: Dingo 2 HMG (Woodland) (CUP)";
        GVAR(createVic) = "CUP_B_Dingo_CZ_Wdl";
    };
    class GVAR(ind_heliAttack): GVAR(ind_rifleman) {
        displayName = "Heli-Attack: Wildcat (A3)";
        GVAR(createVic) = "I_Heli_light_03_F";
    };
    class GVAR(ind_cupBmp): GVAR(ind_rifleman) {
        displayName = "IFV: BMP-1 (CUP)";
        GVAR(createVic) = "CUP_O_BMP1_TKA";
    };
    class GVAR(ind_ifvModern): GVAR(ind_rifleman) {
        displayName = "IFV: Warrior (A3)";
        GVAR(createVic) = "I_APC_tracked_03_cannon_F";
    };
    class GVAR(ind_ifvModern2): GVAR(ind_rifleman) {
        displayName = "IFV: Pandur II (A3)";
        GVAR(createVic) = "I_APC_Wheeled_03_cannon_F";
    };
    class GVAR(ind_cupT34): GVAR(ind_rifleman) {
        displayName = "Tank: T34 (CUP)";
        GVAR(createVic) = "CUP_O_T34_TKA";
    };
    class GVAR(ind_cupT55): GVAR(ind_rifleman) {
        displayName = "Tank: T55 (CUP)";
        GVAR(createVic) = "CUP_O_T55_TK";
    };
    class GVAR(ind_cupT72): GVAR(ind_rifleman) {
        displayName = "Tank: T72 (CUP)";
        GVAR(createVic) = "CUP_B_T72_CDF";
    };
    class GVAR(ind_tankModern): GVAR(ind_rifleman) {
        displayName = "Tank: Kuma (A3)";
        GVAR(createVic) = "I_MBT_03_cannon_F";
    };
    class GVAR(ind_dismounts): GVAR(ind_rifleman) {
        curatorCanAttach = 1;
        scope = 1;
        displayName = "#Dismounts (6) [attach]";
        portrait = "\A3\Air_F_Beta\Parachute_01\Data\UI\Portrait_Parachute_01_CA.paa";
        GVAR(createUnits)[] = {"potato_i_sl","potato_i_ar","potato_i_lat","potato_i_rifleman","potato_i_rifleman_02","potato_i_rifleman_03"};
    };

    //------------ Utility modules ----------
    class GVAR(ungarrison_nearest_group): GVAR(base_prebuilt) {
        scope = 1;
        scopeCurator = 2;
        displayName = "Ungarrison nearest group";
        category = QEGVAR(core,util);
        function = QFUNC(ungarrisonNearestGroupZeus);
    };
    class GVAR(ungarrison_all_groups): GVAR(ungarrison_nearest_group) {
        displayName = "Ungarrison all groups";
        function = QFUNC(ungarrisonAllGroupsZeus);
    };
    class GVAR(move_all_to_hc): GVAR(ungarrison_nearest_group) {
        displayName = "Move all AI to HC";
        function = QFUNC(transferAllToHCZeus);
    };

    //------------ Custom group/vehicle modules ----------
    class GVAR(build_a_group): GVAR(base_module) {
        isGlobal = 1;
        category = QGVAR(custom);
        scopeCurator = 2;
        displayName = "Build-a-Group";
        function = QFUNC(buildAGroupZeus);
    };
    class GVAR(spawn_a_vehicle): GVAR(build_a_group) {
        displayName = "Spawn-a-Vic";
        function = QFUNC(spawnAVicZeus);
    };
    class GVAR(garrison): GVAR(build_a_group) { //TODO: refactor this to be a lot more dynamic
        scope = 2;
        displayName = "Spawn and Garrison units";
        function = QFUNC(garrisonModule);
        isTriggerActivated = 1;

        class Attributes {
            class GVAR(garrisonFaction) {
                displayName = "Faction";
                tooltip = "Faction of the units to garrison with";
                property = QGVAR(garrisonFaction);
                control = "Combo";
                expression = "_this setVariable [""%s"",_value];";

                class values {
                    class 1 { name = "NATO"; value = "potato_w"; default = 1; };
                    class 2 { name = "AAF"; value = "potato_i"; };
                    class 3 { name = "CSAT"; value = "potato_e"; };
                };

                typeName = "STRING";
            };
            class GVAR(garrisonChance) {
                displayName = "Garrison Chance";
                tooltip = "Chance a building in the radius will be garrisoned";
                property = QGVAR(garrisonChance);
                control = "Slider";
                expression = "_this setVariable [""%s"",_value * 100];";
                defaultValue = "0.5";
                validate = "number";
            };
            class GVAR(garrisonRadius) {
                displayName = "Radius";
                tooltip = "Radius from placed module to garrison";
                property = QGVAR(garrisonRadius);
                control = "Edit";
                expression = "_this setVariable [""%s"",_value];";
                defaultValue = "500";
                validate = "number";
                typeName = "NUMBER";
            };
            class GVAR(garrisonMin) {
                displayName = "Min Units";
                tooltip = "Minimum units to garrison with";
                property = QGVAR(garrisonMin);
                control = "Combo";
                expression = "_this setVariable [""%s"",_value];";

                class values {
                    class 1 { name = "1"; value = 1; default = 1; };
                    class 2 { name = "2"; value = 2; };
                    class 3 { name = "3"; value = 3; };
                    class 4 { name = "4"; value = 4; };
                    class 5 { name = "5"; value = 5; };
                    class 6 { name = "6"; value = 6; };
                    class 7 { name = "7"; value = 7; };
                    class 8 { name = "8"; value = 8; };
                    class 9 { name = "9"; value = 9; };
                    class 10 { name = "10"; value = 10; };
                };

                validate = "number";
                typeName = "NUMBER";
            };
            class GVAR(garrisonMax): GVAR(garrisonMin) {
                displayName = "Max Units";
                tooltip = "Maximum units to garrison with";
                property = QGVAR(garrisonMax);
            };
        };
    };
};

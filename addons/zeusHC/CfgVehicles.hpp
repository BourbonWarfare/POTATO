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
        GVAR(crewAir) = "O_Helipilot_F";
        GVAR(crewArmor)= "O_crew_F";
        GVAR(createUnits)[] = {"O_soldier_F"};
    };
    class GVAR(east_ftl): GVAR(east_rifleman) {
        displayName = "@FTL";
        GVAR(createUnits)[] = {"O_soldier_TL_F"};
    };
    class GVAR(east_ar): GVAR(east_rifleman) {
        displayName = "@AR";
        GVAR(createUnits)[] = {"O_soldier_AR_F"};
    };
    class GVAR(east_rat): GVAR(east_rifleman) {
        displayName = "@RAT";
        GVAR(createUnits)[] = {"O_Soldier_LAT_F"};
    };
    class GVAR(east_manpad): GVAR(east_rifleman) {
        displayName = "@MANPAD";
        GVAR(createUnits)[] = {"O_soldier_AA_F"};
    };
    class GVAR(east_manpadTeam): GVAR(east_rifleman) {
        displayName = "#MANPAD Team (2)";
        GVAR(createUnits)[] = {"O_soldier_AA_F","O_soldier_AAA_F"};
    };
    class GVAR(east_matTeam): GVAR(east_rifleman) {
        displayName = "#MAT Team (2)";
        GVAR(createUnits)[] = {"O_soldier_AT_F","O_soldier_AAT_F"};
    };
    class GVAR(east_patrol): GVAR(east_rifleman) {
        displayName = "#Patrol (2)";
        GVAR(createUnits)[] = {"O_soldier_F","O_soldier_F"};
    };
    class GVAR(east_fireteam): GVAR(east_rifleman) {
        displayName = "#Fireteam (4)";
        GVAR(createUnits)[] = {"O_soldier_TL_F","O_soldier_AR_F","O_soldier_F","O_Soldier_LAT_F"};
    };
    class GVAR(east_squad): GVAR(east_rifleman) {
        displayName = "#Squad (8)";
        GVAR(createUnits)[] = {"O_soldier_SL_F","O_soldier_TL_F","O_soldier_AR_F","O_soldier_AR_F","O_soldier_LAT_F","O_soldier_F","O_soldier_F","O_soldier_F"};
    };
    class GVAR(east_aaModern): GVAR(east_rifleman) {
        displayName = "AA: Tigris (A3)";
        GVAR(createVic) = "O_APC_Tracked_02_AA_F";
    };
    class GVAR(east_rhsZsu): GVAR(east_rifleman) {
        displayName = "AA: ZSU 23 Shilka (RHS)";
        GVAR(createVic) = "rhs_zsu234_aa";
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
    class GVAR(east_cupBrdm): GVAR(east_rifleman) {
        displayName = "Car: BRDM-2 (CUP)";
        GVAR(createVic) = "CUP_O_BRDM2_RUS";
    };
    class GVAR(east_cupBrdmAtgm): GVAR(east_rifleman) {
        displayName = "Car: BRDM-2 Konkers (CUP)";
        GVAR(createVic) = "CUP_O_BRDM2_ATGM_RUS";
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
    class GVAR(east_heliAttackHeavy): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Heavy): Mi-48 Kajman (A3)";
        GVAR(createVic) = "O_Heli_Attack_02_F";
    };
    class GVAR(east_rhsMi24): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Heavy): MI-24V (RHS)";
        GVAR(createVic) = "RHS_Mi24V_vvsc";
    };
    class GVAR(east_cupMi24): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Heavy): MI-24P (CUP)";
        GVAR(createVic) = "CUP_O_Mi24_P_RU";
    };
    class GVAR(east_cupKa50): GVAR(east_rifleman) {
        displayName = "Heli-Attack (Heavy): Ka-50 (CUP)";
        GVAR(createVic) = "CUP_O_Ka50_RU";
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
        GVAR(createVic) = "CUP_O_BMP2_RU";
    };
    class GVAR(east_rhsBmp3): GVAR(east_rifleman) {
        displayName = "IFV: BMP-3 (RHS)";
        GVAR(createVic) = "rhs_bmp3mera_msv";
    };
    class GVAR(east_cupBmp3): GVAR(east_rifleman) {
        displayName = "IFV: BMP-3 (CUP)";
        GVAR(createVic) = "CUP_O_BMP3_RU";
    };
    class GVAR(east_rhsT72): GVAR(east_rifleman) {
        displayName = "Tank: T-72B (RHS)";
        GVAR(createVic) = "rhs_t72bb_tv";
    };
    class GVAR(east_cupT72): GVAR(east_rifleman) {
        displayName = "Tank: T-72 (CUP)";
        GVAR(createVic) = "CUP_O_T72_RU";
    };
    class GVAR(east_rhsT80): GVAR(east_rifleman) {
        displayName = "Tank: T-80U (CUP)";
        GVAR(createVic) = "rhs_t80u";
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
        GVAR(createUnits)[] = {"O_soldier_SL_F","O_soldier_AR_F","O_soldier_LAT_F","O_soldier_F","O_soldier_F","O_soldier_F"};
    };

    //------------ West ----------
    class GVAR(west_rifleman): GVAR(base_prebuilt) {
        scope = 2;
        scopeCurator = 2;
        displayName = "@Rifleman";
        category = QGVAR(west);
        GVAR(crewAir) = "B_Helipilot_F";
        GVAR(crewArmor)= "B_crew_F";
        GVAR(createUnits)[] = {"B_soldier_F"};
    };
    class GVAR(west_ftl): GVAR(west_rifleman) {
        displayName = "@FTL";
        GVAR(createUnits)[] = {"B_soldier_TL_F"};
    };
    class GVAR(west_ar): GVAR(west_rifleman) {
        displayName = "@AR";
        GVAR(createUnits)[] = {"B_soldier_AR_F"};
    };
    class GVAR(west_rat): GVAR(west_rifleman) {
        displayName = "@RAT";
        GVAR(createUnits)[] = {"B_Soldier_LAT_F"};
    };
    class GVAR(west_manpad): GVAR(west_rifleman) {
        displayName = "@MANPAD";
        GVAR(createUnits)[] = {"B_soldier_AA_F"};
    };
    class GVAR(west_manpadTeam): GVAR(west_rifleman) {
        displayName = "#MANPAD Team (2)";
        GVAR(createUnits)[] = {"B_soldier_AA_F","B_soldier_AAA_F"};
    };
    class GVAR(west_matTeam): GVAR(west_rifleman) {
        displayName = "#MAT Team (2)";
        GVAR(createUnits)[] = {"B_soldier_AT_F","B_soldier_AAT_F"};
    };
    class GVAR(west_patrol): GVAR(west_rifleman) {
        displayName = "#Patrol (2)";
        GVAR(createUnits)[] = {"B_soldier_F","B_soldier_F"};
    };
    class GVAR(west_fireteam): GVAR(west_rifleman) {
        displayName = "#Fireteam (4)";
        GVAR(createUnits)[] = {"B_soldier_TL_F","B_soldier_AR_F","B_soldier_F","B_soldier_LAT_F"};
    };
    class GVAR(west_squad): GVAR(west_rifleman) {
        displayName = "#Squad (8)";
        GVAR(createUnits)[] = {"B_soldier_SL_F","B_soldier_TL_F","B_soldier_AR_F","B_soldier_AR_F","B_soldier_LAT_F","B_soldier_F","B_soldier_F","B_soldier_F"};
    };
    class GVAR(west_aaModern): GVAR(west_rifleman) {
        displayName = "AA: Bardelas";
        GVAR(createVic) = "B_APC_Tracked_01_AA_F";
    };
    class GVAR(west_rhsLinebackerD): GVAR(west_rifleman) {
        displayName = "AA: M6A2 Linebacker (Desert)";
        GVAR(createVic) = "RHS_M6";
    };
    class GVAR(west_rhsLinebackerW): GVAR(west_rifleman) {
        displayName = "AA: M6A2 Linebacker (Woodland)";
        GVAR(createVic) = "RHS_M6_wd";
    };
    class GVAR(west_rhsM113GmgD): GVAR(west_rifleman) {
        displayName = "APC: M113 GMG (Desert)";
        GVAR(createVic) = "rhsusf_m113d_usarmy_MK19";
    };
    class GVAR(west_rhsM113HmgD): GVAR(west_rifleman) {
        displayName = "APC: M113 HMG (Desert)";
        GVAR(createVic) = "rhsusf_m113d_usarmy";
    };
    class GVAR(west_rhsM113GmgW): GVAR(west_rifleman) {
        displayName = "APC: M113 GMG (Woodland)";
        GVAR(createVic) = "rhsusf_m113_usarmy_MK19";
    };
    class GVAR(west_rhsM113HmgW): GVAR(west_rifleman) {
        displayName = "APC: M113 HMG (Woodland)";
        GVAR(createVic) = "rhsusf_m113_usarmy";
    };
    class GVAR(west_apcModern): GVAR(west_rifleman) {
        displayName = "APC: Namer GMG/HMG";
        GVAR(createVic) = "B_APC_Tracked_01_rcws_F";
    };
    class GVAR(west_strykerGmgD): GVAR(west_rifleman) {
        displayName = "APC: Stryker GMG (Desert)";
        GVAR(createVic) = "CUP_B_M1126_ICV_MK19_Desert";
    };
    class GVAR(west_strykerHmgD): GVAR(west_rifleman) {
        displayName = "APC: Stryker HMG (Desert)";
        GVAR(createVic) = "CUP_B_M1126_ICV_M2_Desert";
    };
    class GVAR(west_strykerGmgW): GVAR(west_rifleman) {
        displayName = "APC: Stryker GMG (Woodland)";
        GVAR(createVic) = "CUP_B_M1126_ICV_MK19_Woodland";
    };
    class GVAR(west_strykerHmgW): GVAR(west_rifleman) {
        displayName = "APC: Stryker HMG (Woodland)";
        GVAR(createVic) = "CUP_B_M1126_ICV_M2_Woodland";
    };
    class GVAR(west_rhsHmmwvGmgD): GVAR(west_rifleman) {
        displayName = "Car: HMMWV GMG (Desert)";
        GVAR(createVic) = "rhsusf_m1025_d_mk19";
    };
    class GVAR(west_rhsHmmwvHmgD): GVAR(west_rifleman) {
        displayName = "Car: HMMWV HMG (Desert)";
        GVAR(createVic) = "rhsusf_m1025_d_m2";
    };
    class GVAR(west_rhsHmmwvGmgW): GVAR(west_rifleman) {
        displayName = "Car: HMMWV GMG (Woodland)";
        GVAR(createVic) = "rhsusf_m1025_w_mk19";
    };
    class GVAR(west_rhsHmmwvHmgW): GVAR(west_rifleman) {
        displayName = "Car: HMMWV HMG (Woodland)";
        GVAR(createVic) = "rhsusf_m1025_w_m2";
    };
    class GVAR(west_carModernGmg): GVAR(west_rifleman) {
        displayName = "Car: M-ATV GMG";
        GVAR(createVic) = "B_MRAP_01_gmg_F";
    };
    class GVAR(west_carModernHmg): GVAR(west_rifleman) {
        displayName = "Car: M-ATV HMG";
        GVAR(createVic) = "B_MRAP_01_hmg_F";
    };
    class GVAR(west_carOffroad): GVAR(west_rifleman) {
        displayName = "Car: Offroad HMG";
        GVAR(createVic) = "B_G_Offroad_01_armed_F";
    };
    class GVAR(west_heliAttackHeavy): GVAR(west_rifleman) {
        displayName = "Heli-Attack (Heavy): AH-1Z Viper";
        GVAR(createVic) = "RHS_AH1Z";
    };
    class GVAR(west_heliAttack): GVAR(west_rifleman) {
        displayName = "Heli-Attack (Light): AH-9 Littlebird";
        GVAR(createVic) = "B_Heli_Light_01_armed_F";
    };
    class GVAR(west_rhsBradleyD): GVAR(west_rifleman) {
        displayName = "IFV: M2A2 Bradley (Desert)";
        GVAR(createVic) = "RHS_M2A2";
    };
    class GVAR(west_rhsBradleyW): GVAR(west_rifleman) {
        displayName = "IFV: M2A2 Bradley (Woodland)";
        GVAR(createVic) = "RHS_M2A2_wd";
    };
    class GVAR(west_ifvModern): GVAR(west_rifleman) {
        displayName = "IFV: Marshall";
        GVAR(createVic) = "B_APC_Wheeled_01_cannon_F";
    };
    class GVAR(west_rhsM1A1D): GVAR(west_rifleman) {
        displayName = "Tank: M1A1 (Desert)";
        GVAR(createVic) = "rhsusf_m1a1aimd_usarmy";
    };
    class GVAR(west_rhsM1A1W): GVAR(west_rifleman) {
        displayName = "Tank: M1A1 (Woodland)";
        GVAR(createVic) = "rhsusf_m1a1aimwd_usarmy";
    };
    class GVAR(west_tankModern): GVAR(west_rifleman) {
        displayName = "Tank: Merkava TUSK";
        GVAR(createVic) = "B_MBT_01_TUSK_F";
    };
    class GVAR(west_dismounts): GVAR(west_rifleman) {
        curatorCanAttach = 1;
        scope = 1;
        displayName = "#Dismounts (6) [attach]";
        portrait = "\A3\Air_F_Beta\Parachute_01\Data\UI\Portrait_Parachute_01_CA.paa";
        GVAR(createUnits)[] = {"B_soldier_SL_F","B_soldier_AR_F","B_soldier_LAT_F","B_soldier_F","B_soldier_F","B_soldier_F"};
    };

    //------------ Independent ----------
    class GVAR(ind_rifleman): GVAR(base_prebuilt) {
        scope = 2;
        scopeCurator = 2;
        displayName = "@Rifleman";
        category = QGVAR(ind);
        GVAR(crewAir) = "I_Helipilot_F";
        GVAR(crewArmor)= "I_crew_F";
        GVAR(createUnits)[] = {"I_soldier_F"};
    };
    class GVAR(ind_ftl): GVAR(ind_rifleman) {
        displayName = "@FTL";
        GVAR(createUnits)[] = {"I_soldier_TL_F"};
    };
    class GVAR(ind_ar): GVAR(ind_rifleman) {
        displayName = "@AR";
        GVAR(createUnits)[] = {"I_soldier_AR_F"};
    };
    class GVAR(ind_rat): GVAR(ind_rifleman) {
        displayName = "@RAT";
        GVAR(createUnits)[] = {"I_Soldier_LAT_F"};
    };
    class GVAR(ind_manpad): GVAR(ind_rifleman) {
        displayName = "@MANPAD";
        GVAR(createUnits)[] = {"I_soldier_AA_F"};
    };
    class GVAR(ind_manpadTeam): GVAR(ind_rifleman) {
        displayName = "#MANPAD Team (2)";
        GVAR(createUnits)[] = {"I_soldier_AA_F","I_soldier_AAA_F"};
    };
    class GVAR(ind_matTeam): GVAR(ind_rifleman) {
        displayName = "#MAT Team (2)";
        GVAR(createUnits)[] = {"I_soldier_AT_F","I_soldier_AAT_F"};
    };
    class GVAR(ind_patrol): GVAR(ind_rifleman) {
        displayName = "#Patrol (2)";
        GVAR(createUnits)[] = {"I_soldier_F","I_soldier_F"};
    };
    class GVAR(ind_fireteam): GVAR(ind_rifleman) {
        displayName = "#Fireteam (4)";
        GVAR(createUnits)[] = {"I_soldier_TL_F","I_soldier_AR_F","I_soldier_F","I_soldier_LAT_F"};
    };
    class GVAR(ind_squad): GVAR(ind_rifleman) {
        displayName = "#Squad (8)";
        GVAR(createUnits)[] = {"I_soldier_SL_F","I_soldier_TL_F","I_soldier_AR_F","I_soldier_AR_F","I_soldier_LAT_F","I_soldier_F","I_soldier_F","I_soldier_F"};
    };
    class GVAR(ind_rhsZsu): GVAR(ind_rifleman) {
        displayName = "AA: ZSU 23 Shilka";
        GVAR(createVic) = "rhs_zsu234_aa";
    };
    class GVAR(ind_gazZu): GVAR(ind_rifleman) {
        displayName = "AA: GAZ ZU 23";
        GVAR(createVic) = "rhsgref_ins_g_gaz66_zu23";
    };
    class GVAR(ind_rhsBTR60): GVAR(ind_rifleman) {
        displayName = "APC: BTR-60";
        GVAR(createVic) = "rhs_btr60_vv";
    };
    class GVAR(ind_carModernGmg): GVAR(ind_rifleman) {
        displayName = "Car: Fennek GMG";
        GVAR(createVic) = "I_MRAP_03_gmg_F";
    };
    class GVAR(ind_carModernHmg): GVAR(ind_rifleman) {
        displayName = "Car: Fennek HMG";
        GVAR(createVic) = "I_MRAP_03_hmg_F";
    };
    class GVAR(ind_technical): GVAR(ind_rifleman) {
        displayName = "Car: Offroad HMG";
        GVAR(createVic) = "I_G_Offroad_01_armed_F";
    };
    class GVAR(ind_cupUazGmg): GVAR(ind_rifleman) {
        displayName = "Car: UAZ GMG";
        GVAR(createVic) = "CUP_O_UAZ_AGS30_CHDKZ";
    };
    class GVAR(ind_cupUazHmg): GVAR(ind_rifleman) {
        displayName = "Car: UAZ HMG";
        GVAR(createVic) = "CUP_O_UAZ_MG_CHDKZ";
    };
    class GVAR(ind_cupUazSpg): GVAR(ind_rifleman) {
        displayName = "Car: UAZ SPG-9";
        GVAR(createVic) = "CUP_O_UAZ_SPG9_CHDKZ";
    };
    class GVAR(ind_cupUazAtgm): GVAR(ind_rifleman) {
        displayName = "Car: UAZ Metis";
        GVAR(createVic) = "CUP_O_UAZ_METIS_CHDKZ";
    };
    class GVAR(ind_heliAttack): GVAR(ind_rifleman) {
        displayName = "Heli-Attack: Wildcat";
        GVAR(createVic) = "I_Heli_light_03_F";
    };
    class GVAR(ind_rhsBmd): GVAR(ind_rifleman) {
        displayName = "IFV: BMD-1";
        GVAR(createVic) = "rhs_bmd1";
    };
    class GVAR(ind_rhsBmp): GVAR(ind_rifleman) {
        displayName = "IFV: BMP-1";
        GVAR(createVic) = "rhs_bmp1_vdv";
    };
    class GVAR(ind_ifvModern): GVAR(ind_rifleman) {
        displayName = "IFV: Pandur II";
        GVAR(createVic) = "I_APC_Wheeled_03_cannon_F";
    };
    class GVAR(ind_ifvModern2): GVAR(ind_rifleman) {
        displayName = "IFV: Warrior";
        GVAR(createVic) = "I_APC_tracked_03_cannon_F";
    };
    class GVAR(ind_tankModern): GVAR(ind_rifleman) {
        displayName = "Tank: Kuma";
        GVAR(createVic) = "I_MBT_03_cannon_F";
    };
    class GVAR(ind_rhsT72): GVAR(ind_rifleman) {
        displayName = "Tank: T72B";
        GVAR(createVic) = "rhs_t72ba_tv";
    };
    class GVAR(ind_dismounts): GVAR(ind_rifleman) {
        curatorCanAttach = 1;
        scope = 1;
        displayName = "#Dismounts (6) [attach]";
        portrait = "\A3\Air_F_Beta\Parachute_01\Data\UI\Portrait_Parachute_01_CA.paa";
        GVAR(createUnits)[] = {"I_soldier_SL_F","I_soldier_AR_F","I_soldier_LAT_F","I_soldier_F","I_soldier_F","I_soldier_F"};
    };

    //------------ Utility modules ----------
    class GVAR(ungarrison_nearest_group): GVAR(base_prebuilt) {
        scope = 1;
        scopeCurator = 2;
        displayName = "Ungarrison nearest group";
        category = QGVAR(util);
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
    class GVAR(fix_nearest_group): GVAR(ungarrison_nearest_group) {
        displayName = "'Fix' nearest group";
        function = QFUNC(fixNearestGroupZeus);
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
                    class 1 { name = "NATO"; value = "blu_f"; default = 1; };
                    class 2 { name = "AAF"; value = "ind_f"; };
                    class 3 { name = "CSAT"; value = "opf_f"; };
                    class 4 { name = "MSV"; value = "rhs_faction_msv"; };
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

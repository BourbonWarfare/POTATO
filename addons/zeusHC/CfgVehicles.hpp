class CfgVehicles {
    class Logic;
    class Module_F: Logic {};

    //------------ Base module ----------
    class GVAR(base_module): Module_F {
        author = QUOTE(PREFIX);
        scope = 1;
        scopeCurator = 2;
        isTriggerActivated = 0;
        function = QFUNC(createEntityZeus);
        isGlobal = 0;
        curatorCost = 0;
        class Arguments {};
        class Attributes {};

        GVAR(createVic) = "";
    };

    //------------ East ----------
    class GVAR(base_east): GVAR(base_module) {
        category = QGVAR(east);
        GVAR(crewAir) = "O_Helipilot_F";
        GVAR(crewArmor)= "O_crew_F";
        GVAR(createUnits)[] = {"O_soldier_F"};
    }
    class GVAR(east_ftl): GVAR(base_east) {
        displayName = "#FTL";
        GVAR(createUnits)[] = {"O_soldier_TL_F"};
    };
    class GVAR(east_ar): GVAR(base_east) {
        displayName = "#AR";
        GVAR(createUnits)[] = {"O_soldier_AR_F"};
    };
    class GVAR(east_rat): GVAR(base_east) {
        displayName = "#RAT";
        GVAR(createUnits)[] = {"O_Soldier_LAT_F"};
    };
    class GVAR(east_rifleman): GVAR(base_east) {
        displayName = "#Rifleman";
    };
    class GVAR(east_fireteam): GVAR(base_east) {
        displayName = "#Fireteam (4)";
        GVAR(createUnits)[] = {"O_soldier_TL_F","O_soldier_AR_F","O_soldier_F","O_Soldier_LAT_F"};
    };
    class GVAR(east_squad): GVAR(base_east) {
        displayName = "#Squad (8)";
        GVAR(createUnits)[] = {"O_soldier_SL_F","O_soldier_TL_F","O_soldier_AR_F","O_soldier_AR_F","O_soldier_LAT_F","O_soldier_F","O_soldier_F","O_soldier_F"};
    };
    class GVAR(east_apcModern): GVAR(base_east) {
        displayName = "APC: Otokar GMG/HMG";
        GVAR(createVic) = "O_APC_Wheeled_02_rcws_F";
    };
    class GVAR(east_carOffroad): GVAR(base_east) {
        displayName = "Car: Offroad HMG";
        GVAR(createVic) = "O_G_Offroad_01_armed_F";
    };
    class GVAR(east_carModernGmg): GVAR(base_east) {
        displayName = "Car: Punisher GMG";
        GVAR(createVic) = "O_MRAP_02_gmg_F";
    };
    class GVAR(east_carModernHmg): GVAR(base_east) {
        displayName = "Car: Punisher HMG";
        GVAR(createVic) = "O_MRAP_02_hmg_F";
    };
    class GVAR(east_heliAttackHeavy): GVAR(base_east) {
        displayName = "Heli-Attack (Heavy): Mi-48 Kajman";
        GVAR(createVic) = "O_Heli_Attack_02_F";
    };
    class GVAR(east_heliAttack): GVAR(base_east) {
        displayName = "Heli-Attack (Light): PO-30 Orca";
        GVAR(createVic) = "O_Heli_Light_02_v2_F";
    };
    class GVAR(east_ifvModern): GVAR(base_east) {
        displayName = "IFV: BM-2T Stalker";
        GVAR(createVic) = "O_APC_Tracked_02_cannon_F";
    };
    class GVAR(east_tankModern): GVAR(base_east) {
        displayName = "Tank: T-100";
        GVAR(createVic) = "O_MBT_02_cannon_F";
    };

    //------------ West ----------
    class GVAR(base_west): GVAR(base_module) {
        category = QGVAR(west);
        GVAR(crewAir) = "B_Helipilot_F";
        GVAR(crewArmor)= "B_crew_F";
        GVAR(createUnits)[] = {"B_soldier_F"};
    }
    class GVAR(west_ftl): GVAR(base_west) {
        displayName = "#FTL";
        GVAR(createUnits)[] = {"B_soldier_TL_F"};
    };
    class GVAR(west_ar): GVAR(base_west) {
        displayName = "#AR";
        GVAR(createUnits)[] = {"B_soldier_AR_F"};
    };
    class GVAR(west_rat): GVAR(base_west) {
        displayName = "#RAT";
        GVAR(createUnits)[] = {"B_Soldier_LAT_F"};
    };
    class GVAR(west_rifleman): GVAR(base_west) {
        displayName = "#Rifleman";
    };
    class GVAR(west_fireteam): GVAR(base_west) {
        displayName = "#Fireteam (4)";
        GVAR(createUnits)[] = {"B_soldier_TL_F","B_soldier_AR_F","B_soldier_F","B_soldier_LAT_F"};
    };
    class GVAR(west_squad): GVAR(base_west) {
        displayName = "#Squad (8)";
        GVAR(createUnits)[] = {"B_soldier_SL_F","B_soldier_TL_F","B_soldier_AR_F","B_soldier_AR_F","B_soldier_LAT_F","B_soldier_F","B_soldier_F","B_soldier_F"};
    };
    class GVAR(west_rhsM113GmgD): GVAR(base_west) {
        displayName = "APC: M113 GMG (Desert)";
        GVAR(createVic) = "rhsusf_m113d_usarmy_MK19";
    };
    class GVAR(west_rhsM113HmgD): GVAR(base_west) {
        displayName = "APC: M113 HMG (Desert)";
        GVAR(createVic) = "rhsusf_m113d_usarmy";
    };
    class GVAR(west_rhsM113GmgW): GVAR(base_west) {
        displayName = "APC: M113 GMG (Woodland)";
        GVAR(createVic) = "rhsusf_m113_usarmy_MK19";
    };
    class GVAR(west_rhsM113HmgW): GVAR(base_west) {
        displayName = "APC: M113 HMG (Woodland)";
        GVAR(createVic) = "rhsusf_m113_usarmy";
    };
    class GVAR(west_apcModern): GVAR(base_west) {
        displayName = "APC: Namer GMG/HMG";
        GVAR(createVic) = "B_APC_Tracked_01_rcws_F";
    };
    class GVAR(west_strykerGmgD): GVAR(base_west) {
        displayName = "APC: Stryker GMG (Desert)";
        GVAR(createVic) = "M1126_ICV_mk19_DG1_NOSLATDES";
    };
    class GVAR(west_strykerHmgD): GVAR(base_west) {
        displayName = "APC: Stryker HMG (Desert)";
        GVAR(createVic) = "M1126_ICV_M2_DG1_NOSLATDES";
    };
    class GVAR(west_strykerGmgW): GVAR(base_west) {
        displayName = "APC: Stryker GMG (Woodland)";
        GVAR(createVic) = "M1126_ICV_mk19_DG1_NOSLATWOOD";
    };
    class GVAR(west_strykerHmgW): GVAR(base_west) {
        displayName = "APC: Stryker HMG (Woodland)";
        GVAR(createVic) = "M1126_ICV_M2_DG1_NOSLATWOOD";
    };
    class GVAR(west_rhsHmmwvGmgD): GVAR(base_west) {
        displayName = "Car: HMMWV GMG (Desert)";
        GVAR(createVic) = "rhsusf_m1025_d_mk19";
    };
    class GVAR(west_rhsHmmwvHmgD): GVAR(base_west) {
        displayName = "Car: HMMWV HMG (Desert)";
        GVAR(createVic) = "rhsusf_m1025_d_m2";
    };
    class GVAR(west_rhsHmmwvGmgW): GVAR(base_west) {
        displayName = "Car: HMMWV GMG (Woodland)";
        GVAR(createVic) = "rhsusf_m1025_w_mk19";
    };
    class GVAR(west_rhsHmmwvHmgW): GVAR(base_west) {
        displayName = "Car: HMMWV HMG (Woodland)";
        GVAR(createVic) = "rhsusf_m1025_w_m2";
    };
    class GVAR(west_carModernGmg): GVAR(base_west) {
        displayName = "Car: M-ATV GMG";
        GVAR(createVic) = "B_MRAP_01_gmg_F";
    };
    class GVAR(west_carModernHmg): GVAR(base_west) {
        displayName = "Car: M-ATV HMG";
        GVAR(createVic) = "B_MRAP_01_hmg_F";
    };
    class GVAR(west_carOffroad): GVAR(base_west) {
        displayName = "Car: Offroad HMG";
        GVAR(createVic) = "B_G_Offroad_01_armed_F";
    };
    class GVAR(west_heliAttackHeavy): GVAR(base_west) {
        displayName = "Heli-Attack (Heavy): AH-1Z Viper";
        GVAR(createVic) = "RHS_AH1Z";
    };
    class GVAR(west_heliAttack): GVAR(base_west) {
        displayName = "Heli-Attack (Light): AH-9 Littlebird";
        GVAR(createVic) = "B_Heli_Light_01_armed_F";
    };
    class GVAR(west_rhsBradly): GVAR(base_west) {
        displayName = "IFV: M2A2 Bradly";
        GVAR(createVic) = "RHS_M2A2";
    };
    class GVAR(west_ifvModern): GVAR(base_west) {
        displayName = "IFV: Marshall";
        GVAR(createVic) = "B_APC_Wheeled_01_cannon_F";
    };
    class GVAR(west_rhsM1A1D): GVAR(base_west) {
        displayName = "Tank: M1A1 (Desert)";
        GVAR(createVic) = "rhsusf_m1a1aimd_usarmy";
    };
    class GVAR(west_rhsM1A1W): GVAR(base_west) {
        displayName = "Tank: M1A1 (Woodland)";
        GVAR(createVic) = "rhsusf_m1a1aimwd_usarmy";
    };
    class GVAR(west_tankModern): GVAR(base_west) {
        displayName = "Tank: Merkava TUSK";
        GVAR(createVic) = "B_MBT_01_TUSK_F";
    };

    //------------ Independent ----------
    class GVAR(base_ind): GVAR(base_module) {
        category = QGVAR(ind);
        GVAR(crewAir) = "I_Helipilot_F";
        GVAR(crewArmor)= "I_crew_F";
        GVAR(createUnits)[] = {"I_soldier_F"};
    }
    class GVAR(ind_ftl): GVAR(base_ind) {
        displayName = "#FTL";
        GVAR(createUnits)[] = {"I_soldier_TL_F"};
    };
    class GVAR(ind_ar): GVAR(base_ind) {
        displayName = "#AR";
        GVAR(createUnits)[] = {"I_soldier_AR_F"};
    };
    class GVAR(ind_rat): GVAR(base_ind) {
        displayName = "#RAT";
        GVAR(createUnits)[] = {"I_Soldier_LAT_F"};
    };
    class GVAR(ind_rifleman): GVAR(base_ind) {
        displayName = "#Rifleman";
    };
    class GVAR(ind_fireteam): GVAR(base_ind) {
        displayName = "#Fireteam (4)";
        GVAR(createUnits)[] = {"I_soldier_TL_F","I_soldier_AR_F","I_soldier_F","I_soldier_LAT_F"};
    };
    class GVAR(ind_squad): GVAR(base_ind) {
        displayName = "#Squad (8)";
        GVAR(createUnits)[] = {"I_soldier_SL_F","I_soldier_TL_F","I_soldier_AR_F","I_soldier_AR_F","I_soldier_LAT_F","I_soldier_F","I_soldier_F","I_soldier_F"};
    };
    class GVAR(ind_rhsBTR60): GVAR(base_ind) {
        displayName = "APC: BTR-60";
        GVAR(createVic) = "rhs_btr60_vv";
    };
    class GVAR(ind_carModernGmg): GVAR(base_ind) {
        displayName = "Car: Fennek GMG";
        GVAR(createVic) = "I_MRAP_03_gmg_F";
    };
    class GVAR(ind_carModernHmg): GVAR(base_ind) {
        displayName = "Car: Fennek HMG";
        GVAR(createVic) = "I_MRAP_03_hmg_F";
    };
    class GVAR(ind_technical): GVAR(base_ind) {
        displayName = "Car: Offroad HMG";
        GVAR(createVic) = "I_G_Offroad_01_armed_F";
    };
    class GVAR(ind_rhsUazGmg): GVAR(base_ind) {
        displayName = "Car: UAZ GMG";
        GVAR(createVic) = "rhs_uaz_ags_chdkz";
    };
    class GVAR(ind_rhsUazHmg): GVAR(base_ind) {
        displayName = "Car: UAZ HMG";
        GVAR(createVic) = "rhs_uaz_dshkm_chdkz";
    };
    class GVAR(ind_rhsUazSpg): GVAR(base_ind) {
        displayName = "Car: UAZ SPG-9";
        GVAR(createVic) = "rhs_uaz_spg9_chdkz";
    };
    class GVAR(ind_heliAttack): GVAR(base_ind) {
        displayName = "Heli-Attack: Wildcat";
        GVAR(createVic) = "I_Heli_light_03_F";
    };
    class GVAR(ind_rhsBmd): GVAR(base_ind) {
        displayName = "IFV: BMD-1";
        GVAR(createVic) = "rhs_bmd1";
    };
    class GVAR(ind_rhsBmp): GVAR(base_ind) {
        displayName = "IFV: BMP-1";
        GVAR(createVic) = "rhs_bmp1_vdv";
    };
    class GVAR(ind_ifvModern): GVAR(base_ind) {
        displayName = "IFV: Warrior";
        GVAR(createVic) = "I_APC_tracked_03_cannon_F";
    };
    class GVAR(ind_tankModern): GVAR(base_ind) {
        displayName = "Tank: Kuma";
        GVAR(createVic) = "I_MBT_03_cannon_F";
    };
    class GVAR(ind_rhsT72): GVAR(base_ind) {
        displayName = "Tank: T72B";
        GVAR(createVic) = "rhs_t72ba_tv";
    };

    //------------ Russian MSV ----------
    class GVAR(base_msv): GVAR(base_module) {
        category = QGVAR(msv);
        GVAR(crewAir) = "rhs_pilot_transport_heli";
        GVAR(crewArmor)= "rhs_msv_crew";
        GVAR(createUnits)[] = {"rhs_msv_rifleman"};
    }
    class GVAR(msv_ftl): GVAR(base_msv) {
        displayName = "#FTL";
        GVAR(createUnits)[] = {"rhs_msv_junior_sergeant"};
    };
    class GVAR(msv_ar): GVAR(base_msv) {
        displayName = "#AR";
        GVAR(createUnits)[] = {"rhs_msv_machinegunner"};
    };
    class GVAR(msv_rat): GVAR(base_msv) {
        displayName = "#RAT";
        GVAR(createUnits)[] = {"rhs_msv_at"};
    };
    class GVAR(msv_rifleman): GVAR(base_msv) {
        displayName = "#Rifleman";
    };
    class GVAR(msv_fireteam): GVAR(base_msv) {
        displayName = "#Fireteam (4)";
        GVAR(createUnits)[] = {"rhs_msv_junior_sergeant","rhs_msv_machinegunner","rhs_msv_rifleman","rhs_msv_at"};
    };
    class GVAR(msv_squad): GVAR(base_msv) {
        displayName = "#Squad (8)";
        GVAR(createUnits)[] = {"rhs_msv_sergeant","rhs_msv_junior_sergeant","rhs_msv_machinegunner","rhs_msv_machinegunner","rhs_msv_at","rhs_msv_rifleman","rhs_msv_rifleman","rhs_msv_rifleman"};
    };
    class GVAR(msv_rhsBTR60): GVAR(base_msv) {
        displayName = "APC: BTR-60";
        GVAR(createVic) = "rhs_btr60_msv";
    };
    class GVAR(msv_rhsBTR70): GVAR(base_msv) {
        displayName = "APC: BTR-70";
        GVAR(createVic) = "rhs_btr70_msv";
    };
    class GVAR(msv_carBrdm): GVAR(base_msv) {
        displayName = "Car: BRDM-2";
        GVAR(createVic) = "Cha_BRDM2_TK";
    };
    class GVAR(msv_carBrdmAtgm): GVAR(base_msv) {
        displayName = "Car: BRDM-2 Konkers";
        GVAR(createVic) = "Cha_BRDM2_ATGM_TK";
    };
    class GVAR(msv_rhsUazGmg): GVAR(base_msv) {
        displayName = "Car: UAZ GMG";
        GVAR(createVic) = "rhs_uaz_ags_chdkz";
    };
    class GVAR(msv_rhsUazHmg): GVAR(base_msv) {
        displayName = "Car: UAZ HMG";
        GVAR(createVic) = "rhs_uaz_dshkm_chdkz";
    };
    class GVAR(msv_rhsUazSpg): GVAR(base_msv) {
        displayName = "Car: UAZ SPG-9";
        GVAR(createVic) = "rhs_uaz_spg9_chdkz";
    };
    class GVAR(msv_heliAttackHeavy): GVAR(base_msv) {
        displayName = "Heli-Attack (Heavy): MI-24";
        GVAR(createVic) = "RHS_Mi24V_vvsc";
    };
    class GVAR(msv_heliAttack): GVAR(base_msv) {
        displayName = "Heli-Attack (Light): MI-8";
        GVAR(createVic) = "RHS_Mi8MTV3_vvs";
    };
    class GVAR(msv_rhsBTR80A): GVAR(base_msv) {
        displayName = "IFV: BTR-80A";
        GVAR(createVic) = "rhs_btr80a_msv";
    };
    class GVAR(msv_rhsBmd1): GVAR(base_msv) {
        displayName = "IFV: BMD-1P";
        GVAR(createVic) = "rhs_bmd1p";
    };
    class GVAR(msv_rhsBmd2): GVAR(base_msv) {
        displayName = "IFV: BMD-2";
        GVAR(createVic) = "rhs_bmd2";
    };
    class GVAR(msv_rhsBmd4): GVAR(base_msv) {
        displayName = "IFV: BMD-4M";
        GVAR(createVic) = "rhs_bmd4ma_vdv";
    };
    class GVAR(msv_rhsBmp1): GVAR(base_msv) {
        displayName = "IFV: BMP-1P";
        GVAR(createVic) = "rhs_bmp1p_vdv";
    };
    class GVAR(msv_rhsBmp2): GVAR(base_msv) {
        displayName = "IFV: BMP-2D";
        GVAR(createVic) = "rhs_bmp2d_vdv";
    };
    class GVAR(msv_rhsBmp3): GVAR(base_msv) {
        displayName = "IFV: BMP-3";
        GVAR(createVic) = "rhs_bmp3mera_msv";
    };
    class GVAR(msv_rhsT72): GVAR(base_msv) {
        displayName = "Tank: T-72B";
        GVAR(createVic) = "rhs_t72bb_tv";
    };
    class GVAR(msv_rhsT80): GVAR(base_msv) {
        displayName = "Tank: T-80U";
        GVAR(createVic) = "rhs_t80u";
    };
};

class CfgZeusFactory {
    cars[] = {
        // vanilla Cars
        "B_MRAP_01_F", // M ATV
        "B_MRAP_01_hmg_F", // M ATV HMG
        "B_MRAP_01_gmg_F", // M ATV GMG
        "B_T_LSV_01_unarmed_F", // Prowler
        "B_T_LSV_01_armed_F", // Prowler HMG
        "I_MRAP_03_F", // Fennek
        "I_MRAP_03_hmg_F", // Fennek HMG
        "I_MRAP_03_gmg_F", // Fennek GMG
        "I_G_Offroad_01_F", // Pickup
        "C_Offroad_02_unarmed_F", // Jeep
        "O_MRAP_02_F", // Punisher
        "O_MRAP_02_hmg_F", // Punisher HMG
        "O_MRAP_02_gmg_F", // Punisher GMG
        "O_T_LSV_02_unarmed_F", // Qilin
        "O_T_LSV_02_armed_F", // Qilin Mini-Gun

        // vanilla Trucks
        "B_Truck_01_transport_F", // HEMMTT
        "I_Truck_02_transport_F", // KamAZ
        "I_G_Van_01_transport_F", // Civ Truck
        "O_Truck_03_transport_F", // Typhoon

        // RHS Cars
        "rhsusf_m998_w_2dr_halftop", // Woodland troop HMMWV
        "rhsusf_m998_d_2dr_halftop", // Desert troop HMMWV
        "rhsusf_m1025_w_m2", // Woodland HMG HMMWV
        "rhsusf_m1025_d_m2", // Desert HMG HMMWV
        "rhsusf_m1025_w_mk19", // Woodland GMG HMMWV
        "rhsusf_m1025_d_mk19", // Desert GMG HMMWV
        "rhsusf_M1232_usarmy_wd", // Woodland RG-33L
        "rhsusf_M1232_usarmy_d", // Desert RG-33L
        "rhsusf_M1232_M2_usarmy_wd", // Woodland HMG RG-33L
        "rhsusf_M1232_M2_usarmy_d", // Desert HMG RG-33L
        "rhsusf_M1232_MK19_usarmy_wd", // Woodland GMG RG-33L
        "rhsusf_M1232_MK19_usarmy_d", // Desert GMG RG-33L
        "rhsusf_M1117_W", // Woodland ASV HMG/GMG
        "rhsusf_M1117_D", // Desert ASV HMG/GMG
        "rhsgref_ins_uaz_open", // UAZ Jeep Carrier
        "rhsgref_ins_uaz_dshkm", // UAZ HMG Jeep
        "rhsgref_ins_uaz_ags", // UAZ GMG Jeep
        "rhsgref_ins_uaz_spg9", // UAZ SPG Jeep
        "rhs_tigr_vdv", // Tiger
        "rhs_tigr_sts_vdv", // Tiger LMG/GMG
        "rhsgref_BRDM2_vdv", // BRDM HMG

        // RHS Trucks
        "rhsusf_M1083A1P2_B_wd_open_fmtv_usarmy", // Woodland US Truck
        "rhsusf_M1083A1P2_B_d_open_fmtv_usarmy", // Desert US Truck
        "rhsusf_M1083A1P2_B_M2_wd_open_fmtv_usarmy", // Woodland HMG US Truck
        "rhsusf_M1083A1P2_B_M2_d_open_fmtv_usarmy", // Desert HMG US Truck
        "rhsgref_ins_gaz66", // GAZ 66 open truck
        "rhsgref_ins_ural_open", // Ural 4320 open truck
        "rhs_kamaz5350_open_vdv" // KamAZ 5350
    };

    apcs[] = {
        // Vanilla APCs
        "B_APC_Wheeled_01_cannon_F", // Badger IFV
        "B_APC_Tracked_01_rcws_F", // Namer APC
        "B_APC_Wheeled_01_cannon_F", // Badger IFV
        "B_APC_Tracked_01_rcws_F", // Namer APC
        "B_MBT_01_TUSK_F", // Merkava MBT
        "I_APC_Wheeled_03_cannon_F", // Pandur IFV
        "I_APC_tracked_03_cannon_F", // Warrior IFV
        "O_APC_Wheeled_02_rcws_F", // Otokar APC
        "O_APC_Tracked_02_cannon_F", // Stalker IFV

        // RHS APCs
        "rhsusf_m113_usarmy_unarmed", // Woodland M113
        "rhsusf_m113d_usarmy_unarmed", // Desert M113
        "rhsusf_m113_usarmy", // Woodland M113 HMG
        "rhsusf_m113d_usarmy", // Desert M113 HMG
        "rhsusf_m113_usarmy_MK19", // Woodland M113 GMG
        "rhsusf_m113d_usarmy_MK19", // Desert M113 GMG
        "RHS_M2A2_wd", // Woodland Bradley IFV
        "RHS_M2A2", // Desert Bradley IFV
        "rhs_btr60_msv", // BTR 60 APC
        "rhs_btr70_msv", // BTR 70 APC
        "rhs_btr80_msv", // BTR 80 APC
        "rhs_btr80a_msv", // BTR 80A IFV
        "rhs_bmp1_msv", // BMD 1 IFV
        "rhs_bmd2m", // BMD 2M IFV
        "rhs_bmd4m_vdv", // BMD 4 IFV
        "rhs_bmp1_vdv", // BMP 1 IFV
        "rhs_bmp2_msv", // BMP 2M IFV
        "rhs_bmp3_msv" // BMP 3 IFV

    };

    helicopters[] = {
        // Vanilla Transport Helicopters
        "B_Heli_Light_01_F", // MH 6
        "B_Heli_Transport_03_unarmed_F", // Future Chinook
        "I_Heli_Transport_02_F", // Merlin
        "I_Heli_light_03_unarmed_F", // Wildcat
        "O_Heli_Light_02_unarmed_F", // KA 60
        "O_Heli_Transport_04_covered_F", // Taru

        // Vanilla Armed Helicopters
        "B_Heli_Transport_01_F", // Future Blackhawk (armed)
        "B_Heli_Transport_03_F", // Future Chinook (armed)
        "I_Heli_light_03_F", // Wildcat (armed)
        "O_Heli_Light_02_F", // KA 60 (armed)
        "O_Heli_Attack_02_F", // Mi 48 Kajman

        // RHS Transport Helicopters
        "RHS_UH1Y_UNARMED", // Venom
        "rhsusf_CH53E_USMC", // Super Stallion
        "RHS_Mi8AMT_vdv", // Mi 8

        // RHS Armed Helicopters
        "RHS_UH1Y_FFAR", // Venom (armed)
        "RHS_CH_47F", // Chinook (armed)
        "RHS_UH60M", // Blackhawk (armed)
        "RHS_Mi8AMTSh_vvs", // Mi 8 (armed)
        "rhsgref_cdf_reg_Mi17Sh_UPK", // Mi 17 (armed)
        "rhsgref_mi24g_CAS" // Mi 24
        
    };
};

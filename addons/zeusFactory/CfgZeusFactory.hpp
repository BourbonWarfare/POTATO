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
        "rhsusf_m1151_usarmy_d", //Desert Armored unarmed HMV
        "rhsusf_m1151_m240_v1_usarmy_d", //Desert Armored HMG HMV
        "rhsusf_m1151_usarmy_wd", //Woodland Armored unarmed HMV
        "rhsusf_m1151_m240_v1_usarmy_wd", //Woodland Armored HMG HMV
        "rhs_uaz_open_Base", // UAZ Jeep Carrier
        "RHS_UAZ_DShKM_Base", // UAZ HMG Jeep
        "RHS_UAZ_AGS30_Base", // UAZ GMG Jeep
        "RHS_UAZ_SPG9_Base", // UAZ SPG Jeep
        "rhs_tigr_vdv", // Tiger
        "rhs_tigr_sts_vdv", // Tiger LMG/GMG
        "rhsgref_BRDM2_vdv", // BRDM HMG
        

        // RHS Trucks
        "rhsusf_M1083A1P2_B_wd_open_fmtv_usarmy", // Woodland US Truck
        "rhsusf_M1083A1P2_B_d_open_fmtv_usarmy", // Desert US Truck
        "rhsusf_M1083A1P2_B_M2_wd_open_fmtv_usarmy", // Woodland HMG US Truck
        "rhsusf_M1083A1P2_B_M2_d_open_fmtv_usarmy", // Desert HMG US Truck
        "rhs_gaz66_msv", // GAZ 66 open truck
        "RHS_Ural_MSV_Base", // Ural 4320 open truck
        "rhs_kamaz5350_open_vdv", // KamAZ 5350

        // CUP Cars
        "CUP_B_Jackal2_L2A1_GB_W", // Woodland Jackal HMG
        "CUP_B_Jackal2_L2A1_GB_D", // Desert Jackal HMG
        "CUP_B_Jackal2_GMG_GB_W", // Woodland Jackal GMG
        "CUP_B_Jackal2_GMG_GB_D", // Desert Jackal GMG
        "CUP_B_BAF_Coyote_L2A1_W", // Woodland Coyote HMG
        "CUP_B_BAF_Coyote_L2A1_D", // Desert Coyote HMG
        "CUP_B_BAF_Coyote_GMG_W", // Woodland Coyote GMG
        "CUP_B_BAF_Coyote_GMG_D", // Desert Coyote GMG
        "CUP_B_LR_Transport_GB_W", // Woodland Land Rover
        "CUP_B_LR_Transport_GB_D", // Woodland Land Rover
        "CUP_B_LR_Special_M2_GB_W", // Woodland Land Rover HMG
        "CUP_B_LR_Special_M2_GB_D", // Woodland Land Rover HMG
        "CUP_B_LR_Special_GMG_GB_W", // Woodland Land Rover GMG
        "CUP_B_LR_Special_GMG_GB_D", // Woodland Land Rover GMG
        "CUP_B_Dingo_GER_Wdl", // Woodland Dingo lMG
        "CUP_B_Dingo_GER_Des", // Desert Dingo HMG
        "CUP_B_Dingo_GL_GER_Wdl", // Woodland Dingo GMG
        "CUP_B_Dingo_GL_GER_Des", // Desert Dingo GMG
        "CUP_I_SUV_ION", // Black SUV
        "CUP_I_SUV_Armored_ION", // Black SUV Mini-Gun
        "CUP_I_BTR40_TKG", // BTR 40
        "CUP_I_BTR40_MG_TKG", // BTR 40 HMG
        "CUP_C_Datsun", // Shitty pickup
        "CUP_I_Datsun_PK_Random", // Shitty pickup LMG
        "CUP_O_GAZ_Vodnik_PK_RU", // Vodnik LMG
        "CUP_O_GAZ_Vodnik_AGS_RU", // Vodnik HMG
        "CUP_O_GAZ_Vodnik_BPPU_RU", // Vodnik Cannon
        "CUP_I_Hilux_unarmed_IND_G_F", //Hilux unarmed (Better pickup)
        "CUP_I_Hilux_DSHKM_IND_G_F", //Hilux HMG
        "CUP_I_Hilux_armored_unarmed_IND_G_F", //Armored Hilux unarmed
        "CUP_I_Hilux_armored_DSHKM_IND_G_F" //Armored Hilux HMG

        // CUP Trucks
        "CUP_B_MTVR_USMC", // Woodland MVTR
        "CUP_B_MTVR_USA", // Desert MVTR
        "CUP_I_V3S_Open_TKG", // Praga
        "CUP_C_Ikarus_TKC" // Bus
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
        "CUP_B_Boxer_HMG_GER_DES", //Desert Boxer HMG
        "CUP_B_Boxer_HMG_GER_WDL", //Woodland Boxer HMG
        "CUP_B_Boxer_HMG_HIL", //Jungle Boxer HMG
        "rhs_btr60_msv", // BTR 60 APC
        "rhs_btr70_msv", // BTR 70 APC
        "rhs_btr80_msv", // BTR 80 APC
        "rhs_btr80a_msv", // BTR 80A IFV
        "rhs_bmp1_msv", // BMD 1 IFV
        "rhs_bmd2m", // BMD 2M IFV
        "rhs_bmd4m_vdv", // BMD 4 IFV
        "rhs_bmp1_vdv", // BMP 1 IFV
        "rhs_bmp2_msv", // BMP 2M IFV
        "rhs_bmp3_msv", // BMP 3 IFV

        // CUP APCs
        "CUP_B_M1126_ICV_M2_Woodland", // Woodland Styker HMG
        "CUP_B_M1126_ICV_M2_Desert", // Desert Styker HMG
        "CUP_B_M1126_ICV_MK19_Woodland", // Woodland Styker GMG
        "CUP_B_M1126_ICV_MK19_Desert", // Desert Styker GMG
        "CUP_B_LAV25_USMC", // Woodland LAV IFV
        "CUP_B_LAV25_desert_USMC", // Desert LAV IFV
        "CUP_B_AAV_USMC", // AAVP Amtrac
        "CUP_I_T34_NAPA", // T 34 'MBT'
        "CUP_I_T55_TK_GUE", // T 55 'MBT'
        "CUP_O_BTR90_RU", // BTR 90 IFV
        "CUP_O_BRDM2_RUS", // BRDM
        "CUP_O_BTR60_SLA", // BTR 60
        "CUP_O_MTLB_pk_WDL_RU", // MT-LB Woodland
        "CUP_O_MTLB_pk_Winter_RU", // MT-LB Winter
        "CUP_O_MTLB_pk_TKA" // MT-LB Desert
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
        "rhsgref_mi24g_CAS", // Mi 24

        // CUP Transport Helicopters
        "CUP_O_MI6T_RU", // Mi 6 mass trans
        "CUP_O_Mi17_TK", // Mi 17
        "CUP_I_SA330_Puma_HC1_RACS" // Puma
    };
};

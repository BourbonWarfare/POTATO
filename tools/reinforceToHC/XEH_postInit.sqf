#include "script_component.hpp"

GVAR(reinforceUnits) = [
    [ // BluFor vanilla vics
        "BlueFor (A3)", // display name
        west, // side
        "", // addon to check for
        "potato_w_rifleman", // soft crew
        "B_crew_F", // armored crew
        "B_Helipilot_F", // air crew
        [ // unarmed cars
            "B_MRAP_01_F", // M-ATV
            "B_LSV_01_unarmed_F", // Prowler
            "B_G_Offroad_01_F" // Pickup
        ], [ // armed cars
            "B_MRAP_01_gmg_F", // M-ATV GMG
            "B_MRAP_01_hmg_F", // M-ATV HMG
            "B_LSV_01_armed_F" // Prowler HMG
        ], [ // trucks
            "B_Truck_01_transport_F", // HEMMT
            "B_Truck_01_covered_F" // HEMMT (covered)
        ], [ // APCs/IFVs
            "B_APC_Tracked_01_rcws_F", // Namer
            "B_APC_Wheeled_01_cannon_F" // Badger
        ], [ // unarmed helis
            "B_Heli_Light_01_F", // MH-6
            "B_Heli_Transport_03_unarmed_F" // CH-47I Future Chinook
        ], [ // armed helis
            "B_Heli_Transport_01_F", // UH-80 Ghosthawk
            "B_Heli_Transport_01_camo_F", // UH-80 Ghosthawk (Olive)
            "B_Heli_Transport_03_F" // CH-47I Future Chinook
        ], [ // unarmed boats
            "B_Boat_Transport_01_F", // Assault boat
            "I_C_Boat_Transport_02_F" // RHIB
        ], [ // armed boats
            "B_Boat_Armed_01_minigun_F" // Speedboat Minigun
        ], [ // soldier groups to load into the vics
            ["potato_w_ftl", "potato_w_ar", "potato_w_aar", "potato_w_lat", "potato_w_rifleman", "potato_w_rifleman"],
            ["potato_w_ftl", "potato_w_ar", "potato_w_aar", "potato_w_lat"]
        ]
    ], [ // BluFor RHS vics
        "BlueFor (RHS)", // display name
        west, // side
        "rhsusf_main", // addon to check for
        "potato_w_rifleman", // soft crew
        "B_crew_F", // armored crew
        "B_Helipilot_F", // air crew
        [ // unarmed cars
            "rhsusf_m998_w_2dr_fulltop", // HMMWV Woodland
            "rhsusf_m998_d_2dr_fulltop", // HMMWV Desert
            "rhsusf_rg33_usmc_wd", // RG-33 Woodland
            "rhsusf_rg33_usmc_d", // RG-33 Desert
            "rhsusf_M1232_usarmy_wd", // M1232 (RG-33L) Woodland
            "rhsusf_M1232_usarmy_d" // M1232 (RG-33L) Desert
        ], [ // armed cars
            "rhsusf_m1025_w_m2", // HMMWV Woodland HMG
            "rhsusf_m1025_d_m2", // HMMWV Desert HMG
            "rhsusf_m1025_w_mk19", // HMMWV Woodland GMG
            "rhsusf_m1025_d_Mk19", // HMMWV Desert GMG
            "rhsusf_rg33_m2_usmc_wd", // RG-33 Woodland HMG
            "rhsusf_rg33_m2_usmc_d", // RG-33 Desert HMG
            "rhsusf_M1232_M2_usarmy_wd", // M1232 (RG-33L) Woodland HMG
            "rhsusf_M1232_M2_usarmy_d", // M1232 (RG-33L) Desert HMG
            "rhsusf_M1232_MK19_usarmy_wd", // M1232 (RG-33L) Woodland GMG
            "rhsusf_M1232_MK19_usarmy_d" // M1232 (RG-33L) Desert GMG
        ], [ // trucks
            "rhsusf_M1083A1P2_wd_fmtv_usarmy", // MTV Cargo Woodland
            "rhsusf_M1083A1P2_d_fmtv_usarmy", // MTV Cargo Desert
            "rhsusf_M1083A1P2_B_M2_wd_fmtv_usarmy", // MTV Cargo Woodland HMG
            "rhsusf_M1083A1P2_B_M2_d_fmtv_usarmy" // MTV Cargo Desert HMG
        ], [ // APCs/IFVs
            "rhsusf_M1117_W", // ASV Woodland HMG/GMG
            "rhsusf_M1117_D", // ASV Desert HMG/GMG
            "rhsusf_m113_usarmy", // M113 Woodland HMG
            "rhsusf_m113d_usarmy", // M113 Desert HMG
            "rhsusf_m113_usarmy_MK19", // M113 Woodland GMG
            "rhsusf_m113d_usarmy_MK19", // M113 Desert GMG
            "RHS_M2A2_wd", // Bradley Woodland
            "RHS_M2A2" // Bradley Desert
        ], [ // unarmed helis
            "RHS_MELB_MH6M", // MH-6
            "RHS_UH1Y_UNARMED", // Venom
            "rhsusf_CH53E_USMC" // CH-53E Super Stallion
        ], [ // armed helis
            "RHS_UH1Y", // Venom
            "RHS_UH60M", // Blackhawk
            "RHS_CH_47F" // Chinook
        ], [ // unarmed boats
            "B_Boat_Transport_01_F", // Assault boat (it's vanilla, but RHS aint got shit here)
            "I_C_Boat_Transport_02_F" // RHIB (it's vanilla, but RHS aint got shit here)
        ], [ // armed boats
            "rhsusf_mkvsoc" // Mk. V
        ], [ // soldier groups to load into the vics
            ["potato_w_ftl", "potato_w_ar", "potato_w_aar", "potato_w_lat", "potato_w_rifleman", "potato_w_rifleman"],
            ["potato_w_ftl", "potato_w_ar", "potato_w_aar", "potato_w_lat"]
        ]
    ], [ // BluFor CUP vics
        "BlueFor (CUP)", // display name
        west, // side
        "CUP_Vehicles_Core", // addon to check for
        "potato_w_rifleman", // soft crew
        "B_crew_F", // armored crew
        "B_Helipilot_F", // air crew
        [ // unarmed cars
            "CUP_B_HMMWV_Unarmed_USMC", // HMMWV Woodland
            "CUP_B_HMMWV_Unarmed_USA", // HMMWV Desert
            "CUP_B_LR_Transport_GB_W", // Landrover Woodland
            "CUP_B_LR_Transport_GB_D" // Landrover Desert
        ], [ // armed cars
            "CUP_B_HMMWV_M2_USMC", // HMMWV Woodland HMG
            "CUP_B_HMMWV_M2_USA", // HMMWV Desert HMG
            "CUP_B_HMMWV_MK19_USMC", // HMMWV Woodland GMG
            "CUP_B_HMMWV_MK19_USA", // HMMWV Desert GMG
            "CUP_B_HMMWV_TOW_USMC", // HMMWV Woodland ATGM
            "CUP_B_HMMWV_TOW_USA", // HMMWV Desert ATGM
            "CUP_B_LR_Special_M2_GB_W", // Landrover Woodland HMG
            "CUP_B_LR_Special_M2_GB_D", // Landrover Desert HMG
            "CUP_B_LR_Special_GMG_GB_W", // Landrover Woodland GMG
            "CUP_B_LR_Special_GMG_GB_D", // Landrover Desert GMG
            "CUP_B_Jackal2_L2A1_GB_W", // Jackal Woodland HMG
            "CUP_B_Jackal2_L2A1_GB_D", // Jackal Desert HMG
            "CUP_B_Jackal2_GMG_GB_W", // Jackal Woodland GMG
            "CUP_B_Jackal2_GMG_GB_D", // Jackal Desert GMG
            "CUP_B_BAF_Coyote_L2A1_W", // Coyote Woodland HMG
            "CUP_B_BAF_Coyote_L2A1_D", // Coyote Desert HMG
            "CUP_B_BAF_Coyote_GMG_W", // Coyote Woodland GMG
            "CUP_B_BAF_Coyote_GMG_D", // Coyote Desert GMG
            "CUP_B_RG31_M2_USMC", // RG-31 Woodland HMG
            "CUP_B_RG31_M2_OD_USMC", // RG-31 Desert HMG
            "CUP_B_RG31_Mk19_USMC", // RG-31 Woodland GMG
            "CUP_B_RG31_Mk19_OD_USMC", // RG-31 Desert GMG
            "CUP_B_Mastiff_HMG_GB_W", // Mastiff Woodland HMG
            "CUP_B_Mastiff_HMG_GB_D", // Mastiff Desert HMG
            "CUP_B_Mastiff_GMG_GB_W", // Mastiff Woodland GMG
            "CUP_B_Mastiff_GMG_GB_D" // Mastiff Desert GMG
        ], [ // trucks
            "CUP_B_MTVR_USMC", // MTVR Woodland
            "CUP_B_MTVR_USA" // MTVR Desert
        ], [ // APCs/IFVs
            "CUP_B_M1126_ICV_M2_Woodland", // Stryker Woodland HMG
            "CUP_B_M1126_ICV_M2_Desert", // Stryker Desert HMG
            "CUP_B_M1126_ICV_MK19_Woodland", // Stryker Woodland GMG
            "CUP_B_M1126_ICV_MK19_Desert", // Stryker Desert GMG
            "CUP_B_M113_USA", // M113 Woodland HMG
            "CUP_B_AAV_USMC", // AAVP Woodland HMG/GMG
            "CUP_B_LAV25M240_USMC", // LAV25 Woodland
            "CUP_B_LAV25M240_desert_USMC", // LAV25 Desert
            "CUP_B_FV510_GB_W", // Warrior Woodland
            "CUP_B_FV510_GB_D", // Warrior Desert
            "CUP_B_M2Bradley_USA_W", // Bradley Woodland
            "CUP_B_M2Bradley_USA_D" // Bradley Desert
        ], [ // unarmed helis
            "CUP_B_MH6J_USA", // MH-6
            "CUP_B_AW159_Unarmed_GB", // Wildcat
            "CUP_B_UH1Y_UNA_USMC", // Venom
            "CUP_B_Merlin_HC3_GB", // Merlin
            "CUP_B_CH53E_USMC", // CH-53E Super Stallion
            "CUP_B_UH60M_Unarmed_FFV_US" // Blackhawk
        ], [ // armed helis
            "CUP_B_AW159_Cannon_GB", // Wildcat
            "CUP_B_UH1Y_GUNSHIP_USMC", // Venom
            "CUP_B_UH60M_US", // Blackhawk
            "CUP_B_CH47F_USA" // Chinook
        ], [ // unarmed boats
            "CUP_B_Zodiac_USMC" // Zodiac
        ], [ // armed boats
            "CUP_B_RHIB_USMC", // RHIB HMG
            "CUP_B_RHIB2Turret_USMC" // RHIB GMG
        ], [ // soldier groups to load into the vics
            ["potato_w_ftl", "potato_w_ar", "potato_w_aar", "potato_w_lat", "potato_w_rifleman", "potato_w_rifleman"],
            ["potato_w_ftl", "potato_w_ar", "potato_w_aar", "potato_w_lat"]
        ]
    ], [ // Indy vanilla vics
        "Indy (A3)", // display name
        resistance, // side
        "", // addon to check for
        "potato_i_rifleman", // soft crew
        "I_crew_F", // armored crew
        "I_Helipilot_F", // air crew
        [ // unarmed cars
            "I_G_Offroad_01_F", // Pickup
            "I_C_Offroad_02_unarmed_F", // Jeep
            "I_MRAP_03_F" // Fennek
        ], [ // armed cars
            "I_G_Offroad_01_armed_F", // Pickup HMG
            "I_MRAP_03_hmg_F", // Fennek HMG
            "I_MRAP_03_gmg_F" // Fennek GMG
        ], [ // trucks
            "I_G_Van_01_transport_F", // Civ truck
            "I_Truck_02_covered_F", // KamAZ Transport
            "I_Truck_02_transport_F" // KamAZ Transport (covered)
        ], [ // APCs/IFVs
            "I_APC_Wheeled_03_cannon_F", // Pandur II
            "I_APC_tracked_03_cannon_F" // Warrior
        ], [ // unarmed helis
            "I_Heli_light_03_unarmed_F", // Wildcat
            "I_Heli_Transport_02_F" // Merlin
        ], [ // armed helis
            "I_Heli_light_03_F" // Wildcat
        ], [ // unarmed boats
            "I_Boat_Transport_01_F", // Assault boat
            "I_G_Boat_Transport_01_F", // Assault boat
            "I_C_Boat_Transport_02_F" // RHIB
        ], [ // armed boats
            "I_Boat_Armed_01_minigun_F" // Speedboat minigun
        ], [ // soldier groups to load into the vics
            ["potato_i_ftl", "potato_i_ar", "potato_i_aar", "potato_i_lat", "potato_i_rifleman", "potato_i_rifleman"],
            ["potato_i_ftl", "potato_i_ar", "potato_i_aar", "potato_i_lat"]
        ]
    ], [ // Indy RHS vics
        "Indy (RHS)", // display name
        resistance, // side
        "rhsgref_main", // addon to check for
        "potato_i_rifleman", // soft crew
        "I_crew_F", // armored crew
        "I_Helipilot_F", // air crew
        [ // unarmed cars
            "rhsgref_ins_g_uaz", // UAZ Jeep
            "rhsgref_ins_g_uaz_open" // UAZ Jeep (open)
        ], [ // armed cars
            "rhsgref_ins_g_uaz_dshkm_chdkz", // UAZ Jeep HMG
            "rhsgref_ins_g_uaz_ags", // UAZ Jeep GMG
            "rhsgref_ins_g_uaz_spg9" // UAZ Jeep SPG9
        ], [ // trucks
            "rhsgref_cdf_gaz66", // GAZ-66 Transport
            "rhsgref_cdf_gaz66o" // GAZ-66 Transport (open)
        ], [ // APCs/IFVs
            "rhsgref_BRDM2_ins_g", // BRDM-2
            "rhsgref_ins_g_btr60", // BTR-60
            "rhsgref_ins_g_bmd1", // BMD-1
            "rhsgref_ins_g_bmp1" // BMP-1
        ], [ // unarmed helis
            "rhsgref_ins_g_Mi8amt" // Mi-8
        ], [ // armed helis
            "rhsgref_cdf_reg_Mi17Sh" // Mi-8
        ], [ // unarmed boats
            "I_Boat_Transport_01_F", // Assault boat (it's vanilla, but RHS aint got shit here)
            "I_G_Boat_Transport_01_F", // Assault boat (it's vanilla, but RHS aint got shit here)
            "I_C_Boat_Transport_02_F" // RHIB (it's vanilla, but RHS aint got shit here)
        ], [ // armed boats
            "I_Boat_Armed_01_minigun_F" // Speedboat minigun (it's vanilla, but RHS aint got shit here)
        ], [ // soldier groups to load into the vics
            ["potato_i_ftl", "potato_i_ar", "potato_i_aar", "potato_i_lat", "potato_i_rifleman", "potato_i_rifleman"],
            ["potato_i_ftl", "potato_i_ar", "potato_i_aar", "potato_i_lat"]
        ]
    ], [ // Indy CUP vics
        "Indy (CUP)", // display name
        resistance, // side
        "CUP_Vehicles_Core", // addon to check for
        "potato_i_rifleman", // soft crew
        "I_crew_F", // armored crew
        "I_Helipilot_F", // air crew
        [ // unarmed cars
            "CUP_O_UAZ_Unarmed_CHDKZ", // UAZ Jeep
            "CUP_O_UAZ_Open_CHDKZ", // UAZ Jeep (open)
            "CUP_I_LR_Transport_RACS", // Land rover
            "CUP_I_BTR40_TKG", // BTR-40
            "CUP_I_SUV_ION" // SUV
        ], [ // armed cars
            "CUP_I_Datsun_PK", // Shitty pickup MMG
            "CUP_O_UAZ_MG_CHDKZ", // UAZ Jeep HMG
            "CUP_O_UAZ_AGS30_CHDKZ", // UAZ Jeep GMG
            "CUP_O_UAZ_SPG9_CHDKZ", // UAZ Jeep SPG9
            "CUP_O_UAZ_METIS_CHDKZ", // UAZ Jeep ATGM
            "CUP_O_LR_MG_TKM", // Landrover HMG
            "CUP_O_LR_SPG9_TKM", // Landrover SPG9
            "CUP_I_BTR40_MG_TKG", // BTR-40 HMG
            "CUP_I_SUV_Armored_ION" // SUV minigun
        ], [ // trucks
            "CUP_I_V3S_Covered_TKG", // Praga V3S Transport
            "CUP_I_V3S_Open_TKG", // Praga V3S Transport (open)
            "CUP_C_Ikarus_Chernarus" // Bus
        ], [ // APCs/IFVs
            "CUP_I_BRDM2_TK_Gue", // BRDM-2
            "CUP_I_M113_RACS", // M113
            "CUP_B_BTR60_CDF", // BTR-60
            "CUP_I_BMP1_TK_GUE", // BMP-1
            "CUP_I_T34_NAPA" // T34 (fuck it, why not)
        ], [ // unarmed helis
            "CUP_B_Mi17_CDF" // Mi-17
        ], [ // armed helis
            "CUP_O_UH1H_TKA", // UH-1H Huey
            "CUP_B_Mi171Sh_ACR", // Mi-17
            "CUP_I_Ka60_GL_Blk_ION" // Orca with rockets
        ], [ // unarmed boats
            "CUP_O_PBX_SLA" // PBX
        ], [ // armed boats
            "CUP_I_RHIB_RACS", // RHIB HMG
            "CUP_I_RHIB2Turret_RACS" // RHIB GMG
        ], [ // soldier groups to load into the vics
            ["potato_i_ftl", "potato_i_ar", "potato_i_aar", "potato_i_lat", "potato_i_rifleman", "potato_i_rifleman"],
            ["potato_i_ftl", "potato_i_ar", "potato_i_aar", "potato_i_lat"]
        ]
    ], [ // OpFor vanilla vehicles
        "OpFor (A3)", // display name
        east, // side
        "", // addon to check for
        "potato_e_rifleman", // soft crew
        "O_crew_F", // armored crew
        "O_Helipilot_F", // air crew
        [ // unarmed cars
            "O_MRAP_02_F", // Punisher
            "O_T_LSV_02_unarmed_F", // Qilin
            "O_G_Offroad_01_F" // Pickup
        ], [ // armed cars
            "O_MRAP_02_hmg_F", // Punisher HMG
            "O_MRAP_02_gmg_F", // Puniser GMG
            "O_LSV_02_armed_F" // Qilin minigun
        ], [ // trucks
            "O_Truck_02_covered_F", // KamAZ transport
            "O_Truck_02_transport_F", // KamAZ transport (open)
            "O_Truck_03_covered_F", // Typhoon transport
            "O_Truck_03_transport_F" // Typhoon transport (open)
        ], [ // APCs/IFVs
            "O_APC_Wheeled_02_rcws_F", // Otokar ARMA HMG/GMG
            "O_APC_Tracked_02_cannon_F" // BM-2T
        ], [ // unarmed helis
            "O_Heli_Light_02_unarmed_F", // Orca
            "O_Heli_Transport_04_bench_F", // Taru (open)
            "O_Heli_Transport_04_covered_F" // Taru
        ], [ // armed helis
            "O_Heli_Light_02_F" // Orca
        ], [ // unarmed boats
            "O_Boat_Transport_01_F" // Assault Boat
        ], [ // armed boats
            "O_Boat_Armed_01_hmg_F" // Speedboat (HMG)
        ], [ // soldier groups to load into the vics
            ["potato_e_ftl", "potato_e_ar", "potato_e_aar", "potato_e_lat", "potato_e_rifleman", "potato_e_rifleman"],
            ["potato_e_ftl", "potato_e_ar", "potato_e_aar", "potato_e_lat"]
        ]
    ], [ // OpFor RHS vehicles
        "OpFor (RHS)", // display name
        east, // side
        "RHS_Main", // addon to check for
        "potato_e_rifleman", // soft crew
        "O_crew_F", // armored crew
        "O_Helipilot_F", // air crew
        [ // unarmed cars
            "RHS_UAZ_MSV_01", // UAZ Jeep
            "rhs_uaz_open_MSV_01", // UAZ Jeep (open)
            "rhs_tigr_msv", // Tigr
            "rhs_tigr_m_msv" // Tigr (open turret)
        ], [ // armed cars
            "rhsgref_nat_uaz_dshkm", // UAZ Jeep HMG
            "rhsgref_nat_uaz_ags", // UAZ Jeep GMG
            "rhsgref_nat_uaz_spg9", // UAZ Jeep SPG9
            "rhs_tigr_sts_msv" // Tigr HMG/GMG
        ], [ // trucks
            "rhs_gaz66_msv", // GAZ-66 transport
            "rhs_gaz66o_msv", // GAZ-66 transport (open)
            "RHS_Ural_MSV_01", // Ural transport
            "RHS_Ural_Open_MSV_01", // Ural transport
            "rhs_kamaz5350_msv", // KamAZ 5350 transport
            "rhs_kamaz5350_open_msv" // KamAZ 5350 transport (open)
        ], [ // APCs/IFVs
            "rhsgref_BRDM2_msv", // BRDM-2
            "rhs_btr70_msv", // BTR-70
            "rhs_btr80_msv", // BTR-80
            "rhs_btr80a_msv", // BTR-80A
            "rhs_bmd2m", // BMD-2
            "rhs_bmd4m_vdv", // BMD-4
            "rhs_bmp2d_msv", // BMP-2D
            "rhs_bmp3_late_msv" // BMP-3
        ], [ // unarmed helis
            "rhs_ka60_c", // Orca
            "RHS_Mi8AMT_vdv" // Mi-8
        ], [ // armed helis
            "RHS_Mi8MTV3_vdv", // Mi-8
            "RHS_Mi24V_vdv" // Hind
        ], [ // unarmed boats
            "O_Boat_Transport_01_F" // Assault Boat (it's vanilla, but RHS aint got shit here)
        ], [ // armed boats
            "O_Boat_Armed_01_hmg_F" // Speedboat (HMG) (it's vanilla, but RHS aint got shit here)
        ], [ // soldier groups to load into the vics
            ["potato_e_ftl", "potato_e_ar", "potato_e_aar", "potato_e_lat", "potato_e_rifleman", "potato_e_rifleman"],
            ["potato_e_ftl", "potato_e_ar", "potato_e_aar", "potato_e_lat"]
        ]
    ], [ // OpFor CUP vehicles
        "OpFor (CUP)", // display name
        east, // side
        "CUP_Vehicles_Core", // addon to check for
        "potato_e_rifleman", // soft crew
        "O_crew_F", // armored crew
        "O_Helipilot_F", // air crew
        [ // unarmed cars
            "CUP_O_UAZ_Unarmed_RU", // UAZ Jeep
            "CUP_O_UAZ_Open_RU" // UAZ Jeep (open)
        ], [ // armed cars
            "CUP_O_UAZ_MG_RU", // UAZ Jeep HMG
            "CUP_O_UAZ_AGS30_RU", // UAZ Jeep GMG
            "CUP_O_UAZ_SPG9_RU", // UAZ Jeep SPG9
            "CUP_O_UAZ_METIS_RU", // UAZ Jeep ATGM
            "CUP_O_GAZ_Vodnik_PK_RU", // Vodnik MMG
            "CUP_O_GAZ_Vodnik_AGS_RU" // Vodnik MMG/GMG
        ], [ // trucks
            "CUP_O_Ural_RU", // Ural transport
            "CUP_O_Ural_Open_RU" // Ural transport (open)
        ], [ // APCs/IFVs
            "CUP_O_BRDM2_RUS", // BRDM-2
            "CUP_O_GAZ_Vodnik_BPPU_RU", // Vodnik BPPU
            "CUP_O_BTR90_RU", // BTR-90
            "CUP_O_BMP2_RU", // BMP-2
            "CUP_O_BMP3_RU", // BMP-3
            "CUP_O_T72_RU" // T-72 (fuck it, why not)
        ], [ // unarmed helis
            "CUP_O_Mi8_medevac_RU" // Mi-8
        ], [ // armed helis
            "CUP_O_Ka60_GL_Blk_CSAT", // Orca
            "CUP_O_Mi8_RU", // Mi-8
            "CUP_O_Mi24_V_RU" // Mi-24 Hind
        ], [ // unarmed boats
            "O_Boat_Transport_01_F" // Assault Boat (CUP has fuckall for OpFor water vics)
        ], [ // armed boats
            "CUP_B_RHIB_USMC", // RHIB HMG (CUP has fuckall for OpFor water vics)
            "CUP_B_RHIB2Turret_USMC" // RHIB HMG/GMG (CUP has fuckall for OpFor water vics)
        ], [ // soldier groups to load into the vics
            ["potato_e_ftl", "potato_e_ar", "potato_e_aar", "potato_e_lat", "potato_e_rifleman", "potato_e_rifleman"],
            ["potato_e_ftl", "potato_e_ar", "potato_e_aar", "potato_e_lat"]
        ]
    ]
];

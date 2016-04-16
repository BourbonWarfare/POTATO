#include "script_component.hpp"

GVAR(reinforceUnits) = [
    [
        "BlueFor (NATO)",
        west,
        "",
        ["B_MRAP_01_F","B_G_Offroad_01_F"],
        ["B_MRAP_01_gmg_F","B_MRAP_01_hmg_F"],
        ["B_Truck_01_transport_F","B_Truck_01_covered_F"],
        ["B_APC_Tracked_01_rcws_F","B_APC_Wheeled_01_cannon_F"],
        ["B_Heli_Light_01_F","B_Heli_Transport_03_unarmed_F"],
        ["B_Heli_Transport_01_F","B_Heli_Transport_01_camo_F","B_Heli_Transport_03_F"],
        ["B_Boat_Transport_01_F","B_G_Boat_Transport_01_F"],
        ["B_Boat_Armed_01_minigun_F"],
        [
            ["B_Soldier_TL_F","B_Soldier_AR_F","B_Soldier_AAR_F","B_Soldier_LAT_F","B_Soldier_F","B_Soldier_F"],
            ["B_Soldier_TL_F", "B_Soldier_AR_F", "B_Soldier_AAR_F", "B_Soldier_LAT_F"]
        ]
    ],
    [
        "BlueFor (RHS Vics)",
        west,
        "",
        ["rhsusf_m998_w_2dr","rhsusf_m998_d_2dr"],
        ["rhsusf_m1025_d_mk19","rhsusf_m1025_d_m2","rhsusf_m1025_w_mk19","rhsusf_m1025_w_m2","rhsusf_rg33_m2_d","rhsusf_rg33_m2_wd"],
        ["rhsusf_M1078A1P2_B_d_open_fmtv_usarmy","rhsusf_M1078A1P2_B_wd_open_fmtv_usarmy"],
        ["rhsusf_m113_usarmy","rhsusf_m113d_usarmy","rhsusf_m113_usarmy_MK19","rhsusf_m113d_usarmy_MK19","RHS_M2A2","RHS_M2A2_wd"],
        ["RHS_UH60M_US_base","RHS_CH_47F_base"],
        ["RHS_UH60M","RHS_UH60M_d","RHS_CH_47F"],
        ["B_Boat_Transport_01_F","B_G_Boat_Transport_01_F"],
        ["B_Boat_Armed_01_minigun_F"],
        [
            ["B_Soldier_TL_F","B_Soldier_AR_F","B_Soldier_AAR_F","B_Soldier_LAT_F","B_Soldier_F","B_Soldier_F"],
            ["B_Soldier_TL_F", "B_Soldier_AR_F", "B_Soldier_AAR_F", "B_Soldier_LAT_F"]
        ]
    ],
    [
        "Indy (AAF)",
        resistance,
        "",
        ["I_G_Offroad_01_F","I_MRAP_03_F"],
        ["I_MRAP_03_hmg_F","I_MRAP_03_gmg_F","I_G_Offroad_01_armed_F"],
        ["I_Truck_02_covered_F","I_Truck_02_transport_F"],
        ["I_APC_tracked_03_cannon_F","I_APC_Wheeled_03_cannon_F"],
        ["I_Heli_Transport_02_F", "I_Heli_light_03_unarmed_F"],
        ["I_Heli_light_03_F"],
        ["I_Boat_Transport_01_F", "I_G_Boat_Transport_01_F"],
        ["I_Boat_Armed_01_minigun_F"],
        [
            ["I_Soldier_TL_F","I_Soldier_AR_F","I_Soldier_AAR_F","I_Soldier_LAT_F","I_Soldier_F","I_Soldier_F"],
            ["I_Soldier_TL_F", "I_Soldier_AR_F", "I_Soldier_AAR_F", "I_Soldier_LAT_F"]
        ]
    ],
    [
        "Indy (RHS Vics)",
        resistance,
        "RHS_Main",
        ["RHS_UAZ_MSV_01","rhs_uaz_open_MSV_01"],
        ["rhs_uaz_dshkm_chdkz","rhs_uaz_ags_chdkz","rhs_uaz_spg9_chdkz"],
        ["rhs_gaz66_msv","rhs_gaz66o_msv"],
        ["rhs_btr60_msv","rhs_bmp1_vdv"],
        ["RHS_Mi8mt_vdv"],
        ["RHS_Mi8AMTSh_vdv"],
        ["I_Boat_Transport_01_F", "I_G_Boat_Transport_01_F"],
        ["I_Boat_Armed_01_minigun_F"],
        [
            ["I_Soldier_TL_F","I_Soldier_AR_F","I_Soldier_AAR_F","I_Soldier_LAT_F","I_Soldier_F","I_Soldier_F"],
            ["I_Soldier_TL_F", "I_Soldier_AR_F", "I_Soldier_AAR_F", "I_Soldier_LAT_F"]
        ]
    ],
    [
        "MSV (RHS)",
        east,
        "RHS_Main",
        ["rhs_tigr_msv","RHS_UAZ_MSV_01","rhs_uaz_open_MSV_01","rhs_tigr_ffv_msv","rhs_tigr_ffv_3camo_msv"],
        ["rhs_uaz_dshkm_chdkz","rhs_uaz_ags_chdkz","rhs_uaz_spg9_chdkz","rhs_tigr_msv","rhs_tigr_3camo_msv"],
        ["rhs_gaz66_msv","rhs_gaz66o_msv","rhs_gaz66_r142_msv","rhs_typhoon_vdv","RHS_Ural_MSV_01","RHS_Ural_Open_MSV_01","RHS_Ural_VDV_01"],
        ["rhs_btr60_msv","rhs_btr70_msv","rhs_btr80_msv","rhs_btr80a_msv","rhs_bmp1p_vdv","rhs_bmp2d_vdv","rhs_bmp3mera_msv"],
        ["rhs_ka60_grey","rhs_ka60_c","RHS_Mi8AMT_vdv","RHS_Mi8AMT_vvs","RHS_Mi8AMT_vvsc","RHS_Mi8mt_vdv","RHS_Mi8AMT_vvs","RHS_Mi8AMT_vvsc"],
        ["RHS_Mi24P_vdv","RHS_Mi8AMTSh_vdv","RHS_Mi8AMTSh_vvs","RHS_Mi8AMTSh_vvsc"],
        ["O_Boat_Transport_01_F","O_G_Boat_Transport_01_F"],
        ["O_Boat_Armed_01_hmg_F"],
        [
            ["rhs_msv_junior_sergeant","rhs_msv_machinegunner","rhs_msv_machinegunner_assistant","rhs_msv_at","rhs_msv_rifleman"],
            ["rhs_msv_sergeant","rhs_msv_machinegunner","rhs_msv_at","rhs_msv_rifleman","rhs_msv_marksman"]
        ]
    ],
    [
        "OpFor (CSAT)",
        east,
        "",
        ["O_MRAP_02_F","O_G_Offroad_01_F"],
        ["O_MRAP_02_hmg_F","O_MRAP_02_gmg_F"],
        ["O_Truck_02_covered_F","O_Truck_02_transport_F","O_Truck_03_transport_F","O_Truck_03_covered_F"],
        ["O_APC_Tracked_02_cannon_F","O_APC_Wheeled_02_rcws_F"],
        ["O_Heli_Light_02_unarmed_F","O_Heli_Transport_04_bench_F","O_Heli_Transport_04_covered_F"],
        ["O_Heli_Light_02_F","O_Heli_Light_02_v2_F"],
        ["O_Boat_Transport_01_F","O_G_Boat_Transport_01_F"],
        ["O_Boat_Armed_01_hmg_F"],
        [
            ["O_Soldier_TL_F","O_Soldier_AR_F","O_Soldier_AAR_F","O_Soldier_LAT_F","O_Soldier_F","O_Soldier_F"],
            ["O_Soldier_TL_F", "O_Soldier_AR_F", "O_Soldier_AAR_F", "O_Soldier_LAT_F"]
        ]
    ],
    [
        "OpFor (RHS Vics)",
        east,
        "RHS_Main",
        ["rhs_tigr_msv","RHS_UAZ_MSV_01","rhs_uaz_open_MSV_01"],
        ["rhs_uaz_dshkm_chdkz","rhs_uaz_ags_chdkz","rhs_uaz_spg9_chdkz"],
        ["rhs_gaz66_msv","rhs_gaz66o_msv","rhs_gaz66_r142_msv","rhs_typhoon_vdv","RHS_Ural_MSV_01","RHS_Ural_Open_MSV_01","RHS_Ural_VDV_01"],
        ["rhs_btr60_msv","rhs_btr70_msv","rhs_btr80_msv","rhs_btr80a_msv","rhs_bmp1p_vdv","rhs_bmp2d_vdv","rhs_bmp3mera_msv"],
        ["rhs_ka60_grey","rhs_ka60_c","RHS_Mi8AMT_vdv","RHS_Mi8AMT_vvs","RHS_Mi8AMT_vvsc","RHS_Mi8mt_vdv","RHS_Mi8AMT_vvs","RHS_Mi8AMT_vvsc"],
        ["RHS_Mi24P_vdv","RHS_Mi8AMTSh_vdv","RHS_Mi8AMTSh_vvs","RHS_Mi8AMTSh_vvsc"],
        ["O_Boat_Transport_01_F","O_G_Boat_Transport_01_F"],
        ["O_Boat_Armed_01_hmg_F"],
        [
            ["O_Soldier_TL_F","O_Soldier_AR_F","O_Soldier_AAR_F","O_Soldier_LAT_F","O_Soldier_F","O_Soldier_F"],
            ["O_Soldier_TL_F", "O_Soldier_AR_F", "O_Soldier_AAR_F", "O_Soldier_LAT_F"]
        ]
    ]
];

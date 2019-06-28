class CfgWeapons {
    class Launcher;
    class Launcher_Base_F: Launcher {
        class WeaponSlotsInfo;
    };

    /* HMG's */
    class GVAR(cup_m2): Launcher_Base_F {
        class ACE_CSW {
            type = "weapon";
            deployTime = 4;
            pickupTime = 4;
            class assembleTo {
                ace_csw_m3Tripod = "CUP_I_M2StaticMG_AAF";
                ace_csw_m3TripodLow = "CUP_I_M2StaticMG_MiniTripod_AAF";
            };
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 840;
        };
        displayName = "[CUP] M2 HMG";
        author = "Brandon";
        scope = 2;
        model = ACE_APL_PATH(ACE_CSW_Bag.p3d);
        modes[] = {};
        picture = ACE_CSW_PATH(UI\StaticHGMG_Icon.paa);
    };

    class GVAR(cup_kord): Launcher_Base_F {
        class ACE_CSW {
            type = "weapon";
            deployTime = 4;
            pickupTime = 4;
            class assembleTo {
                ace_csw_m3Tripod = "CUP_O_KORD_high_RU";
                ace_csw_m3TripodLow = "CUP_O_KORD_RU";
            };
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 840;
        };
        displayName = "[CUP] KORD HMG";
        author = "Brandon";
        scope = 2;
        model = ACE_APL_PATH(ACE_CSW_Bag.p3d);
        modes[] = {};
        picture = ACE_CSW_PATH(UI\StaticHGMG_Icon.paa);
    };
    class GVAR(cup_dshkm): Launcher_Base_F {
        class ACE_CSW {
            type = "weapon";
            deployTime = 4;
            pickupTime = 4;
            class assembleTo {
                ace_csw_m3Tripod = "CUP_O_DSHKM_ChDKZ";
                ace_csw_m3TripodLow = "CUP_O_DSHkM_MiniTriPod_ChDKZ";
            };
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 750;
        };
        displayName = "[CUP] DSHKM HMG";
        author = "Brandon";
        scope = 2;
        model = ACE_APL_PATH(ACE_CSW_Bag.p3d);
        modes[] = {};
        picture = ACE_CSW_PATH(UI\StaticHGMG_Icon.paa);
    };


    /* GMG's */
    class GVAR(cup_ags30): Launcher_Base_F {
        class ACE_CSW {
            type = "weapon";
            deployTime = 4;
            pickupTime = 4;
            class assembleTo {
                ace_csw_m3TripodLow = "CUP_B_AGS_ACR";
            };
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 350;
        };

        displayName = "[CUP] AGS-30 GMG";
        author = "Brandon";
        scope = 2;
        model = ACE_APL_PATH(ACE_CSW_Bag.p3d);
        modes[] = {};
        picture = ACE_CSW_PATH(UI\StaticHGMG_Icon.paa);
    };


    /* Launchers */
    class GVAR(cup_metis): Launcher_Base_F {
        class ACE_CSW {
            type = "weapon";
            deployTime = 4;
            pickupTime = 4;
            class assembleTo {
                ace_csw_m3TripodLow = "CUP_O_Metis_RU";
            };
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 300;
        };
        displayName = "[CUP] AT-13 Metis";
        author = "Brandon";
        scope = 2;
        model = ACE_APL_PATH(ACE_CSW_Bag.p3d);
        modes[] = {};
        picture = ACE_CSW_PATH(UI\StaticAT_Icon.paa);
    };

    class GVAR(cup_spg9): Launcher_Base_F {
        class ACE_CSW {
            type = "weapon";
            deployTime = 4;
            pickupTime = 4;
            class assembleTo {
                ace_csw_m3TripodLow = "CUP_O_SPG9_CHdKZ";
            };
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 1000;
        };

        displayName = "[CUP] SPG-9";
        author = "Brandon";
        scope = 2;
        model = ACE_APL_PATH(ACE_CSW_Bag.p3d);
        modes[] = {};
        picture = ACE_CSW_PATH(UI\StaticAT_Icon.paa);
    };


    // Affected Weapons: http://wiki.cup-arma3.org/index.php?title=Arma_3_CfgWeapons_Vehicle_Weapons#CUP_Vmlauncher_TOW_single_veh
    class GVAR(cup_tow): Launcher_Base_F {
        class ACE_CSW {
            type = "weapon";
            deployTime = 4;
            pickupTime = 4;
            class assembleTo {
                ace_csw_m3TripodLow = "CUP_B_TOW_TriPod_USMC";
            };
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 500;
        };
        displayName = "[CUP] BGM-71 TOW";
        author = "Brandon";
        scope = 2;
        model = ACE_APL_PATH(ACE_CSW_Bag.p3d);
        modes[] = {};
        picture = ACE_CSW_PATH(UI\StaticAT_Icon.paa);
    };

    /* Proxy Weapons */
    class CUP_Vhmg_M2_static;
    class GVAR(CUP_Vhmg_M2_static): CUP_Vhmg_M2_static {
        magazineReloadTime = 0.5;
    };
    class CUP_Vhmg_KORD_veh;
    class GVAR(CUP_Vhmg_KORD_veh): CUP_Vhmg_KORD_veh {
        magazineReloadTime = 0.5;
    };
    class CUP_Vhmg_DSHKM_veh;
    class GVAR(CUP_Vhmg_DSHKM_veh): CUP_Vhmg_DSHKM_veh {
        magazineReloadTime = 0.5;
    };
    class CUP_Vhmg_AGS30_veh;
    class GVAR(CUP_Vhmg_AGS30_veh): CUP_Vhmg_AGS30_veh {
        magazineReloadTime = 0.5;
    };
    class CUP_Vmlauncher_AT13_single_veh;
    class GVAR(CUP_Vmlauncher_AT13_single_veh): CUP_Vmlauncher_AT13_single_veh {
        magazineReloadTime = 0.5;
    };
    class CUP_Vacannon_SPG9_veh;
    class GVAR(CUP_Vacannon_SPG9_veh): CUP_Vacannon_SPG9_veh {
        magazineReloadTime = 0.5;
    };
    class CUP_Vmlauncher_TOW_single_veh;
    class GVAR(CUP_Vmlauncher_TOW_single_veh): CUP_Vmlauncher_TOW_single_veh {
        magazineReloadTime = 0.5;
    };

    // reloadable m119
    class CUP_Vcannon_M119_veh;
    class GVAR(proxy_L118): CUP_Vcannon_M119_veh {
        magazineReloadTime = 0.5;
    };
};

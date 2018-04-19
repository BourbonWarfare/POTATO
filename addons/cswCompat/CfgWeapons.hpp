class CfgWeapons {
	class Launcher;
    class Launcher_Base_F: Launcher {
        class WeaponSlotsInfo;
    };
    class potato_csw_base_carry: Launcher_Base_F {};
	/* HMG's */
    class GVAR(cup_m2_low): potato_csw_base_carry {
        class potato_csw_options {
            assembleTo = "CUP_B_M2StaticMG_MiniTripod_USMC";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 840;
        };
        
        displayName = "[CUP] M2 HMG (Low)";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticHGMG_Icon.paa);
    };
	
	class GVAR(cup_m2_high): potato_csw_base_carry {
        class potato_csw_options {
            assembleTo = "CUP_B_M2StaticMG_USMC";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 840;
        };
        
        displayName = "[CUP] M2 HMG";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticHGMG_Icon.paa);
    };

	class GVAR(cup_kord_low): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "CUP_O_KORD_RU";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 710;
        };
        
        displayName = "[CUP] KORD HMG (Low)";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticHGMG_Icon.paa);
	};
	
	class GVAR(cup_kord_high): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "CUP_O_KORD_high_RU";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 710;
        };
        
        displayName = "[CUP] KORD HMG";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticHGMG_Icon.paa);
	};
	
	class GVAR(cup_dshkm_low): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "CUP_O_DSHkM_MiniTriPod_ChDKZ";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 750;
        };
        
        displayName = "[CUP] DSHKM HMG (Low)";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticHGMG_Icon.paa);
	};
	
	class GVAR(cup_dshkm_high): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "CUP_O_DSHKM_ChDKZ";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 750;
        };
        
        displayName = "[CUP] DSHKM HMG";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticHGMG_Icon.paa);
	};
	
	class GVAR(rhs_nsv): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "RHS_NSV_TriPod_MSV";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 550;
        };
        
        displayName = "[RHS] NSV HMG";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticHGMG_Icon.paa);
	};
	
	// Affected Weapons: http://wiki.cup-arma3.org/index.php?title=Arma_3_CfgWeapons_Vehicle_Weapons#CUP_Vhmg_M2_static
    class CUP_Vhmg_M2_veh;
    class CUP_Vhmg_M2_static: CUP_Vhmg_M2_veh {};
	
	class GVAR(CUP_Vhmg_M2_static): CUP_Vhmg_M2_static {
		class potato_csw_options {
            deployTime = 10;
            pickupTime = 12;
            ammoLoadTime = 7;
            ammoUnloadTime = 5;
        };
		
		magazines[] = { potato_csw_HMG_Dummy_200Rnd_mag, potato_csw_HMG_Dummy_200Rnd_mag_red, potato_csw_HMG_Dummy_200Rnd_mag_green, potato_csw_HMG_Dummy_200Rnd_mag_yellow, potato_csw_100Rnd_127x99_mag, potato_csw_100Rnd_127x99_mag_red, potato_csw_100Rnd_127x99_mag_green, potato_csw_100Rnd_127x99_mag_yellow };
	};
	
	// Affected Weapons: http://wiki.cup-arma3.org/index.php?title=Arma_3_CfgWeapons_Vehicle_Weapons#CUP_Vhmg_KORD_veh
	class MGun;
	class CUP_Vhmg_KORD_veh: MGun {
        class potato_csw_options {
            deployTime = 10;
            pickupTime = 12;
            ammoLoadTime = 5;
            ammoUnloadTime = 4;
        };
        magazines[] = { GVAR(HMG_Dummy_200Rnd_127x108_mag), potato_csw_50Rnd_127x108_mag };
    };
	
	// Affected Weapons: http://wiki.cup-arma3.org/index.php?title=Arma_3_CfgWeapons_Vehicle_Weapons#CUP_Vhmg_DSHKM_veh
	class CUP_Vhmg_DSHKM_veh: MGun {};
	
	class GVAR(CUP_Vhmg_DSHKM_veh): CUP_Vhmg_DSHKM_veh {
		class potato_csw_options {
            deployTime = 10;
            pickupTime = 12;
            ammoLoadTime = 5;
            ammoUnloadTime = 4;
        };
        magazines[] = { GVAR(HMG_Dummy_200Rnd_127x108_mag), potato_csw_50Rnd_127x108_mag };
	};
	
	class rhs_weap_DSHKM;
	class rhs_weap_nsvt: rhs_weap_DSHKM {
		class potato_csw_options {
            deployTime = 10;
            pickupTime = 12;
            ammoLoadTime = 5;
            ammoUnloadTime = 4;
        };
        magazines[] = { GVAR(HMG_Dummy_200Rnd_127x108_mag), potato_csw_50Rnd_127x108_mag };
	};
	
	/* GMG's */
	class GVAR(cup_ags30): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "CUP_B_AGS_ACR";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 350;
        };
        
        displayName = "[CUP] AGS-30 GMG";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticHGMG_Icon.paa);
	};
	
	// Affected Weapons: http://wiki.cup-arma3.org/index.php?title=Arma_3_CfgWeapons_Vehicle_Weapons#CUP_Vhmg_AGS30_veh
	class GMG_20mm;
	class CUP_Vhmg_AGS30_veh: GMG_20mm {};
	
	class GVAR(CUP_Vhmg_AGS30_veh): CUP_Vhmg_AGS30_veh {
		class potato_csw_options {
            deployTime = 8;
            pickupTime = 15;
            ammoLoadTime = 5;
            ammoUnloadTime = 3;
        };
        magazines[] = { GVAR(GMG_Dummy_120Rnd_30mm_belt), GVAR(20Rnd_30mm_G_belt) };
	};
	
	class GVAR(rhs_mk19): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "RHS_MK19_TriPod_USMC_WD";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 770;
        };
        
        displayName = "[RHS] MK-19 GMG";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticHGMG_Icon.paa);
	};
	
	class RHS_MK19: GMG_20mm {
		class potato_csw_options {
            deployTime = 8;
            pickupTime = 15;
            ammoLoadTime = 5;
            ammoUnloadTime = 3;
        };
        magazines[] = { GVAR(GMG_Dummy_120Rnd_40mm_belt), GVAR(20Rnd_40mm_G_belt) };
	};
	
	/* Launchers */
	class GVAR(cup_metis): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "CUP_O_Metis_RU";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 300;
        };
        
        displayName = "[CUP] AT-13 Metis";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticAT_Icon.paa);
	};
	
	// Affected Weapons: http://wiki.cup-arma3.org/index.php?title=Arma_3_CfgWeapons_Vehicle_Weapons#CUP_Vmlauncher_AT13_single_veh
	class missiles_titan;
	class CUP_Vmlauncher_AT13_single_veh: missiles_titan {
		class potato_csw_options {
            deployTime = 15;
            pickupTime = 20;
            ammoLoadTime = 20; // 3 rounds a minute
            ammoUnloadTime = 25;
        };
        magazines[] = {GVAR(cup_at13_dummy), CUP_AT13_M };
	};
	
	class GVAR(cup_spg9): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "CUP_O_SPG9_CHdKZ";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 1000;
        };
        
        displayName = "[CUP] SPG-9";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticAT_Icon.paa);
	};
	
	// Affected Weapons: http://wiki.cup-arma3.org/index.php?title=Arma_3_CfgWeapons_Vehicle_Weapons#CUP_Vacannon_SPG9_veh
	class CUP_Vacannon_2A28;
	class CUP_Vacannon_SPG9_veh: CUP_Vacannon_2A28 {};
	
	class GVAR(CUP_Vacannon_SPG9_veh): CUP_Vacannon_SPG9_veh {
		class potato_csw_options {
            deployTime = 20;
            pickupTime = 25;
            ammoLoadTime = 10; // 6 rounds a minute
            ammoUnloadTime = 15;
        };
        magazines[] = {GVAR(cup_spg9_dummy_at), GVAR(cup_spg9_dummy_he) };
	};
	
	// Affected Weapons: http://wiki.cup-arma3.org/index.php?title=Arma_3_CfgWeapons_Vehicle_Weapons#CUP_Vmlauncher_TOW_single_veh
	class GVAR(cup_tow): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "CUP_B_TOW_TriPod_USMC";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 500;
        };
        
        displayName = "[CUP] BGM-71 TOW";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticAT_Icon.paa);
	};
	
	class CUP_Vmlauncher_TOW_veh;
	class CUP_Vmlauncher_TOW_single_veh: CUP_Vmlauncher_TOW_veh {};
	
	class GVAR(CUP_Vmlauncher_TOW_single_veh): CUP_Vmlauncher_TOW_single_veh {
		class potato_csw_options {
            deployTime = 40;
            pickupTime = 30;
            ammoLoadTime = 30; // 2 rounds a minute
            ammoUnloadTime = 35;
        };
        magazines[] = {GVAR(cup_tow_at_dummy), GVAR(cup_tow_at) };
	};
	
	class rhs_weap_9K114_launcher;
	class rhs_weap_9K115_launcher: rhs_weap_9K114_launcher {};
	class rhs_weap_9K115_2_launcher: rhs_weap_9K115_launcher {
		class potato_csw_options {
            deployTime = 15;
            pickupTime = 20;
            ammoLoadTime = 20; // 3 rounds a minute
            ammoUnloadTime = 25;
        };
        magazines[] = {GVAR(rhs_9m131m_dummy), GVAR(rhs_9m131f_dummy), GVAR(rhs_9m131m), GVAR(rhs_9m131f)};
	};
	
	class GVAR(rhs_metis): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "rhs_Metis_9k115_2_msv";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 300;
        };
        
        displayName = "[RHS] AT-13 Metis";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticAT_Icon.paa);
	};
	
	class GVAR(rhs_kornet): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "rhs_Kornet_9M133_2_msv";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 600;
        };
        
        displayName = "[RHS] AT-14 Kornet";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticAT_Icon.paa);
	};
	
	class rhs_weap_9K133_launcher: rhs_weap_9K115_launcher {
		class potato_csw_options {
            deployTime = 35;
            pickupTime = 25;
            ammoLoadTime = 30; // 2 rounds a minute
            ammoUnloadTime = 35;
        };
        magazines[] = {GVAR(rhs_9m133_dummy), GVAR(rhs_9m133f_dummy), GVAR(rhs_9m1331_dummy), GVAR(rhs_9m133m2_dummy), GVAR(rhs_9m133), GVAR(rhs_9m133f), GVAR(rhs_9m1331), GVAR(rhs_9m133m2)};
	};
	
	class GVAR(rhs_spg9): potato_csw_base_carry {
		class potato_csw_options {
            assembleTo = "rhsgref_ins_SPG9";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 1000;
        };
        
        displayName = "[RHS] SPG-9";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticAT_Icon.paa);
	};
	
	class GVAR(rhs_spg9m): GVAR(rhs_spg9) {
		class potato_csw_options {
            assembleTo = "rhs_SPG9M_msv";
            baseTripod = "potato_csw_m3Tripod";
            type = "weapon";
        };
        displayName = "[RHS] SPG-9M";
	};
	
	class RocketPods;
	class rhs_weap_SPG9: RocketPods {
		class potato_csw_options {
            deployTime = 20;
            pickupTime = 25;
            ammoLoadTime = 10; // 6 rounds a minute
            ammoUnloadTime = 15;
        };
        magazines[] = {GVAR(rhs_PG9V_dummy), GVAR(rhs_PG9N_dummy), GVAR(rhs_PG9VNT_dummy), GVAR(rhs_OG9VM_dummy), GVAR(rhs_OG9V_dummy),GVAR(rhs_PG9V), GVAR(rhs_PG9N), GVAR(rhs_PG9VNT), GVAR(rhs_OG9VM), GVAR(rhs_OG9V) };
	};
};


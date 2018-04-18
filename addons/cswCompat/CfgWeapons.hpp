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
        
        displayName = "M2 HMG (Low)";
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
        
        displayName = "M2 HMG";
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
            mass = 840;
        };
        
        displayName = "KORD HMG (Low)";
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
            mass = 840;
        };
        
        displayName = "KORD HMG";
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
            mass = 840;
        };
        
        displayName = "DSHKM HMG (Low)";
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
            mass = 840;
        };
        
        displayName = "DSHKM HMG";
        author = "Brandon";
        scope = 2;
        model = QPATHTOEF(csw,data\ACE_CSW_WeaponBag.p3d);
        modes[] = {};
        picture = QPATHTOEF(csw,UI\StaticHGMG_Icon.paa);
	};
	
	// Affected Weapons: http://wiki.cup-arma3.org/index.php?title=Arma_3_CfgWeapons_Vehicle_Weapons#CUP_Vhmg_M2_static
    class CUP_Vhmg_M2_veh;
    class CUP_Vhmg_M2_static: CUP_Vhmg_M2_veh {
        class potato_csw_options {
            deployTime = 10;
            pickupTime = 12;
            ammoLoadTime = 7;
            ammoUnloadTime = 16;
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
            ammoUnloadTime = 12;
        };
        magazines[] = { GVAR(HMG_Dummy_200Rnd_127x108_mag), potato_csw_50Rnd_127x108_mag };
    };
	
	// Affected Weapons: http://wiki.cup-arma3.org/index.php?title=Arma_3_CfgWeapons_Vehicle_Weapons#CUP_Vhmg_DSHKM_veh
	class CUP_Vhmg_DSHKM_veh: MGun {
		class potato_csw_options {
            deployTime = 10;
            pickupTime = 12;
            ammoLoadTime = 5;
            ammoUnloadTime = 12;
        };
        magazines[] = { GVAR(HMG_Dummy_200Rnd_127x108_mag), potato_csw_50Rnd_127x108_mag };
	};
	
	
	/* GMG's */
	
};


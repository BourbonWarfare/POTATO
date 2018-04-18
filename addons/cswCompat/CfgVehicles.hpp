class CfgVehicles {
	class LandVehicle;
    class StaticWeapon: LandVehicle {
        class ACE_Actions;
    };
    class StaticMGWeapon: StaticWeapon {
        class Turrets {
            class MainTurret;
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
    };
	class StaticGrenadeLauncher: StaticWeapon {
		class Turrets {
            class MainTurret;
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
	};
	
	class StaticATWeapon: StaticWeapon {
		class Turrets {
            class MainTurret;
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
	};
	
	/* HMG's */
	class CUP_M2StaticMG_base: StaticMGWeapon {
		class Turrets: Turrets {
            class MainTurret: MainTurret {
				weapons[] = { GVAR(CUP_Vhmg_M2_static) };
                magazines[] = {potato_csw_HMG_Dummy_200Rnd_mag};
            };
        };
		class potato_csw_options {
            enabled = 1;
            disassembleTo = QGVAR(cup_m2_high);
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                displayName = "M2";
            };
        };
	};
	
	class CUP_M2StaticMG_MiniTripod_base: CUP_M2StaticMG_base {
		class potato_csw_options {
            enabled = 1;
            disassembleTo = QGVAR(cup_m2_low);
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                displayName = "M2 Mini-Tripod";
            };
        };
	};
	
	class CUP_KORD_Base: StaticMGWeapon {
		class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {GVAR(HMG_Dummy_200Rnd_127x108_mag)};
            };
        };
	};
	
	class CUP_KORD_MiniTripod_Base: CUP_KORD_Base {
		class potato_csw_options {
            enabled = 1;
            disassembleTo = QGVAR(cup_kord_low);
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                displayName = "KORD Mini-Tripod";
            };
        };
	};
	
	class CUP_KORD_High_Base: CUP_KORD_Base {
		class potato_csw_options {
            enabled = 1;
            disassembleTo = QGVAR(cup_kord_high);
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                displayName = "KORD";
            };
        };
	};
	
	class CUP_DSHKM_base: StaticMGWeapon {
		class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {GVAR(HMG_Dummy_200Rnd_127x108_mag)};
				weapons[] = {GVAR(CUP_Vhmg_DSHKM_veh)};
            };
        };
		class potato_csw_options {
            enabled = 1;
            disassembleTo = QGVAR(cup_dshkm_high);
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                displayName = "DSHKM";
            };
        };
	};
	
	class CUP_DSHKM_MiniTripod_base: CUP_DSHKM_base {
		class potato_csw_options {
            enabled = 1;
            disassembleTo = QGVAR(cup_dshkm_low);
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                displayName = "DSHKM Mini-Tripod";
            };
        };
	};
	
	 /* GMG's */
	 class CUP_AGS_base: StaticGrenadeLauncher {
		class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {GVAR(GMG_Dummy_120Rnd_30mm_belt)};
				weapons[] = {GVAR(CUP_Vhmg_AGS30_veh)};
            };
        };
		class potato_csw_options {
            enabled = 1;
            disassembleTo = QGVAR(cup_ags30);
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                displayName = "AGS-30";
            };
        };
	 };
	 
	 /* Launchers */
	 class CUP_Metis_Base: StaticATWeapon {
		class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {GVAR(cup_at13_dummy)};
            };
        };
		class potato_csw_options {
            enabled = 1;
            disassembleTo = QGVAR(cup_metis);
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                displayName = "Metis AT-13";
            };
        };
	 };
	 
	 class CUP_SPG9_base: StaticATWeapon {
		class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {GVAR(cup_spg9_dummy_at)};
				weapons[] = {GVAR(CUP_Vacannon_SPG9_veh)};
            };
        };
		class potato_csw_options {
            enabled = 1;
            disassembleTo = QGVAR(cup_spg9);
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                displayName = "SPG-9";
            };
        };
	 };
	 
	 class CUP_TOW_TriPod_base: StaticATWeapon {
		class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {GVAR(cup_tow_at_dummy)};
				weapons[] = {GVAR(CUP_Vmlauncher_TOW_single_veh)};
            };
        };
		class potato_csw_options {
            enabled = 1;
            disassembleTo = QGVAR(cup_tow);
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                displayName = "BGM-71 TOW";
            };
        };
	 };
};


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
	
	/* HMG's */
	class CUP_M2StaticMG_base: StaticMGWeapon {
		class Turrets: Turrets {
            class MainTurret: MainTurret {
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
};


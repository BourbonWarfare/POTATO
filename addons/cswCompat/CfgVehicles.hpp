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
	
	class CUP_M2StaticMG_base: StaticMGWeapon {
		class Turrets: Turrets {
            class MainTurret: MainTurret {};
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {};
        };
	};
	
	class CUP_M2StaticMG_MiniTripod_base: CUP_M2StaticMG_base {
		class potato_csw_options {
            enabled = 1;
            disassembleTo = QGVAR(cup_m2_low);
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {potato_csw_HMG_Dummy_200Rnd_mag};
            };
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                displayName = "M2 Mini-Tripod";
            };
        };
	};
};


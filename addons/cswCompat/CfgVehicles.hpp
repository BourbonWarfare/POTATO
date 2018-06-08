class CfgVehicles {

    // todod RHS, temp configs to fix inheritance
    class AT_01_base_F;
    class rhs_SPG9_base: AT_01_base_F {
        class ACE_CSW {
            enabled = 0;
        };
    };
    class rhs_Metis_Base: AT_01_base_F {
        class ACE_CSW {
            enabled = 0;
        };
    };
    class rhs_Kornet_Base: AT_01_base_F {
        class ACE_CSW {
            enabled = 0;
        };
    };









    /* HMG's */
    class StaticMGWeapon;
    class CUP_M2StaticMG_base: StaticMGWeapon {
        class ACE_CSW {
            enabled = 1;
            magazineLocation = "_target selectionPosition 'magazine'";
            disassembleWeapon = QGVAR(cup_m2); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m3Tripod"; // turret [CfgVehicles]
            desiredAmmo = 100;
            ammoLoadTime = 3;
            ammoUnloadTime = 3;
        };
    };
    class CUP_M2StaticMG_MiniTripod_base: CUP_M2StaticMG_base {
        class ACE_CSW: ACE_CSW {
            disassembleTurret = "ace_csw_m3TripodLow"; // turret [CfgVehicles]
        };
    };

    class CUP_KORD_Base;
    class CUP_KORD_MiniTripod_Base: CUP_KORD_Base {
        class ACE_CSW {
            enabled = 1;
            magazineLocation = "_target selectionPosition 'magazine'";
            disassembleWeapon = QGVAR(cup_kord); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m3TripodLow"; // turret [CfgVehicles]
            desiredAmmo = 50;
            ammoLoadTime = 3;
            ammoUnloadTime = 3;
        };
    };
    class CUP_KORD_High_Base: CUP_KORD_Base {
        class ACE_CSW {
            enabled = 1;
            magazineLocation = "_target selectionPosition 'magazine'";
            disassembleWeapon = QGVAR(cup_kord); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m3Tripod"; // turret [CfgVehicles]
            desiredAmmo = 50;
            ammoLoadTime = 3;
            ammoUnloadTime = 3;
        };
    };

    class CUP_DSHKM_base: StaticMGWeapon { // no good mem point?
        class ACE_CSW {
            enabled = 1;
            // magazineLocation = "_target selectionPosition 'magazine'";
            disassembleWeapon = QGVAR(cup_dshkm); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m3Tripod"; // turret [CfgVehicles]
            desiredAmmo = 50;
            ammoLoadTime = 3;
            ammoUnloadTime = 3;
        };
    };
    class CUP_DSHKM_MiniTripod_base: CUP_DSHKM_base {
        class ACE_CSW {
            enabled = 1;
            // magazineLocation = "_target selectionPosition 'magazine'";
            disassembleWeapon = QGVAR(cup_dshkm); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m3TripodLow"; // turret [CfgVehicles]
            desiredAmmo = 100;
            ammoLoadTime = 3;
            ammoUnloadTime = 3;
        };
    };


    // /* GMG's */
    class StaticGrenadeLauncher;
    class CUP_AGS_base: StaticGrenadeLauncher {
        class ACE_CSW {
            enabled = 1;
            magazineLocation = "_target selectionPosition 'otochlaven'";
            disassembleWeapon = QGVAR(cup_ags30); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m3TripodLow"; // turret [CfgVehicles]
            desiredAmmo = 29;
            ammoLoadTime = 3;
            ammoUnloadTime = 3;
        };
    };


    // /* Launchers */
    class StaticATWeapon;
    class CUP_Metis_Base: StaticATWeapon {
        class ACE_CSW {
            enabled = 1;
            magazineLocation = "_target selectionPosition 'gun'";
            disassembleWeapon = QGVAR(cup_metis); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m3TripodLow"; // turret [CfgVehicles]
            desiredAmmo = 1;
            ammoLoadTime = 3;
            ammoUnloadTime = 3;
        };
    };

    class CUP_SPG9_base: StaticATWeapon {
        class ACE_CSW {
            enabled = 1;
            magazineLocation = "_target selectionPosition 'otochlaven'";
            disassembleWeapon = QGVAR(cup_spg9); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m3TripodLow"; // turret [CfgVehicles]
            desiredAmmo = 1;
            ammoLoadTime = 3;
            ammoUnloadTime = 3;
        };
    };

    class CUP_TOW_TriPod_base: StaticATWeapon {
        class ACE_CSW {
            enabled = 1;
            magazineLocation = "_target selectionPosition 'otochlaven'";
            disassembleWeapon = QGVAR(cup_tow); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m3TripodLow"; // turret [CfgVehicles]
            desiredAmmo = 1;
            ammoLoadTime = 3;
            ammoUnloadTime = 3;
        };
    };

};


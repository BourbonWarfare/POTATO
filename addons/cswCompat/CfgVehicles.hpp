class CBA_Extended_EventHandlers;
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

    // reloadable m119
    class ACE_Box_82mm_Mo_HE;
    class GVAR(105mmAmmoBox): ACE_Box_82mm_Mo_HE {
        displayName = "Potato M119 105mm Ammo Box (CSW)";
        author = "potato csw mod";
        maximumLoad = 6000;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(GVAR(105mm_117_he),24);
            MACRO_ADDMAGAZINE(GVAR(105mm_117_smoke),24);
        };
    };
    class CUP_M119_base;
    class GVAR(cup_m119_csw): CUP_M119_base {
        displayName = "m119 (CSW loading)";
        author = "CUP (potato csw mod)";
        scope = 2;
        scopeCurator = 2;
        side = 1;
        faction = "BLU_F";
        crew = "B_Soldier_F";
        typicalCargo[] = {"B_Soldier_F"};
        class ACE_CSW {
            enabled = 1;
            proxyWeapon = QGVAR(proxy_L118);
            magazineLocation = "_target selectionPosition 'otochlaven'";
            ammoLoadTime = 5;
            ammoUnloadTime = 5;
        };
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
            init = "(_this select 0) setVariable ['ace_csw_assemblyMode', 2];";
        };
    };









    /* HMG's */
    class StaticMGWeapon;
    class CUP_M2StaticMG_base: StaticMGWeapon {
        class ACE_CSW {
            enabled = 1;
            proxyWeapon = QGVAR(CUP_Vhmg_M2_static);
            magazineLocation = "_target selectionPosition 'magazine'";
            disassembleWeapon = QGVAR(cup_m2); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m3Tripod"; // turret [CfgVehicles]
            desiredAmmo = 100;
            ammoLoadTime = 10; // https://youtu.be/BwoFAFDEJAY?t=37
            ammoUnloadTime = 8;
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
            proxyWeapon = QGVAR(CUP_Vhmg_KORD_veh);
            magazineLocation = "_target selectionPosition 'magazine'";
            disassembleWeapon = QGVAR(cup_kord); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_kordTripodLow"; // turret [CfgVehicles]
            desiredAmmo = 50;
            ammoLoadTime = 10;
            ammoUnloadTime = 9;
        };
    };
    class CUP_KORD_High_Base: CUP_KORD_Base {
        class ACE_CSW {
            enabled = 1;
            proxyWeapon = QGVAR(CUP_Vhmg_KORD_veh);
            magazineLocation = "_target selectionPosition 'magazine'";
            disassembleWeapon = QGVAR(cup_kord); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_kordTripod"; // turret [CfgVehicles]
            desiredAmmo = 50;
            ammoLoadTime = 10;
            ammoUnloadTime = 8;
        };
    };

    class CUP_DSHKM_base: StaticMGWeapon { // no good mem point?
        class ACE_CSW {
            enabled = 1;
            // magazineLocation = "_target selectionPosition 'magazine'";
            proxyWeapon = QGVAR(CUP_Vhmg_DSHKM_veh);
            disassembleWeapon = QGVAR(cup_dshkm); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_kordTripod"; // turret [CfgVehicles]
            desiredAmmo = 50;
            ammoLoadTime = 10;
            ammoUnloadTime = 8;
        };
    };
    class CUP_DSHKM_MiniTripod_base: CUP_DSHKM_base {
        class ACE_CSW {
            enabled = 1;
            proxyWeapon = QGVAR(CUP_Vhmg_DSHKM_veh);
            // magazineLocation = "_target selectionPosition 'magazine'";
            disassembleWeapon = QGVAR(cup_dshkm); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_kordTripodLow"; // turret [CfgVehicles]
            desiredAmmo = 100;
            ammoLoadTime = 10;
            ammoUnloadTime = 8;
        };
    };


    // /* GMG's */
    class StaticGrenadeLauncher;
    class CUP_AGS_base: StaticGrenadeLauncher {
        class ACE_CSW {
            enabled = 1;
            proxyWeapon = QGVAR(CUP_Vhmg_AGS30_veh);
            magazineLocation = "_target selectionPosition 'otochlaven'";
            disassembleWeapon = QGVAR(cup_ags30); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_sag30Tripod"; // turret [CfgVehicles]
            desiredAmmo = 29;
            ammoLoadTime = 10; // https://youtu.be/XZYvCUSusQI?t=130
            ammoUnloadTime = 8;
        };
    };


    // /* Launchers */
    class StaticATWeapon;
    class CUP_Metis_Base: StaticATWeapon {
        class ACE_CSW {
            enabled = 1;
            proxyWeapon = QGVAR(CUP_Vmlauncher_AT13_single_veh);
            magazineLocation = "_target selectionPosition 'gun'";
            disassembleWeapon = QGVAR(cup_metis); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m3TripodLow"; // turret [CfgVehicles]
            desiredAmmo = 1;
            ammoLoadTime = 7; // https://youtu.be/RUJSaeE3EKY?t=13
            ammoUnloadTime = 5;
        };
    };

    class CUP_SPG9_base: StaticATWeapon {
        class ACE_CSW {
            enabled = 1;
            proxyWeapon = QGVAR(CUP_Vacannon_SPG9_veh);
            magazineLocation = "_target selectionPosition 'otochlaven'";
            disassembleWeapon = QGVAR(cup_spg9); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_spg9Tripod"; // turret [CfgVehicles]
            desiredAmmo = 1;
            ammoLoadTime = 5; // https://youtu.be/xc9-MkCxq5c?t=23
            ammoUnloadTime = 3;
        };
    };

    class CUP_TOW_TriPod_base: StaticATWeapon {
        class ACE_CSW {
            enabled = 1;
            proxyWeapon = QGVAR(CUP_Vmlauncher_TOW_single_veh);
            magazineLocation = "_target selectionPosition 'otochlaven'";
            disassembleWeapon = QGVAR(cup_tow); // carry weapon [CfgWeapons]
            disassembleTurret = "ace_csw_m220Tripod"; // turret [CfgVehicles]
            desiredAmmo = 1;
            ammoLoadTime = 8; // https://youtu.be/3MeR97UXrKs?t=113
            ammoUnloadTime = 5;
        };
    };

};


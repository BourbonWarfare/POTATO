class CfgWeapons {
    class CUP_Vacannon_2A42_veh;
    class CUP_Vacannon_2A72_veh: CUP_Vacannon_2A42_veh {
        class LowROF;
        class Close;
        class short;
        class medium;
        class Far;
    };
    class GVARMAIN(TBD_2A27_WEAPON): CUP_Vacannon_2A72_veh {
        magazines[] = {
            QGVARMAIN(tbd_120Rnd_2a27_ap_magazine),
            QGVARMAIN(tbd_180Rnd_2a27_ap_magazine),
            QGVARMAIN(tbd_180Rnd_2a27_he_magazine),
            QGVARMAIN(tbd_120Rnd_2a27_he_magazine)
        };
        magazineReloadTime = 0.5;
        muzzles[] = {"this"};
        reloadMagazineSound[] = {"\x\tbd_mtlb\addons\main\sounds\30mmcycle.ogg",10,1,20};
        reloadSound[] = {};
        reloadTime = 0.3;
        selectionFireAnim = "autocannon_zasleh";
        class gunParticles {
            class Effect1 {
                directionName = "barrel_middle_dir";
                effectName = "MachineGunCloud";
                positionName = "barrel_middle";
            };
            class Effect2 {
                directionName = "usti hlavne_dir";
                effectName = "AutoCannonFired";
                positionName = "usti hlavne";
            };
        };
        class LowROF: LowROF {
            reloadTime = 0.3;
            displayName = "2A27 (200 rpm)";
        };
        class Close: Close {
            reloadTime = 0.3;
        };
        class short: short {
            reloadTime = 0.3;
        };
        class medium: medium {
            reloadTime = 0.3;
        };
        class Far: Far {
            reloadTime = 0.3;
        };
    };

    class CUP_Vhmg_PKT_veh_Noeject;
    class GVARMAIN(TBD_PKT_WEAPON): CUP_Vhmg_PKT_veh_Noeject {
        magazineReloadTime = 19;
        magazines[] = {QGVARMAIN(tbd_pkt_magazine)};
        selectionFireAnim = "machinegun_zasleh";
        class gunParticles {
            class Effect1 {
                directionName = "kulas_dir";
                effectName = "MachineGunCloud";
                positionName = "kulas";
            };
        };
    };
    class GVARMAIN(TBD_PKT_INTERNAL_WEAPON): GVARMAIN(TBD_PKT_WEAPON) {
        magazineReloadTime = 1;
        magazines[] = {QGVARMAIN(tbd_pkt_internal_magazine)};
    };

    class CUP_Vhmg_KPVT_veh;
    class GVARMAIN(TBD_KPVT_WEAPON): CUP_Vhmg_KPVT_veh {
        magazineReloadTime = 19;
        magazines[] = {QGVARMAIN(tbd_kpvt_magazine)};
        selectionFireAnim = "autocannon_zasleh";
        class gunParticles {
            class Effect1 {
                directionName = "usti hlavne_dir";
                effectName = "MachineGunCloud";
                positionName = "usti hlavne";
            };
        };
    };

    class CUP_Vhmg_AGS30_veh;
    class GVARMAIN(TBD_AGS17_WEAPON): CUP_Vhmg_AGS30_veh {
        magazineReloadTime = 15;
        magazines[] = {QGVARMAIN(tbd_ags17_magazine)};
        selectionFireAnim = "ags_zasleh";
        class gunParticles {
            class Effect1 {
                directionName = "agsdust_dir";
                effectName = "MachineGunCloud";
                positionName = "agsdust";
            };
        };
    };
};

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
            "CUP_180Rnd_TE1_Green_Tracer_30mmAP_2A42_M",
            "CUP_120Rnd_TE1_Green_Tracer_30mmHE_2A42_M",
            "CUP_120Rnd_TE1_Green_Tracer_30mmAP_2A42_M",
            "CUP_180Rnd_TE1_Green_Tracer_30mmHE_2A42_M"
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
    };

    class CUP_Vhmg_KPVT_veh;
    class GVARMAIN(TBD_KPVT_WEAPON): CUP_Vhmg_KPVT_veh {
        magazineReloadTime = 19;
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

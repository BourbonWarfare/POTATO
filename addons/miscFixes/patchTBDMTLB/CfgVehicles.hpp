class CfgVehicles {
    class Tank_F;
    class APC_Tracked_01_base_F: Tank_F {
        class Turrets;
    };
    class tbd_mtlb_base: APC_Tracked_01_base_F {
        class AnimationSources;
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class tbd_mtlb_pkt: tbd_mtlb_base {
        class AnimationSources: AnimationSources {
            class machinegun_reload_source {
                weapon = QGVARMAIN(TBD_PKT_WEAPON);
            };
            /*class machinegun_ammoRandom_source: machinegun_reload_source {
                weapon = QGVARMAIN(TBD_KPVT_WEAPON);
            };*/
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                ejectDeadGunner = 1;
                magazines[] = {
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine)
                };
                weapons[] = {QGVARMAIN(TBD_PKT_WEAPON)};
            };
        };
    };
    class tbd_mtlb: tbd_mtlb_base {
        class AnimationSources: AnimationSources {};
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                ejectDeadGunner = 1;
            };
        };
    };
    class tbd_mtlb_6ma: tbd_mtlb {
        class AnimationSources: AnimationSources {
            class machinegun_reload_source {
                weapon = QGVARMAIN(TBD_PKT_WEAPON);
            };
            /*class machinegun_ammoRandom_source: machinegun_reload_source {
                weapon = QGVARMAIN(TBD_KPVT_WEAPON);
            };*/
            class autocannon_reload_source {
                weapon = QGVARMAIN(TBD_KPVT_WEAPON);
            };
            /*class autocannon_ammoRandom_source: autocannon_reload_source {
                weapon = QGVARMAIN(TBD_KPVT_WEAPON);
            };*/
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine)
                };
                weapons[] = {QGVARMAIN(TBD_KPVT_WEAPON), QGVARMAIN(TBD_PKT_WEAPON)};
            };
        };
    };
    class tbd_mtlb_6ma1: tbd_mtlb {
        class AnimationSources: AnimationSources {
            class machinegun_reload_source {
                weapon = QGVARMAIN(TBD_PKT_WEAPON);
            };
            /*class machinegun_ammoRandom_source: machinegun_reload_source {
                weapon = QGVARMAIN(TBD_KPVT_WEAPON);
            };*/
            class autocannon_reload_source {
                weapon = QGVARMAIN(TBD_KPVT_WEAPON);
            };
            /*class autocannon_ammoRandom_source: autocannon_reload_source {
                weapon = QGVARMAIN(TBD_KPVT_WEAPON);
            };*/
            class ags_reload_source {
                weapon = QGVARMAIN(TBD_AGS17_WEAPON);
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_pkt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_kpvt_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine)
                };
                weapons[] = {QGVARMAIN(TBD_KPVT_WEAPON), QGVARMAIN(TBD_AGS17_WEAPON), QGVARMAIN(TBD_PKT_WEAPON)};
            };
        };
    };
    class tbd_mtlb_6mb: tbd_mtlb {
        class AnimationSources: AnimationSources {
            class machinegun_reload_source {
                weapon = QGVARMAIN(TBD_PKT_INTERNAL_WEAPON);
            };
            /*class machinegun_ammoRandom_source: machinegun_reload_source {
                weapon = QGVARMAIN(TBD_KPVT_WEAPON);
            };*/
            class autocannon_reload_source {
                weapon = QGVARMAIN(TBD_2A27_WEAPON);
            };
            class autocannon_recoil_source {
                weapon = QGVARMAIN(TBD_2A27_WEAPON);
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {
                    QGVARMAIN(tbd_pkt_internal_magazine),
                    QGVARMAIN(tbd_180Rnd_2a27_ap_magazine),
                    QGVARMAIN(tbd_120Rnd_2a27_he_magazine)
                };
                weapons[] = {QGVARMAIN(TBD_2A27_WEAPON), QGVARMAIN(TBD_PKT_INTERNAL_WEAPON)};
            };
        };
    };
    class tbd_mtlb_6mb2: tbd_mtlb {
        class AnimationSources: AnimationSources {
            class machinegun_reload_source {
                weapon = QGVARMAIN(TBD_PKT_INTERNAL_WEAPON);
            };
            /*class machinegun_ammoRandom_source: machinegun_reload_source {
                weapon = QGVARMAIN(TBD_KPVT_WEAPON);
            };*/
            class autocannon_reload_source {
                weapon = QGVARMAIN(TBD_2A27_WEAPON);
            };
            class autocannon_recoil_source {
                weapon = QGVARMAIN(TBD_2A27_WEAPON);
            };
            class ags_reload_source {
                weapon = QGVARMAIN(TBD_AGS17_WEAPON);
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {
                    QGVARMAIN(tbd_pkt_internal_magazine),
                    QGVARMAIN(tbd_180Rnd_2a27_ap_magazine),
                    QGVARMAIN(tbd_120Rnd_2a27_he_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine),
                    QGVARMAIN(tbd_ags17_magazine)
                };
                weapons[] = {QGVARMAIN(TBD_2A27_WEAPON), QGVARMAIN(TBD_AGS17_WEAPON), QGVARMAIN(TBD_PKT_INTERNAL_WEAPON)};
            };
        };
    };
};

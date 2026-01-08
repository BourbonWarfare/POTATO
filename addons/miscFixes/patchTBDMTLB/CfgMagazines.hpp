class CfgMagazines {
    class CUP_250Rnd_TE1_Green_Tracer_762x54_PKT_M;
    class GVARMAIN(tbd_pkt_magazine): CUP_250Rnd_TE1_Green_Tracer_762x54_PKT_M {
        ammo = QGVARMAIN(tbd_ammo_pkt);
        count = 250;
        initSpeed = 852;
        maxLeadSpeed = 100;
    };
    class GVARMAIN(tbd_pkt_internal_magazine): GVARMAIN(tbd_pkt_magazine) {
        count = 2500;
    };
    class CUP_50Rnd_TE2_LRT4_Green_Tracer_145x115_KPVT_M;
    class GVARMAIN(tbd_kpvt_magazine): CUP_50Rnd_TE2_LRT4_Green_Tracer_145x115_KPVT_M {
        ammo = QGVARMAIN(tbd_ammo_kpvt);
        initSpeed = 1000;
        maxLeadSpeed = 100;
    };

    class CUP_180Rnd_TE1_Green_Tracer_30mmAP_2A42_M;
    class GVARMAIN(tbd_180Rnd_2a27_ap_magazine): CUP_180Rnd_TE1_Green_Tracer_30mmAP_2A42_M {
        ammo = QGVARMAIN(tbd_ammo_2a27_ap);
        initSpeed = 1000;
        maxLeadSpeed = 100;
    };
    class CUP_120Rnd_TE1_Green_Tracer_30mmAP_2A42_M;
    class GVARMAIN(tbd_120Rnd_2a27_ap_magazine): CUP_120Rnd_TE1_Green_Tracer_30mmAP_2A42_M {
        ammo = QGVARMAIN(tbd_ammo_2a27_ap);
        initSpeed = 1000;
        maxLeadSpeed = 100;
    };

    class CUP_180Rnd_TE1_Green_Tracer_30mmHE_2A42_M;
    class GVARMAIN(tbd_180Rnd_2a27_he_magazine): CUP_180Rnd_TE1_Green_Tracer_30mmHE_2A42_M {
        ammo = QGVARMAIN(tbd_ammo_2a27_he);
        initSpeed = 900;
        maxLeadSpeed = 100;
    };
    class CUP_120Rnd_TE1_Green_Tracer_30mmHE_2A42_M;
    class GVARMAIN(tbd_120Rnd_2a27_he_magazine): CUP_120Rnd_TE1_Green_Tracer_30mmHE_2A42_M {
        ammo = QGVARMAIN(tbd_ammo_2a27_he);
        initSpeed = 900;
        maxLeadSpeed = 100;
    };

    class CUP_29Rnd_30mm_AGS30_M;
    class GVARMAIN(tbd_ags17_magazine): CUP_29Rnd_30mm_AGS30_M {
        ammo = QGVARMAIN(tbd_ammo_asg17);
        airFriction = -0.001;
        count = 30;
        typicalSpeed = 185;
    };
};

class CfgMagazines {
    // C5 & C6 magazines
    class CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M;
    class GVARMAIN(300Rnd_TE3_Red_Tracer_762x51_C5_M): CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M {
        count = 300;
        tracersEvery = 3;
    };
    class ACEGVAR(compat_sog,m1919_250);
    class GVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M): ACEGVAR(compat_sog,m1919_250) {
        ammo = "B_762x51_Tracer_Red";
        count = 250;
        descriptionShort = "250Rnd C5 Belt. <br />Caliber: 7.62x51mm. <br />1:2 tracer, used in C5 GPMG";
        displayName = "[CSW] 250Rnd C5 Box";
        tracersEvery = 3;
    };
    //// 105x617mmR Rounds
    // Smoke rounds
    class gm_1Rnd_105x617mm_apds_t_dm13;
    class GVARMAIN(1Rnd_105x617mm_wp_t_m416): gm_1Rnd_105x617mm_apds_t_dm13 {
        author = "Bourbon Warfare";
        ammo = QGVARMAIN(Sh_105x617mmR_m416_WPT);
        descriptionShort = "Caliber: 105x617mm WP-T M416<br />Rounds: 1<br />Used in: L/7";
        displayName = "105mm WP-T M416";
        displaynameshort = "WP-T";
        nameSound = "cannon";
    };
    class GVARMAIN(5Rnd_105x617mm_wp_t_m416): GVARMAIN(1Rnd_105x617mm_wp_t_m416) {
        count = 5;
    };
    class GVARMAIN(30Rnd_105x617mm_wp_t_m416): GVARMAIN(1Rnd_105x617mm_wp_t_m416) {
        count = 30;
    };
    class gm_30Rnd_105x617mm_apfsds_t_dm33;
    class GVARMAIN(25Rnd_105x617mm_apfsds_t_dm33): gm_30Rnd_105x617mm_apfsds_t_dm33 {
        count = 25;
    };

};

class CfgMagazines {
    class CA_Magazine;

    // 556x45
    class CUP_30Rnd_556x45_Stanag: CA_Magazine {
        modelSpecial = "rhsusf\addons\rhsusf_weapons\mag_proxies\rhs_mag_556x45_stanag_usgi_30rnd";
        modelSpecialIsProxy = 1;
    };
    class CUP_200Rnd_TE4_Green_Tracer_556x45_M249: CA_Magazine {
        modelSpecial = "rhsusf\addons\rhsusf_weapons\mag_proxies\rhs_mag_556x45_m249_pouch_200rnd";
        modelSpecialIsProxy = 1;
    };
    class CUP_100Rnd_TE4_Green_Tracer_556x45_M249: CUP_200Rnd_TE4_Green_Tracer_556x45_M249 {
        modelSpecial = "rhsusf\addons\rhsusf_weapons\mag_proxies\rhs_mag_556x45_m249_pouch_100rnd";
        modelSpecialIsProxy = 1;
    };
    class 200Rnd_556x45_Box_F: CA_Magazine {
        modelSpecial = "rhsusf\addons\rhsusf_weapons\mag_proxies\rhs_mag_556x45_m249_pouch_100rnd";
        modelSpecialIsProxy = 1;
    };

    // 545x39
    class CUP_30Rnd_545x39_AK_M: CA_Magazine {
        modelSpecial = "\rhsafrf\addons\rhs_weapons\mag_proxies\rhs_mag_545x39_6l20_30rnd.p3d";
        modelSpecialIsProxy = 1;
    };
    class CUP_75Rnd_TE4_LRT4_Green_Tracer_545x39_RPK_M;
    class CUP_45Rnd_TE4_LRT4_Green_Tracer_545x39_RPK_M: CUP_75Rnd_TE4_LRT4_Green_Tracer_545x39_RPK_M {
        modelSpecial = "\rhsafrf\addons\rhs_weapons\mag_proxies\rhs_mag_545x39_6l18_45rnd.p3d";
        modelSpecialIsProxy = 1;
    };


    // 762x39
    class CUP_30Rnd_762x39_AK47_M: CA_Magazine {
        modelSpecial = "rhsafrf\addons\rhs_weapons\mag_proxies\rhs_mag_762x39_steel_30rnd";
        modelSpecialIsProxy = 1;
    };
    class 150Rnd_762x51_Box: CA_Magazine {
        modelSpecial = "rhsusf\addons\rhsusf_weapons\mag_proxies\rhs_mag_762x51_m240_pouch_100rnd";
        modelSpecialIsProxy = 1;
    };
    class CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M: CA_Magazine {
        modelSpecial = "rhsusf\addons\rhsusf_weapons\mag_proxies\rhs_mag_762x51_m240_pouch_100rnd";
        modelSpecialIsProxy = 1;
    };
    class hlc_100Rnd_762x51_B_M60E4: 30Rnd_556x45_Stanag {
        modelSpecial = "rhsusf\addons\rhsusf_weapons\mag_proxies\rhs_mag_762x51_m240_pouch_100rnd";
        modelSpecialIsProxy = 1;
    };
};

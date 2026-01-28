class CfgWeapons {
    class mortar_155mm_AMOS;
    class CUP_Vcannon_D30_veh: mortar_155mm_AMOS {
        magazines[] += {QGVARMAIN(DOUBLES(CUP_30Rnd_122mmHE_D30_M,noFrag)),QGVARMAIN(DOUBLES(CUP_30Rnd_122mmHE_D30_M,noSplash))};
        magazineWell[]  = {};
    };
    class CUP_Vcannon_M119_veh: CUP_Vcannon_D30_veh {
        magazineWell[]  = {QGVARMAIN(105x372mmR)};

    };
    //ADD_MAGAZINES_1_WEAPON(CUP_Vcannon_D30_veh,CUP_Vcannon_M119_veh,CUP_30Rnd_105mmHE_M119_M);
    class rockets_230mm_GAT;
    ADD_MAGAZINES_1_WEAPON(rockets_230mm_GAT,CUP_Vmlauncher_MLRS_veh,CUP_12Rnd_MLRS_HE);
    ADD_MAGAZINES_1_WEAPON(rockets_230mm_GAT,CUP_Vmlauncher_GRAD_veh,CUP_40Rnd_GRAD_HE);
};

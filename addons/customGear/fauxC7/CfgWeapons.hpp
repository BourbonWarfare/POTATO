class Mode_FullAuto;
class CfgWeapons {
    // Adds C7, C7GL, and C7A2, C7A2
    class CUP_arifle_M16A1E1;
    class potato_fauxC7_c7: CUP_arifle_M16A1E1 {
        author = "Potato";
        displayName = "C7";
        modes[] = {"Single","FullAuto","Burst_medium","single_medium_optics1","single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_m16a4_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_spar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
            soundBurst = 0;
            ffCount = 3;
            dispersion = 0.0006;
            reloadTime = 0.075;
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
        };
    };
    class CUP_arifle_M16A1GL;
    class potato_fauxC7_c7GL: CUP_arifle_M16A1GL {
        author = "Potato";
        displayName = "C7 M203";
    };
    class CUP_arifle_M16A4_Base;
    class potato_fauxC7_c7a2: CUP_arifle_M16A4_Base {
        author = "Potato";
        displayName = "C7A2";
        modes[] = {"Single","FullAuto","Burst_medium","single_medium_optics1","single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_m16a4_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_spar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
            soundBurst = 0;
            ffCount = 3;
            dispersion = 0.0006;
            reloadTime = 0.075;
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
        };
    };
    class CUP_arifle_M16A4_GL;
    class potato_fauxC7_c7a2GL: CUP_arifle_M16A4_GL {
        author = "Potato";
        displayName = "C7A2 M203";
        modes[] = {"Single","FullAuto","Burst_medium","single_medium_optics1","single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_m16a4_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_spar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
            soundBurst = 0;
            ffCount = 3;
            dispersion = 0.0006;
            reloadTime = 0.075;
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
        };
    };
    // Scaled back Coop recoil
    class CUP_lmg_m249_pip1;
    class potato_lmg_m249_pip1_coop: CUP_lmg_m249_pip1 {
        scope = 1;
        recoil = QGVAR(recoil_SAW_coop);
        recoilProne = QGVAR(recoil_SAW_prone_coop);
    };
    class CUP_lmg_m249_pip3;
    class potato_lmg_m249_pip3_coop: CUP_lmg_m249_pip3 {
        scope = 1;
        recoil = QGVAR(recoil_SAW_coop);
        recoilProne = QGVAR(recoil_SAW_prone_coop);
    };
    class CUP_lmg_m249_E1;
    class potato_lmg_m249_E1_coop: CUP_lmg_m249_E1 {
        scope = 1;
        recoil = QGVAR(recoil_SAW_coop);
        recoilProne = QGVAR(recoil_SAW_prone_coop);
    };
    class CUP_lmg_m249_E2;
    class potato_lmg_m249_E2_coop: CUP_lmg_m249_E2 {
        scope = 1;
        recoil = QGVAR(recoil_SAW_coop);
        recoilProne = QGVAR(recoil_SAW_prone_coop);
    };
    class CUP_lmg_minimipara;
    class potato_lmg_minimipara_coop: CUP_lmg_minimipara {
        scope = 1;
        recoil = QGVAR(recoil_SAW_coop);
        recoilProne = QGVAR(recoil_SAW_prone_coop);
    };
};

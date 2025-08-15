class Mode_FullAuto;
class asdg_MuzzleSlot;
class asdg_MuzzleSlot_556: asdg_MuzzleSlot {
    class compatibleItems {
        CUP_muzzle_snds_M16_camo = 1;
        CUP_muzzle_snds_M16 = 1;
    };
};

#define JSRS_M4_SOUNDSET class StandardSound {\
soundSetShot[] = {"jsrs_m4_shot_soundset","jsrs_5x56mm_reverb_soundset"};\
}
#define JSRS_M4_AUDIO_DEFINES class Burst: Burst {\
    JSRS_M4_SOUNDSET;\
};\
class Burst_medium: Burst_medium {\
    JSRS_M4_SOUNDSET;\
};\
class single_medium_optics1: single_medium_optics1 {\
    JSRS_M4_SOUNDSET;\
};\
class single_medium_optics2: single_medium_optics2 {\
    JSRS_M4_SOUNDSET;\
}
#define COMMON_M4_CARBINE_INCLUDES author = "Potato";\
descriptionShort = "$STR_CUP_dss_m16a2";\
modes[] = {"Single","Burst","Burst_medium","Single_medium_optics1","Single_medium_optics2"}

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
        scopeArsenal = 0;
        recoil = QGVAR(recoil_SAW_coop);
        recoilProne = QGVAR(recoil_SAW_prone_coop);
    };
    class CUP_lmg_m249_pip3;
    class potato_lmg_m249_pip3_coop: CUP_lmg_m249_pip3 {
        scope = 1;
        scopeArsenal = 0;
        recoil = QGVAR(recoil_SAW_coop);
        recoilProne = QGVAR(recoil_SAW_prone_coop);
    };
    class CUP_lmg_m249_E1;
    class potato_lmg_m249_E1_coop: CUP_lmg_m249_E1 {
        scope = 1;
        scopeArsenal = 0;
        recoil = QGVAR(recoil_SAW_coop);
        recoilProne = QGVAR(recoil_SAW_prone_coop);
    };
    class CUP_lmg_m249_E2;
    class potato_lmg_m249_E2_coop: CUP_lmg_m249_E2 {
        scope = 1;
        scopeArsenal = 0;
        recoil = QGVAR(recoil_SAW_coop);
        recoilProne = QGVAR(recoil_SAW_prone_coop);
    };
    class CUP_lmg_minimipara;
    class potato_lmg_minimipara_coop: CUP_lmg_minimipara {
        scope = 1;
        scopeArsenal = 0;
        recoil = QGVAR(recoil_SAW_coop);
        recoilProne = QGVAR(recoil_SAW_prone_coop);
    };
    class Rifle_Base_F;
    class CUP_arifle_M16_Base: Rifle_Base_F {
        class Burst;
        class Burst_medium;
        class single_medium_optics1;
        class single_medium_optics2;
    };
    class CUP_arifle_M4_Base: CUP_arifle_M16_Base {
        JSRS_M4_AUDIO_DEFINES;
    };
    class CUP_arifle_Colt727: CUP_arifle_M16_Base {
        JSRS_M4_AUDIO_DEFINES;
    };
    class potato_arifle_M4: CUP_arifle_Colt727 {
        COMMON_M4_CARBINE_INCLUDES;
        displayName = "M4 Carbine";
        class Library {
            libTextDesc = "The M4 Carbine is a shortened version of the M16A2. It sports a shortened barrel and collapsible stock, making it the Special Operations weapon of choice. As with the M16A2, the M4 Carbine is limited to a 3-round burst mode.&lt;br/&gt;The M4 Carbine can be modified with a variety of special accessories including optics such as the Aimpoint 5000, an easily detachable suppressor, the M203 under barrel grenade launcher, and many others.";
        };
    };

    class CUP_arifle_Colt727_M203: CUP_arifle_Colt727 {};
    class potato_arifle_M4_M203: CUP_arifle_Colt727_M203 {
        COMMON_M4_CARBINE_INCLUDES;
        displayName = "M4 Carbine M203";
        class Library {
            libTextDesc = "The M4 Carbine is a shortened version of the M16A2. It sports a shortened barrel and collapsible stock, making it the Special Operations weapon of choice. As with the M16A2, the M4 Carbine is limited to a 3-round burst mode.&lt;br/&gt;The M4 Carbine uses 5.56x45mm NATO cartridges and this one is equipped with an M203 40mm grenade launcher.";
        };
    };

    class CUP_arifle_M4A1_black;
    class potato_arifle_M4_RIS: CUP_arifle_M4A1_black {
        COMMON_M4_CARBINE_INCLUDES;
        displayName = "M4 Carbine (RIS)";
        class Library {
            libTextDesc = "The M4 Carbine is a shortened version of the M16A2. This specific version was formally adopted by the USMC in 2015 and sports a shortened barrel, collapsible stock, and RIS rail system. As with the M16A2, the M4 Carbine is limited to a 3-round burst mode.&lt;br/&gt;The M4 Carbine can be modified with a variety of special accessories including optics such as the M68 CCO, an easily detachable suppressor, the M203 under barrel grenade launcher, and many others.";
        };
    };

    class CUP_arifle_M4A3_black;
    class potato_arifle_M4_RIS_grip: CUP_arifle_M4A3_black {
        COMMON_M4_CARBINE_INCLUDES;
        displayName = "M4 Carbine (RIS/Grip)";
        class Library {
            libTextDesc = "The M4 Carbine is a shortened version of the M16A2. This specific version was formally adopted by the USMC in 2015 and sports a shortened barrel, collapsible stock, and RIS rail system. As with the M16A2, the M4 Carbine is limited to a 3-round burst mode.&lt;br/&gt;The M4 Carbine can be modified with a variety of special accessories including optics such as the M68 CCO, an easily detachable suppressor, the M203 under barrel grenade launcher, and many others.";
        };
    };

    class CUP_arifle_M4A1_BUIS_GL;
    class potato_arifle_M4_RIS_M203: CUP_arifle_M4A1_BUIS_GL {
        COMMON_M4_CARBINE_INCLUDES;
        displayName = "M4 Carbine M203 (RIS)";
        class Library {
            libTextDesc = "The M4 Carbine is a shortened version of the M16A2. This specific version was formally adopted by the USMC in 2015 and sports a shortened barrel, collapsible stock, and RIS rail system. As with the M16A2, the M4 Carbine is limited to a 3-round burst mode.&lt;br/&gt;The M4 Carbine uses 5.56x45mm NATO cartridges and this one is equipped with an M203 40mm grenade launcher.";
        };
    };

};

class CfgWeapons {
    // Adds MG5 in 7.62x51mm
    class MMG_01_tan_F;
    class potato_fauxMG5_MG5: MMG_01_tan_F {
        author = "Potato";
        displayName = "H&K MG5";
        descriptionShort = "General Purpose Machine Gun<br />Caliber: 7.62x51 mm";
        baseWeapon = "potato_fauxMG5_MG5";
        recoil = "CUP_MG3_recoil";
        magazineWell[] = {"CBA_762x51_LINKS"};
        magazines[] = {
            "CUP_120Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_Yellow_Tracer_762x51_Belt_M"
        };
    };

    // Adds 40x53mm potato grenades
    class GMG_F;
    class GMG_40mm: GMG_F {
        magazineWell[] += {QMAGWELL(HV_40x53mm)};
    };
    
    // Burst-fire M4s
    class Mode_SemiAuto;
    class Mode_Burst;
//    class SlotInfo;
//    class UGL_F;
//    class Rifle;
//    class Rifle_Base_F: Rifle {
//        class WeaponSlotsInfo;
//        class GunParticles;
//    };
//    class CUP_arifle_M16_Base: Rifle_Base_F {};
    class CUP_arifle_Colt727;
    class CUP_arifle_Colt727_M203: CUP_arifle_Colt727 {};
    
    class potato_arifle_M4: CUP_arifle_Colt727 {
        author = "Potato";
        scope = 2;
        displayName = "M4 Carbine";
        class Library {
            libTextDesc = "The M4 Carbine is a shortened version of the M16A2. It sports a shortened barrel and collapsible stock, making it the Special Operations weapon of choice. As with the M16A2, the M4 Carbine is limited to a 3-round burst mode.&lt;br/&gt;The M4 Carbine can be modified with a variety of special accessories including optics such as the Aimpoint 5000, an easily detachable suppressor, the M203 under barrel grenade launcher, and many others.";
        };
        descriptionShort = "$STR_CUP_dss_m16a2";
        modes[] = {"Single","Burst","Burst_medium","single_medium_optics1","single_medium_optics2"};
        class Single: Mode_SemiAuto {
            class BaseSoundModeType{};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_m16a4_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_spar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
            dispersion = 0.0006;
            reloadTime = 0.075;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
        };
        class Burst: Mode_Burst {
            class BaseSoundModeType{};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_m16a4_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_spar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
            soundBurst = 0;
            ffCount = 6;
            dispersion = 0.0006;
            reloadTime = 0.075;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
        };
        class Burst_medium: Burst {
            showToPlayer = 0;
            minRange = 1;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
        };
        class single_medium_optics1: Single {
            requiredOpticType = 1;
            showToPlayer = 0;
            minRange = 5;
            minRangeProbab = 0.2;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 525;
            maxRangeProbab = 0.3;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 525;
        };
        class single_medium_optics2: single_medium_optics1 {
            requiredOpticType = 2;
            minRange = 100;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.7;
            maxRange = 750;
            maxRangeProbab = 0.05;
            aiRateOfFire = 6;
            aiRateOfFireDistance = 750;
        };
    };
    class potato_arifle_M4_M203GL: CUP_arifle_Colt727_M203 {
        author = "Potato";
        scope = 2;
        displayName = "M4 Carbine M203";
        class Library {
            libTextDesc = "The M4 Carbine is a shortened version of the M16A2. It sports a shortened barrel and collapsible stock, making it the Special Operations weapon of choice. As with the M16A2, the M4 Carbine is limited to a 3-round burst mode.&lt;br/&gt;The M4 Carbine uses 5.56x45mm NATO cartridges and this one is equipped with an M203 40mm grenade launcher.";
        };
        descriptionShort = "$STR_CUP_dss_m16a2";
        modes[] = {"Single","Burst","Burst_medium","single_medium_optics1","single_medium_optics2"};
        class Single: Mode_SemiAuto {
            class BaseSoundModeType{};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_m16a4_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_spar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
            dispersion = 0.0006;
            reloadTime = 0.075;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
        };
        class Burst: Mode_Burst {
            class BaseSoundModeType{};
            class StandardSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_m16a4_shot_soundset","jsrs_5x56mm_reverb_soundset"};
            };
            class SilencedSound: BaseSoundModeType {
                soundsetshot[] = {"jsrs_spar_shot_silenced_soundset","jsrs_5x56mm_sd_reverb_soundset"};
            };
            soundBurst = 0;
            ffCount = 6;
            dispersion = 0.0006;
            reloadTime = 0.075;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
        };
        class Burst_medium: Burst {
            showToPlayer = 0;
            minRange = 1;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
        };
        class single_medium_optics1: Single {
            requiredOpticType = 1;
            showToPlayer = 0;
            minRange = 5;
            minRangeProbab = 0.2;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 525;
            maxRangeProbab = 0.3;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 525;
        };
        class single_medium_optics2: single_medium_optics1 {
            requiredOpticType = 2;
            minRange = 100;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.7;
            maxRange = 750;
            maxRangeProbab = 0.05;
            aiRateOfFire = 6;
            aiRateOfFireDistance = 750;
        };
    };

};

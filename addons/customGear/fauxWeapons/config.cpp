#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_fauxWeapons

class CfgPatches {
    class ADDON {
        weapons[] = {
            QGVAR(c7),
            QGVAR(c7GL),
            QGVAR(c7a2),
            QGVAR(c7a2GL),
            QGVAR(MG5)
        };
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "CUP_Weapons_LoadOrder", "jsrs_soundmod_cup_weapons"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Chesheire"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class Mode_FullAuto;
class CfgWeapons {
    
    // Adds C7, C7GL, and C7A2, C7A2
    class CUP_arifle_M16A1E1;
    class GVAR(c7): CUP_arifle_M16A1E1 {
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
    class GVAR(c7GL): CUP_arifle_M16A1GL {
        author = "Potato";
        displayName = "C7 M203";
    };
    class CUP_arifle_M16A4_Base;
    class GVAR(c7a2): CUP_arifle_M16A4_Base {
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
    class GVAR(c7a2GL): CUP_arifle_M16A4_GL {
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
    
    // Adds MG5 in 7.62x51mm
    class MMG_01_tan_F;
    class GVAR(MG5): MMG_01_tan_F {
        author = "Potato";
        displayName = "H&K MG5";
        descriptionShort = "General Purpose Machine Gun<br />Caliber: 7.62x51 mm";
        baseWeapon = QGVAR(MG5);
        recoil = "CUP_MG3_recoil";
        magazineWell[] = {"CBA_762x51_LINKS"};
        magazines[] = {
            "CUP_120Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M",
            "CUP_120Rnd_TE4_LRT4_Yellow_Tracer_762x51_Belt_M"
        };
    };
};

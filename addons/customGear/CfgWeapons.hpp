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
    class Mode_FullAuto;
    class SlotInfo;
    class UGL_F;
    class Rifle;
    class Rifle_Base_F: Rifle {
        class WeaponSlotsInfo;
        class GunParticles;
    };
    class CUP_arifle_M16_Base: Rifle_Base_F {};
    class CUP_arifle_Colt727: CUP_arifle_M16_Base {};
    class CUP_arifle_Colt727_M203: CUP_arifle_Colt727 {};
    
    class potato_arifle_M4: CUP_arifle_Colt727 {
        author = "Potato";
        scope = 2;
        /*
        model = "\CUP\Weapons\CUP_Weapons_M16\CUP_Colt727.p3d";
        picture = "\CUP\Weapons\CUP_Weapons_M16\data\ui\gear_colt727_X_ca.paa";
        handAnim[] = {"OFP2_ManSkeleton","CUP\Weapons\CUP_Weapons_M16\data\anim\M16.rtm"};
        inertia = 0.4;
        dexterity = 1.6;
        aimTransitionSpeed = 1;
        recoil = "CUP_M4A1_recoil";
        initSpeed = -0.9836956;
        jsrs_soundeffect = "JSRS2_Distance_Effects_M4";
        ACE_barrelTwist = 178;
        ACE_barrelLength = 368;
        ACE_overheating_mrbs = 3600;
        ACE_overheating_dispersion = 1;
        ACE_overheating_slowdownFactor = 1;
        cameraDir = "eye_look";
        discreteDistanceCameraPoint[] = {"eye_100","eye","eye_300","eye_400","eye_500","eye_600"};
        hiddenSelections[] = {"camo","camo1","camo2","CamoFrontSight"};
        hiddenSelectionsTextures[] = {"CUP\Weapons\CUP_Weapons_M16\data\colt727_body_co.paa","cup\weapons\cup_weapons_m16\data\colt727_furniture_co.paa","cup\weapons\cup_weapons_m16\data\tigg_m4barrel_co.paa","cup\weapons\cup_weapons_m16\data\m16a1_body_co.paa"};
        */
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
            /*
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_Shot_SoundSet","CUP_rifle1_Tail_SoundSet"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_ShotSD_SoundSet","CUP_rifle1_SD_Tail_SoundSet"};
            };
            */
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
            /*
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_Shot_SoundSet","CUP_rifle1_Tail_SoundSet"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_ShotSD_SoundSet","CUP_rifle1_SD_Tail_SoundSet"};
            };
            */
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
/*
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 66.3;
            class CUP_PicatinnyTopMountM16: CUP_PicatinnyTopMount {
                iconPinPoint = "center";
                iconPosition[] = {0.555,0.203};
                iconScale = 0.17;
                iconPicture = "\A3\Weapons_F\Data\UI\attachment_top.paa";
            };
            class CUP_PicatinnySideMountM16: CUP_PicatinnySideMount {
                iconPinPoint = "center";
                iconPosition[] = {0.184,0.438};
                iconScale = 0.25;
                iconPicture = "\A3\Weapons_F\Data\UI\attachment_side.paa";
            };
            class MuzzleSlot: asdg_MuzzleSlot_556 {
                iconPinPoint = "center";
                iconPosition[] = {0.002,0.391};
                iconScale = 0.23;
                iconPicture = "\A3\Weapons_F\Data\UI\attachment_muzzle.paa";
            };
        };
*/
    };
    class potato_arifle_M4_M203GL: CUP_arifle_Colt727_M203 {
        author = "Potato";
        scope = 2;
        /*
        model = "\CUP\Weapons\CUP_Weapons_M16\CUP_Colt727_GL.p3d";
        picture = "\CUP\Weapons\CUP_Weapons_M16\data\ui\gear_colt727_gl_X_ca.paa";
        UiPicture = "\A3\Weapons_F\Data\UI\icon_gl_CA.paa";
        handAnim[] = {"OFP2_ManSkeleton","CUP\Weapons\CUP_Weapons_M16\data\anim\M16GL.rtm"};
        inertia = 0.6;
        dexterity = 1.25;
        muzzles[] = {"this","M203"};
        hiddenSelections[] = {"camo","camo_gl","camo1","camo2","CamoFrontSight"};
        hiddenSelectionsTextures[] = {"CUP\Weapons\CUP_Weapons_M16\data\colt727_body_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m203_m4_co.paa","cup\weapons\cup_weapons_m16\data\colt727_furniture_co.paa","cup\weapons\cup_weapons_m16\data\tigg_m4barrel_co.paa","cup\weapons\cup_weapons_m16\data\m16a1_body_co.paa"};
        */
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
            /*
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_Shot_SoundSet","CUP_rifle1_Tail_SoundSet"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_ShotSD_SoundSet","CUP_rifle1_SD_Tail_SoundSet"};
            };
            */
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
            /*
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_Shot_SoundSet","CUP_rifle1_Tail_SoundSet"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_ShotSD_SoundSet","CUP_rifle1_SD_Tail_SoundSet"};
            };
            */
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
        /*
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 96.3;
            class CUP_PicatinnyTopMountM16: CUP_PicatinnyTopMount {
                iconPinPoint = "center";
                iconPosition[] = {0.555,0.203};
                iconScale = 0.17;
                iconPicture = "\A3\Weapons_F\Data\UI\attachment_top.paa";
            };
            class CUP_PicatinnySideMountM16{};
            class MuzzleSlot: asdg_MuzzleSlot_556 {
                iconPinPoint = "center";
                iconPosition[] = {0.002,0.391};
                iconScale = 0.23;
                iconPicture = "\A3\Weapons_F\Data\UI\attachment_muzzle.paa";
            };
        };
        */
    };
    
    class CUP_arifle_M4_Base: CUP_arifle_M16_Base {};
    class CUP_arifle_M4A1_BUIS_Base: CUP_arifle_M4_Base {};
    class CUP_arifle_M4A1_black: CUP_arifle_M4A1_BUIS_Base {};
    class CUP_arifle_M4A1_BUIS_GL: CUP_arifle_M4A1_BUIS_Base {};
    
    class potato_arifle_M4RIS: CUP_arifle_M4A1_black {
        author = "Potato";
        scope = 2;
        displayName = "$STR_CUP_dn_m4a1";
        /*
        model = "\CUP\Weapons\CUP_Weapons_M16\CUP_M4A1_BUIS.p3d";
        picture = "\CUP\Weapons\CUP_Weapons_M16\data\ui\gear_m4a1_buis_x_ca.paa";
        inertia = 0.4;
        dexterity = 1.6;
        hiddenSelections[] = {"camo","camo_rail","camo1","camo2","camo3","camo4","camo_lod"};
        hiddenSelectionsTextures[] = {"CUP\Weapons\CUP_Weapons_M16\data\tigg_m4_co.paa","CUP\Weapons\CUP_Weapons_M16\data\m4_v3_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m4furniture_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m4barrel_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_carryhandle_co.paa","CUP\Weapons\CUP_Weapons_WeaponsData\Data\RIS_cover\rail_cover_co.paa","CUP\Weapons\CUP_Weapons_M16\data\m4_co.paa"};
        */
        modes[] = {"Single","Burst","Burst_medium","single_medium_optics1","single_medium_optics2"};
        class Single: Mode_SemiAuto {
            class BaseSoundModeType{};
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_Shot_SoundSet","CUP_rifle1_Tail_SoundSet"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_ShotSD_SoundSet","CUP_rifle1_SD_Tail_SoundSet"};
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
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_Shot_SoundSet","CUP_rifle1_Tail_SoundSet"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_ShotSD_SoundSet","CUP_rifle1_SD_Tail_SoundSet"};
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
    class potato_arifle_M4RIS_M203GL: CUP_arifle_M4A1_BUIS_GL {
        author = "CUP & AChesheireCat";
        scope = 2;
        /*
        model = "\CUP\Weapons\CUP_Weapons_M16\CUP_M4A1_GL.p3d";
        displayName = "$STR_CUP_dn_m4a1_gl";
        picture = "\CUP\Weapons\CUP_Weapons_M16\data\ui\gear_m4a1_buis_gl_x_ca.paa";
        uiPicture = "\A3\Weapons_F\Data\UI\icon_gl_CA.paa";
        hiddenSelections[] = {"camo","camo_rail","camo1","camo2","camo3","camo4","camo_lod","camo_gl"};
        hiddenSelectionsTextures[] = {"CUP\Weapons\CUP_Weapons_M16\data\tigg_m4_co.paa","CUP\Weapons\CUP_Weapons_M16\data\m4_v3_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m4furniture_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m4barrel_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_carryhandle_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_rails_co.paa","CUP\Weapons\CUP_Weapons_M16\data\m4_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m203_m4_co.paa"};
        handAnim[] = {"OFP2_ManSkeleton","CUP\Weapons\CUP_Weapons_M16\data\anim\M4GL.rtm"};
        muzzles[] = {"this","M203"};
        */
        class Library {
            libTextDesc = "$STR_CUP_lib_m4a1_gl";
        };
        descriptionShort = "$STR_CUP_dss_m4a1_gl";
        /*
        inertia = 0.5;
        dexterity = 1.5;
        aimTransitionSpeed = 1;
        */
        modes[] = {"Single","Burst","Burst_medium","single_medium_optics1","single_medium_optics2"};
        class Single: Mode_SemiAuto {
            class BaseSoundModeType{};
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_Shot_SoundSet","CUP_rifle1_Tail_SoundSet"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_ShotSD_SoundSet","CUP_rifle1_SD_Tail_SoundSet"};
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
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_Shot_SoundSet","CUP_rifle1_Tail_SoundSet"};
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {"CUP_m16_Closure_SoundSet","CUP_m16_ShotSD_SoundSet","CUP_rifle1_SD_Tail_SoundSet"};
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
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 107.9;
            class CUP_PicatinnyUnderMountM16{};
        };
    };
};

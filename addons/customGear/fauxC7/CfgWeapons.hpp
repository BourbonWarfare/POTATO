class Mode_FullAuto;
class CUP_PicatinnyTopMount;
class CUP_PicatinnySideMount;
class asdg_MuzzleSlot;
class asdg_MuzzleSlot_556: asdg_MuzzleSlot {
    class compatibleItems {
        CUP_muzzle_snds_M16_camo = 1;
        CUP_muzzle_snds_M16 = 1;
    };
};
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
    
    // Burst Fire M4s
    
//    class Mode_SemiAuto;
//    class Mode_Burst;

    class UGL_F;
    class Rifle;
    class Rifle_Base_F: Rifle {
        class WeaponSlotsInfo;
    };
    class CUP_arifle_M16_Base: Rifle_Base_F {
        class M203: UGL_F {};
    };
    
    class potato_arifle_M4: CUP_arifle_M16_Base {
        author = "Potato";
        scope = 2;
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
        displayName = "M4 Carbine";
        class Library {
            libTextDesc = "The M4 Carbine is a shortened version of the M16A2. It sports a shortened barrel and collapsible stock, making it the Special Operations weapon of choice. As with the M16A2, the M4 Carbine is limited to a 3-round burst mode.&lt;br/&gt;The M4 Carbine can be modified with a variety of special accessories including optics such as the Aimpoint 5000, an easily detachable suppressor, the M203 under barrel grenade launcher, and many others.";
        };
        descriptionShort = "$STR_CUP_dss_m16a2";
        /*
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
    */
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
    };
    
    class potato_arifle_M4_M203GL: potato_arifle_M4 {
        author = "Potato";
        scope = 2;
        model = "\CUP\Weapons\CUP_Weapons_M16\CUP_Colt727_GL.p3d";
        picture = "\CUP\Weapons\CUP_Weapons_M16\data\ui\gear_colt727_gl_X_ca.paa";
        UiPicture = "\A3\Weapons_F\Data\UI\icon_gl_CA.paa";
        handAnim[] = {"OFP2_ManSkeleton","CUP\Weapons\CUP_Weapons_M16\data\anim\M16GL.rtm"};
        inertia = 0.6;
        dexterity = 1.25;
        muzzles[] = {"this","M203"};
        hiddenSelections[] = {"camo","camo_gl","camo1","camo2","CamoFrontSight"};
        hiddenSelectionsTextures[] = {"CUP\Weapons\CUP_Weapons_M16\data\colt727_body_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m203_m4_co.paa","cup\weapons\cup_weapons_m16\data\colt727_furniture_co.paa","cup\weapons\cup_weapons_m16\data\tigg_m4barrel_co.paa","cup\weapons\cup_weapons_m16\data\m16a1_body_co.paa"};
        displayName = "M4 Carbine M203";
        class Library {
            libTextDesc = "The M4 Carbine is a shortened version of the M16A2. It sports a shortened barrel and collapsible stock, making it the Special Operations weapon of choice. As with the M16A2, the M4 Carbine is limited to a 3-round burst mode.&lt;br/&gt;The M4 Carbine uses 5.56x45mm NATO cartridges and this one is equipped with an M203 40mm grenade launcher.";
        };
        descriptionShort = "$STR_CUP_dss_m16a2";
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
    };
};
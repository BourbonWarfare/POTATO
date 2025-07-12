class Mode_FullAuto;
class CUP_PicatinnyTopMount;
class CUP_PicatinnyUnderMount;
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
    class potato_arifle_M4RIS: potato_arifle_M4 {
        displayName = "M4 Carbine RIS";
        reloadMagazineSound[] = {"CUP\Weapons\CUP_Weapons_M16\data\sfx\M4_Reload",1,1,10};
        changeFiremodeSound[] = {"A3\sounds_f\weapons\closure\firemode_changer_2",0.25118864,1,20};
        drySound[] = {"CUP\Weapons\CUP_Weapons_M16\data\sfx\Dry",1,1,35};
        jsrs_soundeffect = "JSRS2_Distance_Effects_M4";
        discreteDistance[] = {300};
        ACE_barrelTwist = 178;
        ACE_barrelLength = 368;
        ACE_overheating_mrbs = 3600;
        ACE_overheating_dispersion = 1;
        ACE_overheating_slowdownFactor = 1;
        model = "\CUP\Weapons\CUP_Weapons_M16\CUP_M4A1_BUIS.p3d";
        picture = "\CUP\Weapons\CUP_Weapons_M16\data\ui\gear_m4a1_buis_x_ca.paa";
        hiddenSelections[] = {"camo","camo_rail","camo1","camo2","camo3","camo4","camo_lod"};
        hiddenSelectionsTextures[] = {"CUP\Weapons\CUP_Weapons_M16\data\tigg_m4_co.paa","CUP\Weapons\CUP_Weapons_M16\data\m4_v3_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m4furniture_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m4barrel_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_carryhandle_co.paa","CUP\Weapons\CUP_Weapons_WeaponsData\Data\RIS_cover\rail_cover_co.paa","CUP\Weapons\CUP_Weapons_M16\data\m4_co.paa"};
        class WeaponSlotsInfo {
            mass = 78;
            class CUP_PicatinnyTopMountM4: CUP_PicatinnyTopMount {
                iconPinPoint = "center";
                iconPosition[] = {0.516,0.227};
                iconScale = 0.18;
                iconPicture = "\A3\Weapons_F\Data\UI\attachment_top.paa";
            };
            class CUP_PicatinnySideMountM4: CUP_PicatinnySideMount {
                iconPinPoint = "center";
                iconPosition[] = {0.33,0.371};
                iconScale = 0.26;
                iconPicture = "\A3\Weapons_F\Data\UI\attachment_side.paa";
            };
            class CUP_PicatinnyUnderMountM16: CUP_PicatinnyUnderMount {
                iconPinPoint = "center";
                iconPosition[] = {0.277,0.676};
                iconScale = 0.3;
                iconPicture = "\A3\weapons_f_mark\data\UI\attachment_under.paa";
            };
            class MuzzleSlot: asdg_MuzzleSlot_556 {
                linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
                iconPinPoint = "center";
                iconPosition[] = {0.02,0.375};
                iconScale = 0.25;
                iconPicture = "\A3\Weapons_F\Data\UI\attachment_muzzle.paa";
            };
            allowedslots[] = {901};
        };
        inertia = 0.4;
        dexterity = 1.6;
    };
    class potato_arifle_M4RIS_grip: potato_arifle_M4RIS {
        displayName = "M4 Carbine RIS (Grip)";
        model = "\CUP\Weapons\CUP_Weapons_M16\CUP_M4A3.p3d";
        picture = "\CUP\Weapons\CUP_Weapons_M16\data\ui\gear_M4A3_X_ca.paa";
        handAnim[] = {"OFP2_ManSkeleton","\CUP\Weapons\CUP_Weapons_M16\data\anim\M4FG.rtm"};
        inertia = 0.32;
        dexterity = 2;
        recoil = "CUP_M4A3_recoil";
        hiddenSelections[] = {"camo","camo_rail","camo1","camo2","camo3","camo4","camo_lod"};
        hiddenSelectionsTextures[] = {"CUP\Weapons\CUP_Weapons_M16\data\tigg_m4_co.paa","CUP\Weapons\CUP_Weapons_M16\data\m4_v3_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m4furniture_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m4barrel_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_carryhandle_co.paa","CUP\Weapons\CUP_Weapons_WeaponsData\Data\RIS_cover\rail_cover_co.paa","CUP\Weapons\CUP_Weapons_M16\data\m4_co.paa"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CUP_PicatinnyTopMountM4: CUP_PicatinnyTopMount {
                iconPinPoint = "center";
                iconPosition[] = {0.502,0.219};
                iconScale = 0.2;
                iconPicture = "\A3\Weapons_F\Data\UI\attachment_top.paa";
            };
            class CUP_PicatinnySideMountM4: CUP_PicatinnySideMount {
                iconPinPoint = "center";
                iconPosition[] = {0.326,0.375};
                iconScale = 0.26;
                iconPicture = "\A3\Weapons_F\Data\UI\attachment_side.paa";
            };
            class CUP_PicatinnyUnderMountM16: CUP_PicatinnyUnderMount {
                iconPinPoint = "center";
                iconPosition[] = {0.266,0.621};
                iconScale = 0.3;
                iconPicture = "\A3\weapons_f_mark\data\UI\attachment_under.paa";
            };
            class MuzzleSlot: asdg_MuzzleSlot_556 {
                iconPinPoint = "center";
                iconPosition[] = {0.02,0.375};
                iconScale = 0.25;
                iconPicture = "\A3\Weapons_F\Data\UI\attachment_muzzle.paa";
            };
            allowedslots[] = {901};
        };
    };
    class potato_arifle_M4RIS_M203GL: potato_arifle_M4RIS {
        displayName = "M4 Carbine RIS M203";
        model = "\CUP\Weapons\CUP_Weapons_M16\CUP_M4A1_GL.p3d";
        picture = "\CUP\Weapons\CUP_Weapons_M16\data\ui\gear_m4a1_buis_gl_x_ca.paa";
        uiPicture = "\A3\Weapons_F\Data\UI\icon_gl_CA.paa";
        hiddenSelections[] = {"camo","camo_rail","camo1","camo2","camo3","camo4","camo_lod","camo_gl"};
        hiddenSelectionsTextures[] = {"CUP\Weapons\CUP_Weapons_M16\data\tigg_m4_co.paa","CUP\Weapons\CUP_Weapons_M16\data\m4_v3_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m4furniture_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m4barrel_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_carryhandle_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_rails_co.paa","CUP\Weapons\CUP_Weapons_M16\data\m4_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m203_m4_co.paa"};
        handAnim[] = {"OFP2_ManSkeleton","CUP\Weapons\CUP_Weapons_M16\data\anim\M4GL.rtm"};
        muzzles[] = {"this","M203"};
        inertia = 0.5;
        dexterity = 1.5;
        aimTransitionSpeed = 1;
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 107.9;
            class CUP_PicatinnyUnderMountM16{};
        };
    };
};

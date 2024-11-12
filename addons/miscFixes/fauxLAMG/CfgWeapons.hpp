#define VOLUME_CLOSURE 0.501187
#define VOLUME_SHOT 1
#define VOLUME_TAIL 0.531
#define VOLUME_TAIL_Interior 1

#define OVERRIDE_SOUND class BaseSoundModeType {\
    closure1[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\closure_SDAR_01",VOLUME_CLOSURE,1,10};\
    closure2[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\closure_SDAR_02",VOLUME_CLOSURE,1,10};\
    soundClosure[] = {"closure1",0.5,"closure2",0.5};\
};\
class StandardSound {\
    begin1[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\SDAR_short_01",VOLUME_SHOT,1,1400};\
    begin2[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\SDAR_short_02",VOLUME_SHOT,1,1400};\
    begin3[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\SDAR_short_03",VOLUME_SHOT,1,1400};\
    closure1[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\closure_SDAR_01",VOLUME_CLOSURE,1,10};\
    closure2[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\closure_SDAR_02",VOLUME_CLOSURE,1,10};\
    soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};\
    soundClosure[] = {"closure1",0.5,"closure2",0.5};\
    SoundSetShot[] = {"SDAR_Shot_SoundSet","SDAR_Tail_SoundSet","SDAR_InteriorTail_SoundSet"};\
    class SoundTails {\
        class TailForest {\
            frequency = 1;\
            sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\SDAR_tail_forest",1,1,1400};\
            volume = "(1-interior/1.4)*forest";\
        };\
        class TailHouses {\
            frequency = 1;\
            sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\SDAR_tail_houses",1,1,1400};\
            volume = "(1-interior/1.4)*houses";\
        };\
        class TailInterior {\
            frequency = 1;\
            sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\SDAR_tail_interior",1.58489,1,1400};\
            volume = "interior";\
        };\
        class TailMeadows {\
            frequency = 1;\
            sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\SDAR_tail_meadows",1,1,1400};\
            volume = "(1-interior/1.4)*(meadows/2 max sea/2)";\
        };\
        class TailTrees {\
            frequency = 1;\
            sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\SDAR\SDAR_tail_trees",1,1,1400};\
            volume = "(1-interior/1.4)*trees";\
        };\
    };\
}

class CfgWeapons {
  class Rifle_Long_Base_F;
    class LMG_Mk200_F: Rifle_Long_Base_F {
        class ACE_Burst_far;
        class close;
        class far_optic1;
        class far_optic2;
        class manual;
        class medium;
        class short;
        class Single;
    };
    class potato_lmg_LAMG: LMG_Mk200_F {
        class ACE_Burst_far: ACE_Burst_far {
            OVERRIDE_SOUND;
        };
        class close: close {
            OVERRIDE_SOUND;
        };
        class far_optic1: far_optic1 {
            OVERRIDE_SOUND;
        };
        class far_optic2: far_optic2 {
            OVERRIDE_SOUND;
        };
        class manual: manual {
            OVERRIDE_SOUND;
        };
        class medium: medium {
            OVERRIDE_SOUND;
        };
        class short: short {
            OVERRIDE_SOUND;
        };
        class Single: Single {
            OVERRIDE_SOUND;
        };
        author = "Potato";
        displayName = "KAC Light Assault Machine Gun";
        descriptionShort = "Light Machine Gun<br />Caliber: 5.56x45 mm";
        baseWeapon = QGVAR(LAMG);
        recoil = "CUP_SAW_recoil";
        magazineWell[] = {"CBA_556x45_MINIMI"};
        magazines[] = {"CUP_100Rnd_TE4_Red_Tracer_556x45_M249"};
    };
    class potato_lmg_LAMG_black: potato_lmg_LAMG {
        author = "Potato";
        displayName = "KAC Light Assault Machine Gun (Black)";
        baseWeapon = QGVAR(LAMG_black);
        picture = "\a3\Weapons_F_Enoch\Machineguns\M200\Data\UI\icon_LMG_Mk200_black_F_ca.paa";
        hiddenSelectionsTextures[] = {
            "a3\Weapons_F_Enoch\Machineguns\M200\Data\1st_person_black_co.paa",
            "a3\Weapons_F_Enoch\Machineguns\M200\Data\Body_black_co.paa",
            "a3\Weapons_F_Enoch\Machineguns\M200\Data\grip_black_co.paa"
        };
    };
};

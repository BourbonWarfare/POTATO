class Mode_SemiAuto;
class CfgWeapons {
    class ItemCore;
    class ace_xm157_prototype: ItemCore {
        scope = 2;
    };


    class Rifle_Base_F;
    class Rifle_Long_Base_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class CUP_srifle_AS50: Rifle_Long_Base_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {};
    };

    class potato_fauxPGS: CUP_srifle_AS50 {
        author = "Potato (CUP Model)";
        displayName = "30mm PGS";
        baseWeapon = "potato_fauxPGS";
        scope = 2;
        scopeArsenal = 2;
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 300;
        };
        magazineWell[] = {};
        magazines[] = {
            QGVAR(5rnd_HE), QGVAR(5rnd_HEDP), QGVAR(5rnd_airburst), QGVAR(5rnd_smoke_white), QGVAR(5rnd_smoke_red), QGVAR(5rnd_00buckshot)
        };

        modes[] = {"Single"};
        discreteDistance[] = {100};
        discreteDistanceInitIndex = 0;

        class Single: Mode_SemiAuto {
            sounds[] = {"StandardSound"};
            class StandardSound {
                soundSetShot[] = {"CUP_GrenadeLaunchers_Shot_SoundSet", "UGL_Tail_SoundSet", "UGL_InteriorTail_SoundSet"};
                weaponSoundEffect = "DefaultRifle";
                begin1[] = {"CUP\Weapons\CUP_Weapons_GrenadeLaunchers\data\sfx\g_launcher",1,1,200};
                soundBegin[] = {"begin1", 1};
                class SoundTails {
                    class TailInterior {
                        sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_interior",2.2387211,1,1800};
                        frequency = 1;
                        volume = "interior";
                    };
                    class TailTrees {
                        sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_trees",1.0,1,1800};
                        frequency = 1;
                        volume = "(1-interior/1.4)*trees";
                    };
                    class TailForest {
                        sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_forest",1.0,1,1800};
                        frequency = 1;
                        volume = "(1-interior/1.4)*forest";
                    };
                    class TailMeadows {
                        sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_meadows",1.0,1,1800};
                        frequency = 1;
                        volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
                    };
                    class TailHouses {
                        sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_houses",1.0,1,1800};
                        frequency = 1;
                        volume = "(1-interior/1.4)*houses";
                    };
                };
            };
        };
    };
};

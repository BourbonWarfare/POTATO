class Mode_SemiAuto;

class CfgWeapons {
    class Launcher_Base_F;
    class GVAR(carryWeapon): Launcher_Base_F {
        author = "pab";
        scope = 2;
        displayName = "VZ99 60mm Mortar";
        model = QUOTE(PATHTOF(data\vz99_carry));
        picture = QUOTE(PATHTOF(ui\weaponSide_ca.paa));
        modes[] = {};
    };

    class CannonCore;
    class mortar60mm: CannonCore {
        class StandardSound {
            SoundSetShot[] = {"Mortar82mm_Shot_SoundSet","Mortar82mm_Tail_SoundSet"};
            begin1[] = {"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_01",1.25893,1,250};
            begin2[] = {"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_02",1.25893,1,250};
            soundBegin[] = {"begin1",0.5,"begin2",0.5};
        };

        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            class StandardSound {
                SoundSetShot[] = {"Mortar82mm_Shot_SoundSet","Mortar82mm_Tail_SoundSet"};
                begin1[] = {"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_01",1.25893,1,250};
                begin2[] = {"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_02",1.25893,1,250};
                soundBegin[] = {"begin1",0.5,"begin2",0.5};
            };
            displayName = "Single";
            sounds[] = {"StandardSound"};
            reloadSound[] = {"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar",1,1,20};
            soundServo[] = {"",0.0001,1};
            reloadTime = 1.8;
            minRange = 0;
            midRange = 0;
            maxRange = 0;
            artilleryDispersion = 0;
            artilleryCharge = 1;
        };

        scope = 1;
        displayname = "Mortar 60 mm (Trigger)";
        nameSound = "CannonCore";
        cursor = "mortar";
        cursorAim = "EmptyCursor";
        sounds[] = {"StandardSound"};
        reloadSound[] = {"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar",1,1,20};
        reloadMagazineSound[] = {"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_magazine_Mortar",1,1,20};
        soundServo[] = {"",0.0001,1};
        minRange = 80;
        minRangeProbab = 0.7;
        midRange = 2000;
        midRangeProbab = 0.7;
        maxRange = 4000;
        maxRangeProbab = 0.1;
        reloadTime = 1.8;
        magazineReloadTime = 1; ///xxxxxxxxxxxxxxx
        maxLeadSpeed = 100;
        autoReload = 1;
        canLock = 0;
        magazines[] = {QGVAR(HE), QGVAR(HE_charge0), QGVAR(HE_multi), QGVAR(HE_multi_charge0), QGVAR(HE_PRX), QGVAR(HE_PRX_charge0), QGVAR(HE_NSB), QGVAR(HE_NSB_charge0), QGVAR(smokeWhite), QGVAR(smokeWhite_charge0), GVAR(smokeRed), GVAR(smokeRed_charge0), QGVAR(flare), QGVAR(flare_charge0)};
        ballisticsComputer = 0;
        class GunParticles {
            class FirstEffect {
                effectName = "MortarFired";
                positionName = "Usti Hlavne";
                directionName = "Konec Hlavne";
            };
        };
    };
};

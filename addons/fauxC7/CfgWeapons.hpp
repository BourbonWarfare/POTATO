class CfgWeapons {
    class ItemCore;
    class InventoryMuzzleItem_Base_F;
    class Rifle;
    class Rifle_Base_F: Rifle {
        class WeaponSlotsInfo;
        class GunParticles;
    };
    class CUP_arifle_M16_Base: Rifle_Base_F {
    };
    class CUP_arifle_M16A4_Base: CUP_arifle_M16_Base {
    };
    class CUP_arifle_M16A4_GL: CUP_arifle_M16_Base {
    };
    class CUP_arifle_XM16E1: CUP_arifle_M16_Base {
    };
    class CUP_arifle_M16A1E1: CUP_arifle_XM16E1 {
    };
    class CUP_arifle_M16A1GL: CUP_arifle_XM16E1 {
    }; 
    class GVAR(c7): CUP_arifle_M16A1E1 {
        author = "Potato";
        displayName = "C7";
        modes[] = {"Single","FullAuto","Burst_medium","single_medium_optics1","single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
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
    class GVAR(c7GL): CUP_arifle_M16A1GL {
        author = "Potato";
        displayName = "C7 M203";
    };
    class GVAR(c7a2): CUP_arifle_M16A4_Base {
        author = "Potato";
        displayName = "C7A2"
        modes[] = {"Single","FullAuto","Burst_medium","single_medium_optics1","single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
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
    class GVAR(c7a2GL): CUP_arifle_M16A4_GL {
        author = "Potato";
        displayName = "C7A2 M203"
        modes[] = {"Single","FullAuto","Burst_medium","single_medium_optics1","single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
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
};
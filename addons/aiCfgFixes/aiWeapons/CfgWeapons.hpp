class Mode_SemiAuto;
class CfgWeapons {
    // Base vanilla includes
    //class ItemCore;
    class Launcher_Base_F;
    //class InventoryOpticsItem_Base_F;
    // Dumb down AI accuracy
    class CUP_launch_RPG7V: Launcher_Base_F {
        maxRange = 350;
        class Single: Mode_SemiAuto { // lower AI range without optics
            aiRateOfFireDistance = 350;
            maxRange = 350;
            maxRangeProbab = 0.1;
            midRange = 200;
            midRangeProbab = 0.8;
            minRange = 10;
            minRangeProbab = 0.4;
        };
        /*class Single_Optic2_AI: Single { // AI optic mode where they hit farther
            aiRateOfFireDistance = 500;
            maxRange = 500;
            maxRangeProbab = 0.1;
            midRange = 300;
            midRangeProbab = 0.8;
            minRange = 10;
            minRangeProbab = 0.3;
            requiredOpticType = 2;
            showToPlayer = 0;
        };*/
        //modes[] = {"Single", "Single_Optic2_AI"};
    };
    class CUP_launch_RPG7V_optic: CUP_launch_RPG7V {
        maxRange = 500;
        class Single: Single { // lower AI range without optics
            aiRateOfFire = 5;
            aiRateOfFireDistance = 500;
            maxRange = 500;
            maxRangeProbab = 0.1;
            midRange = 350;
            midRangeProbab = 0.8;
            minRange = 10;
            minRangeProbab = 0.3;
        };
    };
    class CUP_launch_RPG7V_untrained: CUP_launch_RPG7V {
        scope = 1;
        scopeArsenal = 1;
        class Single: Single {
            aiDispersionCoefY = 2.2;
            aiRateOfFire = 10;
            dispersion = 0.002;
            midRangeProbab = 0.4;
            minRangeProbab = 0.25;
        };
        /*class Single_Optic2_AI: Single_Optic2_AI {
            aiDispersionCoefY = 2.2;
            dispersion = 0.002;
            midRangeProbab = 0.4;
        };*/
        //modes[] = {"Single", "Single_Optic2_AI"};
    };
    class CUP_launch_RPG7V_untrained_optic: CUP_launch_RPG7V_optic {
        maxRange = 500;
        class Single: Single { // lower AI range without optics
            aiDispersionCoefY = 1.6;
            aiRateOfFire = 8;
            midRange = 200;
            midRangeProbab = 0.7;
        };
    };
    // Update PGO-7 sights
    /*class CUP_optic_PGO7V: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            opticType = 2;
        };
    };*/
};

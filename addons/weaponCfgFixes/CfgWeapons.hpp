class Mode_FullAuto;
class Mode_Burst;
class Mode_SemiAuto;
class CfgWeapons {
    class Default;
    class RifleCore: Default {};
    class Rifle: RifleCore {};
    class Rifle_Base_F: Rifle {};
    class Rifle_Long_Base_F: Rifle_Base_F {};
    class PistolCore: Default {};
    class Pistol: PistolCore {};
    class Pistol_Base_F: Pistol {};
    class Rifle_Short_Base_F: Rifle_Base_F {};
    class DMR_01_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","fullauto_medium","potato_single","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 10;
            aiRateOfFireDistance = 1500;
            minRange = 1;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1800;
            maxRangeProbab = 0.1;
        };
    };
    class EBR_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class GM6_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class LRR_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class LMG_Mk200_F: Rifle_Long_Base_F {
        modes[] = {"manual","Single","close","short","medium","far_optic1","far_optic2","ACE_Burst_far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class manual: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: manual {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: manual {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: manual {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: manual {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: manual {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class LMG_Zafir_F: Rifle_Long_Base_F {
        modes[] = {"FullAuto","Single","close","short","medium","far_optic1","far_optic2","ACE_Burst_far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: FullAuto {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: FullAuto {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class hgun_ACPC2_F: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class hgun_P07_F: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class hgun_Pistol_heavy_01_F: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class hgun_Pistol_heavy_02_F: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class hgun_Rook40_F: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class arifle_Katiba_Base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","ACE_Burst_far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_Katiba_C_F: arifle_Katiba_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","ACE_Burst_far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: ACE_Burst_far {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class mk20_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2","ACE_Burst_far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_Mk20C_F: mk20_base_F {
        modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2","ACE_Burst_far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: ACE_Burst_far {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_MX_Base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2","ACE_Burst_far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_MXC_F: arifle_MX_Base_F {
        modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2","ACE_Burst_far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: ACE_Burst_far {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_MX_SW_F: arifle_MX_Base_F {
        modes[] = {"Single","manual","close","short","medium","far_optic1","far_optic2","ACE_Burst_far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class manual: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: ACE_Burst_far {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: Single {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: Single {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: Single {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: Single {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: Single {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class arifle_MXM_F: arifle_MX_Base_F {
        modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2","ACE_Burst_far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: ACE_Burst_far {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class Tavor_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_medium_optics2","fullauto_medium","ACE_Burst_far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_TRG21_F: Tavor_base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_medium_optics2","fullauto_medium","ACE_Burst_far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics2: single_medium_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: ACE_Burst_far {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class pdw2000_base_F: Rifle_Short_Base_F {
        modes[] = {"Single","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class SMG_01_Base: Rifle_Short_Base_F {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
        };
    };
    class SMG_02_base_F: Rifle_Short_Base_F {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_hgun_Compact: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class CUP_srifle_CZ750_Base: Rifle_Long_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_hgun_Duty: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class CUP_srifle_CZ550_base: Rifle_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_srifle_LeeEnfield: Rifle_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_srifle_M14_DMR: Rifle_Base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_srifle_M24_des: Rifle_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_srifle_M40A3: CUP_srifle_M24_des {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_hgun_Phantom: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class DMR_02_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 10;
            aiRateOfFireDistance = 1500;
            minRange = 1;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1800;
            maxRangeProbab = 0.1;
        };
    };
    class DMR_03_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","fullauto_medium","ACE_Burst_far","potato_single","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 10;
            aiRateOfFireDistance = 1500;
            minRange = 1;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1800;
            maxRangeProbab = 0.1;
        };
    };
    class DMR_04_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 10;
            aiRateOfFireDistance = 1500;
            minRange = 1;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1800;
            maxRangeProbab = 0.1;
        };
    };
    class DMR_05_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","fullauto_medium","ACE_Burst_far","potato_single","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 10;
            aiRateOfFireDistance = 1500;
            minRange = 1;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1800;
            maxRangeProbab = 0.1;
        };
    };
    class DMR_06_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","fullauto_medium","ACE_Burst_far","potato_single","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 10;
            aiRateOfFireDistance = 1500;
            minRange = 1;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1800;
            maxRangeProbab = 0.1;
        };
    };
    class MMG_01_base_F: Rifle_Long_Base_F {
        modes[] = {"manual","burst","close","short","medium","far_optic1","far_optic2","ACE_Burst_far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class manual: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: manual {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: manual {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: manual {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: manual {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: manual {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class MMG_02_base_F: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far_optic1","far_optic2","ACE_Burst_far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class manual: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class ACE_Burst_far: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: manual {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: manual {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: manual {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: manual {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: manual {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class CUP_sgun_AA12: Rifle_Base_F {
        modes[] = {"FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_ak74m_Base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_ak74m: rhs_weap_ak74m_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_asval: rhs_weap_ak74m {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_vss: rhs_weap_asval {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_akm: rhs_weap_ak74m {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_ak103_base: rhs_weap_akm {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_ak103_1: rhs_weap_ak103_base {
        modes[] = {"Single","single_medium_optics1","single_far_optics2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_ak103_2: rhs_weap_ak103_base {
        modes[] = {"Single","Burst","single_medium_optics1","single_far_optics2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_ak74: rhs_weap_ak74m {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_aks74: rhs_weap_ak74 {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_aks74u: rhs_weap_aks74 {
        modes[] = {"FullAuto","Single","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_svd: rhs_weap_ak74m {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_svdp: rhs_weap_svd {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_far_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_orsis_Base_F: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hgun_PDW2000_F: pdw2000_base_F {
        modes[] = {"Single","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_pp2000: hgun_PDW2000_F {
        modes[] = {"Single","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_pkp_base: Rifle_Long_Base_F {
        modes[] = {"FullAuto","Single","close","short","medium","far_optic1","far_optic2","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: FullAuto {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: FullAuto {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class rhs_weap_pkp: rhs_pkp_base {
        modes[] = {"FullAuto","Single","close","short","medium","far_optic1","far_optic2","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: short {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: FullAuto {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: FullAuto {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class rhs_weap_pkm: rhs_weap_pkp {
        modes[] = {"manual","close","short","medium","far_optic1","far_optic2","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class manual: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: short {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: manual {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: manual {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: manual {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: manual {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: manual {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class rhs_weap_rpk74m: rhs_weap_pkp {
        modes[] = {"single","manual","close","short","medium","far_optic1","far_optic2","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class manual: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: short {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: single {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: single {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: single {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: single {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: single {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: single {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: single {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class rhs_weap_kar98k_Base_F: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m38_Base_F: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m38: rhs_weap_m38_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: medium_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m38_rail: rhs_weap_m38 {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: medium_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_mosin_sbr: rhs_weap_m38_rail {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: medium_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_XM2010_Base_F: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m70_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m92: rhs_weap_m70_base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m76: rhs_weap_m70_base {
        modes[] = {"Single","single_medium_optics1","single_far_optics2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m21_base: rhs_weap_m70_base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m21s: rhs_weap_m21_base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class SMG_01_F: SMG_01_Base {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_savz61: SMG_01_F {
        modes[] = {"Single","FullAuto","potato_single","potato_burst","potato_fullAuto"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_savz58_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_Izh18: Rifle_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_stgw57_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m4_Base: arifle_MX_Base_F {
        modes[] = {"Single","Burst","single_medium_optics1","single_far_optics2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m4a1: rhs_weap_m4_Base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_hk416d10: rhs_weap_m4a1 {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m27iar: rhs_weap_m4a1 {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_far_optics2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_M249_base: LMG_Mk200_F {
        modes[] = {"FullAuto","close","short","medium","far_optic1","far_optic2","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: short {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: FullAuto {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: FullAuto {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class rhs_weap_saw_base: Rifle_Base_F {
        modes[] = {"FullAuto","close","short","medium","far_optic1","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_lmg_minimipara: rhs_weap_saw_base {
        modes[] = {"FullAuto","close","short","medium","far_optic1","far_optic2","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: short {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: FullAuto {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: FullAuto {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class rhs_weap_m240_base: rhs_weap_M249_base {
        modes[] = {"manual","close","short","medium","far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class manual: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: short {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: manual {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: manual {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: manual {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: manual {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: manual {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class srifle_EBR_F: EBR_base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_far_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_m14ebrri: srifle_EBR_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_far_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_sr25: rhs_weap_m14ebrri {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_far_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_M107_Base_F: GM6_base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: medium_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic2 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhs_weap_M590_5RD: Rifle_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class rhsusf_weap_MP7A1_base_f: SMG_02_base_F {
        modes[] = {"Single","FullAuto","potato_single","potato_burst","potato_fullAuto"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
        };
    };
    class DMR_07_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 10;
            aiRateOfFireDistance = 1500;
            minRange = 1;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1800;
            maxRangeProbab = 0.1;
        };
    };
    class LMG_03_base_F: Rifle_Long_Base_F {
        modes[] = {"FullAutoFast","FullAutoSlow","close","short","medium","far_optic1","far_optic2","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class FullAutoSlow: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAutoFast: FullAutoSlow {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: FullAutoFast {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: FullAutoSlow {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAutoFast {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: FullAutoFast {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: FullAutoFast {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: FullAutoFast {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: FullAutoFast {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: FullAutoFast {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAutoFast {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: FullAutoFast {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class hgun_Pistol_01_F: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class arifle_AK12_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Burst","Single","Burst_medium","single_medium_optics1","single_medium_optics2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst_medium: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_AKM_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single","FullAuto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_AKS_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single","FullAuto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_ARX_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_CTAR_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_CTARS_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single","single_medium_optics1","single_far_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_SPAR_01_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_medium_optics2","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class arifle_SPAR_02_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single","single_medium_optics1","single_medium_optics2","fullauto_medium","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: FullAuto {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: FullAuto {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class arifle_SPAR_03_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","fullauto_medium","potato_single","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 10;
            aiRateOfFireDistance = 1500;
            minRange = 1;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1800;
            maxRangeProbab = 0.1;
        };
    };
    class SMG_05_base_F: Rifle_Short_Base_F {
        modes[] = {"Single","FullAuto","potato_single","potato_burst","potato_fullAuto"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_hgun_Glock17: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class CUP_srifle_ksvk: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium_optic2: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_hgun_M9: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class CUP_hgun_Makarov: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class CUP_hgun_MicroUzi: Pistol_Base_F {
        modes[] = {"Single","FullAuto","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class CUP_smg_MP5SD6: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_smg_MP5A5: CUP_smg_MP5SD6 {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_hgun_PB6P9: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class CUP_hgun_TaurusTracker455: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class CUP_sgun_Saiga12K: Rifle_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_hgun_BallisticShield_Armed: Rifle_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_srifle_SVD: Rifle_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_lmg_UK59: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class manual: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: manual {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: manual {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: manual {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: manual {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: manual {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class CUP_srifle_VSSVintorez: Rifle_Base_F {
        modes[] = {"Single","Full","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Full: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_g3_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics1","single_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_psg1: hlc_g3_base {
        modes[] = {"Single","single_medium_optics1","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_psg1A1: hlc_rifle_psg1 {
        modes[] = {"Single","single_medium_optics1","single_far_optics1","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_g3sg1: hlc_g3_base {
        modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics1","single_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_far_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium: single_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_g3a3: hlc_rifle_g3sg1 {
        modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics1","single_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_far_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium: single_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_g3ka4: hlc_rifle_g3a3 {
        modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics1","single_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_far_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium: single_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_hk51: hlc_rifle_g3sg1 {
        modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics1","single_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_far_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium: single_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_hk53: hlc_g3_base {
        modes[] = {"Single","Burst","FullAuto","single_medium_optics1","single_far_optics2","AI_Burst_close","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class AI_Burst_close: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_hk33a2: hlc_g3_base {
        modes[] = {"Single","Burst","FullAuto","single_medium_optics1","single_far_optics2","AI_Burst_close","AI_far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class AI_Burst_close: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class AI_far: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_MP5_base: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_smg_mp5k_PDW: hlc_MP5_base {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_smg_mp5k: hlc_smg_mp5k_PDW {
        modes[] = {"Single","FullAuto","potato_single"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class hlc_smg_MP5N: hlc_MP5_base {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_smg_9mmar: hlc_smg_MP5N {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_smg_mp510: hlc_smg_MP5N {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_STGW_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_sig5104: hlc_STGW_base {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_far_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: fullauto_medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_amt: hlc_rifle_sig5104 {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_far_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AK_Base: Rifle_Base_F {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AK107_Base: CUP_arifle_AK_Base {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AK47: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AK74: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AK74M: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AK74M_GL: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AK107: CUP_arifle_AK107_Base {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AK107_GL: CUP_arifle_AK107_Base {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AKS_Base: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AKS74: CUP_arifle_AKS_Base {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AKS74U: CUP_arifle_AKS_Base {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AK74_GL: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AKM: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_AKS: CUP_arifle_AKM {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_RPK74: CUP_arifle_AK74 {
        modes[] = {"manual","close","short","medium","far","Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class manual: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: manual {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_srifle_AS50: Rifle_Long_Base_F {
        modes[] = {"Single","potato_single","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 10;
            aiRateOfFireDistance = 1500;
            minRange = 1;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1800;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_srifle_AWM_Base: Rifle_Long_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_smg_bizon: Rifle_Base_F {
        modes[] = {"FullAuto","Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_hgun_Colt1911: Pistol_Base_F {
        modes[] = {"Single","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class CUP_arifle_CZ805_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_CZ805_B_Base: CUP_arifle_CZ805_Base {
        modes[] = {"single","burst","fullauto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_smg_EVO: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_FNFAL: Rifle_Base_F {
        modes[] = {"Fullauto","Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Fullauto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Fullauto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Fullauto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Fullauto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Fullauto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Fullauto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_G36_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","Fullauto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Fullauto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_G36A: CUP_arifle_G36_Base {
        modes[] = {"Single","Burst","Fullauto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Fullauto: Fullauto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_G36K: CUP_arifle_G36A {
        modes[] = {"Single","Burst","Fullauto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Fullauto: Fullauto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_G36C: Rifle_Base_F {
        modes[] = {"Single","Burst","Fullauto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Fullauto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_MG36: CUP_arifle_G36C {
        modes[] = {"Single","Burst","Fullauto","close","medium","far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Fullauto: Fullauto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_lmg_L110A1: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class manual: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: manual {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: manual {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: manual {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: manual {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: manual {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class CUP_srifle_L129A1: Rifle_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_l85a2_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics2: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_sgun_M1014: Rifle_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_srifle_M107_Base: Rifle_Long_Base_F {
        modes[] = {"Single","potato_single","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 10;
            aiRateOfFireDistance = 1500;
            minRange = 1;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1800;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_srifle_M110: Rifle_Base_F {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_srifle_M14: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_M16_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_M16A4_Base: CUP_arifle_M16_Base {
        modes[] = {"Single","Burst","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_M4_Base: CUP_arifle_M16A4_Base {
        modes[] = {"Single","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_M4A1: CUP_arifle_M4_Base {
        modes[] = {"Single","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_srifle_Mk12SPR: CUP_arifle_M4A1 {
        modes[] = {"Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_lmg_M240: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class manual: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: manual {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: manual {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: manual {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: manual {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: manual {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class CUP_saw_base: Rifle_Long_Base_F {
        modes[] = {"FullAuto","close","short","medium","far_optic1","far_optic2","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_M60E4_base: Rifle_Long_Base_F {
        modes[] = {"FullAuto","close","short","medium","far_optic1","far_optic2","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic1: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far_optic2: far_optic1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: FullAuto {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: FullAuto {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: FullAuto {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class CUP_lmg_Mk48_Base: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class manual: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: manual {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: manual {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: manual {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: manual {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: manual {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class CUP_lmg_PKM: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class manual: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: manual {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: manual {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: manual {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: manual {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: manual {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class CUP_lmg_Pecheneg: CUP_lmg_PKM {
        modes[] = {"manual","close","short","medium","far","potato_single","potato_close","potato_short","potato_medium","potato_far1","potato_far2","potato_mediumOptic","potato_farOptic"};
        class manual: manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class close: close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class short: short {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class medium: medium {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class far: far {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+random 20";
            maxRangeProbab = 0.1;
        };
        class potato_close: manual {
            showToPlayer = 0;
            burst = "5+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+random 50";
            midRangeProbab = 0.7;
            maxRange = "100+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_short: manual {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+random 50";
            midRangeProbab = 0.7;
            maxRange = "300+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_medium: manual {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+random 50";
            midRangeProbab = 0.7;
            maxRange = "400+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far1: manual {
            showToPlayer = 0;
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+random 50";
            midRangeProbab = 0.7;
            maxRange = "600+random 50";
            maxRangeProbab = 0.1;
        };
        class potato_far2: manual {
            showToPlayer = 0;
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.3;
        };
        class potato_farOptic: manual {
            showToPlayer = 0;
            burst = "2+round random 3";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.3;
            midRange = "700+random 50";
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.5;
        };
    };
    class CUP_arifle_Sa58_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","fullauto_medium","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_close_optics1: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_medium_optics1: single_close_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class single_far_optics1: single_medium_optics1 {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class fullauto_medium: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_hgun_SA61: Pistol_Base_F {
        modes[] = {"Single","FullAuto","potato_single"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
        };
    };
    class CUP_smg_SA61: Rifle_Base_F {
        modes[] = {"Single","FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_SCAR_Base: Rifle_Base_F {
        modes[] = {"SCAR_L_Single","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class SCAR_L_Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_SCAR_L_Base: CUP_arifle_SCAR_Base {
        modes[] = {"SCAR_L_Single","SCAR_L_FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class SCAR_L_Single: SCAR_L_Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class SCAR_L_FullAuto: SCAR_L_Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_Mk16_CQC: CUP_arifle_SCAR_L_Base {
        modes[] = {"SCAR_L_Single","SCAR_L_FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class SCAR_L_Single: SCAR_L_Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class SCAR_L_FullAuto: SCAR_L_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_Mk16_STD: CUP_arifle_SCAR_L_Base {
        modes[] = {"SCAR_L_Single","SCAR_L_FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class SCAR_L_Single: SCAR_L_Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class SCAR_L_FullAuto: SCAR_L_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_Mk16_SV: CUP_arifle_SCAR_L_Base {
        modes[] = {"SCAR_L_Single","SCAR_L_FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class SCAR_L_Single: SCAR_L_Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class SCAR_L_FullAuto: SCAR_L_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: SCAR_L_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_Mk17_Base: CUP_arifle_SCAR_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class SCAR_H_Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class SCAR_H_FullAuto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_Mk17_CQC: CUP_arifle_Mk17_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class SCAR_H_Single: SCAR_H_Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class SCAR_H_FullAuto: SCAR_H_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_Mk17_STD: CUP_arifle_Mk17_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class SCAR_H_Single: SCAR_H_Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class SCAR_H_FullAuto: SCAR_H_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_Mk17_STD_FG: CUP_arifle_Mk17_STD {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class SCAR_H_Single: SCAR_H_Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class SCAR_H_FullAuto: SCAR_H_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_Mk20: CUP_arifle_Mk17_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class SCAR_H_Single: SCAR_H_Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class SCAR_H_FullAuto: SCAR_H_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: SCAR_H_Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_XM8_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","Fullauto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Fullauto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_XM8_Railed_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","Fullauto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Fullauto: Mode_FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_xm8_sharpshooter: CUP_arifle_XM8_Base {
        modes[] = {"Single","Burst","Fullauto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Fullauto: Fullauto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_xm8_SAW: CUP_arifle_xm8_sharpshooter {
        modes[] = {"Manual","Close","Short","Medium","Far","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Manual: FullAuto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Close: Manual {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Short: Close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Medium: Close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Far: Close {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Manual {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Manual {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Manual {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Manual {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Manual {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_arifle_XM8_Compact: CUP_arifle_XM8_Base {
        modes[] = {"Single","Burst","Fullauto","potato_single","potato_burst","potato_fullAuto","potato_mediumOptic","potato_farOptic"};
        class Single: Single {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Burst: Burst {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class Fullauto: Fullauto {
            minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;
        };
        class potato_single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class potato_burst: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class potato_fullAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
        };
        class potato_mediumOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
        class potato_farOptic: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
        };
    };
};


class Mode_FullAuto;
class Mode_Burst;
class Mode_SemiAuto;
class CfgWeapons {
    class Default;
    class Pistol_Base_F;
    class Rifle_Long_Base_F;
    class Rifle_Base_F;
    class Rifle_Short_Base_F;
    class MGun;
    class GrenadeLauncher: Default {
        aiDispersionCoefX = 3;
    };
    class UGL_F: GrenadeLauncher {
        class Single: Mode_SemiAuto {
            aiDispersionCoefX = 3;
            aiDispersionCoefY = 6;
        };
    };
    class hgun_P07_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 25;
            showToPlayer = 1;
        };
    };
    class Sashka_Russian: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class Shovel_Russian: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class Bat_Spike: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class Pipe_aluminium: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class Police_Bat: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class Crowbar: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class Bat_Clear: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class Rod: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class IceAxe: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class DMR_01_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","Single_Close_optics1","Single_medium_optics1","Single_far_optics1","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class EBR_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
        class FullAuto: Mode_FullAuto {

        };
        class FullAuto_medium: FullAuto {

        };
    };
    class GM6_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 450;
            maxRangeProbab = 0.3;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

        };
    };
    class LRR_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.1;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.05;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

        };
    };
    class LMG_Mk200_F: Rifle_Long_Base_F {
        modes[] = {"Manual","Single","close","short","medium","far_optic1","far_optic2","ACE_Burst_far"};
        class Manual: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.7;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Manual {
            showToPlayer = 1;
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.7;
            maxRange = 10;
            maxRangeProbab = 0.04;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 7;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: medium {

        };
        class far_optic2: far_optic1 {

        };
        class ACE_Burst_far: medium {
            aiRateOfFire = 6;
            aiRateOfFireDistance = 900;
            minRange = 500;
            minRangeProbab = 0.1;
            midRange = 700;
            midRangeProbab = 0.2;
            maxRange = 900;
            maxRangeProbab = 0.2;
            Burst = "3 + round random 5";
            showToPlayer = 0;
        };
    };
    class LMG_Zafir_F: Rifle_Long_Base_F {
        modes[] = {"FullAuto","Single","close","short","medium","far_optic1","far_optic2","ACE_Burst_far"};
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRangeProbab = 0.01;
            midRange = 200;
            midRangeProbab = 0.01;
            maxRange = 400;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
            minRange = 120;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: FullAuto {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 30;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 5;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 400;
            midRangeProbab = 0.6;
            maxRange = 600;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
        class ACE_Burst_far: medium {
            aiRateOfFire = 6;
            aiRateOfFireDistance = 900;
            minRange = 500;
            minRangeProbab = 0.1;
            midRange = 700;
            midRangeProbab = 0.2;
            maxRange = 900;
            maxRangeProbab = 0.2;
            Burst = "3 + round random 5";
            showToPlayer = 0;
        };
    };
    class hgun_ACPC2_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 25;
            showToPlayer = 1;
        };
    };
    class hgun_Pistol_heavy_01_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 25;
            showToPlayer = 1;
        };
    };
    class hgun_Pistol_heavy_02_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 25;
            showToPlayer = 1;
        };
    };
    class hgun_Rook40_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 25;
            showToPlayer = 1;
        };
    };
    class arifle_Katiba_Base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            maxRange = 400;
            maxRangeProbab = 0.3;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 300;
            midRangeProbab = 0.5;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 20;
            Burst = "3 + round random 5";
        };
        class ACE_Burst_far: FullAuto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            Burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class arifle_Katiba_C_F: arifle_Katiba_Base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium","ACE_Burst_far"};
        class Single: Single {
            maxRange = 350;
            maxRangeProbab = 0.2;
            minRange = 120;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 20;
            maxRange = 150;
            Burst = "3 + round random 5";
        };
        class ACE_Burst_far: FullAuto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 300;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.2;
            maxRange = 500;
            maxRangeProbab = 0.2;
            Burst = "2 + round random 3";
            showToPlayer = 0;
        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class mk20_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            maxRange = 300;
            maxRangeProbab = 0.2;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 250;
            midRangeProbab = 0.5;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            minRange = 0;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 20;
            maxRange = 150;
            Burst = "3 + round random 5";
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
        class ACE_Burst_far: FullAuto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            Burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class arifle_Mk20C_F: mk20_base_F {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2","ACE_Burst_far"};
        class Single: Single {
            maxRangeProbab = 0.3;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 250;
            midRangeProbab = 0.5;
            maxRange = 350;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            minRange = 0;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            minRangeProbab = 0.2;
            midRange = 450;
            midRangeProbab = 0.7;
            maxRange = 600;
            maxRangeProbab = 0.05;
            aiRateOfFire = 6;
            aiRateOfFireDistance = 600;
            minRange = 20;
            Burst = "3 + round random 5";
            showToPlayer = 0;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class ACE_Burst_far: FullAuto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 300;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.2;
            maxRange = 500;
            maxRangeProbab = 0.2;
            Burst = "2 + round random 3";
            showToPlayer = 0;
        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class arifle_Mk20_GL_F: mk20_base_F {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2","ACE_Burst_far"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            minRange = 2;
            minRangeProbab = 0.2;
            midRange = 450;
            midRangeProbab = 0.7;
            maxRange = 600;
            maxRangeProbab = 0.05;
            aiRateOfFire = 6;
            aiRateOfFireDistance = 600;
            showToPlayer = 0;
            Burst = "3 + round random 5";
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class arifle_MX_Base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            maxRange = 400;
            maxRangeProbab = 0.3;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 300;
            midRangeProbab = 0.5;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 20;
            Burst = "3 + round random 5";
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
        class ACE_Burst_far: FullAuto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            Burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class arifle_MXC_F: arifle_MX_Base_F {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2","ACE_Burst_far"};
        class Single: Single {
            maxRange = 350;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 20;
            Burst = "3 + round random 5";
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
        class ACE_Burst_far: FullAuto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 300;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.2;
            maxRange = 500;
            maxRangeProbab = 0.2;
            Burst = "2 + round random 3";
            showToPlayer = 0;
        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class arifle_MX_SW_F: arifle_MX_Base_F {
        modes[] = {"Single","Manual","close","short","medium","far_optic1","far_optic2","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0.01;
            midRange = 200;
            midRangeProbab = 0.01;
            maxRange = 400;
            maxRangeProbab = 0.01;
            minRange = 120;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Manual: FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.7;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 5;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
        class ACE_Burst_far: medium {
            aiRateOfFire = 6;
            aiRateOfFireDistance = 900;
            minRange = 500;
            minRangeProbab = 0.1;
            midRange = 700;
            midRangeProbab = 0.2;
            maxRange = 900;
            maxRangeProbab = 0.2;
            Burst = "3 + round random 5";
            showToPlayer = 0;
        };
    };
    class arifle_MXM_F: arifle_MX_Base_F {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2","ACE_Burst_far"};
        class Single: Single {
            maxRange = 450;
            maxRangeProbab = 0.3;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 350;
            midRangeProbab = 0.5;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 20;
            Burst = "3 + round random 5";
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_far_optics2: Single_far_optics2 {

        };
    };
    class SDAR_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0.3;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 35;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 20;
            minRange = 10;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 5;
            midRangeProbab = 0.7;
            maxRange = 10;
            maxRangeProbab = 0.05;
            aiRateOfFire = 0.2;
            aiRateOfFireDistance = 5;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {

        };
    };
    class Tavor_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_medium_optics2","FullAuto_medium","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            maxRangeProbab = 0.2;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 250;
            midRangeProbab = 0.5;
            maxRange = 350;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            minRange = 0;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            minRange = 20;
            maxRange = 150;
            Burst = "3 + round random 5";
            aiRateOfFireDistance = 500;
        };
        class ACE_Burst_far: FullAuto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 300;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.2;
            maxRange = 500;
            maxRangeProbab = 0.2;
            Burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class arifle_TRG21_F: Tavor_base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_medium_optics2","FullAuto_medium","ACE_Burst_far"};
        class Single: Single {
            maxRangeProbab = 0.3;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 300;
            midRangeProbab = 0.5;
            maxRange = 400;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            minRange = 0;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            minRange = 20;
            maxRange = 150;
            Burst = "3 + round random 5";
            aiRateOfFireDistance = 500;
        };
        class ACE_Burst_far: FullAuto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 300;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.2;
            maxRange = 500;
            maxRangeProbab = 0.2;
            Burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class pdw2000_base_F: Rifle_Short_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0.3;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 100;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 70;
            maxRangeProbab = 0.05;
            aiRateOfFire = 0.2;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {

        };
    };
    class SMG_01_Base: Rifle_Short_Base_F {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0.3;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 250;
            minRange = 25;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
    };
    class SMG_02_base_F: Rifle_Short_Base_F {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Mode_SemiAuto {
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            minRangeProbab = 0.3;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 250;
            minRange = 25;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
    };
    class Weap_melee_knife: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 25;
            showToPlayer = 1;
        };
    };
    class hgun_Pistol_Signal_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 25;
            showToPlayer = 1;
        };
    };
    class DMR_02_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class DMR_03_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","Single_Close_optics1","Single_medium_optics1","Single_far_optics1","FullAuto_medium","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            midRange = 350;
            maxRange = 500;
            maxRangeProbab = 0.05;
            minRange = 120;
            minRangeProbab = 0.7;
            midRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            minRange = 20;
            maxRange = 150;
            Burst = "3 + round random 5";
            aiRateOfFireDistance = 500;
        };
        class ACE_Burst_far: FullAuto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            Burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class DMR_04_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 450;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class DMR_05_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","Single_Close_optics1","Single_medium_optics1","Single_far_optics1","FullAuto_medium","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            midRange = 350;
            maxRange = 500;
            maxRangeProbab = 0.05;
            minRange = 120;
            minRangeProbab = 0.7;
            midRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            minRange = 20;
            maxRange = 150;
            Burst = "3 + round random 5";
            aiRateOfFireDistance = 500;
        };
        class ACE_Burst_far: FullAuto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            Burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class DMR_06_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","Single_Close_optics1","Single_medium_optics1","Single_far_optics1","FullAuto_medium","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            midRange = 350;
            maxRange = 500;
            maxRangeProbab = 0.05;
            minRange = 120;
            minRangeProbab = 0.7;
            midRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            minRange = 20;
            maxRange = 150;
            Burst = "3 + round random 5";
            aiRateOfFireDistance = 500;
        };
        class ACE_Burst_far: FullAuto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            Burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class MMG_01_base_F: Rifle_Long_Base_F {
        modes[] = {"Manual","Burst","close","short","medium","far_optic1","far_optic2","ACE_Burst_far"};
        class Manual: Mode_FullAuto {
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 30;
            midRangeProbab = 0.58;
            maxRange = 80;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 10;
            minRangeProbab = 0.3;
            midRange = 60;
            midRangeProbab = 0.58;
            maxRange = 150;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: Burst {
            Burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 600;
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: medium {

        };
        class far_optic2: far_optic1 {

        };
        class ACE_Burst_far: medium {
            aiRateOfFire = 6;
            aiRateOfFireDistance = 900;
            minRange = 700;
            minRangeProbab = 0.1;
            midRange = 900;
            midRangeProbab = 0.2;
            maxRange = 1100;
            maxRangeProbab = 0.2;
            Burst = "3 + round random 5";
            showToPlayer = 0;
        };
    };
    class MMG_02_base_F: Rifle_Long_Base_F {
        modes[] = {"Manual","close","short","medium","far_optic1","far_optic2","ACE_Burst_far"};
        class Manual: Mode_FullAuto {
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 30;
            midRangeProbab = 0.58;
            maxRange = 80;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 600;
            midRangeProbab = 0.6;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
        class ACE_Burst_far: medium {
            aiRateOfFire = 6;
            aiRateOfFireDistance = 900;
            minRange = 700;
            minRangeProbab = 0.1;
            midRange = 900;
            midRangeProbab = 0.2;
            maxRange = 1100;
            maxRangeProbab = 0.2;
            Burst = "3 + round random 5";
            showToPlayer = 0;
        };
    };
    class SMG_03_TR_BASE: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 0;
            showToPlayer = 1;
            minRange = 30;
            minRangeProbab = 0.25;
            midRange = 300;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
        };
        class FullAuto: Mode_FullAuto {

        };
        class Burst: Mode_Burst {

        };
    };
    class SMG_03C_BASE: SMG_03_TR_BASE {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 0;
            showToPlayer = 1;
            minRange = 30;
            minRangeProbab = 0.25;
            midRange = 300;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.08;
            aiRateOfFireDistance = 0;
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 30;
            midRangeProbab = 0.58;
            maxRange = 80;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
        };
    };
    class DMR_07_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 450;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
        class FullAuto: Mode_FullAuto {

        };
    };
    class LMG_03_base_F: Rifle_Long_Base_F {
        modes[] = {"FullAutoFast","FullAutoSlow","close","short","medium","far_optic1","far_optic2"};
        class FullAutoSlow: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.7;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAutoFast: FullAutoSlow {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.7;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: FullAutoFast {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: FullAutoSlow {
            Burst = 7;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: medium {

        };
        class far_optic2: far_optic1 {

        };
    };
    class hgun_Pistol_01_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 60;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class arifle_AK12_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Burst","Single","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst {
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class arifle_AKM_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class arifle_AKS_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 25;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 200;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 75;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class arifle_ARX_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
    };
    class arifle_CTAR_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 175;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 120;
        };
    };
    class arifle_CTARS_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single","Single_medium_optics1","Single_far_optics2","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 150;
        };
    };
    class arifle_SPAR_01_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_medium_optics2","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class arifle_SPAR_02_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single","Single_medium_optics1","Single_medium_optics2","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class arifle_SPAR_03_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_Close_optics1","Single_medium_optics1","Single_far_optics1","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class SMG_05_base_F: Rifle_Short_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 80;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 12;
            midRangeProbab = 0.7;
            maxRange = 25;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 25;
            showToPlayer = 1;
        };
    };

    class sgun_HunterShotgun_01_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","Single_Close","Single_far"};
        class Single: Mode_SemiAuto {
            minRange = 1;
            minRangeProbab = 0.1;
            midRange = 10;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.15;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 20;
            showToPlayer = 1;
        };
        class Single_Close: Single {
            showToPlayer = 0;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 170;
            midRangeProbab = 0.8;
            maxRange = 250;
            maxRangeProbab = 0.15;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            Burst = 1;
        };
        class Single_far: Single_Close {
            minRange = 220;
            minRangeProbab = 0.1;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.15;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
            Burst = 1;
        };
    };
    class sgun_HunterShotgun_01_sawedoff_base_F: sgun_HunterShotgun_01_base_F {
        modes[] = {"Single","Single_Close","Single_far"};
        class Single: Single {
            minRange = 1;
            minRangeProbab = 0.1;
            midRange = 10;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.15;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 20;
            showToPlayer = 1;
        };
        class Single_Close: Single {
            showToPlayer = 0;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 140;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.15;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            Burst = 1;
        };
        class Single_far: Single_Close {
            minRange = 180;
            minRangeProbab = 0.1;
            midRange = 230;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
            Burst = 1;
        };
    };
    class arifle_MSBS65_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_medium_optics2","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 1;
            aiRateOfFireDistance = 500;
        };
    };
    class DMR_06_hunter_base_F: DMR_06_base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Single {
            midRange = 350;
            maxRange = 500;
            maxRangeProbab = 0.05;
            minRange = 120;
            minRangeProbab = 0.7;
            midRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class hgun_esd_01_base_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 1;
            minRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            maxRange = 3;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class arifle_AK12U_base_F: arifle_AK12_base_F {
        modes[] = {"FullAuto","Burst","Single","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Burst: Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst {
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class arifle_RPK12_base_F: arifle_AK12_base_F {
        modes[] = {"FullAuto","Burst","Single","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Burst: Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst {
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 175;
            midRangeProbab = 0.75;
            maxRange = 300;
            maxRangeProbab = 0.25;
            aiRateOfFire = 2;
            Burst = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class arifle_MSBS65_Mark_base_F: arifle_MSBS65_base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_medium_optics2","FullAuto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 1;
            aiRateOfFireDistance = 500;
        };
    };
    class ACE_VMM3: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_ACR_BASE_556: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
    };
    class CUP_arifle_ACR_Short_BASE_556: CUP_arifle_ACR_BASE_556 {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_ACR_DMR_BASE_556: CUP_arifle_ACR_BASE_556 {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 450;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_far_optics2: Single_far_optics2 {

        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
    };
    class CUP_arifle_ACR_BASE_68: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
    };
    class CUP_arifle_ACR_Short_BASE_68: CUP_arifle_ACR_BASE_68 {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_ACR_DMR_BASE_68: CUP_arifle_ACR_BASE_68 {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 450;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_far_optics2: Single_far_optics2 {

        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
    };
    class CUP_CZ_BREN2_Base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class CUP_CZ_BREN2_762_Base: CUP_CZ_BREN2_Base {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class CUP_hgun_Browning_HP: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 25;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_CZ750_Base: Rifle_Long_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_hgun_CZ75: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 60;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_Deagle: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_hgun_Duty: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_smg_EVO: Rifle_Short_Base_F {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 250;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
    };
    class CUP_Famas_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_G3_Base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_Close_optics1","Single_medium_optics1","Single_far_optics1","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 600;
            maxRangeProbab = 0.05;
            aiRateOfFireDistance = 600;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 30;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics1: Single {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            Burst = 1;
        };
    };
    class CUP_arifle_GALIL_BASE: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics1","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_srifle_LeeEnfield: Rifle_Long_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_Mac10_Base: Rifle_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_Mac10_Base: Pistol_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
    };
    class CUP_lmg_MG3: Rifle_Long_Base_F {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.58;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 13;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 12;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 400;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far: close {
            Burst = 16;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 600;
            midRangeProbab = 0.4;
            maxRange = 900;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class CUP_smg_MP5SD6: Rifle_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.25;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.001;
            minRange = 0;
            minRangeProbab = 0.2;
            midRange = 7;
            midRangeProbab = 0.7;
            maxRange = 15;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {

        };
    };
    class CUP_smg_MP5A5: CUP_smg_MP5SD6 {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.25;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.2;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {

        };
    };
    class CUP_smg_P90_BASE: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 50;
        };
    };
    class CUP_smg_p90_olive: CUP_smg_P90_BASE {
        modes[] = {"Single","FullAuto","Single_medium_optics1","Single_far_optics2","FullAuto_medium"};
    };
    class CUP_smg_PS90_olive: CUP_smg_p90_olive {
        modes[] = {"Single","Single_medium_optics1","Single_far_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 225;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.2;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_TT: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 25;
            showToPlayer = 1;
        };
    };
    class CUP_UZI_Base: Rifle_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_UZI_Base: Pistol_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
    };
    class CUP_sgun_SPAS12: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 60;
            midRangeProbab = 0.2;
            maxRange = 100;
            maxRangeProbab = 0.03;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_AUG_Base: Rifle_Base_F {
        modes[] = {"FullAuto","Single","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
    };
    class CUP_srifle_SVD: Rifle_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_hgun_TEC9: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_hgun_TEC9_FA: CUP_hgun_TEC9 {
        modes[] = {"Full"};
        class Full: Mode_FullAuto {
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 500;
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_lmg_UK59: Rifle_Long_Base_F {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.58;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 6;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 4;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 400;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far: close {
            Burst = 3;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 600;
            midRangeProbab = 0.4;
            maxRange = 900;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class CUP_Vhmg_DSHKM_veh: MGun {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: MGun {
            showToPlayer = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 1;
            minRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            maxRange = 3;
            maxRangeProbab = 0.01;
        };
        class close: Manual {
            showToPlayer = 0;
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 100;
            maxRangeProbab = 0.04;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 4;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 500;
            midRangeProbab = 0.58;
            maxRange = 800;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far: close {
            Burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 600;
            minRangeProbab = 0.05;
            midRange = 800;
            midRangeProbab = 0.4;
            maxRange = 1200;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class CUP_Vhmg_NSVT_veh: CUP_Vhmg_DSHKM_veh {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: Manual {
            showToPlayer = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 1;
            minRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            maxRange = 3;
            maxRangeProbab = 0.01;
        };
        class close: close {
            showToPlayer = 0;
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 100;
            maxRangeProbab = 0.04;
        };
        class short: short {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: medium {
            Burst = 4;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 500;
            midRangeProbab = 0.58;
            maxRange = 800;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far: far {
            Burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 600;
            minRangeProbab = 0.05;
            midRange = 800;
            midRangeProbab = 0.4;
            maxRange = 1200;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class LMG_RCWS: MGun {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: MGun {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 10;
            minRange = 0;
            minRangeProbab = 0.01;
            midRange = 1;
            midRangeProbab = 0.01;
            maxRange = 2;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class close: Manual {
            showToPlayer = 0;
            Burst = 8;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.2;
        };
        class short: close {
            showToPlayer = 0;
            Burst = 6;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
        };
        class medium: close {
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            minRange = 150;
            minRangeProbab = 0.7;
            midRange = 600;
            midRangeProbab = 0.65;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class far: close {
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 600;
            minRangeProbab = 0.65;
            midRange = 800;
            midRangeProbab = 0.4;
            maxRange = 1200;
            maxRangeProbab = 0.1;
        };
    };
    class HMG_127: LMG_RCWS {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: MGun {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 10;
            minRange = 0;
            minRangeProbab = 0.01;
            midRange = 1;
            midRangeProbab = 0.01;
            maxRange = 2;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class close: Manual {
            showToPlayer = 0;
            Burst = 8;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 200;
            maxRangeProbab = 0.2;
        };
        class short: close {
            showToPlayer = 0;
            Burst = 6;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 100;
            minRangeProbab = 0.7;
            midRange = 400;
            midRangeProbab = 0.75;
            maxRange = 800;
            maxRangeProbab = 0.2;
        };
        class medium: close {
            showToPlayer = 0;
            Burst = 4;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 400;
            minRangeProbab = 0.75;
            midRange = 800;
            midRangeProbab = 0.7;
            maxRange = 1500;
            maxRangeProbab = 0.1;
        };
        class far: close {
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 800;
            minRange = 800;
            minRangeProbab = 0.6;
            midRange = 1500;
            midRangeProbab = 0.25;
            maxRange = 2000;
            maxRangeProbab = 0.05;
        };
    };
    class HMG_01: HMG_127 {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: Manual {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 10;
            minRange = 0;
            minRangeProbab = 0.01;
            midRange = 1;
            midRangeProbab = 0.01;
            maxRange = 2;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class close: Manual {
            showToPlayer = 0;
            Burst = 8;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 200;
            maxRangeProbab = 0.2;
        };
        class short: close {
            showToPlayer = 0;
            Burst = 6;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 100;
            minRangeProbab = 0.7;
            midRange = 400;
            midRangeProbab = 0.75;
            maxRange = 800;
            maxRangeProbab = 0.2;
        };
        class medium: close {
            showToPlayer = 0;
            Burst = 4;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 400;
            minRangeProbab = 0.75;
            midRange = 800;
            midRangeProbab = 0.7;
            maxRange = 1500;
            maxRangeProbab = 0.1;
        };
        class far: close {
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 800;
            minRange = 800;
            minRangeProbab = 0.6;
            midRange = 1500;
            midRangeProbab = 0.25;
            maxRange = 2000;
            maxRangeProbab = 0.05;
        };
    };
    class HMG_M2: HMG_01 {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: Manual {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 10;
            minRange = 0;
            minRangeProbab = 0.01;
            midRange = 1;
            midRangeProbab = 0.01;
            maxRange = 2;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class close: Manual {
            showToPlayer = 0;
            Burst = 6;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 200;
            maxRangeProbab = 0.2;
        };
        class short: close {
            showToPlayer = 0;
            Burst = 6;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 100;
            minRangeProbab = 0.7;
            midRange = 300;
            midRangeProbab = 0.75;
            maxRange = 600;
            maxRangeProbab = 0.2;
        };
        class medium: close {
            showToPlayer = 0;
            Burst = 4;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 300;
            minRangeProbab = 0.75;
            midRange = 600;
            midRangeProbab = 0.7;
            maxRange = 800;
            maxRangeProbab = 0.2;
        };
        class far: close {
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 600;
            minRangeProbab = 0.65;
            midRange = 1000;
            midRangeProbab = 0.25;
            maxRange = 1500;
            maxRangeProbab = 0.05;
        };
    };
    class CUP_Vhmg_M2_veh: HMG_M2 {
        aiDispersionCoefX = 3.5;
        aiDispersionCoefY = 5;
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: MGun {
            showToPlayer = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 1;
            minRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            maxRange = 3;
            maxRangeProbab = 0.01;
        };
        class close: Manual {
            showToPlayer = 0;
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 100;
            maxRangeProbab = 0.04;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 4;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 500;
            midRangeProbab = 0.58;
            maxRange = 800;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far: close {
            Burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 600;
            minRangeProbab = 0.05;
            midRange = 800;
            midRangeProbab = 0.4;
            maxRange = 1200;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class CUP_Vhmg_M3P_veh: CUP_Vhmg_M2_veh {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: MGun {
            showToPlayer = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 1;
            minRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            maxRange = 3;
            maxRangeProbab = 0.01;
        };
        class close: Manual {
            showToPlayer = 0;
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 100;
            maxRangeProbab = 0.04;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 4;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 500;
            midRangeProbab = 0.58;
            maxRange = 800;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far: close {
            Burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 600;
            minRangeProbab = 0.05;
            midRange = 800;
            midRangeProbab = 0.4;
            maxRange = 1200;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class CUP_Vlmg_M240_veh: MGun {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 10;
            minRange = 0;
            minRangeProbab = 0.01;
            midRange = 1;
            midRangeProbab = 0.01;
            maxRange = 2;
            maxRangeProbab = 0.01;
        };
        class close: Manual {
            showToPlayer = 0;
            Burst = 8;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.2;
        };
        class short: close {
            showToPlayer = 0;
            Burst = 6;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
        };
        class medium: close {
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            minRange = 150;
            minRangeProbab = 0.7;
            midRange = 600;
            midRangeProbab = 0.65;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class far: close {
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 600;
            minRangeProbab = 0.65;
            midRange = 800;
            midRangeProbab = 0.4;
            maxRange = 1200;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_Vlmg_M240_nest: CUP_Vlmg_M240_veh {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: Manual {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 10;
            minRange = 0;
            minRangeProbab = 0.01;
            midRange = 1;
            midRangeProbab = 0.01;
            maxRange = 2;
            maxRangeProbab = 0.01;
        };
        class close: close {
            showToPlayer = 0;
            Burst = 8;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.2;
        };
        class short: short {
            showToPlayer = 0;
            Burst = 6;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
        };
        class medium: medium {
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            minRange = 150;
            minRangeProbab = 0.7;
            midRange = 600;
            midRangeProbab = 0.65;
            maxRange = 800;
            maxRangeProbab = 0.1;
        };
        class far: far {
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 600;
            minRangeProbab = 0.65;
            midRange = 800;
            midRangeProbab = 0.4;
            maxRange = 1200;
            maxRangeProbab = 0.1;
        };
    };
    class CUP_Vlmg_MG3_veh_noeject: CUP_Vlmg_M240_veh {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: Manual {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 10;
            minRange = 0;
            minRangeProbab = 0.01;
            midRange = 1;
            midRangeProbab = 0.01;
            maxRange = 2;
            maxRangeProbab = 0.01;
        };
    };
    class CUP_Vhmg_KORD_veh: MGun {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: MGun {
            showToPlayer = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 1;
            minRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            maxRange = 3;
            maxRangeProbab = 0.01;
        };
        class close: Manual {
            showToPlayer = 0;
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 100;
            maxRangeProbab = 0.04;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 4;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 500;
            midRangeProbab = 0.58;
            maxRange = 800;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far: close {
            Burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 600;
            minRangeProbab = 0.05;
            midRange = 800;
            midRangeProbab = 0.4;
            maxRange = 1200;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class CUP_srifle_VSSVintorez: Rifle_Base_F {
        modes[] = {"Single","Full"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 450;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Full: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_arifle_SR3M_Vikhr: Rifle_Base_F {
        modes[] = {"Single","Full"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.1;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Full: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_sgun_AA12: Rifle_Base_F {
        modes[] = {"FullAuto","Single_Close","Single_far"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 20;
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 10;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {

        };
        class Single_Close: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 170;
            midRangeProbab = 0.8;
            maxRange = 250;
            maxRangeProbab = 0.15;
            Burst = 1;
        };
        class Single_far: Single_Close {
            aiRateOfFire = 4;
            aiRateOfFireDistance = 300;
            minRange = 220;
            minRangeProbab = 0.1;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.15;
            showToPlayer = 0;
            Burst = 1;
        };
    };
    class CUP_arifle_AK_Base: Rifle_Base_F {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_AKS_Base: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium"};
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_AK107_Base: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Burst","Single","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Burst: Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst {
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AKM: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_AKS74U: CUP_arifle_AKS_Base {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 25;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 200;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 25;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 75;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_AK47: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_AKS: CUP_arifle_AKM {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_AK74: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AK74_GL: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AKS74: CUP_arifle_AKS_Base {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AKS74_GL: CUP_arifle_AK74_GL {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AK74M: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AK74M_GL: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AK107: CUP_arifle_AK107_Base {
        modes[] = {"FullAuto","Burst","Single","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst {
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AK107_GL: CUP_arifle_AK107_Base {
        modes[] = {"FullAuto","Burst","Single","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 50;
            minRangeProbab = 0.3;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 600;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst {
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AK102: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst {
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AK104: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst {
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AK105: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst {
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_RPK74: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Manual","close","short","medium","far_optic1","far_optic2"};
        class FullAuto: Mode_FullAuto {
            showToPlayer = 1;
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            showToPlayer = 1;
            aiRateOfFireDistance = 650;
            minRange = 400;
            minRangeProbab = 0;
            midRange = 600;
            midRangeProbab = 0;
            maxRange = 800;
            maxRangeProbab = 0;
            aiRateOfFire = 2;
        };
        class Manual: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.58;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
            Burst = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 1.5;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 12;
            aiRateOfFire = 2.5;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 300;
            midRangeProbab = 0.58;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far_optic1: medium {

        };
        class far_optic2: far_optic1 {

        };
    };
    class CUP_arifle_TYPE_56_2: CUP_arifle_AKM {
        modes[] = {"FullAuto","Single","Burst","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_srifle_AS50: Rifle_Long_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 450;
            maxRangeProbab = 0.3;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

        };
    };
    class CUP_srifle_AWM_Base: Rifle_Long_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_smg_bizon: Rifle_Base_F {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.2;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.25;
            midRange = 40;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 1;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.7;
            maxRange = 60;
            maxRangeProbab = 0.05;
            showToPlayer = 0;
            Burst = 3;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_smg_vityaz: CUP_smg_bizon {
        modes[] = {"FullAuto","Single"};
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.2;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.25;
            midRange = 40;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_hgun_Colt1911: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_hgun_Compact: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_CZ805_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class CUP_hgun_FlareGun: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            showToPlayer = 1;
            minRange = 30;
            minRangeProbab = 0.25;
            midRange = 300;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_FNFAL: Rifle_Base_F {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
        class Burst: Mode_Burst {

        };
    };
    class CUP_arifle_FNFAL5060: CUP_arifle_FNFAL {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
    };
    class CUP_arifle_FNFAL5061: CUP_arifle_FNFAL {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
    };
    class CUP_arifle_FNFAL5062: CUP_arifle_FNFAL {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
    };
    class CUP_arifle_FNFAL_OSW: CUP_arifle_FNFAL {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
    };
    class CUP_arifle_IMI_Romat: CUP_arifle_FNFAL {
        modes[] = {"Single","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
        class FullAuto: FullAuto {

        };
        class FullAuto_medium: FullAuto_medium {

        };
    };
    class CUP_arifle_Steyr_Stg58: CUP_arifle_FNFAL {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
    };
    class CUP_arifle_Gewehr1: CUP_arifle_FNFAL {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
    };
    class CUP_arifle_DSA_SA58: CUP_arifle_FNFAL {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
    };
    class CUP_arifle_DSA_SA58_OSW: CUP_arifle_DSA_SA58 {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
    };
    class CUP_arifle_DSA_SA58_DMR: CUP_arifle_DSA_SA58 {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
    };
    class CUP_arifle_G36_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            Burst = 3;
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
    };
    class CUP_arifle_G36_Base_CarryhandleOptics: CUP_arifle_G36_Base {
        modes[] = {"Single","Burst","FullAuto","FullAuto_medium"};
    };
    class CUP_arifle_G36E: CUP_arifle_G36_Base_CarryhandleOptics {
        modes[] = {"Single","Burst","FullAuto","FullAuto_medium"};
        class Burst: Burst {
            showToPlayer = 1;
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_G36K: CUP_arifle_G36_Base_CarryhandleOptics {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Burst {

        };
        class FullAuto_medium: FullAuto_medium {

        };
    };
    class CUP_arifle_G36C: CUP_arifle_G36_Base {
        modes[] = {"Single","Burst","FullAuto","FullAuto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            Burst = 3;
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
    };
    class CUP_arifle_MG36: CUP_arifle_G36_Base {
        modes[] = {"Single","FullAuto","close","medium","far"};
        class Single: Mode_SemiAuto {
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 500;
            midRangeProbab = 0.4;
            maxRange = 600;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.58;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: FullAuto {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far: close {
            Burst = 5;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class CUP_hgun_Glock17: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_glaunch_Base: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            showToPlayer = 1;
            minRange = 30;
            minRangeProbab = 0.25;
            midRange = 300;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_glaunch_M79: CUP_glaunch_Base {
        modes[] = {"Single"};
        class Single: Single {
            showToPlayer = 1;
            minRange = 30;
            minRangeProbab = 0.25;
            midRange = 300;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_OTS14_GROZA_Base: Rifle_Base_F {
        modes[] = {"Single","Full","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Full: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 25;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: Full {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
    };
    class CUP_arifle_OTS14_GROZA_762_base: CUP_arifle_OTS14_GROZA_Base {
        modes[] = {"Single","Full","FullAuto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Full: Full {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 25;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_HK416_145_Base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
        class Burst: Mode_Burst {

        };
    };
    class CUP_arifle_HK416_11_Base: CUP_arifle_HK416_145_Base {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto_medium {

        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_HK417_Base: CUP_arifle_HK416_145_Base {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_arifle_HK417_20: CUP_arifle_HK417_Base {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
    };
    class CUP_arifle_HK417_12: CUP_arifle_HK417_20 {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 450;
            maxRangeProbab = 0.05;
            aiRateOfFireDistance = 450;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class FullAuto_medium: FullAuto_medium {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            showToPlayer = 0;
            Burst = 3;
        };
        class Single_Close_optics1: Single_Close_optics1 {

        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_far_optics1: Single_far_optics1 {

        };
    };
    class CUP_srifle_CZ550_base: Rifle_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_srifle_CZ550: CUP_srifle_CZ550_base {
        modes[] = {"Single","Single_medium_optics1"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.05;
            midRange = 300;
            midRangeProbab = 0.8;
            maxRange = 500;
            maxRangeProbab = 0.01;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
        };
    };
    class CUP_sgun_CZ584: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 60;
            midRangeProbab = 0.2;
            maxRange = 100;
            maxRangeProbab = 0.03;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_srifle_ksvk: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 450;
            maxRangeProbab = 0.3;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

        };
    };
    class CUP_srifle_L129A1: Rifle_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 500;
            midRangeProbab = 0.7;
            maxRange = 1000;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_l85a2_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class CUP_l85a2: CUP_l85a2_base {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2"};
    };
    class CUP_arifle_L86A2: CUP_l85a2 {
        modes[] = {"Single","FullAuto","FullAuto_medium","Single_medium_optics1","Single_far_optics2"};
        class FullAuto_medium: FullAuto_medium {
            Burst = 4;
            showToPlayer = 0;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
    };
    class CUP_sgun_M1014_base: Rifle_Base_F {
        modes[] = {"Single","Single_Close","Single_far"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 20;
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 10;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
        };
        class Single_Close: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 170;
            midRangeProbab = 0.8;
            maxRange = 250;
            maxRangeProbab = 0.15;
            Burst = 1;
        };
        class Single_far: Single_Close {
            aiRateOfFire = 4;
            aiRateOfFireDistance = 300;
            minRange = 220;
            minRangeProbab = 0.1;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.15;
            showToPlayer = 0;
            Burst = 1;
        };
    };
    class CUP_srifle_M107_Base: Rifle_Long_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 450;
            maxRangeProbab = 0.3;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

        };
    };
    class CUP_srifle_M110: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.69;
            maxRange = 500;
            maxRangeProbab = 0.045;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_srifle_M14: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_srifle_M21: CUP_srifle_M14 {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_srifle_M14_DMR: Rifle_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_arifle_M16_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
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
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_M4_Base: CUP_arifle_M16_Base {
        modes[] = {"Single","FullAuto","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst_medium {
            showToPlayer = 0;
            minRange = 1;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
        class Burst: Burst {

        };
    };
    class CUP_arifle_XM16E1: CUP_arifle_M16_Base {
        modes[] = {"Single","FullAuto","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst_medium {
            midRange = 50;
            showToPlayer = 0;
            minRange = 1;
            minRangeProbab = 0.5;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_M16A1E1: CUP_arifle_XM16E1 {
        modes[] = {"Single","Burst","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class Burst_medium: Burst_medium {
            midRange = 75;
            showToPlayer = 0;
            minRange = 1;
            minRangeProbab = 0.5;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_M16A1GL: CUP_arifle_XM16E1 {
        modes[] = {"Single","FullAuto","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
    };
    class CUP_arifle_M16A1E1GL: CUP_arifle_M16A1GL {
        modes[] = {"Single","Burst","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class Burst_medium: Burst_medium {
            midRange = 75;
            showToPlayer = 0;
            minRange = 1;
            minRangeProbab = 0.5;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_Colt727: CUP_arifle_M16_Base {
        modes[] = {"Single","FullAuto","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst_medium {
            showToPlayer = 0;
            minRange = 1;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
        class Burst: Burst {

        };
    };
    class CUP_srifle_Mk12SPR: CUP_arifle_M4_Base {
        modes[] = {"Single","Single_medium_optics1","Single_medium_optics2","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
        class FullAuto: FullAuto {

        };
        class Burst: Burst {

        };
        class Burst_medium: Burst_medium {

        };
    };
    class CUP_arifle_M4A1_BUIS_Base: CUP_arifle_M4_Base {
        modes[] = {"Single","FullAuto","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
    };
    class CUP_arifle_M4A1_BUIS_NoUnder_Base: CUP_arifle_M4_Base {}; // added in cupdate winter 2026?
    class CUP_arifle_M4A1_MOE_short_black: CUP_arifle_M4A1_BUIS_NoUnder_Base {
        modes[] = {"Single","FullAuto","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst_medium {
            showToPlayer = 0;
            minRange = 1;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
        class Burst: Burst {

        };
    };
    class CUP_arifle_M4A1_standard_short_black: CUP_arifle_M4A1_BUIS_NoUnder_Base {
        modes[] = {"Single","FullAuto","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst_medium {
            showToPlayer = 0;
            minRange = 1;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            Burst = 3;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
        class Burst: Burst {

        };
    };
    class CUP_arifle_M4_MOE_BW: CUP_arifle_M4A1_BUIS_NoUnder_Base {
        modes[] = {"Single","Single_medium_optics1","Single_medium_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 450;
            maxRangeProbab = 0.3;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_medium_optics2: Single_medium_optics2 {

        };
        class FullAuto: FullAuto {

        };
        class Burst: Burst {

        };
        class Burst_medium: Burst_medium {

        };
    };
    class CUP_hgun_M17_Coyote: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_srifle_M2010_BASE: Rifle_Base_F {
        modes[] = {"Single","Single_medium_optics1","Single_far_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 225;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class CUP_lmg_M240: Rifle_Long_Base_F {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.58;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 13;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 12;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 400;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far: close {
            Burst = 16;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 600;
            midRangeProbab = 0.4;
            maxRange = 900;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class CUP_saw_base: Rifle_Long_Base_F {
        modes[] = {"FullAuto","close","short","medium","far_optic1","far_optic2"};
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.58;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: FullAuto {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 12;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 400;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far_optic1: medium {

        };
        class far_optic2: far_optic1 {

        };
    };
    class CUP_srifle_M24_des: Rifle_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_srifle_M40A3: CUP_srifle_M24_des {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            showToPlayer = 1;
            minRange = 30;
            minRangeProbab = 0.25;
            midRange = 300;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_smg_M3A1: Rifle_Base_F {
        modes[] = {"FullAuto","FullAuto_medium"};
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.2;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto_medium: FullAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 250;
            showToPlayer = 1;
        };
    };
    class CUP_M60E4_base: Rifle_Long_Base_F {
        modes[] = {"FullAuto","close","short","medium","far_optic1","far_optic2"};
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.58;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: FullAuto {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 12;
            aiRateOfFire = 2.5;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 400;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far_optic1: medium {

        };
        class far_optic2: far_optic1 {

        };
    };
    class CUP_hgun_M9: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_hgun_Makarov: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_hgun_PMM: CUP_hgun_Makarov {
        modes[] = {"Single"};
        class Single: Single {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_hgun_MicroUzi: Pistol_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 25;
            midRangeProbab = 0.3;
            maxRange = 70;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_hgun_Mk23: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_lmg_Mk48_Base: Rifle_Long_Base_F {
        modes[] = {"Manual","close","short","medium","far","far_optic1","far_optic2"};
        class Manual: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.58;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 30;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.04;
            aiRateOfFireDistance = 50;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 12;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 400;
            midRangeProbab = 0.6;
            maxRange = 600;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            Burst = 16;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 600;
            midRangeProbab = 0.4;
            maxRange = 900;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
    };
    class CUP_srifle_Mosin_Nagant: Rifle_Long_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_smg_MP7: Rifle_Short_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_MP7: Pistol_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_PB6P9: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_hgun_Phantom: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_lmg_PKM: Rifle_Long_Base_F {
        modes[] = {"Manual","close","short","medium","far","far_optic1","far_optic2"};
        class Manual: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.58;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 6;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 4;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 400;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far: close {
            Burst = 3;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 600;
            midRangeProbab = 0.4;
            maxRange = 900;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
    };
    class CUP_srifle_Remington700: Rifle_Long_Base_F {
        modes[] = {"Single","Single_Close_optics1","Single_medium_optics1","Single_far_optics1"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 350;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
    };
    class CUP_hgun_TaurusTracker455: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 25;
            midRangeProbab = 0.6;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_srifle_RSASS_BASE: Rifle_Base_F {
        modes[] = {"Single","Single_medium_optics1","Single_far_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 225;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_far_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_Sa58_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","Single_Close_optics1","Single_medium_optics1","Single_far_optics1","FullAuto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single {

        };
        class Single_medium_optics1: Single_Close_optics1 {

        };
        class Single_far_optics1: Single_medium_optics1 {

        };
        class FullAuto_medium: FullAuto {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_Sa58_LMG_base: CUP_arifle_Sa58_base {
        modes[] = {"Single","FullAuto","Single_Close_optics1","Single_medium_optics1","Single_far_optics1","FullAuto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single_Close_optics1 {

        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_far_optics1: Single_far_optics1 {

        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_Sa58_short_base: CUP_arifle_Sa58_base {
        modes[] = {"Single","FullAuto","Single_Close_optics1","Single_medium_optics1","Single_far_optics1","FullAuto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single_Close_optics1 {

        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_far_optics1: Single_far_optics1 {

        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_Sa56_carbine_base: CUP_arifle_Sa58_base {
        modes[] = {"Single","FullAuto","Single_Close_optics1","Single_medium_optics1","Single_far_optics1","FullAuto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single_Close_optics1: Single_Close_optics1 {

        };
        class Single_medium_optics1: Single_medium_optics1 {

        };
        class Single_far_optics1: Single_far_optics1 {

        };
        class FullAuto_medium: FullAuto_medium {
            showToPlayer = 0;
            Burst = 3;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_hgun_SA61: Pistol_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 25;
            midRangeProbab = 0.3;
            maxRange = 70;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_smg_SA61: Rifle_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 30;
            midRangeProbab = 0.3;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 30;
            midRangeProbab = 0.3;
            maxRange = 50;
            maxRangeProbab = 0.02;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_sgun_Saiga12K: Rifle_Base_F {
        modes[] = {"Single","Single_Close","Single_far"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 20;
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 10;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.15;
            showToPlayer = 1;
        };
        class Single_Close: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 170;
            midRangeProbab = 0.8;
            maxRange = 250;
            maxRangeProbab = 0.15;
            Burst = 1;
        };
        class Single_far: Single_Close {
            aiRateOfFire = 4;
            aiRateOfFireDistance = 300;
            minRange = 220;
            minRangeProbab = 0.1;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.15;
            showToPlayer = 0;
            Burst = 1;
        };
    };
    class CUP_arifle_SCAR_Base: Rifle_Base_F {
        modes[] = {"SCAR_L_Single"};
        class SCAR_L_Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class SCAR_L_FullAuto: Mode_FullAuto {

        };
    };
    class CUP_arifle_Mk17_Base: CUP_arifle_SCAR_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto"};
        class SCAR_H_Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 600;
            maxRangeProbab = 0.05;
            aiRateOfFireDistance = 600;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class SCAR_H_FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 30;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_SCAR_L_Base: CUP_arifle_SCAR_Base {
        modes[] = {"SCAR_L_Single"};
    };
    class CUP_arifle_Mk16_STD: CUP_arifle_SCAR_L_Base {
        modes[] = {"SCAR_L_Single","SCAR_L_FullAuto"};
        class SCAR_L_Single: SCAR_L_Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.9;
            maxRange = 600;
            maxRangeProbab = 0.1;
            aiRateOfFireDistance = 600;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class SCAR_L_FullAuto: SCAR_L_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 70;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_Mk16_SV: CUP_arifle_SCAR_L_Base {
        modes[] = {"SCAR_L_Single","SCAR_L_FullAuto"};
        class SCAR_L_Single: SCAR_L_Single {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 400;
            midRangeProbab = 0.7;
            maxRange = 800;
            maxRangeProbab = 0.05;
            aiRateOfFireDistance = 800;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class SCAR_L_FullAuto: SCAR_L_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 70;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_Mk16_CQC: CUP_arifle_SCAR_L_Base {
        modes[] = {"SCAR_L_Single","SCAR_L_FullAuto"};
        class SCAR_L_Single: SCAR_L_Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class SCAR_L_FullAuto: SCAR_L_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 70;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_Mk17_CQC: CUP_arifle_Mk17_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto"};
        class SCAR_H_Single: SCAR_H_Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class SCAR_H_FullAuto: SCAR_H_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 30;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_Mk17_STD: CUP_arifle_Mk17_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto"};
    };
    class CUP_arifle_Mk17_STD_FG: CUP_arifle_Mk17_STD {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto"};
        class SCAR_H_Single: SCAR_H_Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class SCAR_H_FullAuto: SCAR_H_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 30;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_Mk20: CUP_arifle_Mk17_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto"};
        class SCAR_H_Single: SCAR_H_Single {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 400;
            midRangeProbab = 0.7;
            maxRange = 800;
            maxRangeProbab = 0.05;
            aiRateOfFireDistance = 800;
            showToPlayer = 1;
            aiRateOfFire = 2;
        };
        class SCAR_H_FullAuto: SCAR_H_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 30;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_hgun_BallisticShield_Armed: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            showToPlayer = 1;
            minRange = 30;
            minRangeProbab = 0.25;
            midRange = 300;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_smg_SA61_RIS: CUP_smg_SA61 {
        modes[] = {"Single","FullAuto"};
    };
    class CUP_smg_BallisticShield_Sa61: CUP_smg_SA61_RIS {
        modes[] = {"Single","FullAuto"};
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 30;
            midRangeProbab = 0.3;
            maxRange = 50;
            maxRangeProbab = 0.02;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_smg_vityaz_vfg: CUP_smg_vityaz {
        modes[] = {"FullAuto","Single"};
    };
    class CUP_smg_BallisticShield_PP19: CUP_smg_vityaz_vfg {
        modes[] = {"FullAuto","Single"};
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.2;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.25;
            midRange = 40;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Burst {

        };
    };
    class CUP_smg_BallisticShield_MP7: CUP_smg_MP7 {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
    };
    class CUP_SKS: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.7;
            maxRange = 1300;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_sgun_slamfire: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 60;
            midRangeProbab = 0.2;
            maxRange = 100;
            maxRangeProbab = 0.03;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class CUP_arifle_XM8_Base: Rifle_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 600;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 30;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {

        };
    };
    class CUP_arifle_XM8_Railed_Base: Rifle_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 600;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 30;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {

        };
    };
    class CUP_arifle_xm8_sharpshooter: CUP_arifle_XM8_Base {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 70;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Burst {

        };
    };
    class CUP_arifle_xm8_SAW: CUP_arifle_xm8_sharpshooter {
        modes[] = {"Single","FullAuto","Close","Short","Medium","Far"};
        class Manual: FullAuto {

        };
        class Close: Manual {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.58;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class Short: Close {
            Burst = 6;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 100;
            midRangeProbab = 0.58;
            maxRange = 200;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class Medium: Close {
            Burst = 8;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 400;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 300;
            midRangeProbab = 0.58;
            maxRange = 400;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class Far: Close {
            Burst = 7;
            aiRateOfFire = 7;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 500;
            midRangeProbab = 0.4;
            maxRange = 600;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class CUP_arifle_XM8_Compact: CUP_arifle_XM8_Base {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.1;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.1;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 60;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Burst {

        };
    };
    class CUP_arifle_M16A1: CUP_arifle_XM16E1 {
        modes[] = {"Single","FullAuto","Burst_medium","Single_medium_optics1","Single_medium_optics2"};
    };
    class cwr3_arifle_m16a1_lsw: CUP_arifle_M16A1 {
        modes[] = {"Single","Manual","close","short","medium","far_optic1","far_optic2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.01;
            midRange = 200;
            midRangeProbab = 0.01;
            maxRange = 400;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Manual: FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.7;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 10;
            aiRateOfFire = 0.4;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 5;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
    };
    class cwr3_arifle_m16a1e1_lsw: CUP_arifle_M16A1E1 {
        modes[] = {"Single","Manual","close","short","medium","far_optic1","far_optic2"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.01;
            midRange = 200;
            midRangeProbab = 0.01;
            maxRange = 400;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Manual: FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.7;
            maxRange = 10;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: Manual {
            Burst = 10;
            aiRateOfFire = 0.4;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 5;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
    };
    class cwr3_lmg_bren: CUP_arifle_FNFAL5060 {
        modes[] = {"FullAuto","Single","close","short","medium","far_optic1","far_optic2"};
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.01;
            midRange = 200;
            midRangeProbab = 0.01;
            maxRange = 400;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: FullAuto {
            Burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 30;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class short: close {
            Burst = 8;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            Burst = 5;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 400;
            midRangeProbab = 0.6;
            maxRange = 600;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
    };
    class cwr3_glaunch_mm1: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            showToPlayer = 1;
            minRange = 30;
            minRangeProbab = 0.25;
            midRange = 300;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class cwr3_vhmg_m2_veh: HMG_M2 {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: MGun {
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            maxRange = 3;
            maxRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            minRange = 1;
            minRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class close: Manual {
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            Burst = 10;
            maxRange = 100;
            maxRangeProbab = 0.04;
            midRange = 20;
            midRangeProbab = 0.58;
            minRange = 0;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class short: close {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            Burst = 8;
            maxRange = 300;
            maxRangeProbab = 0.04;
            midRange = 150;
            midRangeProbab = 0.58;
            minRange = 50;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class medium: close {
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            Burst = 4;
            maxRange = 800;
            maxRangeProbab = 0.04;
            midRange = 500;
            midRangeProbab = 0.58;
            minRange = 200;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class far: close {
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            Burst = 5;
            maxRange = 1200;
            maxRangeProbab = 0.01;
            midRange = 800;
            midRangeProbab = 0.4;
            minRange = 600;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
    };
    class cwr3_vhmg_m2_twin_veh: cwr3_vhmg_m2_veh {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: Manual {
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            maxRange = 3;
            maxRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            minRange = 1;
            minRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class close: close {
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            Burst = 10;
            maxRange = 100;
            maxRangeProbab = 0.04;
            midRange = 20;
            midRangeProbab = 0.58;
            minRange = 0;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class short: short {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            Burst = 8;
            maxRange = 300;
            maxRangeProbab = 0.04;
            midRange = 150;
            midRangeProbab = 0.58;
            minRange = 50;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class medium: medium {
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            Burst = 4;
            maxRange = 800;
            maxRangeProbab = 0.04;
            midRange = 500;
            midRangeProbab = 0.58;
            minRange = 200;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class far: far {
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            Burst = 5;
            maxRange = 1200;
            maxRangeProbab = 0.01;
            midRange = 800;
            midRangeProbab = 0.4;
            minRange = 600;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
    };
    class cwr3_vhmg_nsvt_veh: MGun {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: MGun {
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            maxRange = 3;
            maxRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            minRange = 1;
            minRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class close: Manual {
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            Burst = 10;
            maxRange = 100;
            maxRangeProbab = 0.04;
            midRange = 20;
            midRangeProbab = 0.58;
            minRange = 0;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class short: close {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            Burst = 8;
            maxRange = 300;
            maxRangeProbab = 0.04;
            midRange = 150;
            midRangeProbab = 0.58;
            minRange = 50;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class medium: close {
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            Burst = 4;
            maxRange = 800;
            maxRangeProbab = 0.04;
            midRange = 500;
            midRangeProbab = 0.58;
            minRange = 200;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class far: close {
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            Burst = 5;
            maxRange = 1200;
            maxRangeProbab = 0.01;
            midRange = 800;
            midRangeProbab = 0.4;
            minRange = 600;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
    };
    class cwr3_vhmg_nsv_veh: MGun {
        modes[] = {"Manual","close","short","medium","far"};
        class Manual: MGun {
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            maxRange = 3;
            maxRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            minRange = 1;
            minRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class close: Manual {
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            Burst = 10;
            maxRange = 100;
            maxRangeProbab = 0.04;
            midRange = 20;
            midRangeProbab = 0.58;
            minRange = 0;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class short: close {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            Burst = 8;
            maxRange = 300;
            maxRangeProbab = 0.04;
            midRange = 150;
            midRangeProbab = 0.58;
            minRange = 50;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class medium: close {
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            Burst = 4;
            maxRange = 800;
            maxRangeProbab = 0.04;
            midRange = 500;
            midRangeProbab = 0.58;
            minRange = 200;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
        class far: close {
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            Burst = 5;
            maxRange = 1200;
            maxRangeProbab = 0.01;
            midRange = 800;
            midRangeProbab = 0.4;
            minRange = 600;
            minRangeProbab = 0.05;
            showToPlayer = 0;
        };
    };
    class CUP_arifle_AK12_Base: Rifle_Base_F {
        modes[] = {"FullAuto","Burst","Single"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst {

        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AK15_Base: CUP_arifle_AK12_Base {
        modes[] = {"FullAuto","Burst","Single"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst_medium: Burst {

        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
    class CUP_arifle_AK19_Base: Rifle_Base_F {
        modes[] = {"FullAuto","Single"};
        class FullAuto: Mode_FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_medium_optics1: Single {

        };
        class Single_medium_optics2: Single_medium_optics1 {

        };
    };
};


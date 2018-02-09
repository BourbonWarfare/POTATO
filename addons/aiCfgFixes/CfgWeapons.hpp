class Mode_FullAuto;
class Mode_Burst;
class Mode_SemiAuto;
class CfgWeapons {
    class Rifle_Long_Base_F;
    class Pistol_Base_F;
    class Rifle_Base_F;
    class Rifle_Short_Base_F;
    class DMR_01_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 80;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class EBR_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
        class FullAuto: Mode_FullAuto {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class srifle_EBR_F: EBR_base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Single {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: single_close_optics1 {

        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics1: single_far_optics1 {

        };
    };
    class GM6_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
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
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
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
        modes[] = {"manual","Single","close","short","medium","far","far_optic1","far_optic2","potato_long","ACE_Burst_far"};
        class manual: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class Single: manual {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: manual {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: medium {

        };
        class far_optic2: far_optic1 {

        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
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
            burst = "3 + round random 5";
            showToPlayer = 0;
        };
    };
    class LMG_Zafir_F: Rifle_Long_Base_F {
        modes[] = {"FullAuto","Single","close","short","medium","far","far_optic1","far_optic2","potato_long","ACE_Burst_far"};
        class FullAuto: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class Single: Mode_SemiAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            minRange = 120;
        };
        class close: FullAuto {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
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
            burst = "3 + round random 5";
            showToPlayer = 0;
        };
    };
    class hgun_ACPC2_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class hgun_P07_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class hgun_Pistol_heavy_01_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class hgun_Pistol_heavy_02_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class hgun_Rook40_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class arifle_Katiba_Base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            maxRange = 500;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 300;
            midRangeProbab = 0.5;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
        class ACE_Burst_far: fullauto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class arifle_Katiba_C_F: arifle_Katiba_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","ACE_Burst_far"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            maxRange = 500;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 0.3;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class ACE_Burst_far: ACE_Burst_far {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 300;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.2;
            maxRange = 500;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
        class fullauto_medium: fullauto_medium {

        };
        class single_medium_optics2: single_medium_optics1 {

        };
    };
    class mk20_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            maxRange = 500;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 250;
            midRangeProbab = 0.5;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            minRange = 0;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
        class ACE_Burst_far: fullauto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class arifle_Mk20C_F: mk20_base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","ACE_Burst_far"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 250;
            midRangeProbab = 0.5;
            maxRange = 350;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            minRange = 0;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class ACE_Burst_far: ACE_Burst_far {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 300;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.2;
            maxRange = 500;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
        class single_medium_optics2: single_medium_optics1 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class arifle_Mk20_GL_F: mk20_base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","ACE_Burst_far"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.3;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class ACE_Burst_far: ACE_Burst_far {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
        class single_medium_optics2: single_medium_optics1 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class arifle_MX_Base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            maxRange = 500;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 300;
            midRangeProbab = 0.5;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
        class ACE_Burst_far: fullauto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class arifle_MXC_F: arifle_MX_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","ACE_Burst_far"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            maxRange = 500;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 0.3;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class ACE_Burst_far: ACE_Burst_far {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 300;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.2;
            maxRange = 500;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
        class fullauto_medium: fullauto_medium {

        };
        class single_medium_optics2: single_medium_optics1 {

        };
    };
    class arifle_MX_SW_F: arifle_MX_Base_F {
        modes[] = {"Single","manual","close","short","medium","far_optic1","far_optic2","ACE_Burst_far"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            minRange = 120;
            showToPlayer = 1;
        };
        class close: Single {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
        class ACE_Burst_far: ACE_Burst_far {
            aiRateOfFire = 6;
            aiRateOfFireDistance = 900;
            minRange = 500;
            minRangeProbab = 0.1;
            midRange = 700;
            midRangeProbab = 0.2;
            maxRange = 900;
            maxRangeProbab = 0.2;
            burst = "3 + round random 5";
            showToPlayer = 0;
        };
        class FullAuto: FullAuto {

        };
        class manual: FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class far: close {

        };
        class potato_long: close {

        };
    };
    class arifle_MXM_F: arifle_MX_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","ACE_Burst_far"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            maxRange = 500;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 350;
            midRangeProbab = 0.5;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class ACE_Burst_far: ACE_Burst_far {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class SDAR_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            minRange = 10;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {

        };
    };
    class Tavor_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_medium_optics2","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 250;
            midRangeProbab = 0.5;
            maxRange = 350;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            minRange = 0;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_medium_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
        class ACE_Burst_far: fullauto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 300;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.2;
            maxRange = 500;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class arifle_TRG21_F: Tavor_base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_medium_optics2","ACE_Burst_far"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.7;
            midRange = 300;
            midRangeProbab = 0.5;
            maxRange = 400;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            minRange = 0;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_medium_optics2: single_medium_optics2 {

        };
        class ACE_Burst_far: ACE_Burst_far {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 300;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.2;
            maxRange = 500;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class pdw2000_base_F: Rifle_Short_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            minRange = 100;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {

        };
    };
    class hgun_PDW2000_F: pdw2000_base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class SMG_01_Base: Rifle_Short_Base_F {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            minRange = 50;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            minRange = 25;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class SMG_01_F: SMG_01_Base {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class SMG_02_base_F: Rifle_Short_Base_F {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            minRange = 50;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            minRange = 25;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class hgun_Pistol_Signal_F: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_Compact: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_CZ750_Base: Rifle_Long_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

        };
    };
    class CUP_hgun_Duty: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_CZ550_base: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_LeeEnfield: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_M14_DMR: Rifle_Base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
    };
    class CUP_srifle_M24_des: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_M40A3: CUP_srifle_M24_des {
        modes[] = {"Single"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_Phantom: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class DMR_02_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
    };
    class DMR_03_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            midRange = 200;
            maxRange = 500;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.7;
            midRangeProbab = 0.3;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
        class ACE_Burst_far: fullauto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class DMR_04_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
    };
    class DMR_05_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            midRange = 200;
            maxRange = 500;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.7;
            midRangeProbab = 0.3;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
        class ACE_Burst_far: fullauto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class DMR_06_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1","ACE_Burst_far"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            midRange = 200;
            maxRange = 500;
            maxRangeProbab = 0.1;
            minRange = 120;
            minRangeProbab = 0.7;
            midRangeProbab = 0.3;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
        class ACE_Burst_far: fullauto_medium {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 500;
            midRangeProbab = 0.2;
            maxRange = 600;
            maxRangeProbab = 0.2;
            burst = "2 + round random 3";
            showToPlayer = 0;
        };
    };
    class MMG_01_base_F: Rifle_Long_Base_F {
        modes[] = {"manual","burst","close","short","medium","far","potato_long","far_optic1","far_optic2","ACE_Burst_far"};
        class manual: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: manual {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: Burst {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
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
            burst = "3 + round random 5";
            showToPlayer = 0;
        };
    };
    class MMG_02_base_F: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far","potato_long","far_optic1","far_optic2","ACE_Burst_far"};
        class manual: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: manual {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
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
            burst = "3 + round random 5";
            showToPlayer = 0;
        };
    };
    class CUP_sgun_AA12: Rifle_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 60;
            midRangeProbab = 0.2;
            maxRange = 120;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 40;
            midRangeProbab = 0.5;
            maxRange = 60;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
    };
    class RHS_SAFE_BASE: Rifle_Base_F {
        modes[] = {"Safe"};
        class Safe: Mode_SemiAuto {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0;
            midRange = 0.001;
            midRangeProbab = 0;
            maxRange = 0.001;
            maxRangeProbab = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            burst = 1;
        };
    };
    class rhs_weap_ak74m_Base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class Single_AI: Single {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class rhs_weap_ak74m: rhs_weap_ak74m_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_asval: rhs_weap_ak74m {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_vss: rhs_weap_asval {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_akm: rhs_weap_ak74m {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class Single_AI: Single {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_ak103_base: rhs_weap_akm {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_ak103_1: rhs_weap_ak103_base {
        modes[] = {"Single","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class rhs_weap_ak103_2: rhs_weap_ak103_base {
        modes[] = {"Single","Burst","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class rhs_weap_ak74: rhs_weap_ak74m {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_aks74: rhs_weap_ak74 {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_aks74u: rhs_weap_aks74 {
        modes[] = {"FullAuto","Single","single_medium_optics1","single_far_optics2"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_svd: rhs_weap_ak74m {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
    };
    class rhs_weap_svdp: rhs_weap_svd {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: single_close_optics1 {

        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics1: single_far_optics1 {

        };
    };
    class rhs_weap_orsis_Base_F: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

        };
    };
    class rhs_weap_pp2000: hgun_PDW2000_F {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.4;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.6;
            midRange = 10;
            midRangeProbab = 0.4;
            maxRange = 20;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
    };
    class rhs_weap_pya: hgun_Rook40_F {
        modes[] = {"Single"};
        class Single: Single {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class rhs_pkp_base: Rifle_Long_Base_F {
        modes[] = {"FullAuto","Single","close","short","medium","far","potato_long","far_optic1","far_optic2"};
        class FullAuto: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class Single: Mode_SemiAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class close: FullAuto {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
    };
    class rhs_weap_pkp: rhs_pkp_base {
        modes[] = {"FullAuto","Single","close","short","medium","far","potato_long","far_optic1","far_optic2"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            burst = 1;
            showToPlayer = 0;
        };
        class close: close {
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class short: short {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: medium {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: far {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: potato_long {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: far_optic1 {

        };
        class far_optic2: far_optic2 {

        };
    };
    class rhs_weap_pkm: rhs_weap_pkp {
        modes[] = {"manual","close","short","medium","far","potato_long","far_optic1","far_optic2"};
        class manual: FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: close {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: short {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: medium {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: far {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: potato_long {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: far_optic1 {

        };
        class far_optic2: far_optic2 {

        };
    };
    class rhs_weap_rpk74m: rhs_weap_pkp {
        modes[] = {"single","manual","close","short","medium","far","potato_long","far_optic1","far_optic2"};
        class single: Single {
            showToPlayer = 1;
            minRange = 0;
            midRange = 0;
            maxRange = 0;
            minRangeProbab = 0;
            midRangeProbab = 0;
            maxRangeProbab = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
        };
        class manual: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: close {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: short {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: medium {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: far {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: potato_long {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: far_optic1 {

        };
        class far_optic2: far_optic2 {

        };
    };
    class rhs_weap_kar98k_Base_F: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

        };
    };
    class rhs_weap_m38_Base_F: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

        };
    };
    class rhs_weap_m38: rhs_weap_m38_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: far_optic1 {

        };
        class medium_optic2: medium_optic2 {

        };
        class far_optic2: far_optic2 {

        };
    };
    class rhs_weap_m38_rail: rhs_weap_m38 {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: far_optic1 {

        };
        class medium_optic2: medium_optic2 {

        };
        class far_optic2: far_optic2 {

        };
    };
    class rhs_weap_mosin_sbr: rhs_weap_m38_rail {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: far_optic1 {

        };
        class medium_optic2: medium_optic2 {

        };
        class far_optic2: far_optic2 {

        };
    };
    class rhs_weap_XM2010_Base_F: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

        };
    };
    class rhs_weap_m70_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class rhs_weap_m92: rhs_weap_m70_base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_m76: rhs_weap_m70_base {
        modes[] = {"Single","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class rhs_weap_m21_base: rhs_weap_m70_base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_m21a_pr: rhs_weap_m21_base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_m21s: rhs_weap_m21_base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_m21s_pr: rhs_weap_m21a_pr {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_savz61: SMG_01_F {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.4;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.6;
            midRange = 10;
            midRangeProbab = 0.4;
            maxRange = 20;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
    };
    class rhs_weap_savz58_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class rhs_weap_Izh18: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class rhs_weap_stgw57_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class rhs_weap_tt33: rhs_weap_pya {
        modes[] = {"Single"};
        class Single: Single {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class RHSUSF_SAFE_BASE: Rifle_Base_F {
        modes[] = {"Safe"};
        class Safe: Mode_SemiAuto {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0;
            midRange = 0.001;
            midRangeProbab = 0;
            maxRange = 0.001;
            maxRangeProbab = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            burst = 1;
        };
    };
    class rhs_weap_M320_Base_F: Pistol_Base_F {
        modes[] = {"Single","single_medium_optics1","single_far_optics2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.04;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
    };
    class rhs_weap_m24sws: rhs_weap_XM2010_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: far_optic1 {

        };
        class medium_optic2: medium_optic2 {

        };
        class far_optic2: far_optic2 {

        };
    };
    class rhs_weap_m40a5: rhs_weap_XM2010_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: far_optic1 {

        };
        class medium_optic2: medium_optic2 {

        };
        class far_optic2: far_optic2 {

        };
    };
    class rhs_weap_m4_Base: arifle_MX_Base_F {
        modes[] = {"Single","Burst","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class Single_AI: Single {

        };
        class FullAuto: FullAuto {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class rhs_weap_m4a1: rhs_weap_m4_Base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class rhs_weap_m16a4: rhs_weap_m4_Base {
        modes[] = {"Single","Burst","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class rhs_weap_hk416d10: rhs_weap_m4a1 {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class rhs_weap_m27iar: rhs_weap_m4a1 {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class rhs_weap_M249_base: LMG_Mk200_F {
        modes[] = {"FullAuto","close","short","medium","far","potato_long","far_optic1","far_optic2"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: close {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: short {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: medium {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: far {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: potato_long {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: far_optic1 {

        };
        class far_optic2: far_optic2 {

        };
    };
    class rhs_weap_saw_base: Rifle_Base_F {
        modes[] = {"FullAuto","close","short","medium","far","potato_long","far_optic1","far_optic2"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: FullAuto {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: close {

        };
        class far_optic2: far_optic1 {

        };
    };
    class rhs_weap_lmg_minimipara: rhs_weap_saw_base {
        modes[] = {"FullAuto","close","short","medium","far","potato_long","far_optic1","far_optic2"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: close {
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class short: short {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: medium {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: far {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: potato_long {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: far_optic1 {

        };
        class far_optic2: far_optic2 {

        };
    };
    class rhs_weap_m240_base: rhs_weap_M249_base {
        modes[] = {"manual","close","short","medium","far","potato_long"};
        class manual: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: close {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: short {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: medium {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: far {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: potato_long {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class rhs_weap_m14ebrri: srifle_EBR_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: single_close_optics1 {

        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics1: single_far_optics1 {

        };
    };
    class rhs_weap_sr25: rhs_weap_m14ebrri {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: single_close_optics1 {

        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics1: single_far_optics1 {

        };
    };
    class rhs_weap_M107_Base_F: GM6_base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: far_optic1 {

        };
        class medium_optic2: medium_optic2 {

        };
        class far_optic2: far_optic2 {

        };
    };
    class rhs_weap_M590_5RD: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 60;
            midRangeProbab = 0.2;
            maxRange = 120;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
    };
    class rhs_weap_M590_8RD: rhs_weap_M590_5RD {
        modes[] = {"Single"};
        class Single: Single {
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 60;
            midRangeProbab = 0.2;
            maxRange = 120;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
    };
    class rhs_weap_m32_Base_F: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.04;
            aiRateOfFire = 2;
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
    class rhsusf_weap_MP7A1_base_f: SMG_02_base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class rhsusf_weap_m1911a1: hgun_ACPC2_F {
        modes[] = {"Single"};
        class Single: Single {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class DMR_07_base_F: Rifle_Long_Base_F {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
    };
    class LMG_03_base_F: Rifle_Long_Base_F {
        modes[] = {"FullAutoFast","FullAutoSlow","close","short","medium","far","potato_long","far_optic1","far_optic2"};
        class FullAutoSlow: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class FullAutoFast: FullAutoSlow {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: FullAutoFast {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: FullAutoSlow {
            showToPlayer = 0;
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
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
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class arifle_AK12_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Burst","Single","single_medium_optics1","single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_medium_optics2: single_medium_optics1 {

        };
        class Burst_medium: Burst {

        };
    };
    class arifle_AKM_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto_medium: FullAuto {

        };
    };
    class arifle_AKS_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto_medium: FullAuto {

        };
    };
    class arifle_ARX_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class arifle_CTAR_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class arifle_CTARS_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single","single_medium_optics1","single_far_optics2"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class arifle_SPAR_01_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_medium_optics2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_medium_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class arifle_SPAR_02_base_F: Rifle_Base_F {
        modes[] = {"FullAuto","Single","single_medium_optics1","single_medium_optics2"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_medium_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class arifle_SPAR_03_base_F: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class SMG_05_base_F: Rifle_Short_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_Glock17: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class CUP_glaunch_Base: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 30;
            minRangeProbab = 0.25;
            midRange = 300;
            midRangeProbab = 0.58;
            maxRange = 600;
            maxRangeProbab = 0.04;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_ksvk: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

        };
    };
    class CUP_hgun_M9: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_Makarov: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_MicroUzi: Pistol_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.4;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.6;
            midRange = 10;
            midRangeProbab = 0.4;
            maxRange = 20;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
    };
    class CUP_smg_MP5SD6: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_smg_MP5A5: CUP_smg_MP5SD6 {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_PB6P9: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_TaurusTracker455: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class CUP_sgun_Saiga12K: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 60;
            midRangeProbab = 0.2;
            maxRange = 120;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
    };
    class CUP_hgun_BallisticShield_Armed: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_SVD: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_lmg_UK59: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far","potato_long"};
        class manual: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: manual {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class CUP_srifle_VSSVintorez: Rifle_Base_F {
        modes[] = {"Single","Full"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Full: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class hlc_G36_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class Burst: Mode_Burst {

        };
        class Burst2rnd: Burst {

        };
        class fullauto_medium: FullAuto {

        };
        class AI_Burst_close: FullAuto {

        };
    };
    class hlc_rifle_G36A1: hlc_G36_base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
        class AI_Burst_close: AI_Burst_close {

        };
    };
    class hlc_rifle_MG36: hlc_G36_base {
        modes[] = {"Single","FullAuto","close","medium","far","potato_long","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: FullAuto {
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 500;
            minRangeProbab = 0.05;
            midRange = 600;
            midRangeProbab = 0.1;
            maxRange = 700;
            maxRangeProbab = 0.1;
            burst = "3 + round random 5";
            showToPlayer = 0;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
        class AI_Burst_close: AI_Burst_close {

        };
    };
    class hlc_rifle_G36KA1: hlc_rifle_G36A1 {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class Burst: Burst {

        };
        class fullauto_medium: fullauto_medium {

        };
        class AI_Burst_close: AI_Burst_close {

        };
    };
    class hlc_rifle_G36C: hlc_G36_base {
        modes[] = {"Single","Burst","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class fullauto_medium: fullauto_medium {

        };
        class AI_Burst_close: AI_Burst_close {

        };
    };
    class hlc_rifle_G36KE1: hlc_rifle_G36KA1 {
        modes[] = {"Single","Burst2rnd","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst2rnd: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class hlc_rifle_G36MLIC: hlc_G36_base {
        modes[] = {"Single","Burst2rnd","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst2rnd: Burst2rnd {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.2;
            midRange = 20;
            midRangeProbab = 0.8;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class Burst: Burst {

        };
        class fullauto_medium: fullauto_medium {

        };
        class AI_Burst_close: AI_Burst_close {

        };
    };
    class hlc_rifle_G36KMLIC: hlc_rifle_G36MLIC {
        modes[] = {"Single","Burst2rnd","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst2rnd: Burst2rnd {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class Burst: Burst {

        };
        class fullauto_medium: fullauto_medium {

        };
        class AI_Burst_close: AI_Burst_close {

        };
    };
    class hlc_rifle_G36CMLIC: hlc_rifle_G36MLIC {
        modes[] = {"Single","Burst2rnd","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst2rnd: Burst2rnd {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
        class Burst: Burst {

        };
        class fullauto_medium: fullauto_medium {

        };
        class AI_Burst_close: AI_Burst_close {

        };
    };
    class hlc_g3_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics1"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics1: single_medium_optics1 {

        };
        class single_medium: Single {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class hlc_rifle_g3sg1: hlc_g3_base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics1"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics1: single_far_optics1 {

        };
        class single_medium: single_medium {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class hlc_rifle_psg1: hlc_g3_base {
        modes[] = {"Single","single_medium_optics1"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
    };
    class hlc_rifle_g3a3: hlc_rifle_g3sg1 {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics1"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics1: single_far_optics1 {

        };
        class single_medium: single_medium {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class hlc_rifle_g3ka4: hlc_rifle_g3a3 {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics1"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics1: single_far_optics1 {

        };
        class single_medium: single_medium {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class hlc_rifle_hk51: hlc_rifle_g3sg1 {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics1"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics1: single_far_optics1 {

        };
        class single_medium: single_medium {

        };
        class fullauto_medium: fullauto_medium {

        };
    };
    class hlc_rifle_hk53: hlc_g3_base {
        modes[] = {"Single","Burst","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class AI_Burst_close: FullAuto {

        };
    };
    class hlc_rifle_hk33a2: hlc_g3_base {
        modes[] = {"Single","Burst","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class AI_Burst_close: FullAuto {

        };
        class AI_far: Single {

        };
    };
    class hlc_MG42_base: Rifle_Base_F {
        modes[] = {"FullAuto","close","short","medium","far","veryfar","far_optic1","toofar_optic1","far_optic2","toofar_optic2"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: FullAuto {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class veryfar: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: medium {

        };
        class toofar_optic1: medium {

        };
        class far_optic2: far_optic1 {

        };
        class toofar_optic2: far_optic2 {

        };
        class medium_burst: close {

        };
    };
    class hlc_lmg_MG3: hlc_MG42_base {
        modes[] = {"FullAuto","close","short","medium","far","veryfar","far_optic1","toofar_optic1","far_optic2","toofar_optic2"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: close {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: short {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: medium {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: far {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class veryfar: veryfar {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: far_optic1 {

        };
        class toofar_optic1: toofar_optic1 {

        };
        class far_optic2: far_optic2 {

        };
        class toofar_optic2: toofar_optic2 {

        };
        class medium_burst: medium_burst {

        };
    };
    class hlc_MP5_base: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class hlc_smg_mp5k_PDW: hlc_MP5_base {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class hlc_smg_MP5N: hlc_MP5_base {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class hlc_smg_9mmar: hlc_smg_MP5N {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class hlc_smg_mp510: hlc_smg_MP5N {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class hlc_smg_mp5sd5: hlc_MP5_base {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class hlc_STGW_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: FullAuto {

        };
        class single_medium_optics1: Single {

        };
        class single_far_optics1: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class CUP_arifle_AK_Base: Rifle_Base_F {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            burst = 3;
        };
    };
    class CUP_arifle_AKS_Base: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            burst = 3;
            showToPlayer = 0;
        };
    };
    class CUP_arifle_AK107_Base: CUP_arifle_AK_Base {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_AK47: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            burst = 3;
        };
    };
    class CUP_arifle_AK74: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            burst = 3;
        };
    };
    class CUP_arifle_AK74M: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            burst = 3;
        };
    };
    class CUP_arifle_AK74M_GL: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            burst = 3;
        };
    };
    class CUP_arifle_AK107: CUP_arifle_AK107_Base {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_AK107_GL: CUP_arifle_AK107_Base {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_AKS74: CUP_arifle_AKS_Base {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            burst = 3;
        };
    };
    class CUP_arifle_AKS74U: CUP_arifle_AKS_Base {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            burst = 3;
        };
    };
    class CUP_arifle_AK74_GL: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            burst = 3;
        };
    };
    class CUP_arifle_AKM: CUP_arifle_AK_Base {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            burst = 3;
        };
    };
    class CUP_arifle_AKS: CUP_arifle_AKM {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            burst = 3;
        };
    };
    class CUP_arifle_RPK74: CUP_arifle_AK74 {
        modes[] = {"manual","close","short","medium","far","Single","potato_long"};
        class manual: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: manual {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class Single: Single {
            aiRateOfFireDistance = 650;
            minRange = 400;
            midRange = 600;
            maxRange = 800;
            minRangeProbab = 0;
            midRangeProbab = 0;
            maxRangeProbab = 0;
            aiRateOfFire = 1;
            showToPlayer = 1;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class FullAuto: FullAuto {

        };
    };
    class CUP_srifle_AS50: Rifle_Long_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_AWM_Base: Rifle_Long_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_smg_bizon: Rifle_Base_F {
        modes[] = {"FullAuto","Single","Burst"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            burst = "3+round random 3";
        };
    };
    class CUP_hgun_Colt1911: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_CZ805_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class CUP_smg_EVO: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 75;
            midRangeProbab = 0.5;
            maxRange = 150;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 40;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_FNFAL: Rifle_Base_F {
        modes[] = {"Fullauto","Single"};
        class Fullauto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_G36_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","Fullauto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Fullauto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_G36A: CUP_arifle_G36_Base {
        modes[] = {"Single","Burst","Fullauto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Fullauto: Fullauto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_G36K: CUP_arifle_G36A {
        modes[] = {"Single","Burst","Fullauto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Fullauto: Fullauto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_G36C: Rifle_Base_F {
        modes[] = {"Single","Burst","Fullauto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Fullauto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_MG36: CUP_arifle_G36C {
        modes[] = {"Single","Burst","Fullauto","close","medium","far","potato_long"};
        class Single: Single {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Fullauto: Fullauto {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class close: FullAuto {
            showToPlayer = 0;
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class CUP_lmg_L110A1: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far","potato_long"};
        class manual: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: manual {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class CUP_srifle_L129A1: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_l85a2_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class CUP_sgun_M1014: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 60;
            midRangeProbab = 0.2;
            maxRange = 120;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_M107_Base: Rifle_Long_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 10;
            aiRateOfFireDistance = 1500;
            minRange = 1;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1800;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_M110: Rifle_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 6;
            aiRateOfFireDistance = 1100;
            minRange = 0;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1100;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_M14: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
    };
    class CUP_arifle_M16_Base: Rifle_Base_F {
        modes[] = {"Single","Burst"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_M16A4_Base: CUP_arifle_M16_Base {
        modes[] = {"Single","Burst"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_M4_Base: CUP_arifle_M16A4_Base {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_M4A1: CUP_arifle_M4_Base {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_srifle_Mk12SPR: CUP_arifle_M4A1 {
        modes[] = {"Single"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_lmg_M240: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far","potato_long"};
        class manual: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: manual {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class CUP_saw_base: Rifle_Long_Base_F {
        modes[] = {"FullAuto","close","short","medium","far","far_optic1","far_optic2","potato_long"};
        class FullAuto: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: FullAuto {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: medium {

        };
        class far_optic2: far_optic1 {

        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class CUP_M60E4_base: Rifle_Long_Base_F {
        modes[] = {"FullAuto","close","short","medium","far","far_optic1","far_optic2","potato_long"};
        class FullAuto: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: FullAuto {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far_optic1: medium {

        };
        class far_optic2: far_optic1 {

        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class CUP_lmg_Mk48_Base: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far","potato_long"};
        class manual: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: manual {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class CUP_lmg_PKM: Rifle_Long_Base_F {
        modes[] = {"manual","close","short","medium","far","potato_long"};
        class manual: Mode_FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class close: manual {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class short: close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class CUP_lmg_Pecheneg: CUP_lmg_PKM {
        modes[] = {"manual","close","short","medium","far","potato_long"};
        class manual: manual {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: close {
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class short: short {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: medium {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: far {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: potato_long {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class CUP_arifle_Sa58_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","single_close_optics1","single_medium_optics1","single_far_optics1"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {

        };
    };
    class CUP_hgun_SA61: Pistol_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.4;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.6;
            midRange = 10;
            midRangeProbab = 0.4;
            maxRange = 20;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
    };
    class CUP_smg_SA61: Rifle_Base_F {
        modes[] = {"Single","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.5;
            midRange = 20;
            midRangeProbab = 0.3;
            maxRange = 80;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.4;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.6;
            midRange = 10;
            midRangeProbab = 0.4;
            maxRange = 20;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_SCAR_Base: Rifle_Base_F {
        modes[] = {"SCAR_L_Single"};
        class SCAR_L_Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class SCAR_L_FullAuto: Mode_FullAuto {

        };
    };
    class CUP_arifle_SCAR_L_Base: CUP_arifle_SCAR_Base {
        modes[] = {"SCAR_L_Single"};
        class SCAR_L_Single: SCAR_L_Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_Mk16_CQC: CUP_arifle_SCAR_L_Base {
        modes[] = {"SCAR_L_Single","SCAR_L_FullAuto"};
        class SCAR_L_Single: SCAR_L_Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class SCAR_L_FullAuto: SCAR_L_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_Mk16_STD: CUP_arifle_SCAR_L_Base {
        modes[] = {"SCAR_L_Single","SCAR_L_FullAuto"};
        class SCAR_L_Single: SCAR_L_Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class SCAR_L_FullAuto: SCAR_L_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_Mk16_SV: CUP_arifle_SCAR_L_Base {
        modes[] = {"SCAR_L_Single","SCAR_L_FullAuto"};
        class SCAR_L_Single: SCAR_L_Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class SCAR_L_FullAuto: SCAR_L_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_Mk17_Base: CUP_arifle_SCAR_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto"};
        class SCAR_H_Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class SCAR_H_FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_Mk17_CQC: CUP_arifle_Mk17_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto"};
        class SCAR_H_Single: SCAR_H_Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class SCAR_H_FullAuto: SCAR_H_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_Mk17_STD: CUP_arifle_Mk17_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto"};
        class SCAR_H_Single: SCAR_H_Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class SCAR_H_FullAuto: SCAR_H_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_Mk17_STD_FG: CUP_arifle_Mk17_STD {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto"};
        class SCAR_H_Single: SCAR_H_Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class SCAR_H_FullAuto: SCAR_H_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_Mk20: CUP_arifle_Mk17_Base {
        modes[] = {"SCAR_H_Single","SCAR_H_FullAuto"};
        class SCAR_H_Single: SCAR_H_Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class SCAR_H_FullAuto: SCAR_H_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_XM8_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","Fullauto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Fullauto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_XM8_Railed_Base: Rifle_Base_F {
        modes[] = {"Single","Burst","Fullauto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 550;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Fullauto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_xm8_sharpshooter: CUP_arifle_XM8_Base {
        modes[] = {"Single","Burst","Fullauto"};
        class Single: Single {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 800;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 650;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Fullauto: Fullauto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class CUP_arifle_xm8_SAW: CUP_arifle_xm8_sharpshooter {
        modes[] = {"Manual","Close","Short","Medium","Far","potato_long"};
        class Manual: FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = "30+ random 20";
            maxRangeProbab = 0.1;
        };
        class Close: Manual {
            showToPlayer = 0;
            burst = "6+round random 4";
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = "50+ random 50";
            midRangeProbab = 0.7;
            maxRange = "100+ random 50";
            maxRangeProbab = 0.1;
        };
        class Short: Close {
            burst = "4+round random 6";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 400;
            minRange = 50;
            minRangeProbab = 0.8;
            midRange = "100+ random 50";
            midRangeProbab = 0.7;
            maxRange = "300+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class Medium: Close {
            burst = "4+round random 4";
            aiRateOfFire = 2;
            aiRateOfFireDistance = 600;
            minRange = 100;
            minRangeProbab = 0.8;
            midRange = "300+ random 50";
            midRangeProbab = 0.7;
            maxRange = "400+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class Far: Close {
            burst = "2+round random 4";
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 300;
            minRangeProbab = 0.8;
            midRange = "500+ random 50";
            midRangeProbab = 0.7;
            maxRange = "600+ random 50";
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class potato_long: Close {
            burst = "8+round random 6";
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.8;
            midRange = "700+ random 50";
            midRangeProbab = 0.2;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class CUP_arifle_XM8_Compact: CUP_arifle_XM8_Base {
        modes[] = {"Single","Burst","Fullauto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 400;
            minRange = 0;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 400;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 0;
            minRangeProbab = 0.8;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 200;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Fullauto: Fullauto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 60;
            midRangeProbab = 0.7;
            maxRange = 120;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
    };
    class ACE_VMM3: Pistol_Base_F {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 0.6;
            aiRateOfFireDistance = 50;
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.05;
            showToPlayer = 1;
        };
    };
};


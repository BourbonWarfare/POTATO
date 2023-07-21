class Mode_FullAuto;
class Mode_Burst;
class Mode_SemiAuto;
class CfgWeapons {
    class Rifle_Base_F;
    class Rifle_Long_Base_F;
    class Pistol_Base_F;
    class PKT;
    class MGun;
    class CannonCore;
    class Rifle_Short_Base_F;
    class rhs_weap_pkt: PKT {
        modes[] = {"manual","close","short","medium","far"};
        class manual: MGun {
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
        class close: manual {
            showToPlayer = 0;
            burst = 12;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
        };
        class short: close {
            burst = 10;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = 7;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 500;
            midRangeProbab = 0.7;
            maxRange = 600;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = 6;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 850;
            midRangeProbab = 0.4;
            maxRange = 1100;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class rhs_weap_pktm: rhs_weap_pkt {
        modes[] = {"manual","close","short","medium","far"};
        class manual: manual {
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
    };
    class LMG_RCWS: MGun {
        modes[] = {"manual","close","short","medium","far"};
        class manual: MGun {
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
        class close: manual {
            showToPlayer = 0;
            burst = 8;
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
            burst = 6;
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
            burst = 3;
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
            burst = 3;
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
    class rhs_weap_DSHKM: LMG_RCWS {
        modes[] = {"manual","close","short","medium","far"};
        class manual: MGun {
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
        class close: manual {
            showToPlayer = 0;
            burst = 10;
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
            burst = 9;
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
            burst = 6;
            aiRateOfFire = 4;
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
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 800;
            midRangeProbab = 0.4;
            maxRange = 1100;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class rhs_weap_nsvt: rhs_weap_DSHKM {
        modes[] = {"manual","close","short","medium","far"};
        class manual: MGun {
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
        class close: manual {
            showToPlayer = 0;
            burst = 10;
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
            burst = 9;
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
            burst = 8;
            aiRateOfFire = 4;
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
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 800;
            midRangeProbab = 0.4;
            maxRange = 1100;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class rhs_weap_nsvt_effects: rhs_weap_nsvt {
        modes[] = {"manual","close","short","medium","far"};
    };
    class rhs_weap_kord: rhs_weap_nsvt_effects {
        modes[] = {"manual","close","short","medium","far"};
        class manual: manual {
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 1;
            minRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            maxRange = 3;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class close: manual {
            showToPlayer = 0;
            burst = 10;
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
            burst = 9;
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
            burst = 8;
            aiRateOfFire = 4;
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
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 800;
            midRangeProbab = 0.4;
            maxRange = 1100;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class rhs_weap_kpvt: MGun {
        modes[] = {"manual","close","short","medium","far"};
        class manual: MGun {
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
        class close: manual {
            showToPlayer = 0;
            burst = 8;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 100;
            midRangeProbab = 0.58;
            maxRange = 300;
            maxRangeProbab = 0.04;
        };
        class short: close {
            burst = 6;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 600;
            midRangeProbab = 0.58;
            maxRange = 1000;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class medium: close {
            burst = 4;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 800;
            minRangeProbab = 0.05;
            midRange = 1000;
            midRangeProbab = 0.58;
            maxRange = 1200;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class far: close {
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 1000;
            minRangeProbab = 0.05;
            midRange = 1200;
            midRangeProbab = 0.4;
            maxRange = 1500;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class rhs_weap_pkm_tigr: rhs_weap_pkt {
        modes[] = {"manual","close","short","medium","far"};
        class manual: manual {
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
        class close: manual {
            showToPlayer = 0;
            burst = 12;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
        };
        class short: close {
            burst = 10;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.05;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = 7;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 200;
            minRangeProbab = 0.05;
            midRange = 500;
            midRangeProbab = 0.7;
            maxRange = 600;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = 6;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 400;
            minRangeProbab = 0.05;
            midRange = 850;
            midRangeProbab = 0.4;
            maxRange = 1100;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class rhs_weap_azp23: CannonCore {
        modes[] = {"manual","close","short","medium","far"};
        class manual: CannonCore {
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
        class close: manual {
            showToPlayer = 0;
            burst = 10;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 1000;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 1000;
            midRangeProbab = 0.58;
            maxRange = 1600;
            maxRangeProbab = 0.3;
        };
        class short: close {
            burst = 10;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1600;
            minRange = 1000;
            minRangeProbab = 0.3;
            midRange = 1600;
            midRangeProbab = 0.58;
            maxRange = 2200;
            maxRangeProbab = 0.3;
            showToPlayer = 0;
        };
        class medium: close {
            burst = 15;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 2200;
            minRange = 1600;
            minRangeProbab = 0.3;
            midRange = 2000;
            midRangeProbab = 0.58;
            maxRange = 2800;
            maxRangeProbab = 0.3;
            showToPlayer = 0;
        };
        class far: close {
            burst = 9;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 3000;
            minRange = 1600;
            minRangeProbab = 0.3;
            midRange = 2200;
            midRangeProbab = 0.4;
            maxRange = 8500;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
    };
    class rhs_weap_2a14: rhs_weap_azp23 {
        modes[] = {"manual","close","short","medium","far"};
        class manual: manual {
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
    };
    class RHS_SAFE_BASE: Rifle_Base_F {
        modes[] = {"Safe"};
        class Safe: Mode_SemiAuto {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.001;
            midRange = 0.001;
            midRangeProbab = 0.001;
            maxRange = 0.001;
            maxRangeProbab = 0.001;
            burst = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class RHS_FOLD_BASE: Rifle_Base_F {
        modes[] = {"Safe"};
        class Safe: Mode_SemiAuto {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.001;
            midRange = 0.001;
            midRangeProbab = 0.001;
            maxRange = 0.001;
            maxRangeProbab = 0.001;
            burst = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class rhs_weap_ak74m_Base_F: Rifle_Base_F {
        modes[] = {"Single","Single_AI","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_AI: Single {
            showToPlayer = 0;
            minRange = 200;
            minRangeProbab = 0.5;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            aiRateOfFire = 1;
            burst = 1;
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
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {
            showToPlayer = 0;
            burst = 2;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 500;
        };
    };
    class rhs_weap_ak74m: rhs_weap_ak74m_Base_F {
        modes[] = {"Single","Single_AI","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium"};
    };
    class rhs_weap_ak105: rhs_weap_ak74m {
        modes[] = {"Single","Single_AI","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.04;
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
    };
    class rhs_weap_akm: rhs_weap_ak74m {
        modes[] = {"Single","Single_AI","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 200;
            maxRangeProbab = 0.3;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_AI: Single {
            showToPlayer = 0;
            minRange = 200;
            minRangeProbab = 0.5;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            aiRateOfFire = 1;
            burst = 1;
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
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {
            showToPlayer = 0;
            burst = 2;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
        };
    };
    class rhs_weap_ak103_base: rhs_weap_akm {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium"};
        class Single: Single {
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
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {
            showToPlayer = 0;
            burst = 2;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
        };
        class Burst: Mode_Burst {

        };
    };
    class rhs_weap_ak103_1: rhs_weap_ak103_base {
        modes[] = {"Single","single_medium_optics1","single_far_optics2"};
        class Single: Single {
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
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
    };
    class rhs_weap_ak103_2: rhs_weap_ak103_base {
        modes[] = {"Single","Burst","single_medium_optics1","single_far_optics2"};
        class Single: Single {
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
        class Burst: Burst {
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
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
    };
    class rhs_weap_ak104: rhs_weap_ak103_base {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium"};
        class Single: Single {
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
    };
    class rhs_weap_ak74: rhs_weap_ak74m {
        modes[] = {"Single","Single_AI","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium"};
    };
    class rhs_weap_aks74: rhs_weap_ak74 {
        modes[] = {"Single","Single_AI","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium"};
    };
    class rhs_weap_aks74u: rhs_weap_aks74 {
        modes[] = {"FullAuto","Single","single_medium_optics1","single_far_optics2","fullauto_medium"};
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
            minRangeProbab = 0.3;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {
            showToPlayer = 0;
            burst = 2;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
    };
    class rhs_weap_asval: rhs_weap_ak74m {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 420;
            maxRangeProbab = 0.45;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 400;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 35;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: Single {

        };
        class fullauto_medium: FullAuto {
            showToPlayer = 0;
            burst = 2;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 75;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 75;
        };
    };
    class rhs_weap_vss: rhs_weap_asval {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium"};
        class Single: Single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 420;
            maxRangeProbab = 0.45;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 400;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.7;
            maxRange = 35;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
    };
    class rhs_weap_svd: rhs_weap_ak74m {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
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
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
    };
    class rhs_weap_svdp: rhs_weap_svd {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
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
        class single_close_optics1: Single {

        };
        class single_medium_optics1: single_close_optics1 {

        };
        class single_far_optics1: single_medium_optics1 {

        };
    };
    class rhs_weap_svds: rhs_weap_svdp {
        modes[] = {"Single","single_close_optics1","single_medium_optics1","single_far_optics1"};
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
    };
    class rhs_weap_orsis_Base_F: Rifle_Base_F {
        modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class far_optic1: Single {

        };
        class medium_optic2: Single {

        };
        class far_optic2: far_optic1 {

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
    class hgun_PDW2000_F: pdw2000_base_F {
        modes[] = {"Single","FullAuto"};
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
        class FullAuto: Mode_FullAuto {
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
        class burst: Mode_Burst {

        };
    };
    class rhs_weap_pp2000: hgun_PDW2000_F {
        modes[] = {"Single","FullAuto"};
        class Single: single {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 350;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
            showToPlayer = 1;
        };
        class FullAuto: fullauto {
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
    };
    class rhs_weap_an94_base: Rifle_Base_F {
        modes[] = {"Single","Burst","Single_AI","FullAuto","single_medium_optics1","single_far_optics2","fullauto_medium"};
        class Single: Mode_SemiAuto {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 100;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Burst: Mode_Burst {
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 250;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class Single_AI: Single {
            showToPlayer = 0;
            minRange = 200;
            minRangeProbab = 0.5;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.3;
            aiRateOfFire = 1;
            burst = 1;
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
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
        class fullauto_medium: FullAuto {
            showToPlayer = 0;
            burst = 2;
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 75;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.05;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 500;
        };
    };
    class rhs_pkp_base: Rifle_Long_Base_F {
        modes[] = {"FullAuto","Single","close","short","medium","far_optic1","far_optic2"};
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
            minRangeProbab = 0.01;
            midRange = 200;
            midRangeProbab = 0.01;
            maxRange = 400;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
            burst = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class close: FullAuto {
            burst = 6;
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
            burst = 5;
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
            burst = 4;
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
    class rhs_weap_pkp: rhs_pkp_base {
        modes[] = {"FullAuto","Single","close","short","medium","far_optic1","far_optic2"};
    };
    class rhs_weap_pkm: rhs_weap_pkp {
        modes[] = {"manual","close","short","medium","far_optic1","far_optic2"};
        class manual: FullAuto {
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
        class close: manual {
            burst = 6;
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
            burst = 6;
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
            burst = 5;
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
    class rhs_weap_rpk_base: Rifle_Long_Base_F {
        modes[] = {"single","manual","close","short","medium","far_optic1","far_optic2"};
        class single: Mode_SemiAuto {
            minRange = 0;
            minRangeProbab = 0.01;
            midRange = 0;
            midRangeProbab = 0.01;
            maxRange = 0;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 500;
        };
        class manual: Mode_FullAuto {
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
            burst = 6;
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
            burst = 5;
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
            burst = 5;
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
    class vn_pistol: Pistol_Base_F {
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
    class vn_rifle: Rifle_Base_F {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class FullAuto: Mode_FullAuto {
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
        class AICQB: Single {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 75;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 100;
            minRange = 75;
            minRangeProbab = 0.5;
            midRange = 130;
            midRangeProbab = 1;
            maxRange = 190;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 130;
            minRangeProbab = 0.5;
            midRange = 190;
            midRangeProbab = 1;
            maxRange = 290;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 190;
            minRangeProbab = 0.5;
            midRange = 290;
            midRangeProbab = 1;
            maxRange = 650;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
        };
        class AIOpticmode1: Single {

        };
        class AIOpticmode2: Single {

        };
    };
    class vn_smg: vn_rifle {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class FullAuto: FullAuto {
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
        class AICQB: FullAuto {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 60;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 6;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 100;
            minRange = 60;
            minRangeProbab = 0.5;
            midRange = 100;
            midRangeProbab = 1;
            maxRange = 160;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 100;
            minRangeProbab = 0.5;
            midRange = 160;
            midRangeProbab = 1;
            maxRange = 250;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 160;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
        };
    };
    class vn_shotgun: vn_rifle {
        modes[] = {"FullAuto","Single_Close","Single_Far"};
        class FullAuto: FullAuto {
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 70;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.1;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 120;
            showToPlayer = 1;
        };
        class Single_Close: FullAuto {
            showToPlayer = 0;
            minRange = 40;
            minRangeProbab = 0.1;
            midRange = 80;
            midRangeProbab = 0.8;
            maxRange = 120;
            maxRangeProbab = 0.15;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            burst = 1;
        };
        class Single_Far: Single_Close {
            minRange = 120;
            minRangeProbab = 0.1;
            midRange = 150;
            midRangeProbab = 0.7;
            maxRange = 200;
            maxRangeProbab = 0.15;
            aiRateOfFire = 6;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
            burst = 1;
        };
    };
    class vn_rifle762: vn_rifle {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar"};
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
        class FullAuto: FullAuto {
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
        class AICQB: Single {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 90;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 100;
            minRange = 90;
            minRangeProbab = 0.5;
            midRange = 190;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 190;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 800;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
        };
    };
    class vn_lmg: vn_rifle {
        modes[] = {"manual","close","short","medium","far_optic1","far_optic2"};
        class manual: Mode_FullAuto {
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
        class close: manual {
            burst = 10;
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
            burst = 6;
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
            burst = 7;
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
    class vn_m1911: vn_pistol {
        modes[] = {"single"};
        class single: Single {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 75;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class vn_hp: vn_m1911 {
        modes[] = {"single"};
        class single: Single {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 75;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class vn_mk22: vn_pistol {
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
    class vn_hd: vn_pistol {
        modes[] = {"Single"};
        class Single: Mode_SemiAuto {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 75;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class vn_welrod: vn_hd {
        modes[] = {"Single"};
        class Single: Single {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 75;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class vn_pm: vn_pistol {
        modes[] = {"single"};
        class single: Single {
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
    class vn_tt33: vn_pm {
        modes[] = {"Single"};
        class Single: Single {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 75;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class vn_m10: vn_mk22 {
        modes[] = {"Single"};
        class Single: Single {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 75;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class vn_m1897: vn_shotgun {
        modes[] = {"FullAuto","AIClose","AIMedium"};
        class FullAuto: FullAuto {
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
        class AIClose: FullAuto {
            showToPlayer = 0;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 130;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.15;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            burst = 1;
        };
        class AIMedium: AIClose {
            minRange = 150;
            minRangeProbab = 0.1;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
            burst = 1;
        };
    };
    class vn_izh54: vn_shotgun {
        modes[] = {"FullAuto","AIClose","AIMedium"};
        class FullAuto: FullAuto {
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
        class AIClose: FullAuto {
            showToPlayer = 0;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 130;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.15;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            burst = 1;
        };
        class AIMedium: AIClose {
            minRange = 150;
            minRangeProbab = 0.1;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
            burst = 1;
        };
    };
    class vn_izh54_shorty: vn_izh54 {
        modes[] = {"FullAuto","AIClose","AIMedium"};
        class FullAuto: FullAuto {
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
        class AIClose: AIClose {
            showToPlayer = 0;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 130;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.15;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            burst = 1;
        };
        class AIMedium: AIMedium {
            minRange = 150;
            minRangeProbab = 0.1;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
            burst = 1;
        };
    };
    class vn_izh54_p: vn_izh54 {
        modes[] = {"FullAuto","AIClose","AIMedium"};
        class FullAuto: FullAuto {
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
        class AIClose: AIClose {
            showToPlayer = 0;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 130;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.15;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 200;
            burst = 1;
        };
        class AIMedium: AIMedium {
            minRange = 150;
            minRangeProbab = 0.1;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 300;
            maxRangeProbab = 0.15;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
            burst = 1;
        };
    };
    class vn_pps52: vn_smg {
        modes[] = {"FullAuto","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: FullAuto {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 200;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 1;
            maxRange = 250;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 200;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 300;
            maxRangeProbab = 0.5;
            aiRateOfFire = 6;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
        };
    };
    class vn_mc10: vn_pps52 {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: FullAuto {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 200;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 1;
            maxRange = 250;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 200;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 300;
            maxRangeProbab = 0.5;
            aiRateOfFire = 6;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
        };
    };
    class vn_ppsh41: vn_smg {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar"};
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
        class FullAuto: FullAuto {
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
        class AICQB: FullAuto {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 300;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 400;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
        };
    };
    class vn_k50m: vn_ppsh41 {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar"};
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
        class FullAuto: FullAuto {
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
    };
    class vn_mat49: vn_smg {
        modes[] = {"FullAuto","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: FullAuto {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 300;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 300;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
        };
    };
    class vn_mat49_vc: vn_mat49 {
        modes[] = {"FullAuto","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
    };
    class vn_m3a1: vn_smg {
        modes[] = {"FullAuto","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: FullAuto {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 200;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 1;
            maxRange = 250;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 200;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 300;
            maxRangeProbab = 0.5;
            aiRateOfFire = 6;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
        };
    };
    class vn_sten: vn_smg {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar"};
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
        class FullAuto: FullAuto {
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
        class AICQB: Single {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 60;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 100;
            minRange = 60;
            minRangeProbab = 0.5;
            midRange = 100;
            midRangeProbab = 1;
            maxRange = 160;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 100;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 230;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 230;
            midRangeProbab = 1;
            maxRange = 250;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
        };
    };
    class vn_m45: vn_smg {
        modes[] = {"FullAuto","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: Mode_FullAuto {
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
        class AICQB: FullAuto {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 300;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 300;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
        };
    };
    class vn_mp40: vn_smg {
        modes[] = {"FullAuto","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: Mode_FullAuto {
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
        class AICQB: FullAuto {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 290;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 300;
            midRangeProbab = 1;
            maxRange = 330;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
        };
    };
    class vn_type56: vn_rifle762 {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: Single {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 100;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 300;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 800;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 500;
            showToPlayer = 0;
        };
    };
    class vn_m16: vn_rifle {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class FullAuto: FullAuto {
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
        class AICQB: FullAuto {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1.7;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 300;
            minRangeProbab = 0.5;
            midRange = 450;
            midRangeProbab = 1;
            maxRange = 650;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2.4;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
        };
        class AIOpticmode1: Single {

        };
        class AIOpticmode2: Single {

        };
    };
    class vn_xm177: vn_m16 {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class FullAuto: FullAuto {
            aiRateOfFire = 1e-006;
            minRange = 1;
            minRangeProbab = 0.2;
            midRange = 30;
            midRangeProbab = 0.58;
            maxRange = 80;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
            aiRateOfFireDistance = 500;
        };
        class AICQB: FullAuto {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1.7;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 450;
            midRangeProbab = 1;
            maxRange = 590;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2.4;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
        };
        class AIOpticmode1: Single {

        };
        class AIOpticmode2: Single {

        };
    };
    class vn_m63a: vn_rifle {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar"};
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
        class FullAuto: FullAuto {
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
        class AICQB: Single {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 1.2;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2.4;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 450;
            midRangeProbab = 1;
            maxRange = 580;
            maxRangeProbab = 0.5;
            aiRateOfFire = 3.6;
            aiRateOfFireDistance = 450;
            showToPlayer = 0;
        };
    };
    class vn_m14: vn_rifle762 {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class FullAuto: Mode_FullAuto {
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
        class AICQB: FullAuto {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 550;
            maxRangeProbab = 0.5;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 350;
            burst = 3;
            showToPlayer = 0;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_rifle_boltaction_base: vn_rifle762 {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar"};
    };
    class vn_m40a1_base: vn_rifle_boltaction_base {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class AICQB: Single {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 50;
            burst = 1;
        };
        class AIClose: AICQB {
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1.4;
            aiRateOfFireDistance = 100;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
            burst = 1;
        };
        class AIMedium: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 450;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2.4;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
            burst = 1;
        };
        class AIFar: AICQB {
            minRange = 350;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 600;
            maxRangeProbab = 0.5;
            aiRateOfFire = 3.4;
            aiRateOfFireDistance = 450;
            showToPlayer = 0;
            burst = 1;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_rifle_boltaction_clip_base: vn_rifle_boltaction_base {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar"};
    };
    class vn_m38: vn_rifle_boltaction_clip_base {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class AICQB: Single {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 50;
            burst = 1;
        };
        class AIClose: AICQB {
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1.5;
            aiRateOfFireDistance = 100;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
            burst = 1;
        };
        class AIMedium: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 450;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2.5;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
            burst = 1;
        };
        class AIFar: AICQB {
            minRange = 350;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 600;
            maxRangeProbab = 0.5;
            aiRateOfFire = 3.5;
            aiRateOfFireDistance = 450;
            showToPlayer = 0;
            burst = 1;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_sks: vn_rifle762 {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class AICQB: Single {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            burst = 1;
        };
        class AIClose: AICQB {
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
            burst = 1;
        };
        class AIMedium: AICQB {
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
            burst = 1;
        };
        class AIFar: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 600;
            maxRangeProbab = 0.5;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
            burst = 1;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_m1carbine: vn_rifle762 {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class AICQB: Single {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            burst = 1;
        };
        class AIClose: AICQB {
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
            burst = 1;
        };
        class AIMedium: AICQB {
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
            burst = 1;
        };
        class AIFar: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 550;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
            burst = 1;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_m2carbine: vn_m1carbine {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class FullAuto: Mode_FullAuto {
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
        class AICQB: FullAuto {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 550;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_m4956: vn_rifle762 {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class AICQB: Single {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            burst = 1;
        };
        class AIClose: AICQB {
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
            burst = 1;
        };
        class AIMedium: AICQB {
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
            burst = 1;
        };
        class AIFar: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 600;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
            burst = 1;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_rpd: vn_lmg {
        modes[] = {"FullAuto","AIClose","AIMedium","AIFar"};
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
        class AIClose: FullAuto {
            burst = 10;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 70;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIMedium: AIClose {
            burst = 4;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 75;
            minRangeProbab = 0.05;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIFar: AIClose {
            burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 300;
            minRangeProbab = 0.05;
            midRange = 700;
            midRangeProbab = 0.6;
            maxRange = 1000;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class vn_rpd_shorty: vn_rpd {
        modes[] = {"FullAuto","AIClose","AIMedium","AIFar"};
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
        class AIClose: AIClose {
            burst = 10;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 70;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIMedium: AIMedium {
            burst = 4;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 75;
            minRangeProbab = 0.05;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIFar: AIFar {
            burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 300;
            minRangeProbab = 0.05;
            midRange = 700;
            midRangeProbab = 0.6;
            maxRange = 1000;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class vn_dp28: vn_lmg {
        modes[] = {"FullAuto","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 50;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
        };
        class AICQB: FullAuto {
            burst = 8;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 6;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 100;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 4;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 3;
            minRange = 300;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 800;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 500;
            showToPlayer = 0;
        };
    };
    class vn_pk: vn_lmg {
        modes[] = {"FullAuto","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 5;
            midRangeProbab = 0.58;
            maxRange = 10;
            maxRangeProbab = 0.04;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            showToPlayer = 1;
        };
        class AICQB: FullAuto {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 100;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 4;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 3;
            minRange = 300;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 800;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 500;
            showToPlayer = 0;
        };
    };
    class vn_m60: vn_lmg {
        modes[] = {"FullAuto","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 70;
            maxRangeProbab = 0.1;
        };
        class AICQB: FullAuto {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 100;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 4;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 3;
            minRange = 300;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 800;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 500;
            showToPlayer = 0;
        };
    };
    class vn_m60_shorty: vn_m60 {
        modes[] = {"FullAuto","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
            showToPlayer = 1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 70;
            maxRangeProbab = 0.1;
        };
        class AICQB: FullAuto {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 100;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 4;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 3;
            minRange = 300;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 800;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 500;
            showToPlayer = 0;
        };
    };
    class vn_m79: vn_rifle {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
    class vn_m79_p: vn_pistol {
        modes[] = {"Single"};
        class Single: Single {
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
    class vn_mk1_udg: vn_smg {
        modes[] = {"Single"};
        class Single: Single {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 75;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class vn_mpu: vn_smg {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: FullAuto {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 200;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 1;
            maxRange = 250;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 200;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 300;
            maxRangeProbab = 0.5;
            aiRateOfFire = 6;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
        };
    };
    class vn_vz61_p: vn_pistol {
        modes[] = {"Single","FullAuto"};
        class Single: Single {
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
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.001;
            minRange = 0;
            minRangeProbab = 0.3;
            midRange = 15;
            midRangeProbab = 0.6;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class vn_vz61: vn_smg {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: FullAuto {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 200;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 1;
            maxRange = 250;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 200;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 300;
            maxRangeProbab = 0.5;
            aiRateOfFire = 6;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
        };
    };
    class vn_m1a1_tommy: vn_smg {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: Single {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 60;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 100;
            minRange = 60;
            minRangeProbab = 0.5;
            midRange = 100;
            midRangeProbab = 1;
            maxRange = 160;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 100;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 230;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 230;
            midRangeProbab = 1;
            maxRange = 250;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
        };
    };
    class vn_m1928a1_tommy: vn_m1a1_tommy {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
    };
    class vn_m1928_tommy: vn_m1a1_tommy {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
    };
    class vn_m63a_lmg: vn_rifle {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: Single {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: FullAuto {
            burst = 10;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 70;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIMedium: AIClose {
            burst = 4;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 75;
            minRangeProbab = 0.05;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIFar: AIClose {
            burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 300;
            minRangeProbab = 0.05;
            midRange = 700;
            midRangeProbab = 0.6;
            maxRange = 1000;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class vn_f1_smg: vn_smg {
        modes[] = {"Single","FullAuto","AICQB","AIClose","AIMedium","AIFar"};
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
        class FullAuto: FullAuto {
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
        class AICQB: FullAuto {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 300;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 400;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
        };
    };
    class vn_m1_garand: vn_rifle762 {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class AICQB: Single {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            burst = 1;
        };
        class AIClose: AICQB {
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
            burst = 1;
        };
        class AIMedium: AICQB {
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
            burst = 1;
        };
        class AIFar: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 550;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
            burst = 1;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_l1a1_01: vn_rifle762 {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class FullAuto: FullAuto {

        };
        class AICQB: FullAuto {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 550;
            maxRangeProbab = 0.5;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 350;
            burst = 3;
            showToPlayer = 0;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_vz54: vn_rifle762 {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class AICQB: Single {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 50;
            burst = 1;
        };
        class AIClose: AICQB {
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1.4;
            aiRateOfFireDistance = 100;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
            burst = 1;
        };
        class AIMedium: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 450;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2.4;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
            burst = 1;
        };
        class AIFar: AICQB {
            minRange = 350;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 600;
            maxRangeProbab = 0.5;
            aiRateOfFire = 3.4;
            aiRateOfFireDistance = 450;
            showToPlayer = 0;
            burst = 1;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_m1918: vn_lmg {
        modes[] = {"FullAutoSlow","FullAuto","AIClose","AIMedium","AIFar"};
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
        class FullAutoSlow: FullAuto {
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
        class AIClose: FullAuto {
            burst = 10;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 70;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIMedium: AIClose {
            burst = 4;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 75;
            minRangeProbab = 0.05;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIFar: AIClose {
            burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 300;
            minRangeProbab = 0.05;
            midRange = 700;
            midRangeProbab = 0.6;
            maxRange = 1000;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class vn_type64: vn_pistol {
        modes[] = {"Single"};
        class Single: Single {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 75;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class vn_ppk: vn_pistol {
        modes[] = {"Single"};
        class Single: Single {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 75;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class vn_p38: vn_pistol {
        modes[] = {"Single"};
        class Single: Single {
            minRange = 5;
            minRangeProbab = 0.3;
            midRange = 30;
            midRangeProbab = 0.6;
            maxRange = 75;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 30;
            showToPlayer = 1;
        };
    };
    class vn_type64_smg: vn_smg {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: Single {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 25;
            midRangeProbab = 0.7;
            maxRange = 60;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 100;
            minRange = 60;
            minRangeProbab = 0.5;
            midRange = 100;
            midRangeProbab = 1;
            maxRange = 160;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 100;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 230;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 230;
            midRangeProbab = 1;
            maxRange = 250;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
        };
    };
    class vn_l2a3: vn_smg {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: FullAuto {
            burst = 6;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 150;
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 300;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 400;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 300;
            showToPlayer = 0;
        };
    };
    class vn_l34a1: vn_l2a3 {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
    class vn_l34a1_xm148: vn_l2a3 {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
    class vn_kbkg: vn_rifle {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
        class AICQB: Single {
            burst = 3;
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 50;
            midRangeProbab = 0.7;
            maxRange = 100;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
        };
        class AIClose: AICQB {
            burst = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            minRange = 100;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            showToPlayer = 0;
            maxRangeProbab = 0.1;
        };
        class AIMedium: AICQB {
            burst = 1;
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
        };
        class AIFar: AICQB {
            burst = 1;
            minRange = 300;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 800;
            maxRangeProbab = 0.5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 500;
            showToPlayer = 0;
        };
    };
    class vn_ak_01: vn_type56 {
        modes[] = {"FullAuto","Single","AICQB","AIClose","AIMedium","AIFar"};
        class FullAuto: FullAuto {
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
    class vn_m1903: vn_rifle762 {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class AICQB: Single {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 50;
            burst = 1;
        };
        class AIClose: AICQB {
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1.5;
            aiRateOfFireDistance = 100;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
            burst = 1;
        };
        class AIMedium: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 450;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2.5;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
            burst = 1;
        };
        class AIFar: AICQB {
            minRange = 350;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 600;
            maxRangeProbab = 0.5;
            aiRateOfFire = 3.5;
            aiRateOfFireDistance = 450;
            showToPlayer = 0;
            burst = 1;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_svd: vn_rifle762 {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class AICQB: Single {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            burst = 1;
        };
        class AIClose: AICQB {
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 150;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
            burst = 1;
        };
        class AIMedium: AICQB {
            minRange = 150;
            minRangeProbab = 0.5;
            midRange = 250;
            midRangeProbab = 1;
            maxRange = 350;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
            burst = 1;
        };
        class AIFar: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 550;
            maxRangeProbab = 0.5;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            showToPlayer = 0;
            burst = 1;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_m36: vn_rifle762 {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class AICQB: Single {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 50;
            burst = 1;
        };
        class AIClose: AICQB {
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1.5;
            aiRateOfFireDistance = 100;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
            burst = 1;
        };
        class AIMedium: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 450;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2.5;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
            burst = 1;
        };
        class AIFar: AICQB {
            minRange = 350;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 600;
            maxRangeProbab = 0.5;
            aiRateOfFire = 3.5;
            aiRateOfFireDistance = 450;
            showToPlayer = 0;
            burst = 1;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_k98k: vn_rifle762 {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
        class AICQB: Single {
            showToPlayer = 0;
            minRange = 0;
            minRangeProbab = 1;
            midRange = 50;
            midRangeProbab = 1;
            maxRange = 100;
            maxRangeProbab = 0.5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 50;
            burst = 1;
        };
        class AIClose: AICQB {
            minRange = 50;
            minRangeProbab = 0.5;
            midRange = 150;
            midRangeProbab = 1;
            maxRange = 250;
            aiRateOfFire = 1.5;
            aiRateOfFireDistance = 100;
            showToPlayer = 0;
            maxRangeProbab = 0.5;
            burst = 1;
        };
        class AIMedium: AICQB {
            minRange = 250;
            minRangeProbab = 0.5;
            midRange = 350;
            midRangeProbab = 1;
            maxRange = 450;
            maxRangeProbab = 0.1;
            aiRateOfFire = 2.5;
            aiRateOfFireDistance = 250;
            showToPlayer = 0;
            burst = 1;
        };
        class AIFar: AICQB {
            minRange = 350;
            minRangeProbab = 0.5;
            midRange = 500;
            midRangeProbab = 1;
            maxRange = 600;
            maxRangeProbab = 0.5;
            aiRateOfFire = 3.5;
            aiRateOfFireDistance = 450;
            showToPlayer = 0;
            burst = 1;
        };
        class AIOpticmode1: AICQB {

        };
        class AIOpticmode2: AICQB {

        };
    };
    class vn_m1carbine_shorty: vn_m1carbine {
        modes[] = {"Single","AICQB","AIClose","AIMedium","AIFar","AIOpticmode1","AIOpticmode2"};
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
    class vn_l4: vn_lmg {
        modes[] = {"FullAuto","Single","AIClose","AIMedium","AIFar"};
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
        class AIClose: FullAuto {
            burst = 10;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 70;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIMedium: AIClose {
            burst = 4;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 75;
            minRangeProbab = 0.05;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIFar: AIClose {
            burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 300;
            minRangeProbab = 0.05;
            midRange = 700;
            midRangeProbab = 0.6;
            maxRange = 1000;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class vn_mg42: vn_lmg {
        modes[] = {"FullAuto","Single","AIClose","AIMedium","AIFar"};
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
        class AIClose: FullAuto {
            burst = 10;
            aiRateOfFire = 1e-006;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 70;
            midRangeProbab = 0.7;
            maxRange = 150;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIMedium: AIClose {
            burst = 4;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 75;
            minRangeProbab = 0.05;
            midRange = 250;
            midRangeProbab = 0.7;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 0;
        };
        class AIFar: AIClose {
            burst = 3;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 600;
            minRange = 300;
            minRangeProbab = 0.05;
            midRange = 700;
            midRangeProbab = 0.6;
            maxRange = 1000;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
    };
    class hlc_aug_base: Rifle_Base_F {
        modes[] = {"FullAuto","Single","fullauto_medium","single_medium_optics1","single_far_optics2"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class fullauto_medium: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
    };
    class hlc_rifle_aug: hlc_aug_base {
        modes[] = {"FullAuto","Single","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Single {
            maxRange = 600;
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRangeProbab = 0.1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_far: Single {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 600;
            midRangeProbab = 0.05;
            maxRange = 800;
            maxRangeProbab = 0.01;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_auga1carb: hlc_rifle_aug {
        modes[] = {"FullAuto","Single","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class FullAuto: FullAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
        };
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_far: Single {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 600;
            midRangeProbab = 0.05;
            maxRange = 800;
            maxRangeProbab = 0.01;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_aughbar: hlc_rifle_aug {
        modes[] = {"FullAuto","50","AI_long","AI_close","AI_short","AI_far","AI_toofar","AI_far_optic1"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {

        };
        class 50: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_long: 50 {
            showToPlayer = 0;
            burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.1;
        };
        class AI_close: AI_long {
            burst = 8;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 25;
            minRangeProbab = 0.1;
            midRange = 50;
            midRangeProbab = 0.8;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_short: AI_close {
            burst = 5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 100;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_far: AI_close {
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 400;
            minRange = 200;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.8;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_toofar: AI_far {
            burst = 5;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 800;
            midRangeProbab = 0.2;
            maxRange = 1000;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
        class AI_far_optic1: AI_far {

        };
        class AI_medium: AI_close {

        };
        class AI_toofar_optic1: AI_far_optic1 {

        };
        class AI_far_optic2: AI_far_optic1 {

        };
        class AI_toofar_optic2: AI_toofar_optic1 {

        };
        class AI_Single: FullAuto {

        };
    };
    class hlc_rifle_augpara: hlc_aug_base {
        modes[] = {"FullAuto","Single","fullauto_medium"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.8;
            maxRange = 20;
            maxRangeProbab = 0.4;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.9;
            midRange = 80;
            midRangeProbab = 0.5;
            maxRange = 300;
            maxRangeProbab = 0.01;
        };
        class fullauto_medium: FullAuto {
            showToPlayer = 0;
            burst = 3;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 20;
            minRangeProbab = 0.8;
            midRange = 30;
            midRangeProbab = 0.5;
            maxRange = 60;
            maxRangeProbab = 0.4;
        };
    };
    class hlc_rifle_auga2para: hlc_aug_base {
        modes[] = {"FullAuto","Single","fullauto_medium"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.2;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 20;
            midRangeProbab = 0.8;
            maxRange = 30;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
        };
        class Single: Mode_SemiAuto {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 40;
            minRangeProbab = 0.9;
            midRange = 80;
            midRangeProbab = 0.5;
            maxRange = 250;
            maxRangeProbab = 0.1;
        };
        class fullauto_medium: FullAuto {
            burst = 3;
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 50;
            minRange = 30;
            minRangeProbab = 0.8;
            midRange = 40;
            midRangeProbab = 0.5;
            maxRange = 50;
            maxRangeProbab = 0.2;
        };
    };
    class hlc_rifle_auga2: hlc_rifle_aug {
        modes[] = {"FullAuto","Single","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
    };
    class hlc_rifle_auga2carb: hlc_rifle_auga2 {
        modes[] = {"FullAuto","Single","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {
            maxRange = 400;
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRangeProbab = 0.1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_far: Single {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 600;
            midRangeProbab = 0.05;
            maxRange = 800;
            maxRangeProbab = 0.01;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_auga2lsw: hlc_rifle_aughbar {
        modes[] = {"FullAuto","50","AI_long","AI_close","AI_short","AI_far","AI_toofar","AI_far_optic1"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Single: Single {

        };
        class 50: Single {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_long: 50 {
            showToPlayer = 0;
            burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.1;
        };
        class AI_close: AI_long {
            burst = 8;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 25;
            minRangeProbab = 0.1;
            midRange = 50;
            midRangeProbab = 0.8;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_short: AI_close {
            burst = 5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 100;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_far: AI_close {
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 400;
            minRange = 200;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.8;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_toofar: AI_far {
            burst = 5;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 800;
            midRangeProbab = 0.2;
            maxRange = 1000;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
        class AI_far_optic1: AI_far {

        };
        class AI_medium: AI_close {

        };
        class AI_toofar_optic1: AI_far_optic1 {

        };
        class AI_far_optic2: AI_far_optic1 {

        };
        class AI_toofar_optic2: AI_toofar_optic1 {

        };
        class AI_Single: FullAuto {

        };
    };
    class hlc_rifle_augsr: hlc_rifle_auga2 {
        modes[] = {"Single","AI_Single","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Single {
            showToPlayer = 1;
            minRange = 0;
            maxRange = 600;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_augsrcarb: hlc_rifle_auga2carb {
        modes[] = {"Single","AI_Single","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Single {
            showToPlayer = 1;
            minRange = 0;
            maxRange = 400;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_augsrhbar: hlc_rifle_auga2lsw {
        modes[] = {"Single","AI_Single","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Single {
            showToPlayer = 1;
            minRange = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
    };
    class hlc_rifle_auga3: hlc_rifle_aug {
        modes[] = {"FullAuto","Single","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Single {
            showToPlayer = 1;
            maxRange = 500;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRangeProbab = 0.1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_far: Single {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 600;
            midRangeProbab = 0.05;
            maxRange = 800;
            maxRangeProbab = 0.01;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_G36_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
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
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_far: Single {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 600;
            midRangeProbab = 0.05;
            maxRange = 800;
            maxRangeProbab = 0.01;
        };
        class Burst: Mode_Burst {

        };
        class Burst2rnd: Burst {

        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_MG36: hlc_G36_base {
        modes[] = {"Single","FullAuto","AI_long","AI_close","AI_short","AI_far","AI_toofar","AI_far_optic1"};
        class 50: FullAuto {

        };
        class AI_long: 50 {
            showToPlayer = 0;
            burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.1;
        };
        class AI_close: AI_long {
            burst = 8;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 25;
            minRangeProbab = 0.1;
            midRange = 50;
            midRangeProbab = 0.8;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_short: AI_close {
            burst = 5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 100;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_far: AI_close {
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 400;
            minRange = 200;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.8;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_toofar: AI_far {
            burst = 5;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 800;
            midRangeProbab = 0.2;
            maxRange = 1000;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
        class AI_far_optic1: AI_far {

        };
        class AI_medium: AI_close {

        };
        class AI_toofar_optic1: AI_far_optic1 {

        };
        class AI_far_optic2: AI_far_optic1 {

        };
        class AI_toofar_optic2: AI_toofar_optic1 {

        };
        class AI_Single: Single {

        };
    };
    class hlc_rifle_G36A1: hlc_G36_base {
        modes[] = {"Single","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
    };
    class hlc_rifle_G36KA1: hlc_rifle_G36A1 {
        modes[] = {"Single","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
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
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_far: Single {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 600;
            midRangeProbab = 0.05;
            maxRange = 800;
            maxRangeProbab = 0.01;
        };
        class Burst: Burst {

        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_G36C: hlc_G36_base {
        modes[] = {"Single","Burst","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 250;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_G36E1: hlc_rifle_G36A1 {
        modes[] = {"Single","Burst2rnd","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Burst2rnd: Burst {
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
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_far: Single {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 600;
            midRangeProbab = 0.05;
            maxRange = 800;
            maxRangeProbab = 0.01;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_G36KE1: hlc_rifle_G36KA1 {
        modes[] = {"Single","Burst2rnd","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Burst2rnd: Burst {
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
    };
    class hlc_rifle_G36V: hlc_G36_base {
        modes[] = {"Single","Burst2rnd","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Burst2rnd: Burst {
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
    };
    class hlc_rifle_G36KV: hlc_rifle_G36V {
        modes[] = {"Single","Burst2rnd","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
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
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_far: Single {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 600;
            midRangeProbab = 0.05;
            maxRange = 800;
            maxRangeProbab = 0.01;
        };
        class Burst: Burst {

        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_G36CV: hlc_rifle_G36V {
        modes[] = {"Single","Burst","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.2;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 250;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_G36KA1KSK: hlc_rifle_G36KV {
        modes[] = {"Single","FullAuto","single_medium_optics1","single_far_optics2"};
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
    };
    class hlc_rifle_G36MLIC: hlc_G36_base {
        modes[] = {"Single","Burst2rnd","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
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
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_far: Single {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 600;
            midRangeProbab = 0.05;
            maxRange = 800;
            maxRangeProbab = 0.01;
        };
        class Burst: Burst {

        };
        class Burst2rnd: Burst {
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
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_G36KMLIC: hlc_rifle_G36MLIC {
        modes[] = {"Single","Burst2rnd","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
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
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_far: Single {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 600;
            midRangeProbab = 0.05;
            maxRange = 800;
            maxRangeProbab = 0.01;
        };
        class Burst: Burst {

        };
        class Burst2rnd: Burst {
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
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_G36CMLIC: hlc_rifle_G36MLIC {
        modes[] = {"Single","Burst2rnd","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 250;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 400;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.2;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 5;
            midRangeProbab = 0.8;
            maxRange = 10;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 250;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class Burst: Burst {

        };
        class Burst2rnd: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 10;
            minRangeProbab = 0.8;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_g3_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","AI_SemiAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            minRange = 15;
            minRangeProbab = 0.8;
            midRange = 150;
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
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            minRange = 15;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 15;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class AI_SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
    };
    class hlc_rifle_psg1: hlc_g3_base {
        modes[] = {"Single","single_medium_optics1"};
        class Single: Single {
            aiRateOfFire = 7;
            aiRateOfFireDistance = 1000;
            minRange = 0;
            minRangeProbab = 0.4;
            midRange = 500;
            midRangeProbab = 0.8;
            maxRange = 1600;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class single_medium_optics1: Single {

        };
    };
    class hlc_rifle_g3sg1: hlc_g3_base {
        modes[] = {"Single","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","AI_SemiAuto"};
    };
    class hlc_rifle_g3a3: hlc_rifle_g3sg1 {
        modes[] = {"Single","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","AI_SemiAuto"};
        class Single: Single {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            minRange = 15;
            minRangeProbab = 0.8;
            midRange = 150;
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
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            minRange = 15;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 15;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class AI_SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
    };
    class hlc_rifle_g3ka4: hlc_rifle_g3a3 {
        modes[] = {"Single","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","AI_SemiAuto"};
        class Single: Single {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            minRange = 15;
            minRangeProbab = 0.8;
            midRange = 150;
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
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            minRange = 15;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 15;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class AI_SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
    };
    class hlc_rifle_hk51: hlc_rifle_g3sg1 {
        modes[] = {"Single","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 250;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_hk53: hlc_g3_base {
        modes[] = {"Single","Burst","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 0;
            minRangeProbab = 0.2;
            midRange = 30;
            midRangeProbab = 0.8;
            maxRange = 60;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.2;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 5;
            midRangeProbab = 0.8;
            maxRange = 10;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 250;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_hk33a2: hlc_g3_base {
        modes[] = {"Single","Burst","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
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
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_far: Single {
            showToPlayer = 0;
            burst = 5;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 600;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 600;
            midRangeProbab = 0.05;
            maxRange = 800;
            maxRangeProbab = 0.01;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_rifle_hk33ka3: hlc_rifle_hk33a2 {
        modes[] = {"Single","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","SemiAuto","AI_far"};
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 30;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 250;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.04;
            burst = 1;
        };
        class Burst3: Single {

        };
        class Burst2: Burst3 {

        };
    };
    class hlc_MG42_base: Rifle_Base_F {
        modes[] = {"FullAuto","close","short","medium","medium_burst","far","veryfar","far_optic1","toofar_optic1","far_optic2","toofar_optic2"};
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: FullAuto {
            burst = 10;
            aiRateOfFire = 0.05;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class short: close {
            burst = 8;
            aiRateOfFire = 0.05;
            aiRateOfFireDistance = 100;
            minRange = 25;
            minRangeProbab = 0.1;
            midRange = 50;
            midRangeProbab = 0.8;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = 5;
            aiRateOfFire = 0.05;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 100;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium_burst: close {
            burst = 4;
            aiRateOfFire = 0.05;
            aiRateOfFireDistance = 400;
            minRange = 100;
            minRangeProbab = 0.1;
            midRange = 200;
            midRangeProbab = 0.8;
            maxRange = 400;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = 4;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 400;
            minRange = 100;
            minRangeProbab = 0.1;
            midRange = 200;
            midRangeProbab = 0.8;
            maxRange = 400;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class veryfar: close {
            burst = 5;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 800;
            midRangeProbab = 0.2;
            maxRange = 1000;
            maxRangeProbab = 0.01;
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
    };
    class hlc_lmg_MG3: hlc_MG42_base {
        modes[] = {"FullAuto","close","short","medium","medium_burst","far","veryfar","far_optic1","toofar_optic1","far_optic2","toofar_optic2"};
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class close: FullAuto {
            burst = 10;
            aiRateOfFire = 0.06;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class short: close {
            burst = 8;
            aiRateOfFire = 0.06;
            aiRateOfFireDistance = 100;
            minRange = 25;
            minRangeProbab = 0.1;
            midRange = 50;
            midRangeProbab = 0.8;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium: close {
            burst = 5;
            aiRateOfFire = 0.06;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 100;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class medium_burst: close {
            burst = 4;
            aiRateOfFire = 0.06;
            aiRateOfFireDistance = 400;
            minRange = 100;
            minRangeProbab = 0.1;
            midRange = 200;
            midRangeProbab = 0.8;
            maxRange = 400;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class far: close {
            burst = 4;
            aiRateOfFire = 0.06;
            aiRateOfFireDistance = 400;
            minRange = 100;
            minRangeProbab = 0.1;
            midRange = 200;
            midRangeProbab = 0.8;
            maxRange = 400;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class veryfar: close {
            burst = 5;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 800;
            midRangeProbab = 0.2;
            maxRange = 1000;
            maxRangeProbab = 0.01;
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
    };
    class hlc_MP5_base: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.9;
            midRange = 80;
            midRangeProbab = 0.5;
            maxRange = 300;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 20;
            minRangeProbab = 0.8;
            midRange = 30;
            midRangeProbab = 0.5;
            maxRange = 60;
            maxRangeProbab = 0.4;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.8;
            maxRange = 20;
            maxRangeProbab = 0.4;
            showToPlayer = 1;
        };
    };
    class hlc_smg_mp5k_PDW: hlc_MP5_base {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.9;
            midRange = 80;
            midRangeProbab = 0.5;
            maxRange = 300;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 20;
            minRangeProbab = 0.8;
            midRange = 30;
            midRangeProbab = 0.5;
            maxRange = 60;
            maxRangeProbab = 0.4;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.8;
            maxRange = 20;
            maxRangeProbab = 0.4;
            showToPlayer = 1;
        };
    };
    class hlc_smg_MP5N: hlc_MP5_base {
        modes[] = {"Single","Burst","FullAuto"};
    };
    class hlc_smg_9mmar: hlc_smg_MP5N {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.9;
            midRange = 80;
            midRangeProbab = 0.5;
            maxRange = 300;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 20;
            minRangeProbab = 0.8;
            midRange = 30;
            midRangeProbab = 0.5;
            maxRange = 60;
            maxRangeProbab = 0.4;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.8;
            maxRange = 20;
            maxRangeProbab = 0.4;
            showToPlayer = 1;
        };
    };
    class hlc_smg_mp510: hlc_smg_MP5N {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.9;
            midRange = 80;
            midRangeProbab = 0.5;
            maxRange = 300;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 20;
            minRangeProbab = 0.8;
            midRange = 30;
            midRangeProbab = 0.5;
            maxRange = 60;
            maxRangeProbab = 0.4;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.8;
            maxRange = 20;
            maxRangeProbab = 0.4;
            showToPlayer = 1;
        };
    };
    class hlc_smg_mp5sd5: hlc_MP5_base {
        modes[] = {"Single","Burst","FullAuto"};
        class Single: Single {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 300;
            minRange = 50;
            minRangeProbab = 0.9;
            midRange = 80;
            midRangeProbab = 0.5;
            maxRange = 300;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class Burst: Burst {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 20;
            minRangeProbab = 0.8;
            midRange = 30;
            midRangeProbab = 0.5;
            maxRange = 60;
            maxRangeProbab = 0.4;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.8;
            maxRange = 20;
            maxRangeProbab = 0.4;
            showToPlayer = 1;
        };
    };
    class hlc_STGW_base: Rifle_Base_F {
        modes[] = {"Single","FullAuto","AI_Single","AI_FullAuto","AI_Burst_close","AI_Single_optics1","AI_Single_optics2","AI_SemiAuto"};
        class Single: Mode_SemiAuto {
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
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
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class AI_Single: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 350;
            minRange = 15;
            minRangeProbab = 0.8;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_FullAuto: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_Burst_close: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 15;
            maxRangeProbab = 0.2;
        };
        class AI_Single_optics1: Single {

        };
        class AI_Single_optics2: AI_Single_optics1 {

        };
        class AI_SemiAuto: Single {
            showToPlayer = 0;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
            burst = 1;
        };
    };
    class hlc_M1941_base: Rifle_Base_F {
        modes[] = {"NI_Single","FullAuto","25","AI_long","AI_close","AI_short","AI_medium","AI_far","AI_toofar","AI_far_optic1","AI_toofar_optic1","AI_far_optic2","AI_toofar_optic2"};
        class NI_Single: Mode_SemiAuto {
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
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
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class 25: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_long: 25 {
            showToPlayer = 0;
            burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.1;
        };
        class AI_close: AI_long {
            burst = 8;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 25;
            minRangeProbab = 0.1;
            midRange = 50;
            midRangeProbab = 0.8;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_short: AI_close {
            burst = 5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 100;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_medium: AI_close {
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 400;
            minRange = 100;
            minRangeProbab = 0.1;
            midRange = 200;
            midRangeProbab = 0.8;
            maxRange = 400;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_far: AI_close {
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 400;
            minRange = 200;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.8;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_toofar: AI_far {
            burst = 5;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 800;
            midRangeProbab = 0.2;
            maxRange = 1000;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
        class AI_far_optic1: AI_far {

        };
        class AI_toofar_optic1: AI_far_optic1 {

        };
        class AI_far_optic2: AI_far_optic1 {

        };
        class AI_toofar_optic2: AI_toofar_optic1 {

        };
        class AI_Single: NI_Single {

        };
    };
    class hlc_rifle_M1941LMG: hlc_M1941_base {
        modes[] = {"NI_Single","FullAuto","25","AI_long","AI_close","AI_short","AI_medium","AI_far","AI_toofar","AI_far_optic1","AI_toofar_optic1","AI_far_optic2","AI_toofar_optic2"};
        class 25: FullAuto {
            showToPlayer = 0;
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.1;
            burst = 1;
        };
        class AI_long: 25 {
            showToPlayer = 0;
            burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 10;
            minRangeProbab = 0.1;
            midRange = 25;
            midRangeProbab = 0.8;
            maxRange = 50;
            maxRangeProbab = 0.1;
        };
        class AI_close: AI_long {
            burst = 8;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 25;
            minRangeProbab = 0.1;
            midRange = 50;
            midRangeProbab = 0.8;
            maxRange = 100;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_short: AI_close {
            burst = 5;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 200;
            minRange = 50;
            minRangeProbab = 0.1;
            midRange = 100;
            midRangeProbab = 0.8;
            maxRange = 200;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_medium: AI_close {
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 400;
            minRange = 100;
            minRangeProbab = 0.1;
            midRange = 200;
            midRangeProbab = 0.8;
            maxRange = 400;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_far: AI_close {
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 400;
            minRange = 200;
            minRangeProbab = 0.1;
            midRange = 400;
            midRangeProbab = 0.8;
            maxRange = 800;
            maxRangeProbab = 0.1;
            showToPlayer = 0;
        };
        class AI_toofar: AI_far {
            burst = 5;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 800;
            minRange = 400;
            minRangeProbab = 0.1;
            midRange = 800;
            midRangeProbab = 0.2;
            maxRange = 1000;
            maxRangeProbab = 0.01;
            showToPlayer = 0;
        };
        class AI_far_optic1: AI_far {

        };
        class AI_toofar_optic1: AI_far_optic1 {

        };
        class AI_far_optic2: AI_far_optic1 {

        };
        class AI_toofar_optic2: AI_toofar_optic1 {

        };
        class AI_Single: NI_Single {

        };
    };
    class hlc_sg550_base: Rifle_Base_F {
        modes[] = {"Single","Burst","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2"};
        class Single: Mode_SemiAuto {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class Burst: Mode_Burst {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: Mode_FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class fullauto_medium: FullAuto {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class single_medium_optics1: Single {

        };
        class single_far_optics2: single_medium_optics1 {

        };
    };
    class hlc_rifle_SG551SB: hlc_sg550_base {
        modes[] = {"Single","Burst","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class Burst: Burst {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class fullauto_medium: fullauto_medium {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class hlc_rifle_SG551LB: hlc_rifle_SG551SB {
        modes[] = {"Single","Burst","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class Burst: Burst {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class fullauto_medium: fullauto_medium {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class hlc_rifle_SG553SB: hlc_sg550_base {
        modes[] = {"Single","Burst","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class Burst: Burst {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class fullauto_medium: fullauto_medium {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class hlc_rifle_SG553LB: hlc_rifle_SG551SB {
        modes[] = {"Single","Burst","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class Burst: Burst {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class fullauto_medium: fullauto_medium {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class hlc_rifle_SG550Sniper: hlc_sg550_base {
        modes[] = {"Single","fullauto_medium","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class fullauto_medium: fullauto_medium {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class hlc_rifle_sg553RSB: hlc_rifle_SG553SB {
        modes[] = {"Single","Burst","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class Burst: Burst {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class fullauto_medium: fullauto_medium {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
    class hlc_rifle_sg553RLB: hlc_rifle_sg553RSB {
        modes[] = {"Single","Burst","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2"};
        class Single: Single {
            showToPlayer = 1;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 350;
            minRange = 20;
            minRangeProbab = 0.7;
            midRange = 150;
            midRangeProbab = 0.5;
            maxRange = 500;
            maxRangeProbab = 0.1;
        };
        class Burst: Burst {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class FullAuto: FullAuto {
            aiRateOfFire = 0.1;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 1;
            midRangeProbab = 0.8;
            maxRange = 5;
            maxRangeProbab = 0.1;
            showToPlayer = 1;
        };
        class fullauto_medium: fullauto_medium {
            showToPlayer = 0;
            burst = 4;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 100;
            minRange = 5;
            minRangeProbab = 0.8;
            midRange = 10;
            midRangeProbab = 0.7;
            maxRange = 20;
            maxRangeProbab = 0.2;
        };
        class single_medium_optics1: single_medium_optics1 {

        };
        class single_far_optics2: single_far_optics2 {

        };
    };
};


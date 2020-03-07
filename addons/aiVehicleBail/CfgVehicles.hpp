class CfgVehicles {
    class Wheeled_APC_F;
    class APC_Tracked_02_base_F;
    class Tank_F;
    class CUP_BRDM2_Base : Wheeled_APC_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.7;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.7;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_BMP1_base : APC_Tracked_02_base_F { // CUP BMP2 Base inherits from this
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.8;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.5;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_T72_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.8;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.8;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.5;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.2;
    };
    class CUP_FV432_Bulldog_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.7;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.7;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_FV510_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.2;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_Mastiff_Base : Wheeled_APC_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.7;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.7;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_Ridgback_Base : Wheeled_APC_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.7;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.7;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_Wolfhound_Base : Wheeled_APC_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.7;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.7;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_Challenger2_base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0;
        ACEGVAR(vehicleDamage,turretFireProb) = 0;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.5;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0;
    };
    class CUP_Leopard2_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.3;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.5;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.3;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.5;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.7;
    };
    class CUP_ZSU23_Base : Tank_F {
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.7;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.8;
    };
    class CUP_BTR60_Base : Wheeled_APC_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.7;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.7;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_MTLB_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_M113_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_M113_Med_Base : CUP_M113_Base {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0;
        ACEGVAR(vehicleDamage,turretFireProb) = 0;
        ACEGVAR(vehicleDamage,engineFireProb) = 0;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0;
    };
    class CUP_M2Bradley_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.2;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_StrykerBase : Wheeled_APC_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.5;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.7;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_B_M1128_MGS_Desert : CUP_StrykerBase {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.5;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.5;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.2;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.5;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_M1_Abrams_base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0;
        ACEGVAR(vehicleDamage,turretFireProb) = 0;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.5;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0;
    };
    class CUP_AAV_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.5;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.5;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_LAV25_Base : Wheeled_APC_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.7;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.7;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_M60A3_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.5;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.5;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.5;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_2S6_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.4;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.4;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0.4;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.7;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.8;
    };
    class CUP_BMP3_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.5;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_BTR90_Base : Wheeled_APC_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.5;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.5;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.5;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_GAZ_Vodnik_Base : Wheeled_APC_F { // PKM Vodnik
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0.1;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.7;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_GAZ_Vodnik_MedEvac_Base : CUP_GAZ_Vodnik_Base {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0;
        ACEGVAR(vehicleDamage,turretFireProb) = 0;
        ACEGVAR(vehicleDamage,engineFireProb) = 0;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0;
    };
    class CUP_GAZ_Vodnik_BPPU_Base : CUP_GAZ_Vodnik_Base {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0.1;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0;
    };
    class CUP_T90_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.2;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.5;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0;
    };
    class CUP_T55_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.5;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.5;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.2;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.5;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_T34_Base : Tank_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.2;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.2;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.8;
    };
    class CUP_BTR40_MG_Base : Wheeled_APC_F {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0.2;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0.1;
        ACEGVAR(vehicleDamage,hullFireProb) = 0.7;
        ACEGVAR(vehicleDamage,turretFireProb) = 0.7;
        ACEGVAR(vehicleDamage,engineFireProb) = 0.8;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0.5;
    };
    class CUP_BTR40_Base : CUP_BTR40_MG_Base {
        ACEGVAR(vehicleDamage,hullDetonationProb) = 0;
        ACEGVAR(vehicleDamage,turretDetonationProb) = 0;
        ACEGVAR(vehicleDamage,engineDetonationProb) = 0;
        ACEGVAR(vehicleDamage,hullFireProb) = 0;
        ACEGVAR(vehicleDamage,turretFireProb) = 0;
        ACEGVAR(vehicleDamage,engineFireProb) = 0;
        ACEGVAR(vehicleDamage,detonationDuringFireProb) = 0;
    };
};


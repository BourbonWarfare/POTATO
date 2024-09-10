class CfgAmmo {
    class M_Titan_AA;
    class MissileBase;
    class M_Titan_AT;
    class Bo_GBU12_LGB;

    class ShellBase;
    class ace_dragon_serviceCharge: ShellBase {
        soundSetExplosion[] = {};
    };

    class ACEGVAR(missileguidance,type_Stela);
    class ACEGVAR(missileguidance,type_Igla);
    class ACEGVAR(missileguidance,type_Falanga);
    class ACEGVAR(missileguidance,type_Fleyta);
    class ACEGVAR(missileguidance,type_Konkurs);
    class ACEGVAR(missileguidance,type_Shturm);
    class ACEGVAR(missileguidance,type_Ataka);
    class ACEGVAR(missileguidance,type_Bastion);
    class ACEGVAR(missileguidance,type_Refleks);
    class ACEGVAR(missileguidance,type_Metis);
    class ACEGVAR(missileguidance,type_Kornet);
    class ACEGVAR(missileguidance,type_Vikhr);
    class ACEGVAR(missileguidance,type_KH29);
    class ACEGVAR(missileguidance,type_Hellfire);
    class ACEGVAR(missileguidance,type_Sidewinder);
    class ACEGVAR(missileguidance,type_Stinger);
    class ACEGVAR(missileguidance,type_RBS70);
    class ACEGVAR(missileguidance,type_Maverick);
    class ACEGVAR(missileguidance,type_TOW);
    class ACEGVAR(missileguidance,type_Paveway);
    class ACEGVAR(missileguidance,type_KAB);
    class ACEGVAR(missileguidance,type_Redeye);

    class CUP_M_9K32_Strela_2_AA: M_Titan_AA {
        maneuvrability = 0;
        ACE_MISSILE(Strela);
    };

    class CUP_M_9K38_Igla_AA: M_Titan_AA {
        maneuvrability = 0;
        ACE_MISSILE(Igla);
    };

    class CUP_M_9M17P_AT2_Falanga_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Falanga);
    };

    class CUP_M_9M17P_AT3_Sagger_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Fleyta);
    };

    class CUP_M_9M113_AT5_Spandrel_AT: M_Titan_AT {
        maneuvrability = 0;
        ACE_MISSILE(Konkurs);
    };

    class CUP_M_Shturm_9M114_AT6_Spiral_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Shturm);
    };

    class CUP_M_Ataka_V_9M120_AT9_Spiral_2_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Ataka);
    };

    class CUP_M_9K116_1_Bastion_AT10_Stabber_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Bastion);
    };

    class CUP_M_9M119M_Refleks_AT11_Sniper_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Refleks);
    };

    class CUP_M_9K115_2_AT13_Saxhorn_2_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Metis);
    };

    class CUP_M_9M133_1_AT14_Spriggan_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Kornet);
    };

    class CUP_M_9M133_1_AT14_Spriggan_HE: CUP_M_9M133_1_AT14_Spriggan_AT {
        maneuvrability = 0;
        ACE_MISSILE(Kornet);
    };

    class CUP_M_9K121_Vikhr_AT16_Scallion_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Vikhr);
    };

    class CUP_M_KH29L_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(KH29);
    };

    class CUP_M_AGM_114K_Hellfire_II_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Hellfire);
    };

    class CUP_M_AGM_114L_Hellfire_II_AT: MissileBase {
        class ace_missileguidance: ACEGVAR(missileguidance,type_Hellfire) {
            enabled = 1;
            // Guidance type for munitions
            defaultSeekerType = "MillimeterWaveRadar";
            seekerTypes[] = { "MillimeterWaveRadar" };

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 70;           // Angle in front of the missile which can be searched
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 1;
            activeRadarEngageDistance = 1000;
            seekerMaxRange = 2000; // distance that the hellfire internal radar can scan
        };
    };

    class CUP_M_AIM_9L_Sidewinder_AA: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Sidewinder);
    };

    class CUP_M_Stinger_AA: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Stinger);
    };

    class CUP_M_RBS70_AA: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(RBS70);
    };

    class CUP_AGM65pod_AT: MissileBase {
        maneuvrability = 0;
        ACE_MISSILE(Maverick);
    };

    class CUP_R_TOW_AT: M_Titan_AT {
        maneuvrability = 0;
        ACE_MISSILE(TOW);
    };

    class CUP_R_TOW2_AT: CUP_R_TOW_AT {
        maneuvrability = 0;
        ACE_MISSILE(TOW);
    };

    class CUP_Bo_GBU12_LGB: Bo_GBU12_LGB {
        maneuvrability = 0; // no maneuvrability so that default guidance doesnt work
        ACE_MISSILE(Paveway);
    };

    class CUP_Bo_KAB250_LGB: Bo_GBU12_LGB {
        maneuvrability = 0; // no maneuvrability so that default guidance doesnt work
        ACE_MISSILE(KAB);
    };

    class GVAR(redeye): CUP_M_Stinger_AA {
        maneuvrability = 0;
        ACE_MISSILE(Redeye);
    };
};


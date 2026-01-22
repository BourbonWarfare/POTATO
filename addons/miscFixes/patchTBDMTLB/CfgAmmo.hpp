class CfgAmmo {
    // Missiles
    class M_Titan_AT;
    class tbd_ammo_shturm: M_Titan_AT {
        maneuvrability = 0;
        manualControl = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Shturm) {
            enabled = 1;
            pitchRate = 7.5;
            showTrail = 0;
        };
    };
    class tbd_ammo_kornet_tandem: M_Titan_AT {
        maneuvrability = 0;
        manualControl = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Kornet) {
            enabled = 1;
        };
    };

    class M_Titan_AA;
    class tbd_ammo_9k35_1: M_Titan_AA {
        maneuvrability = 0;
        manualControl = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Strela) {
            enabled = 1;
            flareAngleFilter = 1.6;
            flareDistanceFilter = 100;
            seekerMinRange = 100;
            seekerMaxRange = 5000;
            seekerAccuracy = 0.6;
        };
    };
    class tbd_ammo_9k35_2: M_Titan_AA {
        maneuvrability = 0;
        manualControl = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Strela) {
            enabled = 1;
            flareAngleFilter = 1.6;
            flareDistanceFilter = 80;
            seekerMinRange = 100;
            seekerMaxRange = 5000;
            seekerAccuracy = 0.7;
        };
    };
    class tbd_ammo_9k35_3: M_Titan_AA {
        maneuvrability = 0;
        manualControl = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Strela) {
            enabled = 1;
            flareAngleFilter = 1.6;
            flareDistanceFilter = 70;
            seekerMinRange = 100;
            seekerMaxRange = 5000;
            seekerAccuracy = 0.8;
        };
    };
    class tbd_ammo_9k35_4: M_Titan_AA {
        maneuvrability = 0;
        manualControl = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Strela) {
            enabled = 1;
            flareAngleFilter = 1.6;
            flareDistanceFilter = 50;
            seekerMinRange = 100;
            seekerMaxRange = 5000;
            seekerAccuracy = 0.9;
        };
    };
    class tbd_ammo_9k38: M_Titan_AA {
        maneuvrability = 0;
        manualControl = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Igla) {
            enabled = 1;
        };
    };
    // Bullet
    class CUP_B_762x54_Ball_Green_Tracer;
    class GVARMAIN(tbd_ammo_pkt): CUP_B_762x54_Ball_Green_Tracer {
        airFriction = -0.0010922;
        typicalSpeed = 852;
    };

    class CUP_B_145x115_AP_Green_Tracer;
    class GVARMAIN(tbd_ammo_kpvt): CUP_B_145x115_AP_Green_Tracer {
        airFriction = -0.0005;
        typicalSpeed = 1000;
    };

    class CUP_B_30mm_AP_Green_Tracer;
    class GVARMAIN(tbd_ammo_2a27_ap): CUP_B_30mm_AP_Green_Tracer {
        airFriction = -0.00056;
        typicalSpeed = 1000;
    };
    class CUP_B_30mm_HE_Green_Tracer;
    class GVARMAIN(tbd_ammo_2a27_he): CUP_B_30mm_HE_Green_Tracer {
        airFriction = -0.00056;
        typicalSpeed = 900;
    };

    class CUP_G_30mm_HE;
    class GVARMAIN(tbd_ammo_asg17): CUP_G_30mm_HE {
        airFriction = -0.001;
        typicalSpeed = 185;
    };
};

/*///tbd_ammo_2a14_ap
airFriction = -0.00056;
typicalSpeed = 1000;
tracerStartTime = 0.5;
tracerEndTime = 5;
// magazine
initSpeed = 900;
maxLeadSpeed = 200;
///tbd_ammo_2a14_he
airFriction = -0.00056;
typicalSpeed = 900;
tracerStartTime = 0.5;
tracerEndTime = 5;
// magazine
initSpeed = 900;
maxLeadSpeed = 200;*/

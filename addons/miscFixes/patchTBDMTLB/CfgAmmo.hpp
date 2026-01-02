class CfgAmmo {
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
};

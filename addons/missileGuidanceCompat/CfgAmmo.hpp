class CfgAmmo {
    class M_Titan_AA;
    class MissileBase;
    class M_Titan_AT;
    class Bo_GBU12_LGB;

    class CUP_M_9K32_Strela_2_AA: M_Titan_AA {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 30;          // Minium flap deflection for guidance
            yawRate = 30;            // Maximum flap deflection for guidance

            canVanillaLock = 1;          // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "IR";
            seekerTypes[] = { "IR" };

            flareDistanceFilter = 100;
            flareAngleFilter = 1.6; // can filter out flares that are >= flareAngleFilter to known target velocity

            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };

            defaultNavigationType = "ProportionalNavigation";
            navigationTypes[] = { "ProportionalNavigation" };

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 45;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 0.6;         // seeker accuracy multiplier

            seekerMinRange = 10;
            seekerMaxRange = 3700;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "DIR";
            attackProfiles[] = {"DIR"};
        };
    };

    class CUP_M_9K38_Igla_AA: M_Titan_AA {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 30;          // Minium flap deflection for guidance
            yawRate = 43;            // Maximum flap deflection for guidance

            canVanillaLock = 1;          // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "IR";
            seekerTypes[] = { "IR" };

            flareDistanceFilter = 100;
            flareAngleFilter = 1.1; // can filter out flares that are >= flareAngleFilter to known target velocity

            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };

            defaultNavigationType = "AugmentedProportionalNavigation";
            navigationTypes[] = { "AugmentedProportionalNavigation" };

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 45;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 0.76;         // seeker accuracy multiplier

            seekerMinRange = 5;
            seekerMaxRange = 5200;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "DIR";
            attackProfiles[] = {"DIR"};
        };
    };

    class CUP_M_9M17P_AT2_Falanga_AT: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 15;          // Minium flap deflection for guidance
            yawRate = 15;            // Maximum flap deflection for guidance

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            showTrail = 1;

            // Guidance type for munitions
            defaultSeekerType = "MCLOS";
            seekerTypes[] = { "MCLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 5;
            lineGainD = 0;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 30;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 0;
            seekerMaxRange = 2500;      // Range from the missile which the seeker can visually search

            correctionDistance = 0; // distance from center of crosshair where missile slows down
            offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

            // Attack profile type selection
            defaultAttackProfile = "WIRE";
            attackProfiles[] = {"WIRE"};
        };
    };

    class CUP_M_9M17P_AT3_Sagger_AT: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 15;          // Minium flap deflection for guidance
            yawRate = 15;            // Maximum flap deflection for guidance

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            showTrail = 1;

            // Guidance type for munitions
            defaultSeekerType = "MCLOS";
            seekerTypes[] = { "MCLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 5;
            lineGainD = 0;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 30;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 0;
            seekerMaxRange = 3000;      // Range from the missile which the seeker can visually search

            correctionDistance = 0; // distance from center of crosshair where missile slows down
            offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

            // Attack profile type selection
            defaultAttackProfile = "WIRE";
            attackProfiles[] = {"WIRE"};
        };
    };

    class CUP_M_9M113_AT5_Spandrel_AT: M_Titan_AT {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 45;          // Minium flap deflection for guidance
            yawRate = 45;            // Maximum flap deflection for guidance

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            showTrail = 1;

            // Guidance type for munitions
            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 35;
            lineGainD = 30;

            initialPitch = 2;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 30;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 75;
            seekerMaxRange = 4000;      // Range from the missile which the seeker can visually search

            correctionDistance = 30; // distance from center of crosshair where missile slows down
            offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

            // Attack profile type selection
            defaultAttackProfile = "WIRE";
            attackProfiles[] = {"WIRE"};
        };
    };

    class CUP_M_Shturm_9M114_AT6_Spiral_AT: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 45;          // Minium flap deflection for guidance
            yawRate = 45;            // Maximum flap deflection for guidance

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            showTrail = 1;

            // Guidance type for munitions
            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 35;
            lineGainD = 30;

            initialPitch = 2;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 30;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 75;
            seekerMaxRange = 4000;      // Range from the missile which the seeker can visually search

            correctionDistance = 30; // distance from center of crosshair where missile slows down
            offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

            // Attack profile type selection
            defaultAttackProfile = "BEAM";
            attackProfiles[] = {"BEAM"};
        };
    };

    class CUP_M_Ataka_V_9M120_AT9_Spiral_2_AT: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 45;          // Minium flap deflection for guidance
            yawRate = 45;            // Maximum flap deflection for guidance

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            showTrail = 1;

            // Guidance type for munitions
            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 35;
            lineGainD = 30;

            initialPitch = 2;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 30;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 75;
            seekerMaxRange = 6000;      // Range from the missile which the seeker can visually search

            correctionDistance = 30; // distance from center of crosshair where missile slows down
            offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

            // Attack profile type selection
            defaultAttackProfile = "BEAM";
            attackProfiles[] = {"BEAM"};
        };
    };

    class CUP_M_9K116_1_Bastion_AT10_Stabber_AT: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 45;          // Minium flap deflection for guidance
            yawRate = 45;            // Maximum flap deflection for guidance

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            showTrail = 1;

            // Guidance type for munitions
            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 35;
            lineGainD = 30;

            initialPitch = 2;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 30;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 75;
            seekerMaxRange = 4000;      // Range from the missile which the seeker can visually search

            correctionDistance = 30; // distance from center of crosshair where missile slows down
            offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

            // Attack profile type selection
            defaultAttackProfile = "BEAM";
            attackProfiles[] = {"BEAM"};
        };
    };

    class CUP_M_9M119M_Refleks_AT11_Sniper_AT: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 45;          // Minium flap deflection for guidance
            yawRate = 45;            // Maximum flap deflection for guidance

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            showTrail = 1;

            // Guidance type for munitions
            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 35;
            lineGainD = 30;

            initialPitch = 2;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 30;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 75;
            seekerMaxRange = 5000;      // Range from the missile which the seeker can visually search

            correctionDistance = 30; // distance from center of crosshair where missile slows down
            offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

            // Attack profile type selection
            defaultAttackProfile = "BEAM";
            attackProfiles[] = {"BEAM"};
        };
    };

    class CUP_M_9K115_2_AT13_Saxhorn_2_AT: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 50;          // Minium flap deflection for guidance
            yawRate = 50;     // Maximum flap deflection for guidance
            initialPitch = 2;

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            showTrail = 1;

            // Guidance type for munitions
            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 30;
            lineGainD = 30;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 15;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 80;
            seekerMaxRange = 2000;      // Range from the missile which the seeker can visually search

            correctionDistance = 3; // distance from center of crosshair where missile slows down
            offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

            // Attack profile type selection
            defaultAttackProfile = "WIRE";
            attackProfiles[] = {"WIRE"};
        };
    };

    class CUP_M_9M133_1_AT14_Spriggan_AT: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 45;          // Minium flap deflection for guidance
            yawRate = 45;            // Maximum flap deflection for guidance

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            showTrail = 1;

            // Guidance type for munitions
            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 35;
            lineGainD = 30;

            initialPitch = 2;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 30;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 75;
            seekerMaxRange = 5000;      // Range from the missile which the seeker can visually search

            correctionDistance = 30; // distance from center of crosshair where missile slows down
            offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

            // Attack profile type selection
            defaultAttackProfile = "BEAM";
            attackProfiles[] = {"BEAM"};
        };
    };

    class CUP_M_9M133_1_AT14_Spriggan_HE: CUP_M_9M133_1_AT14_Spriggan_AT {
        maneuvrability = 0;
        class ace_missileguidance {
            enabled = 1;
        };
    };

    class CUP_M_9K121_Vikhr_AT16_Scallion_AT: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;
            showTrail = 1;

            pitchRate = 60;          // Minium flap deflection for guidance
            yawRate = 60;            // Maximum flap deflection for guidance

            canVanillaLock = 1;          // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 40;
            lineGainD = 30;
            correctionDistance = 5;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 15;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 30;
            seekerMaxRange = 12000;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "BEAM";
            attackProfiles[] = {"BEAM"};
        };
    };

    class CUP_M_KH29L_AT: MissileBase {
        maneuvrability = 0;
        class ace_missileguidance {
            enabled = 1;

            pitchRate = 20;
            yawRate = 20;

            canVanillaLock = 0;

            defaultSeekerType = "SALH";
            seekerTypes[] = {"SALH"};

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = {"LOAL"};

            defaultNavigationType = "AugmentedProportionalNavigation";
            navigationTypes[] = { "AugmentedProportionalNavigation" };

            seekLastTargetPos = 1;
            seekerAngle = 40;
            seekerAccuracy = 1;

            seekerMinRange = 1;
            seekerMaxRange = 10000;

            defaultAttackProfile = "maverick";
            attackProfiles[] = {"maverick"};
        };
    };

    class CUP_M_AGM_114K_Hellfire_II_AT: MissileBase {
        maneuvrability = 0;
        class ace_missileguidance {
            enabled = 1;

            pitchRate = 30; // degrees per second
            yawRate = 30;

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "SALH";
            seekerTypes[] = { "SALH" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            defaultNavigationType = "Direct";
            navigationTypes[] = { "Direct", "ZeroEffortMiss" };

            seekLastTargetPos = 1;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 70;           // Angle in front of the missile which can be searched
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 1;
            seekerMaxRange = 8000;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "hellfire";
            attackProfiles[] = {"hellfire", "hellfire_hi", "hellfire_lo"};

            class navigationStates {
                class initial {
                    transitionCondition = "ace_hellfire_fnc_midCourseTransition";
                    navigationType = "Direct";
                };
                class terminal {
                    transitionCondition = "";
                    navigationType = "ZeroEffortMiss";
                };
                // transitions from initial -> termimal
                states[] = {"initial", "terminal"};
            };
        };
    };

    class CUP_M_AGM_114L_Hellfire_II_AT: MissileBase {
        class ace_missileguidance {
            enabled = 1;

            pitchRate = 30; // degrees per second
            yawRate = 30;

            canVanillaLock = 1;          // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "MillimeterWaveRadar";
            seekerTypes[] = { "MillimeterWaveRadar" };

            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };

            defaultNavigationType = "Direct";
            navigationTypes[] = { "Direct", "ZeroEffortMiss" };

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 70;           // Angle in front of the missile which can be searched
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 1;
            activeRadarEngageDistance = 1000;
            seekerMaxRange = 2000; // distance that the hellfire internal radar can scan

            // Attack profile type selection
            defaultAttackProfile = "hellfire";
            attackProfiles[] = {"hellfire", "hellfire_hi", "hellfire_lo"};

            class navigationStates {
                class initial {
                    transitionCondition = "ace_hellfire_fnc_midCourseTransition";
                    navigationType = "Direct";
                };
                class terminal {
                    transitionCondition = "";
                    navigationType = "ZeroEffortMiss";
                };
                // transitions from initial -> termimal
                states[] = {"initial", "terminal"};
            };
        };
    };

    class CUP_M_AIM_9L_Sidewinder_AA: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 25;          // Minium flap deflection for guidance
            yawRate = 25;            // Maximum flap deflection for guidance

            canVanillaLock = 1;          // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "IR";
            seekerTypes[] = { "IR" };

            flareDistanceFilter = 100;
            flareAngleFilter = 1.6; // can filter out flares that are >= flareAngleFilter to known target velocity

            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };

            defaultNavigationType = "AugmentedProportionalNavigation";
            navigationTypes[] = { "AugmentedProportionalNavigation" };

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 45;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 0.8;         // seeker accuracy multiplier

            seekerMinRange = 75;
            seekerMaxRange = 5000;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "DIR";
            attackProfiles[] = {"DIR"};
        };
    };

    class CUP_M_Stinger_AA: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 42;          // Minium flap deflection for guidance
            yawRate = 42;            // Maximum flap deflection for guidance

            canVanillaLock = 1;          // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "IR";
            seekerTypes[] = { "IR" };

            flareDistanceFilter = 100;
            flareAngleFilter = 1.3; // can filter out flares that are >= flareAngleFilter to known target velocity

            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };

            defaultNavigationType = "AugmentedProportionalNavigation";
            navigationTypes[] = { "AugmentedProportionalNavigation" };

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 45;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 0.8;         // seeker accuracy multiplier

            seekerMinRange = 75;
            seekerMaxRange = 5000;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "DIR";
            attackProfiles[] = {"DIR"};
        };
    };

    class CUP_M_RBS70_AA: MissileBase {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 45;          // Minium flap deflection for guidance
            yawRate = 45;            // Maximum flap deflection for guidance

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            showTrail = 1;

            // Guidance type for munitions
            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 35;
            lineGainD = 30;

            initialPitch = 2;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 30;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 75;
            seekerMaxRange = 5000;      // Range from the missile which the seeker can visually search

            correctionDistance = 30; // distance from center of crosshair where missile slows down
            offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

            // Attack profile type selection
            defaultAttackProfile = "BEAM";
            attackProfiles[] = {"BEAM"};
        };
    };

    class CUP_AGM65pod_AT: MissileBase {
        maneuvrability = 0;
        class ace_missileguidance {
            enabled = 1;

            pitchRate = 15;
            yawRate = 15;

            canVanillaLock = 1;

            defaultSeekerType = "Optic";
            seekerTypes[] = {"Optic"};

            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = {"LOBL"};

            defaultNavigationType = "AugmentedProportionalNavigation";
            navigationTypes[] = { "AugmentedProportionalNavigation" };

            seekLastTargetPos = 1;
            seekerAngle = 60;
            seekerAccuracy = 1;

            seekerMinRange = 1;
            seekerMaxRange = 14000;

            defaultAttackProfile = "maverick";
            attackProfiles[] = {"maverick"};
        };
    };

    class CUP_R_TOW_AT: M_Titan_AT {
        maneuvrability = 0;
        class ace_missileguidance {
            enabled = 1;

            pitchRate = 45;          // Minium flap deflection for guidance
            yawRate = 45;            // Maximum flap deflection for guidance

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            showTrail = 1;

            // Guidance type for munitions
            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 35;
            lineGainD = 30;

            initialPitch = 2;

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 30;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 65;
            seekerMaxRange = 3750;      // Range from the missile which the seeker can visually search

            correctionDistance = 30; // distance from center of crosshair where missile slows down
            offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

            // Attack profile type selection
            defaultAttackProfile = "WIRE";
            attackProfiles[] = {"WIRE"};
        };
    };

    class CUP_R_TOW2_AT: CUP_R_TOW_AT {
        maneuvrability = 0;
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
        };
    };

    class CUP_Bo_GBU12_LGB: Bo_GBU12_LGB {
        maneuvrability = 0; // no maneuvrability so that default guidance doesnt work
        class ace_missileguidance {
            enabled = 1;

            pitchRate = 5;
            yawRate = 5;

            bangBangGuidance = 1;
            stabilityCoefficient = 0.4; // how much this projectile likes to "weathervane" (keep direction toward velocity)

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "SALH";
            seekerTypes[] = { "SALH" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL" };

            defaultNavigationType = "ProportionalNavigation";
            navigationTypes[] = { "ProportionalNavigation" };

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 60;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 5;
            seekerMaxRange = 4000;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "DIR";
            attackProfiles[] = {"DIR"};
        };
    };

    class CUP_Bo_KAB250_LGB: Bo_GBU12_LGB {
        maneuvrability = 0; // no maneuvrability so that default guidance doesnt work
        class ace_missileguidance {
            enabled = 1;

            pitchRate = 8;
            yawRate = 8;

            bangBangGuidance = 1;
            stabilityCoefficient = 0.4; // how much this projectile likes to "weathervane" (keep direction toward velocity)

            canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "SALH";
            seekerTypes[] = { "SALH" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL" };

            defaultNavigationType = "ProportionalNavigation";
            navigationTypes[] = { "ProportionalNavigation" };

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 60;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 5;
            seekerMaxRange = 4000;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "DIR";
            attackProfiles[] = {"DIR"};
        };
    };

    class GVAR(redeye): CUP_M_Stinger_AA {
        maneuvrability = 0;

        class ace_missileguidance {
            enabled = 1;

            pitchRate = 27;          // Minium flap deflection for guidance
            yawRate = 27;            // Maximum flap deflection for guidance

            canVanillaLock = 1;          // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "IR";
            seekerTypes[] = { "IR" };

            flareDistanceFilter = 100;
            flareAngleFilter = 2.0; // can filter out flares that are >= flareAngleFilter to known target velocity

            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };

            defaultNavigationType = "ProportionalNavigation";
            navigationTypes[] = { "ProportionalNavigation" };

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 45;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 0.4;         // seeker accuracy multiplier

            seekerMinRange = 75;
            seekerMaxRange = 4500;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "DIR";
            attackProfiles[] = {"DIR"};
        };
    };
};


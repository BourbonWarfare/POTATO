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

    lineGainP = 16;
    lineGainD = 9.5;

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
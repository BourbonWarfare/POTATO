class ace_missileguidance {
    enabled = 1;

    pitchRate = 60;          // Minium flap deflection for guidance
    yawRate = 60;            // Maximum flap deflection for guidance

    canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

    showTrail = 0;

    // Guidance type for munitions
    defaultSeekerType = "SACLOS";
    seekerTypes[] = { "SACLOS" };

    defaultSeekerLockMode = "LOAL";
    seekerLockModes[] = { "LOAL", "LOBL" };

    defaultNavigationType = "Line";
    navigationTypes[] = { "Line" };

    lineGainP = 25;
    lineGainD = 12;

    initialPitch = -0.4;

    seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
    seekerAngle = 5;           // Angle from the shooter's view that can track the missile, implemented
    seekerAccuracy = 1;         // seeker accuracy multiplier, not implemented?

    seekerMinRange = 100;
    seekerMaxRange = 2000;      // Range from the missile which the seeker can visually search

    offsetFromCrosshair[] = { 0, 0, 0 }; // where the missile wants to stay in relation to the center of the crosshair.

    // Attack profile type selection
    defaultAttackProfile = "WIRE";
    attackProfiles[] = {"WIRE"};
};
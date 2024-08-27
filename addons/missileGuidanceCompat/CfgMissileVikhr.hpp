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

    lineGainP = 20;
    lineGainD = 16;
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
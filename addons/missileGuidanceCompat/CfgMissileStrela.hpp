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
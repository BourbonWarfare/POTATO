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
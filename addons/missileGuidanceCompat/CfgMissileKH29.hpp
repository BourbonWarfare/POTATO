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
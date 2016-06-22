class ACE_Settings {
    /*   Master enable/disable   */
    class VGVAR(enabled) {
        typeName = "BOOL";
        value = 0;
    };

    /*   Granular bevhavior toggles   */
    class VGVAR(advancedSuppression) {
        typeName = "BOOL";
        value = 0;
    };
    class VGVAR(allowFlanking) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(applyToPlayerLedGroups) {
        typeName = "BOOL";
        value = 0;
    };
    class VGVAR(canCallInArtillery) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(earsEnabled) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(increaseAccuracyOnStaticTargets) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(loiteringEnabled) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(proneAndMoveToCoverOnHit) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(useBackpackStatics) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(useCharges) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(useEnhancedDriving) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(useEnhancedGunning) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(useMines) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(usePlacedStaticWeapons) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(useSmoke) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(useUav) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(warnAlliesOnDeath) {
        typeName = "BOOL";
        value = 1;
    };

    /*   AI distance settings   */
    class VGVAR(aiMutualSupportRange) {
        typeName = "SCALAR";
        value = 1000;
    };
    class VGVAR(deadBodyDetectionRange) {
        typeName = "SCALAR";
        value = 50;
    };
    class VGVAR(gunshotDetectionRange) {
        typeName = "SCALAR";
        value = 1000;
    };
    class VGVAR(maxDistanceToConsiderTargetStatic) {
        typeName = "SCALAR";
        value = 20;
    };
    class VGVAR(maxDistanceToGarrison) {
        typeName = "SCALAR";
        value = 200;
    };
    class VGVAR(maxDistanceToMountEmptyStatic) {
        typeName = "SCALAR";
        value = 100;
    };
    class VGVAR(maxDistanceToPlantCharge) {
        typeName = "SCALAR";
        value = 200;
    };
    class VGVAR(maxDistanceToPlantMine) {
        typeName = "SCALAR";
        value = 1500;
    };
    class VGVAR(maxDistanceToSmoke) {
        typeName = "SCALAR";
        value = 1500;
    };
    class VGVAR(maxEngagementDistance) {
        typeName = "SCALAR";
        value = 1000;
    };
    class VGVAR(maxThreatDistance) {
        typeName = "SCALAR";
        value = 3000;
    };
    class VGVAR(maxUAVRevealDistance) {
        typeName = "SCALAR";
        value = 1000;
    };

    /*   Chances of usage   */
    class VGVAR(chanceToUseArtillery) {
        typeName = "SCALAR";
        value = 10;
    };
    class VGVAR(chanceToUseGrenade) {
        typeName = "SCALAR";
        value = 30;
    };
    class VGVAR(chanceToUseMine) {
        typeName = "SCALAR";
        value = 50;
    };
    class VGVAR(lightGarrisonChance) {
        typeName = "SCALAR";
        value = 75;
    };

    /*    Special artillery settings    */
    class VGVAR(artilleryFireThreshold) {
        typeName = "SCALAR";
        value = 90;
    };
    class VGVAR(maximumRoundDispersion) {
        typeName = "SCALAR";
        value = 50;
    };
    class VGVAR(maximumRoundsPerBarrage) {
        typeName = "SCALAR";
        value = 2;
    };

    /*   Side array settings   */
    class VGVAR(executionEnabledSides) {
        typeName = "ARRAY";
        value[] = {WEST,EAST,RESISTANCE};
    };
    class VGVAR(movementEnabledSides) {
        typeName = "ARRAY";
        value[] = {WEST,EAST,RESISTANCE};
    };

    /*   Operation Timeouts   */
    class VGVAR(artilleryThreshold) {
        typeName = "SCALAR";
        value = 150;
    };
    class VGVAR(bombThreshold) {
        typeName = "SCALAR";
        value = 120;
    };
    class VGVAR(brainCycleWait) {
        typeName = "SCALAR";
        value = 0.5;
    };
    class VGVAR(clearingThreshold) {
        typeName = "SCALAR";
        value = 30;
    };
    class VGVAR(craterCheckThreshold) {
        typeName = "SCALAR";
        value = 15;
    };
    class VGVAR(deadBodyCheckThreshold) {
        typeName = "SCALAR";
        value = 15;
    };
    class VGVAR(flankThreshold) {
        typeName = "SCALAR";
        value = 120;
    };
    class VGVAR(formationChangeThreshold) {
        typeName = "SCALAR";
        value = 10;
    };
    class VGVAR(gearCheckThreshold) {
        typeName = "SCALAR";
        value = 20;
    };
    class VGVAR(globalSmokeThreshold) {
        typeName = "SCALAR";
        value = 90;
    };
    class VGVAR(grenadeThreshold) {
        typeName = "SCALAR";
        value = 20;
    };
    class VGVAR(mineThreshold) {
        typeName = "SCALAR";
        value = 120;
    };
    class VGVAR(moveCompletedThreshold) {
        typeName = "SCALAR";
        value = 10;
    };
    class VGVAR(movedRecentlyThreshold) {
        typeName = "SCALAR";
        value = 30;
    };
    class VGVAR(orderedIntoStaticThreshold) {
        typeName = "SCALAR";
        value = 60;
    };
    class VGVAR(uavScanTime) {
        typeName = "SCALAR";
        value = 20;
    };
};

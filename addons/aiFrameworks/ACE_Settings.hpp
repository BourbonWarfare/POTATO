class ACE_Settings {
    /*   Master enable/disable   */
    class VGVAR(enabled) {
        typeName = "BOOL";
        value = 0;
    };

    /*   Granular bevhavior toggles   */
    class VGVAR(advancedSuppression) {
        typeName = "BOOL";
        value = 1;
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
    class VGVAR(increaseAccuracyOnStaticTargets) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(earsEnabled) {
        typeName = "BOOL";
        value = 1;
    };
    class VGVAR(loiteringEnabled) {
        typeName = "BOOL";
        value = 0;
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

    /*   AI distance settings   */
    class VGVAR(aiMutualSupportRange) {
        typeName = "SCALAR";
        value = 800;
    };
    class VGVAR(gunshotDetectionRange) {
        typeName = "SCALAR";
        value = 800;
    };
    class VGVAR(maxEngagementDistance) {
        typeName = "SCALAR";
        value = 1000;
    };
    class VGVAR(maxDistanceToMountEmptyStatic) {
        typeName = "SCALAR";
        value = 100;
    };
    class VGVAR(maxDistanceToGarrison) {
        typeName = "SCALAR";
        value = 200;
    };
    class VGVAR(maxDistanceToConsiderTargetStatic) {
        typeName = "SCALAR";
        value = 20;
    };
    class VGVAR(maxDistanceToSmoke) {
        typeName = "SCALAR";
        value = 1500;
    };
    class VGVAR(maxDistanceToBombBuilding) {
        typeName = "SCALAR";
        value = 200;
    };
    class VGVAR(maxDistanceToPlantMine) {
        typeName = "SCALAR";
        value = 2000;
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
        typeName = "SCALAR"
        value = 25;
    };
    class VGVAR(chanceToUseGrenade) {
        typeName = "SCALAR";
        value = 30;
    };
    class VGVAR(chanceToUseMine) {
        typeName = "SCALAR";
        value = 50;
    };

    /*   Side array settings   */
    class VGVAR(movementEnabledSides) {
        typeName = "ARRAY";
        value = {WEST,EAST,CIVILIAN,RESISTANCE};
    };
    class VGVAR(executionEnabledSides) {
        typeName = "ARRAY";
        value = {WEST,EAST,CIVILIAN,RESISTANCE};
    };

    /*   Operation Timeouts   */
    class VGVAR(artilleryThreshold) {
        typeName = "SCALAR";
        value = 120;
    };
    class VGVAR(moveCompletedThreshold) {
        typeName = "SCALAR";
        value = 10;
    };
    class VGVAR(grenadeThreshold) {
        typeName = "SCALAR";
        value = 20;
    };
    class VGVAR(movedRecentlyThreshold) {
        typeName = "SCALAR";
        value = 30;
    };
    class VGVAR(clearingThreshold) {
        typeName = "SCALAR";
        value = 30;
    };
    class VGVAR(flankThreshold) {
        typeName = "SCALAR";
        value = 300;
    };
    class VGVAR(formationChangeThreshold) {
        typeName = "SCALAR";
        value = 10;
    };
    class VGVAR(uavScanTime) {
        typeName = "SCALAR";
        value = 10;
    };
    class VGVAR(bombThreshold) {
        typeName = "SCALAR";
        value = 120;
    };
};

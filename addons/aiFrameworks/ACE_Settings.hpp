class ACE_Settings {
    /*   Master enable/disable   */
    class VGVAR(enabled) {
        typeName = "BOOL";
        value = 0;
    };

    /*   Granular bevhavior toggles   */
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

    /*   Chances of usage   */
    class VGVAR(chanceToUseGrenade) {
        typeName = "SCALAR";
        value = 20;
    };
    class VGVAR(chanceToUseMine) {
        typeName = "SCALAR";
        value = 40;
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
};

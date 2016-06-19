class ACE_Settings {
    class GVAR(groupAndUnitEnabled) {
        typeName = "BOOL";
        value = 0;
    };
    class GVAR(intraFireteamEnabled) {
        typeName = "BOOL";
        value = 0;
    };

    class GVAR(groupAndUnitUpdateDelay) {
        typeName = "SCALAR";
        value = 3;
    };

    class GVAR(viewBluForMarkers) {
        typeName = "ARRAY";
        value[] = {WEST};
    };
    class GVAR(viewOpForMarkers) {
        typeName = "ARRAY";
        value[] = {EAST};
    };
    class GVAR(viewIndyMarkers) {
        typeName = "ARRAY";
        value[] = {RESISTANCE};
    };
    class GVAR(viewCivMarkers) {
        typeName = "ARRAY";
        value[] = {CIVILIAN};
    };
};

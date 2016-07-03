class ACE_Settings {
    class GVAR(stHudMode) {
        category = "ST HUD";
        displayName = "ST HUD Mode";
        typeName = "SCALAR";
        value = 3;
        values[] = {"OFF", "HUD Only", "Names Only", "Normal"};
        isClientSettable = 1;
    };
    class GVAR(stHudCompass) {
        category = "ST HUD";
        displayName = "ST HUD Compass";
        typeName = "BOOL";
        value = 1;
        isClientSettable = 1;
    };
};

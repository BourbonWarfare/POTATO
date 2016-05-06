class ACE_Settings {
    class GVAR(showNotifcations) {
        category = QUOTE(PREFIX);
        displayName = "Potato: Show SystemChat Notifcations";
        description = "False should disable most Notifcations, can use to make clean recordings.";
        typeName = "BOOL";
        value = 1;
        isClientSettable = 1;
    };
    class GVAR(maxAICount) {
        typeName = "NUMBER";
        value = 90;
    };
    class GVAR(maxGroupCountPerSide) {
        typeName = "NUMBER";
        value = 140;
    };
};

class ACE_Settings {
    /* master on/off */
    class GVAR(enabled) {
        typeName = "BOOL";
        value = 0;
    };

    /* common channel config */
    class GVAR(addCommonChannelName) {
        typeName = "STRING";
        value = "Negotiations";
    };
    class GVAR(addCommonChannelNumber) {
        typeName = "SCALAR";
        value = 8;
    };
    class GVAR(addCommonChannelFreq) {
        typeName = "SCALAR";
        value = 90.75;
    };
    class GVAR(addCommonChannelAllMR) {
        typeName = "BOOL";
        value = 0;
    };
    class GVAR(addCommonChannelAllLR) {
        typeName = "BOOL";
        value = 0;
    };

    /* blufor specific settings */
    class GVAR(westPresetSR) {
        typeName = "STRING";
        value = "default2";
    };
    class GVAR(westPresetMR) {
        typeName = "STRING";
        value = "default2";
    };
    class GVAR(westPresetLR) {
        typeName = "STRING";
        value = "default2";
    };
    class GVAR(addCommonChannelWestMR) {
        typeName = "BOOL";
        value = 0;
    };
    class GVAR(addCommonChannelWestLR) {
        typeName = "BOOL";
        value = 0;
    };

    /* opfor specific settings */
    class GVAR(eastPresetSR) {
        typeName = "STRING";
        value = "default3";
    };
    class GVAR(eastPresetMR) {
        typeName = "STRING";
        value = "default3";
    };
    class GVAR(eastPresetLR) {
        typeName = "STRING";
        value = "default3";
    };
    class GVAR(addCommonChannelEastMR) {
        typeName = "BOOL";
        value = 0;
    };
    class GVAR(addCommonChannelEastLR) {
        typeName = "BOOL";
        value = 0;
    };

    /* indy specific settings */
    class GVAR(indyPresetSR) {
        typeName = "STRING";
        value = "default4";
    };
    class GVAR(indyPresetMR) {
        typeName = "STRING";
        value = "default4";
    };
    class GVAR(indyPresetLR) {
        typeName = "STRING";
        value = "default4";
    };
    class GVAR(addCommonChannelIndyMR) {
        typeName = "BOOL";
        value = 0;
    };
    class GVAR(addCommonChannelIndyLR) {
        typeName = "BOOL";
        value = 0;
    };

    /* civ specific settings */
    class GVAR(civPresetSR) {
        typeName = "STRING";
        value = "default";
    };
    class GVAR(civPresetMR) {
        typeName = "STRING";
        value = "default";
    };
    class GVAR(civPresetLR) {
        typeName = "STRING";
        value = "default";
    };
    class GVAR(addCommonChannelCivMR) {
        typeName = "BOOL";
        value = 0;
    };
    class GVAR(addCommonChannelCivLR) {
        typeName = "BOOL";
        value = 0;
    };
};

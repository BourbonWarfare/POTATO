class ACE_Settings {
    /* master on/off */
    class GVAR(enabled) {
        typeName = "BOOL";
        value = 0;
    };

    /* system settings */
    class GVAR(radioInterference) {
        typeName = "BOOL";
        value = 0;
    };
    class GVAR(omnidirectionalAntenna) {
        typeName = "BOOL";
        value = 1;
    };
    class GVAR(terrainInterference) {
        typeName = "SCALAR";
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
    class GVAR(westSRChannelNames) { // order matters, really only used for UI/Briefing
        typeName = "ARRAY";
        value[] = {"Alpha","Bravo","Charlie","Delta","Echo","Foxtrot","Empty","Empty","Empty","1st Platoon","2nd Platoon","COY","Air","Armor","Fire Support"};
    };
    class GVAR(westPresetMR) {
        typeName = "STRING";
        value = "default2";
    };
    class GVAR(westMRChannelNames) { // order matters
        typeName = "ARRAY";
        value[] = {"PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"};
    };
    class GVAR(westPresetLR) {
        typeName = "STRING";
        value = "default2";
    };
    class GVAR(westLRChannelNames) { // order matters
        typeName = "ARRAY";
        value[] = {"PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"};
    };
    class GVAR(westDefaultLanguages) { // language must be defined
        typeName = "ARRAY";
        value[] = {"en"};
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
    class GVAR(eastSRChannelNames) { // order matters, really only used for UI/Briefing
        typeName = "ARRAY";
        value[] = {"Alpha","Bravo","Charlie","Delta","Echo","Foxtrot","Empty","Empty","Empty","1st Platoon","2nd Platoon","COY","Air","Armor","Fire Support"};
    };
    class GVAR(eastPresetMR) {
        typeName = "STRING";
        value = "default3";
    };
    class GVAR(eastMRChannelNames) { // order matters
        typeName = "ARRAY";
        value[] = {"PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"};
    };
    class GVAR(eastPresetLR) {
        typeName = "STRING";
        value = "default3";
    };
    class GVAR(eastLRChannelNames) { // order matters
        typeName = "ARRAY";
        value[] = {"PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"};
    };
    class GVAR(eastDefaultLanguages) { // language must be defined
        typeName = "ARRAY";
        value[] = {"ru"};
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
    class GVAR(indySRChannelNames) { // order matters, really only used for UI/Briefing
        typeName = "ARRAY";
        value[] = {"Alpha","Bravo","Charlie","Delta","Echo","Foxtrot","Empty","Empty","Empty","1st Platoon","2nd Platoon","COY","Air","Armor","Fire Support"};
    };
    class GVAR(indyPresetMR) {
        typeName = "STRING";
        value = "default4";
    };
    class GVAR(indyMRChannelNames) { // order matters
        typeName = "ARRAY";
        value[] = {"PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"};
    };
    class GVAR(indyPresetLR) {
        typeName = "STRING";
        value = "default4";
    };
    class GVAR(indyLRChannelNames) { // order matters
        typeName = "ARRAY";
        value[] = {"PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"};
    };
    class GVAR(indyDefaultLanguages) { // language must be defined
        typeName = "ARRAY";
        value[] = {"ar"};
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
    class GVAR(civSRChannelNames) { // order matters, really only used for UI/Briefing
        typeName = "ARRAY";
        value[] = {"Alpha","Bravo","Charlie","Delta","Echo","Foxtrot","Empty","Empty","Empty","1st Platoon","2nd Platoon","COY","Air","Armor","Fire Support"};
    };
    class GVAR(civPresetMR) {
        typeName = "STRING";
        value = "default";
    };
    class GVAR(civMRChannelNames) { // order matters
        typeName = "ARRAY";
        value[] = {"PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"};
    };
    class GVAR(civPresetLR) {
        typeName = "STRING";
        value = "default";
    };
    class GVAR(civLRChannelNames) { // order matters
        typeName = "ARRAY";
        value[] = {"PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"};
    };
    class GVAR(civDefaultLanguages) { // language must be defined
        typeName = "ARRAY";
        value[] = {"ar"};
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

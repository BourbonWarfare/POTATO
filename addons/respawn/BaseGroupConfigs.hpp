// group configuration stubs
class Alpha {
    displayName = "";

    colorTeam1 = "YELLOW";
    colorTeam2 = "BLUE";
    colorTeam3 = "RED";
    colorTeam4 = "GREEN";

    markerPrefix = "A";
    markerText = "";
    markerColor[] = {0.9,0,0,1};
    markerTexture = QPATHTOEF(markers,data\infantry.paa);
    markerSize = 24;

    srChannel = 1;
    mrChannel = 1;
    lrChannel = 1;
};
class Bravo: Alpha {
    markerPrefix = "B";
    markerColor[] = {0,0,1,1};

    srChannel = 2;
};
class Charlie: Alpha {
    markerPrefix = "C";
    markerColor[] = {0,0.8,0,1};

    srChannel = 3;
};
class Delta: Alpha {
    markerPrefix = "D";

    srChannel = 5;
    mrChannel = 2;
    lrChannel = 2;
};
class Echo: Delta {
    markerPrefix = "E";
    markerColor[] = {0,0,1,1};

    srChannel = 6;
};
class Foxtrot: Delta {
    markerPrefix = "F";
    markerColor[] = {0,0.8,0,1};

    srChannel = 7;
};
class Golf: Alpha {
    markerPrefix = "G";

    srChannel = 9;
    mrChannel = 3;
    lrChannel = 3;
};
class Hotel: Golf {
    markerPrefix = "H";
    markerColor[] = {0,0,1,1};

    srChannel = 10;
};
class India: Golf {
    markerPrefix = "I";
    markerColor[] = {0,0.8,0,1};

    srChannel = 11;
};
class Weapons: Alpha {
    markerPrefix = "";
    markerColor[] = {1,0.647,0,1};

    srChannel = 16;
    mrChannel = 7;
    lrChannel = 4;
};
class Armor: Alpha {
    markerPrefix = "";
    markerTexture = QPATHTOEF(markers,data\armor.paa);
    markerSize = 32;

    srChannel = 15;
    mrChannel = 6;
    lrChannel = 4;
};
class Air: Armor {
    markerTexture = "";

    srChannel = 14;
    mrChannel = 5;
    lrChannel = 4;
};

// base units for inheritence
class BaseUnit {
    displayName = "Rifleman";
    type = "soldier_f";
    rank = "private";
    colorTeam = 0;
    leader = 0;

    markerText = "";
    markerTexture = "";
    markerColor[] = {0,0,0,0}; // <- same as no color, will be overriden by group cfg
    markerSize = 12;
};
class BaseSquadLead: BaseUnit {
    displayName = "Squad Leader";
    type = "soldier_sl_f";
    rank = "sergeant";
    leader = 1;

    markerText = "SL";
    markerTexture = QPATHTOEF(markers,data\hq.paa);
    markerSize = 24;
};
class BaseMedic: BaseUnit {
    displayName = "Medic";
    type = "medic_f";
    rank = "corporal";

    markerText = "M";
    markerColor[] = {1,0.753,0.796,1}; // color override, careful of inheritence
    markerTexture = QPATHTOEF(markers,data\medical.paa);
};

// base MSV units for inheritence
class BaseMSVUnit {
    displayName = "Rifleman";
    type = "rifleman";
    rank = "private";
    colorTeam = 0;
    leader = 0;

    markerText = "";
    markerTexture = "";
    markerColor[] = {0,0,0,0}; // <- same as no color, will be overriden by group cfg
    markerSize = 12;
};
class BaseMSVGunner: BaseMSVUnit {
    displayName = "Gunner";
    type = "vicc";
    rank = "corporal";
    colorTeam = 1;

    markerText = "V";
    markerTexture = QPATHTOEF(markers,data\mechanized_infantry.paa);
    markerSize = 36;
};
class BaseSeniorRifleman: BaseMSVUnit {
    displayName = "Senior Rifleman";
    type = "sr";
    rank = "corporal";

    markerText = "SR";
    markerTexture = QPATHTOEF(markers,data\infantry.paa);
};
class BaseMSVMedic: BaseMSVUnit {
    displayName = "Medic";
    type = "sm";
    rank = "corporal";
    colorTeam = 2;

    markerText = "M";
    markerColor[] = {1,0.753,0.796,1}; // color override, careful of inheritence
    markerTexture = QPATHTOEF(markers,data\medical.paa);
};

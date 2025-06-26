class CfgMagazines {

    // CUP Inheritances
    class CUP_M136_M;
    class CUP_M72A6_M;

    //// M136
    class MAGAZINE(AT4CS_RS): CUP_M136_M {
        author = "Potato";
        ammo = QAMMO(R_AT4CS_RS_HEAT);
        descriptionShort = "Range: 10m - 200m<br/>Type: HEDP<br/>Used in: AT4CS LMAW";
        displayName = "AT4CS-RS (HEAT) Rocket";
        initSpeed = 220;
        mass = 39.4;
    };
    class MAGAZINE(AT4CS_LMAW): CUP_M136_M {
        author = "Potato";
        ammo = QAMMO(R_AT4CS_LMAW_HEDP);
        descriptionShort = "Range: 10m - 200m<br/>Type: HEDP<br/>Used in: AT4CS LMAW";
        displayName = "AT4CS LMAW (HEDP) Rocket";
        displayNameShort = "$STR_CUP_DNS_HEDP_M";
        initSpeed = 235;
        mass = 39.4;
    };
    class MAGAZINE(AT4CS_HP): CUP_M136_M {
        author = "Potato";
        ammo = QAMMO(R_AT4CS_HP_HEAT);
        descriptionShort = "Range: 10m - 300m<br/>Type: HEAT<br/>Used in: AT4CS HP";
        displayName = "AT4CS HP (HEAT) Rocket";
        initSpeed = 220;
        mass = 57;
    };

    // M72A9 Anti structure Munition magazine
    class MAGAZINE(M72A7_M): CUP_M72A6_M {
        author = "Potato";
        ammo = QAMMO(R_M72A7_HEDP);
        descriptionShort = "Range: 0 - 350m<br/>Type: HEDP<br/>Used in: M72A7";
        displayName = "M72A7 (HEDP) Rocket";
        displayNameShort = "$STR_CUP_DNS_HEDP_M";
        initSpeed = 200;
        mass = 29.8;
    };
    class MAGAZINE(M72A8_M): MAGAZINE(M72A7_M) {
        ammo = QAMMO(R_M72A8_HEDP);
        descriptionShort = "Range: 25 - 350m<br/>Type: HEDP<br/>Used in: M72A8";
        displayname = "M72A8 (HEDP, FFE) Rocket";
        initSpeed = 166;
        mass = 62.8;
    };
    class MAGAZINE(M72A9_M): CUP_M72A6_M {
        author = "Potato";
        ammo = QAMMO(R_M72A9_HEDP);
        descriptionShort = "Range: 0 - 200 m<br/>Type: HEDP<br/>Used in: M72A9";
        displayName = "M72A9 (LASM) Rocket";
        displaynameshort = "$STR_CUP_DNS_NE_M";
        initSpeed = 130;
        mass = 47.4;
    };
    class MAGAZINE(M72A10_M): MAGAZINE(M72A9_M) {
        ammo = QAMMO(R_M72A10_HEDP);
        descriptionShort = "Range: 25 - 200m<br/>Type: HEDP<br/>Used in: M72A10";
        displayName = "M72A10 (LASM, FFE) Rocket";
        initSpeed = 108;
        mass = 80.4;
    };
};
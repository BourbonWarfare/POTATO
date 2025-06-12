class CfgMagazines {
    // Base Classes
    class CA_LauncherMagazine;

    // CUP Inheritances
    class CUP_M72A6_M: CA_LauncherMagazine {};

    // M72A9 HEDP magazine
    class MAGAZINE(M72A9_M): CUP_M72A6_M {
        scope = 2;
        author = "Potato";
        ammo = QAMMO(R_M72A9_HEDP);
        descriptionshort = "Range: 0 - 200 m<br/>Type: HEDP<br/>Used in: M72A9";
        displayname = "M72A9 (HEDP) Rocket";
        displaynameshort = "$STR_A3_HEAT_0"; // swap to HEDP?
    };
};
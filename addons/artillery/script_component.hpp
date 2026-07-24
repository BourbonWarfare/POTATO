#define COMPONENT artillery
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DRAW_SHOT_PLACEMENT
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_ADMINCOMS
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"

//// Potato Artillery Rounds
#define CREATE_AMMOS(parent) class parent;\
class GVARMAIN(DOUBLES(parent,noFrag)): parent {\
    ACEGVAR(frag,skip) = 1;\
};\
class GVARMAIN(DOUBLES(parent,noSplash)): GVARMAIN(DOUBLES(parent,noFrag)) {\
    indirectHit = 0;\
    indirectHitRange = 0;\
    hit = 8;\
}

#define CREATE_AMMOS_SUBMUNTION(parent,submuntion) CREATE_AMMOS(submuntion);\
class parent;\
class GVARMAIN(DOUBLES(parent,noFrag)): parent {\
    submunitionAmmo = QGVARMAIN(DOUBLES(submuntion,noFrag));\
};\
class GVARMAIN(DOUBLES(parent,noSplash)): GVARMAIN(DOUBLES(parent,noFrag)) {\
    submunitionAmmo = QGVARMAIN(DOUBLES(submuntion,noSplash));\
}

#define CREATE_MAGAZINES(baseMagazine,baseAmmo) class baseMagazine;\
class GVARMAIN(DOUBLES(baseMagazine,noFrag)): baseMagazine {\
    ammo = QGVARMAIN(DOUBLES(baseAmmo,noFrag));\
};\
class GVARMAIN(DOUBLES(baseMagazine,noSplash)): baseMagazine {\
    ammo = QGVARMAIN(DOUBLES(baseAmmo,noSplash));\
}

#define ADD_MAGAZINES_1_WEAPON(parentWeapon,weapon,magazineBase) class weapon: parentWeapon {\
    magazines[] += {QGVARMAIN(DOUBLES(magazineBase,noFrag)), QGVARMAIN(DOUBLES(magazineBase,noSplash))};\
}
#define MAGAZINE_PAIRS(base) QGVARMAIN(DOUBLES(base,noFrag)), QGVARMAIN(DOUBLES(base,noSplash))
#define ADD_MAGAZINES_2_WEAPON(parentWeapon,weapon,magazineBase0,magazineBase1) class weapon: parentWeapon {\
    magazines[] += {MAGAZINE_PAIRS(magazineBase0), MAGAZINE_PAIRS(magazineBase1)};\
}
#define ADD_MAGAZINES_3_WEAPON(parentWeapon,weapon,magazineBase0,magazineBase1,magazineBase2) class weapon: parentWeapon {\
    magazines[] += {MAGAZINE_PAIRS(magazineBase0), MAGAZINE_PAIRS(magazineBase1), MAGAZINE_PAIRS(magazineBase3)};\
}

//// Scripted Artillery
// Display
#define IDD_ARTILLERY_MENU 241011
#define IDC_ARTILLERY_GUUNCOUNT 2099
#define IDC_ARTILLERY_MISSIONTYPE 2100
#define IDC_ARTILLERY_ROUNDTYPE 2101
#define IDC_ARTILLERY_DISPERSION 1900
#define IDC_ARTILLERY_DISPERSIONTXT 1901
#define IDC_ARTILLERY_ROTATION 1902
#define IDC_ARTILLERY_ROTATIONTXT 1903
#define IDC_ARTILLERY_MISSIONGLENGTH 1904
#define IDC_ARTILLERY_MISSIONGLENGTHTXT 1905
#define IDC_ARTILLERY_MISSIONGDELAY 1906
#define IDC_ARTILLERY_MISSIONGDELAYTXT 1907
#define IDC_ARTILLERY_MISSIONGLENGTHTIME 1908
#define IDC_ARTILLERY_MISSIONGLENGTHTIMETXT 1909
#define IDC_ARTILLERY_AVOIDPLAYERS 2200
#define IDC_ARTILLERY_MAP 1200

//// Zeus and Editor modules
#define ARTILLERY_EDITOR_ROUND_ATTRIBUTE 260128
#define ARTILLERY_EDITOR_ROUND_LISTBOX 2300
#define ARTILLERY_EDITOR_ROUND_LEFTARROW 2301
#define ARTILLERY_EDITOR_ROUND_RIGHTARROW 2302

#include "script_macros.hpp"

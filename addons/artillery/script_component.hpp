#define COMPONENT artillery
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_ADMINCOMS
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define CREATE_AMMOS(parent) class parent;\
class GVARMAIN(DOUBLES(parent,noFrag)): parent {\
    ACEGVAR(frag,skip) = 1;\
};\
class GVARMAIN(DOUBLES(parent,noSplash)): GVARMAIN(DOUBLES(parent,noFrag)) {\
    indirectHit = 0;\
    indirectHitRange = 0;\
    hit = 1;\
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

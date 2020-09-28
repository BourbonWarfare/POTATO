class CfgVehicles {
    #include "subClasses\unitDef.hpp"
    // add POTATO USMC
    #define FACTION_MACRO(unit) MSV(unit)
    FACTION_DEF(SoldierEB,e);

    // add POTATO MSV
    #undef FACTION_MACRO
    #define FACTION_MACRO(unit) USMC(unit)
    FACTION_DEF(SoldierWB,w);

    // add POTATO Airborne
    #undef FACTION_MACRO
    #define FACTION_MACRO(unit) AIR(unit)
    FACTION_DEF(SoldierGB,i);

    // add POTATO MSV (Backwards Compat)
    #undef FACTION_MACRO
    #include "subClasses\bwc_msv.hpp"
};

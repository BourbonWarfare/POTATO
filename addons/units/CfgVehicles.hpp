class CfgVehicles {
    class CAManBase;
    #include "subClasses\unitDef.hpp"
    // add POTATO East
    #define FACTION_MACRO(unit) MSV(unit)
    FACTION_DEF(SoldierEB,e,2)

    // add POTATO MSV (Backwards Compat)
    #include "subClasses\bwc_msv.hpp"

    // add POTATO West
    #undef FACTION_MACRO
    #define FACTION_MACRO(unit) USMC(unit)
    FACTION_DEF(SoldierWB,w,2)

    // add POTATO Indy
    #undef FACTION_MACRO
    #define FACTION_MACRO(unit) AIR(unit)
    FACTION_DEF(SoldierGB,i,2)

};

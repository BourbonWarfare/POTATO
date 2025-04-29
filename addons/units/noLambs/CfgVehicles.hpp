class CfgVehicles {
    class CAManBase;
    #include "..\subClasses\unitDef.hpp"
    // add POTATO East
    #define FACTION_MACRO(unit) SIDE_NOLAMBS(unit,e)
    FACTION_DEF(SoldierEB,e,1)

    // add POTATO West
    #undef FACTION_MACRO
    #define FACTION_MACRO(unit) SIDE_NOLAMBS(unit,w)
    FACTION_DEF(SoldierWB,w,1)

    // add POTATO Indy
    #undef FACTION_MACRO
    #define FACTION_MACRO(unit) SIDE_NOLAMBS(unit,i)
    FACTION_DEF(SoldierGB,i,1)

};

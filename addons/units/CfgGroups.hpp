class CfgGroups {
    #include "groups\groupDef.hpp"
    #define CLASS_MACRO(unit) USMC(unit)
    GROUP_DEF(WEST,"Potato: West",w)

    #undef CLASS_MACRO
    #undef FACTION_LETTER
    #define CLASS_MACRO(unit) MSV(unit)
    GROUP_DEF(EAST,"Potato: East",e)

    #undef CLASS_MACRO
    #undef FACTION_LETTER
    #define CLASS_MACRO(unit) AIR(unit)
    GROUP_DEF(Indep,"Potato: Indy",i)
};

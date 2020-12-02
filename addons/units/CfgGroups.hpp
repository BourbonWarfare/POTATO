class CfgGroups {
  #include "groups\groupDef.hpp"
  #define CLASS_MACRO(unit) USMC(unit)
  GROUP_DEF(WEST,"POTATO: West",w,1)

  #undef CLASS_MACRO
  #undef FACTION_LETTER
  #define CLASS_MACRO(unit) MSV(unit)
  GROUP_DEF(East,"POTATO: East",e,0)
  
  #undef CLASS_MACRO
  #undef FACTION_LETTER
  #define CLASS_MACRO(unit) AIR(unit)
  GROUP_DEF(INDEP,"POTATO: Indy",i,2)
};

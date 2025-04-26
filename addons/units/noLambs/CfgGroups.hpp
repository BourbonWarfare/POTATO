class CfgGroups {
    #include "groupDef.hpp"
    #define CLASS_MACRO(unit) SIDE_NOLAMBS(unit,w)
    GROUP_DEF(WEST,"POTATO: West (No Lambs)",w,1)

    #undef CLASS_MACRO
    #define CLASS_MACRO(unit) SIDE_NOLAMBS(unit,e)
    GROUP_DEF(East,"POTATO: East (No Lambs)",e,0)

    #undef CLASS_MACRO
    #define CLASS_MACRO(unit) SIDE_NOLAMBS(unit,i)
    GROUP_DEF(INDEP,"POTATO: Indy (No Lambs)",i,2)
};

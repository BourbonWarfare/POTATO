#define COMPONENT aiFrameworks
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#ifdef DEBUG_ENABLED_AIFRAMEWORK
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_AIFRAMEWORK
    #define DEBUG_SETTINGS DEBUG_SETTINGS_AIFRAMEWORK
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define QUADS(var1,var2,var3,var4) ##var1##_##var2##_##var3##_##var4
#define V_PATHTO_SYS(var1,var2,var3) \MAINPREFIX\##var1\SUBPREFIX\##var2\vcom\functions\##var3.sqf

#define VFUNC(var) QUADS(ADDON,vcom,fnc,var)
#define VQFUNC(var) QUOTE(VFUNC(var))
#define VGVAR(var) TRIPLES(ADDON,vcom,var)
#define VQGVAR(var) QUOTE(VGVAR(var))

#ifdef DISABLE_COMPILE_CACHE
    #define VPREP(var) QUADS(ADDON,vcom,fnc,var) = compile preProcessFileLineNumbers 'V_PATHTO_SYS(PREFIX,COMPONENT_F,DOUBLES(fnc,var))'
#else
    #define VPREP(var) ['V_PATHTO_SYS(PREFIX,COMPONENT_F,DOUBLES(fnc,var))', 'QUADS(ADDON,vcom,fnc,var)'] call SLX_XEH_COMPILE_NEW
#endif

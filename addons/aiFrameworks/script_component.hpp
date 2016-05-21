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

#define VFUNC(var) FUNC(DOUBLES(vcom,var))
#define VQFUNC(var) QUOTE(VFUNC(var))
#define VGVAR(var) GVAR(DOUBLES(vcom,var))
#define VQGVAR(var) QUOTE(VGVAR(var))
#define VPREP(var) PREP(DOUBLES(vcom,var))

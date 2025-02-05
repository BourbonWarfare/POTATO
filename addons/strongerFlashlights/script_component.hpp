#define COMPONENT strongerFlashlights
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_STRONGER_FLASH_LIGHTS
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define GENERIC_CUP_ADAPTED_FLASHLIGHT_LMD(ENUM) QUOTE(DOUBLES(GVAR(acc_cup_Flashlight),ENUM)),\
QUOTE(TRIPLES(GVAR(acc_cup_Flashlight),ENUM,Spot)),\
QUOTE(TRIPLES(GVAR(acc_cup_Flashlight),ENUM,Wide))

#define COMPONENT safestart
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_SAFESTART
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_SAFESTART
    #define DEBUG_SETTINGS DEBUG_SETTINGS_SAFESTART
#endif

#define TIMER_LAYER "SafeStartTimerRscLayer"
#define START_LAYER "SafeStartStartingRscLayer"

#include "\z\potato\addons\core\script_macros.hpp"

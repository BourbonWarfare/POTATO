#define COMPONENT serverMonitor
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_SERVERMONITOR
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_SERVERMONITOR
    #define DEBUG_SETTINGS DEBUG_SETTINGS_SERVERMONITOR
#endif

#include "\z\potato\addons\core\script_macros.hpp"
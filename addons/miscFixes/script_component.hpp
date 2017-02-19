#define COMPONENT miscFixes
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_MISCFIXES
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MISCFIXES
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MISCFIXES
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define USMC(var) TRIPLES(PREFIX,usmc,var)
#define QUSMC(var) QUOTE(USMC(var))

#define MSV(var) TRIPLES(PREFIX,msv,var)
#define QMSV(var) QUOTE(MSV(var))

#define AIR(var) TRIPLES(PREFIX,airborne,var)
#define QAIR(var) QUOTE(AIR(var))

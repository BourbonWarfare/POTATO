#define COMPONENT units
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_UNITS
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define USMC(var) TRIPLES(PREFIX,w,var)
#define QUSMC(var) QUOTE(USMC(var))

#define MSV(var) TRIPLES(PREFIX,e,var)
#define QMSV(var) QUOTE(MSV(var))

#define AIR(var) TRIPLES(PREFIX,i,var)
#define QAIR(var) QUOTE(AIR(var))


#define BWC_MSV(var) TRIPLES(PREFIX,msv,var)
#define QBWC_MSV(var) QUOTE(MSV(var))

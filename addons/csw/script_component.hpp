#define COMPONENT csw
#define COMPONENT_BEAUTIFIED Crew-Served Weapons
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_CSW
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"


#define DISTANCE_FROM_GUN 1.5
#define RELATIVE_DIRECTION(direction) [DISTANCE_FROM_GUN, direction]


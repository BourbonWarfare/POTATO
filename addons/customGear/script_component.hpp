#define COMPONENT customGear
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_CUSTOMGEAR
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define AMMO(var1) DOUBLES(PREFIX,var1)
#define QAMMO(var1) QUOTE(AMMO(var1))
#define MAGAZINE(var1) DOUBLES(PREFIX,var1)
#define QMAGAZINE(var1) QUOTE(MAGAZINE(var1))
#define MAGWELL(var1) DOUBLES(PREFIX,var1)
#define QMAGWELL(var1) QUOTE(MAGWELL(var1))

#define MAGWELL_ENTRY_NAME DOUBLES(PREFIX,magazineWell)

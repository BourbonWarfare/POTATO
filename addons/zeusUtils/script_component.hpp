#define COMPONENT zeusUtils
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_ADMINCOMS
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define ZEUSUTILS_IDC_DISPLAYFPSBUTTON 241119
#define ZEUSUTILS_IDC_DISPLAYMARKERBUTTON 241120

#define ZEUSUTILS_DEH_INVALID -1
#define ZEUSUTILS_DEH_FPS      0
#define ZEUSUTILS_DEH_MARKERS  1

#define INFORM_USER(var1) systemChat QUOTE([POTATO][zeusUtils] var1)

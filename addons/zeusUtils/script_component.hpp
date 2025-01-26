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

#define INFORM_USER(var1) systemChat QUOTE([POTATO][zeusUtils] var1)

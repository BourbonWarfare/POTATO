#define COMPONENT adminComs
#include "\z\potato\addons\core\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
#define CBA_DEBUG_SYNCHRONOUS

#ifdef DEBUG_ENABLED_ADMINCOMS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_ADMINCOMS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_ADMINCOMS
#endif

#include "\z\potato\addons\core\script_macros.hpp"

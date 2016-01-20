#define COMPONENT safestart
#include "\z\potato\addons\core\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
#define CBA_DEBUG_SYNCHRONOUS

#ifdef DEBUG_ENABLED_SAFESTART
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_SAFESTART
    #define DEBUG_SETTINGS DEBUG_SETTINGS_SAFESTART
#endif

#include "\z\potato\addons\core\script_macros.hpp"
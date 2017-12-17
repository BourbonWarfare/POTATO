#define COMPONENT aiCfgFixes
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
 #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_AI_CFG_FIXES
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_AI_CFG_FIXES
    #define DEBUG_SETTINGS DEBUG_SETTINGS_AI_CFG_FIXES
#endif

#include "\z\potato\addons\core\script_macros.hpp"
#define LINE_BREAK toString[13,10]
#define INDENT "    "
#define CFG_FOOTER "};" + LINE_BREAK + LINE_BREAK
#define CFG_CLASS_DATA(dataName, data) INDENT + INDENT + dataName + " = " + str(data) + ";" + LINE_BREAK


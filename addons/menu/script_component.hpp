#define COMPONENT menu
#include "\z\potato\addons\core\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
#define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_MENU
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MENU
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MENU
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define MENU_DISPLAY (findDisplay 9999)

#ifdef DEBUG_MODE_FULL
    #define UITOOLTIP(CTRLCREATE,IDC) CTRLCREATE ctrlSetTooltip IDC
#else
    #define UITOOLTIP(CTRLCREATE,IDC)
#endif

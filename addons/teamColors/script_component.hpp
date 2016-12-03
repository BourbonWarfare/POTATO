#define COMPONENT teamColors
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_TEAMCOLORS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_TEAMCOLORS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_TEAMCOLORS
#endif

#define TEAM_COLOR_IDC 132030
#define TEAM_COLORS 'MAIN','RED','GREEN','BLUE','YELLOW'
#define TEAM_COLOR_STRINGS "$STR_TEAM_MAIN","$STR_TEAM_RED","$STR_TEAM_GREEN","$STR_TEAM_BLUE","$STR_TEAM_YELLOW"

#include "\z\potato\addons\core\script_macros.hpp"

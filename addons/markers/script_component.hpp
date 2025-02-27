#define COMPONENT markers
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DEBUG_MODE_DRAW_EH
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_MARKERS
    #undef DEBUG_MODE_FULL
    #define DEBUG_MODE_FULL
#endif

#define MARKER_SET_IDC 79899
#define MARKER_ICON_IDC 176983
#define MARKER_NAME_IDC 464271
#define MARKER_SIZE_IDC 578744
#define MARKER_COLOR_IDC 604448

#define MAP_IDC 51
#define GPS_IDC 101

#include "defaultMarkerDefines.hpp"

#define MARKER_DRAW_HASH_REFRESH_TIME 30

#include "\z\potato\addons\core\script_macros.hpp"

#define COMPONENT missionModules
#include "\z\potato\addons\core\script_mod.hpp"

#define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#ifdef DEBUG_ENABLED_MISSIONMODULES
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MISSIONMODULES
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MISSIONMODULES
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define COLOR_IDC 288066
#define ICON_IDC 709588

#define ICON_VALUES 'mil_dot_noShadow',\
'mil_box_noShadow',\
'mil_triangle_noShadow',\
'mil_circle_noShadow',\
'mil_unknown_noShadow',\
'mil_warning_noShadow',\
'mil_join_noShadow',\
'mil_pickup_noShadow',\
'mil_start_noShadow',\
'mil_end_noShadow',\
'mil_destroy_noShadow',\
'mil_ambush_nowShadow',\
'mil_arrow_noShadow',\
'mil_arrow2_noShadow',\
'mil_flag_noShadow',\
'mil_marker_noShadow',\
'mil_objective_noShadow'

#define COLOR_VALUES 'ColorBlack',\
'ColorRed',\
'ColorBrown',\
'ColorOrange',\
'ColorYellow',\
'ColorGreen',\
'ColorBlue',\
'ColorPink',\
'ColorCIV',\
'ColorWhite'

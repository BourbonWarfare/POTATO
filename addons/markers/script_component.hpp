#define COMPONENT markers
#include "\z\potato\addons\core\script_mod.hpp"

#define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#ifdef DEBUG_ENABLED_MARKERS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MARKERS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MARKERS
#endif

#define MAP_IDC 51
#define GPS_IDC 101

#define UNIT_MARKER_ICON "\A3\ui_f\data\map\markers\military\start_CA.paa"
#define UNIT_MARKER_SIZE 12

#define RED_ARRAY [0.9,0,0,1]
#define YELLOW_ARRAY [0.9,0.9,0,1]
#define GREEN_ARRAY [0,0.8,0,1]
#define BLUE_ARRAY [0,0,1,1]
#define WHITE_ARRAY [1,1,1,1]

#include "\z\potato\addons\core\script_macros.hpp"

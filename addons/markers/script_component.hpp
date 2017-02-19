#define COMPONENT markers
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_MARKERS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MARKERS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MARKERS
#endif

#define MARKER_SET_IDC 79899
#define MARKER_ICON_IDC 176983
#define MARKER_NAME_IDC 464271
#define MARKER_SIZE_IDC 578744
#define MARKER_COLOR_IDC 604448

#define MAP_IDC 51
#define GPS_IDC 101

#define RED_ARRAY [0.9,0,0,1]
#define YELLOW_ARRAY [0.9,0.9,0,1]
#define GREEN_ARRAY [0,0.8,0,1]
#define BLUE_ARRAY [0,0,1,1]
#define WHITE_ARRAY [1,1,1,1]
#define ORANGE_ARRAY [1,0.647,0,1]
#define BLACK_ARRAY [0,0,0,1]
#define PINK_ARRAY [1,0.753,0.796,1]

#define DEFAULT_MARKER_TEXT ""
#define DEFAULT_MARKER_ICON "\A3\ui_f\data\map\markers\nato\b_unknown.paa"
#define DEFAULT_MARKER_COLOR_TEXT "white"
#define DEFAULT_MARKER_COLOR WHITE_ARRAY
#define DEFAULT_MARKER_SIZE 24

#define UNIT_MARKER_ICON "\A3\ui_f\data\map\markers\military\start_CA.paa"
#define UNIT_MARKER_SIZE 12

#define UNIT_MARKERS '\A3\ui_f\data\map\markers\nato\b_unknown.paa',\
'\A3\ui_f\data\map\markers\nato\b_inf.paa',\
'\A3\ui_f\data\map\markers\nato\b_hq.paa',\
'\A3\ui_f\data\map\markers\nato\b_support.paa',\
'\A3\ui_f\data\map\markers\nato\b_motor_inf.paa',\
'\A3\ui_f\data\map\markers\nato\b_recon.paa',\
'\A3\ui_f\data\map\markers\nato\b_mortar.paa',\
'\A3\ui_f\data\map\markers\nato\b_maint.paa',\
'\A3\ui_f\data\map\markers\nato\b_mech_inf.paa',\
'\A3\ui_f\data\map\markers\nato\b_armor.paa',\
'\A3\ui_f\data\map\markers\nato\b_air.paa',\
'\A3\ui_f\data\map\markers\nato\b_plane.paa',\
'\A3\ui_f\data\map\markers\nato\b_art.paa',\
'\A3\ui_f\data\map\markers\nato\b_med.paa'

#define UNIT_MARKERS_STRINGS "\A3\ui_f\data\map\markers\nato\b_unknown.paa",\
"\A3\ui_f\data\map\markers\nato\b_inf.paa",\
"\A3\ui_f\data\map\markers\nato\b_hq.paa",\
"\A3\ui_f\data\map\markers\nato\b_support.paa",\
"\A3\ui_f\data\map\markers\nato\b_motor_inf.paa",\
"\A3\ui_f\data\map\markers\nato\b_recon.paa",\
"\A3\ui_f\data\map\markers\nato\b_mortar.paa",\
"\A3\ui_f\data\map\markers\nato\b_maint.paa",\
"\A3\ui_f\data\map\markers\nato\b_mech_inf.paa",\
"\A3\ui_f\data\map\markers\nato\b_armor.paa",\
"\A3\ui_f\data\map\markers\nato\b_air.paa",\
"\A3\ui_f\data\map\markers\nato\b_plane.paa",\
"\A3\ui_f\data\map\markers\nato\b_art.paa",\
"\A3\ui_f\data\map\markers\nato\b_med.paa"

#define UNIT_MARKER_SIZES 16,24,32
#define UNIT_MARKER_SIZES_STRINGS "Small","Medium","Large"

#define UNIT_MARKER_COLORS "white","red","blue","green","orange","yellow","pink","black"
#define UNIT_MARKER_COLORS_STRINGS "White","Red","Blue","Green","Orange","Yellow","Pink","Black"

#include "\z\potato\addons\core\script_macros.hpp"

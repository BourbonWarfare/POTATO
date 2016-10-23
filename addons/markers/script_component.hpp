#define COMPONENT markers
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS
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

#define RED_ARRAY [1,0,0,1]
#define YELLOW_ARRAY [1,1,0,1];
#define GREEN_ARRAY [0,0.8,0,1]
#define BLUE_ARRAY [0,0.69,0.921,1]
#define WHITE_ARRAY [1,1,1,1]
#define ORANGE_ARRAY [1,0.647,0,1]
#define BLACK_ARRAY [0,0,0,1]
#define PINK_ARRAY [1,0.753,0.796,1]
#define PURPLE_ARRAY [0.678,0,0.678,1]
#define GREY_ARRAY [0.8,0.8,0.8,1]

#define DEFAULT_MARKER_TEXT ""
#define DEFAULT_MARKER_ICON "\A3\ui_f\data\map\markers\nato\b_unknown.paa"
#define DEFAULT_MARKER_COLOR_TEXT "white"
#define DEFAULT_MARKER_COLOR WHITE_ARRAY
#define DEFAULT_MARKER_SIZE 24
#define INVISIBLE_TEXTURE "sc_mapmarkers\data\empty.paa"

#define UNIT_MARKERS '\A3\ui_f\data\map\markers\nato\b_unknown.paa',\
'sc_mapmarkers\data\company_hq.paa',\
'sc_mapmarkers\data\platoon_hq.paa',\
'sc_mapmarkers\data\squad_hq.paa',\
'sc_mapmarkers\data\fireteam.paa',\
'sc_mapmarkers\data\attachment.paa',\
'sc_mapmarkers\data\engineers.paa',\
'sc_mapmarkers\data\sam.paa',\
'sc_mapmarkers\data\scout.paa',\
'sc_mapmarkers\data\armored.paa',\
'sc_mapmarkers\data\rotarywing.paa',\
'sc_mapmarkers\data\fixedwing.paa',\
'sc_mapmarkers\data\mortar.paa',\
'sc_mapmarkers\data\u_jtac.paa',\
'sc_mapmarkers\data\u_xo.paa',\
'sc_mapmarkers\data\u_medic.paa'


#define UNIT_MARKERS_STRINGS "\A3\ui_f\data\map\markers\nato\b_unknown.paa",\
"sc_mapmarkers\data\company_hq.paa",\
"sc_mapmarkers\data\platoon_hq.paa",\
"sc_mapmarkers\data\squad_hq.paa",\
"sc_mapmarkers\data\fireteam.paa",\
"sc_mapmarkers\data\attachment.paa",\
"sc_mapmarkers\data\engineers.paa",\
"sc_mapmarkers\data\sam.paa",\
"sc_mapmarkers\data\scout.paa",\
"sc_mapmarkers\data\armored.paa",\
"sc_mapmarkers\data\rotarywing.paa",\
"sc_mapmarkers\data\fixedwing.paa",\
"sc_mapmarkers\data\mortar.paa",\
"sc_mapmarkers\data\u_jtac.paa",\
"sc_mapmarkers\data\u_xo.paa",\
"sc_mapmarkers\data\u_medic.paa"

#define UNIT_MARKER_SIZES 16,26,30,34,38
#define UNIT_MARKER_SIZES_STRINGS "Tiny","Small","Medium","Large","Huge"

#define UNIT_MARKER_COLORS "white","red","blue","green","orange","yellow","pink","black","purple","grey"
#define UNIT_MARKER_COLORS_STRINGS "White","Red","Blue","Green","Orange","Yellow","Pink","Black","Purple","Grey"

#include "\z\potato\addons\core\script_macros.hpp"

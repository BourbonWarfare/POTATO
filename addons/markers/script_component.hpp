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

#define COLOR_TO_MARKER_HASH [\
    [\
        QUOTE(RED_ARRAY),\
        QUOTE(YELLOW_ARRAY),\
        QUOTE(GREEN_ARRAY),\
        QUOTE(BLUE_ARRAY),\
        QUOTE(WHITE_ARRAY),\
        QUOTE(ORANGE_ARRAY),\
        QUOTE(BLACK_ARRAY),\
        QUOTE(PINK_ARRAY)\
    ], [\
        "Red",\
        "Yellow",\
        "Green",\
        "Blue",\
        "White",\
        "Yellow",\
        "Black",\
        "White"\
    ]\
]

#define DEFAULT_MARKER_TEXT ""
#define DEFAULT_MARKER_ICON QPATHTOF(data\unknown.paa)
#define DEFAULT_MARKER_COLOR_TEXT "white"
#define DEFAULT_MARKER_COLOR WHITE_ARRAY
#define DEFAULT_MARKER_SIZE 24

#define UNIT_MARKER_ICON "\A3\ui_f\data\map\markers\military\start_CA.paa"
#define UNIT_MARKER_SIZE 12

#define UNIT_MARKERS 'PATHTOF(data\unknown.paa)',\
'PATHTOF(data\infantry.paa)',\
'PATHTOF(data\motorized_infantry.paa)',\
'PATHTOF(data\mechanized_infantry.paa)',\
'PATHTOF(data\hq.paa)',\
'PATHTOF(data\mmg.paa)',\
'PATHTOF(data\mat.paa)',\
'PATHTOF(data\msam.paa)',\
'PATHTOF(data\mortar.paa)',\
'PATHTOF(data\engineer.paa)',\
'PATHTOF(data\maintenance.paa)',\
'PATHTOF(data\recon.paa)',\
'PATHTOF(data\support.paa)',\
'PATHTOF(data\medical.paa)',\
'PATHTOF(data\artillery.paa)',\
'PATHTOF(data\armor.paa)',\
'PATHTOF(data\helicopter.paa)',\
'PATHTOF(data\attack_helicopter.paa)',\
'PATHTOF(data\fixed_wing.paa)',\
'PATHTOF(data\attack_fixed_wing.paa)'

#define UNIT_MARKERS_STRINGS QPATHTOF(data\unknown.paa),\
QPATHTOF(data\infantry.paa),\
QPATHTOF(data\motorized_infantry.paa),\
QPATHTOF(data\mechanized_infantry.paa),\
QPATHTOF(data\hq.paa),\
QPATHTOF(data\mmg.paa),\
QPATHTOF(data\mat.paa),\
QPATHTOF(data\msam.paa),\
QPATHTOF(data\mortar.paa),\
QPATHTOF(data\engineer.paa),\
QPATHTOF(data\maintenance.paa),\
QPATHTOF(data\recon.paa),\
QPATHTOF(data\support.paa),\
QPATHTOF(data\medical.paa),\
QPATHTOF(data\artillery.paa),\
QPATHTOF(data\armor.paa),\
QPATHTOF(data\helicopter.paa),\
QPATHTOF(data\attack_helicopter.paa),\
QPATHTOF(data\fixed_wing.paa),\
QPATHTOF(data\attack_fixed_wing.paa)

#define UNIT_MARKER_SIZES 16,24,32
#define UNIT_MARKER_SIZES_STRINGS "Small","Medium","Large"

#define UNIT_MARKER_COLORS "white","red","blue","green","orange","yellow","pink","black"
#define UNIT_MARKER_COLORS_STRINGS "White","Red","Blue","Green","Orange","Yellow","Pink","Black"

#include "\z\potato\addons\core\script_macros.hpp"

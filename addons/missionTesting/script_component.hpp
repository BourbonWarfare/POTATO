#define COMPONENT missiontesting
#include "\z\potato\addons\core\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
#define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_MISSIONTESTING
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MISSIONTESTING
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MISSIONTESTING
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define TEXT_ORANGE [1,0.5,0,1]
#define TEXT_H_LARGE 0.06
#define TEXT_RED [1,0,0,1]
#define TEXT_BLUE [0,0.5,1,1]
#define A_PASSFAIL ["FAIL","PASS","NA"]
#define D_PASSFAIL 0
#define A_CHECK ["X","O"]
#define D_CHECK false
#define CHECK_TF [false,true]
#define D_NOTEFLAG 0
#define A_MISSION_TYPE ["COOP","TVT"]
#define MISSION_TYPE_APPLIES_BOTH 0
#define MISSION_TYPE_APPLIES_TVT 1
#define MISSION_TYPE_APPLIES_COOP 2
#define A_MISSION_TAGS ["None","NIGHT","DAWN","MSV","TvT1","TvT2","AH"]
#define S_NEWTEXTLINE _textArray pushBack format
#define S_NEWTEXTLINE_FORMATTEXT _textArray pushBack formattext
#define CGMAINFRAME 1
#define CGZBRIEFING 2
#define CGSBRIEFING 3
#define CGSPARE 4
#define CTRLHORZ 0
#define CTRLVERT 1
#define BBTRUE "[color=#00FF00]X[/color]"
#define BBFALSE "[color=#FF0000]O[/color]"
#define BBPASS "[color=#00FF00]PASS[/color]"
#define BBFAIL "[color=#FF0000]FAIL[/color]"
#define BBNA "[color=#FFFF00]Not Applicable[/color]"
#define CONTROL_SIZE_H 0.05
#define INCREMENT_YCOORD GVAR(yStartCoord) = GVAR(yStartCoord) + 0.01
#define INCREMENT_YCOORD_TEXT GVAR(yStartCoord) = GVAR(yStartCoord) + 0.06
#define LINE_W 0.81

#define DISPLAY_TESTMENU (findDisplay 9999)
#define CONTROL_GROUP_L_IDC 9991
#define CONTROL_GROUP_L DISPLAY_TESTMENU displayCtrl CONTROL_GROUP_L_IDC
#define CONTROL_GROUP_R_IDC 9992
#define CONTROL_GROUP_R DISPLAY_TESTMENU displayCtrl CONTROL_GROUP_R_IDC

#define DISPLAY_BRIEF (findDisplay 9998)
#define BRIEFINGS_GROUP_L_IDC 9993
#define BRIEFINGS_GROUP_L DISPLAY_BRIEF displayCtrl BRIEFINGS_GROUP_L_IDC
#define BRIEFINGS_GROUP_R_IDC 9994
#define BRIEFINGS_GROUP_R DISPLAY_BRIEF displayCtrl BRIEFINGS_GROUP_R_IDC

#define IDC_GENERAL 3000
#define IDC_CBITEMS 5000
#define IDC_PASSFAIL 6000
#define IDC_BREIFING 8000

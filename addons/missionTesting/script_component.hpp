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

// Default Values in Checklist
#define D_PASSFAIL 0
#define D_CHECK false
#define D_NOTEFLAG 0

// Array Defines
#define A_PASSFAIL ["FAIL","PASS","NA"]
#define A_CHECK ["X","O"]
#define A_YESNO ["No","Yes"]
#define A_CHECK_TF [false,true]
#define A_MISSION_TYPE ["BOTH","COOP","TVT"]
#define A_MISSION_TAGS ["NONE","NIGHT","DAWN","MSV","TvT1","TvT2","AH","FOG","BRIEF ON MAP"]

// BBCode Defines
#define BBNOTEFLAG_A ["","[size=85][i](Check notes in spoiler tag!!!)[/i][/size]"]
#define BBTRUE "[color=#00FF00]X[/color]"
#define BBFALSE "[color=#FF0000]O[/color]"
#define BBPASS "[color=#00FF00]PASS[/color]"
#define BBFAIL "[color=#FF0000]FAIL[/color]"
#define BBNA "[color=#FFFF00]Not Applicable[/color]"
#define BBPASSFAIL_A [BBFAIL,BBPASS,BBNA]

// Report Defines
#define S_NEWTEXTLINE _textArray pushBack format
#define S_NEWTEXTLINE_FORMATTEXT _textArray pushBack formattext
#define S_NEWTEXTLINE_SHORT _textArrayShort pushBack format
#define S_NEWTEXTLINE_FORMATTEXT_SHORT _textArrayShort pushBack formattext
#define MISSION_TYPE_APPLIES_BOTH 0
#define MISSION_TYPE_APPLIES_COOP 1
#define MISSION_TYPE_APPLIES_TVT 2

// Menu Defines
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

#define DISPLAY_PID (findDisplay 9997)
#define PID_SIDE_2_IDC 2100
#define PID_CLASS_2_IDC 2103
#define PID_STANCE_2_IDC 2106
#define PID_DIR_SLIDER_2_IDC 1900
#define PID_SIDE_1_IDC 2101
#define PID_CLASS_1_IDC 2104
#define PID_STANCE_1_IDC 2107
#define PID_DIR_SLIDER_1_IDC 1901
#define PID_SIDE_3_IDC 2102
#define PID_CLASS_3_IDC 2105
#define PID_STANCE_3_IDC 2108
#define PID_DIR_SLIDER_3_IDC 1902

#define PID_DEFAULT_DIR 0
#define PID_DEFAULT_FACTION 0
#define PID_DEFAULT_CLASS 0
#define PID_DEFAULT_STANCE_INDEX 0
#define PID_DEFAULT_STANCE "AidlPercMstpSrasWrflDnon_AI"
#define PID_STANCES [\
                        [QUOTE(Standing (Weapon Down)),QUOTE(AidlPercMstpSrasWrflDnon_AI)]\
                        ,[QUOTE(Standing (ADS)),QUOTE(AidlPercMstpSrasWrflDnon_G01_player)]\
                        ,[QUOTE(Crouch (Weapon Down)),QUOTE(AidlPknlMstpSrasWrflDnon_AI)]\
                        ,[QUOTE(Crouch (ADS)),QUOTE(AidlPknlMstpSrasWrflDnon_G01_player)]\
                        ,[QUOTE(Prone (ADS)),QUOTE(AidlPpneMstpSrasWrflDnon_G01_player)]\
                    ]\

#define IDC_GENERAL 3000
#define IDC_GENERAL_MT_NOTES 4000
#define IDC_CBITEMS 5000
#define IDC_PASSFAIL 6000
#define IDC_GENERATE_REPORT 7000
#define IDC_REPORT_L 7500
#define IDC_REPORT_S 7501
#define IDC_BREIFING 8000

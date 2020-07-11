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
#define TEXT_RED [1,0,0,1]
#define TEXT_BLUE [0,0.5,1,1]
#define A_PASSFAIL ["FAIL","PASS","NA"]
#define A_CHECK ["X","O"]
#define A_MISSION_TYPE ["COOP","TVT"]
#define A_MISSION_TAGS ["None","NIGHT","DAWN","MSV","TvT1","TvT2","AH"]
#define S_NEWTEXTLINE _textArray pushBack format
#define S_NEWTEXTLINE_FORMATTEXT _textArray pushBack formattext
#define MENU_DISPLAY (findDisplay 46)
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

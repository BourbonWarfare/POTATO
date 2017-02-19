#define COMPONENT fixPlayerCount
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE // do not turn off
#define CBA_DEBUG_SYNCHRONOUS // do not turn off

#ifdef DEBUG_ENABLED_FIX_PLAYER_COUNT
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_FIX_PLAYER_COUNT
    #define DEBUG_SETTINGS DEBUG_SETTINGS_RATIOS
#endif

// A3 display defines
#define SLOT_DISPLAY_IDD 70
#define SLOT_DISPLAY_NAME "RscDisplayMultiplayerSetup"
#define SLOT_DISPLAY (findDisplay SLOT_DISPLAY_IDD)

#define GET_CTRL(var1) (SLOT_DISPLAY displayCtrl var1)

#define PLAYER_LIST_IDC 114
#define PLAYER_LIST GET_CTRL(PLAYER_LIST_IDC)

#define OLD_PLAYER_DISPLAY_IDC 1015
#define OLD_PLAYER_DISPLAY GET_CTRL(OLD_PLAYER_DISPLAY_IDC)

#define PLAYER_DISPLAY_IDC 973574
#define PLAYER_DISPLAY GET_CTRL(PLAYER_DISPLAY_IDC)

#include "\z\potato\addons\core\script_macros.hpp"

#define SET_UI_VAR(var1,var2) (uiNamespace setVariable [QGVAR(var1), var2])
#define GET_UI_VAR(var1) (uiNamespace getVariable [QGVAR(var1), nil])

#define COMPONENT recruits
#include "\z\potato\addons\core\script_mod.hpp"

#define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_RECRUITS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_RECRUITS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_RECRUITS
#endif

#define MESSAGE_DISPLAY (uiNamespace getVariable [ARR_2(QGVAR(message),displayNull)])
#define MESSAGE_IDC 596868
#define MESSAGE_CONTROL (MESSAGE_DISPLAY displayCtrl MESSAGE_IDC)

#include "\z\potato\addons\core\script_macros.hpp"

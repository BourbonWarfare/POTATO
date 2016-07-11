#define COMPONENT radios
#include "\z\potato\addons\core\script_mod.hpp"

#define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#ifdef DEBUG_ENABLED_RADIOS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_RADIOS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_RADIOS
#endif

#include "\z\potato\addons\core\script_macros.hpp"

// ACRE functions
#define ACRE_FUNC(var1) DOUBLES(acre_api_fnc,var1)
#define ACRE_QFUNC(var1) QUOTE(DOUBLES(acre_api_fnc,var1))

// Display defines
#define RADIO_SET_IDC 413265
#define RADIO_CHOOSE_IDC 141722
#define RADIO_CHANNEL_IDC 958093

#define CFG_SIDE_IDC 200679
#define CFG_CHANNEL_IDC 394038
#define BABEL_LIST_IDC 464541

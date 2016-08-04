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

// Default values
#define RADIOS_ENABLED false
#define RADIO_INTERFERENCE false
#define TERRAIN_INTERFERENCE 0.5
#define COMMON_CHANNEL_NAME "Negotiations"
#define COMMON_CHANNEL_NUMBER 8
#define ADD_COMMON_CHANNEL_ALL_MR false
#define ADD_COMMON_CHANNEL_ALL_LR false

// Display defines
#define RADIO_SET_IDC 413265
#define RADIO_CHOOSE_IDC 141722
#define RADIO_CHANNEL_IDC 958093

#define CFG_SIDE_IDC 200679
#define CFG_CHANNEL_IDC 394038
#define CFG_SHARED_MR 164300
#define CFG_SHARED_LR 941575
#define BABEL_LIST_IDC 464541

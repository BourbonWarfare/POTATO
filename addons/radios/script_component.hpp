#define COMPONENT radios
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_ACRE_API
// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_RADIOS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_RADIOS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_RADIOS
#endif

#include "\z\potato\addons\core\script_macros.hpp"

// ACRE functions
#ifdef DEBUG_ACRE_API
    #define ACRE_FUNC(var1) {if (QUOTE(var1) != QUOTE(isInitialized)) then {INFO_2("API call %1 with %2", QUOTE(DOUBLES(acre_api_fnc,var1)), _this);}; _this call DOUBLES(acre_api_fnc,var1);}
    #define ACRE_QFUNC(var1) QUOTE(DOUBLES(acre_api_fnc,var1))
#else
    #define ACRE_FUNC(var1) DOUBLES(acre_api_fnc,var1)
    #define ACRE_QFUNC(var1) QUOTE(DOUBLES(acre_api_fnc,var1))
#endif

// Display defines
#define RADIO_SET_IDC 413265
#define RADIO_CHOOSE_IDC 141722
#define RADIO_CHANNEL_IDC 958093

#define BABEL_LIST_IDC 464541

#define CFG_S_SIDE_IDC 200679
#define CFG_S_CHANNEL_IDC 394038
#define CFG_S_SHARED_MR 164300
#define CFG_S_SHARED_LR 941575

#define CFG_G_SET_IDC 204468
#define CFG_G_CC_NAME_IDC 389742
#define CFG_G_CC_NUMBER_IDC 722725
#define CFG_G_CC_MR_IDC 974122
#define CFG_G_CC_LR_IDC 981063

// Radio Macros
#define RADIO_SR "ACRE_PRC343"
#define RADIO_MR "ACRE_PRC148"
#define RADIO_LR "ACRE_PRC117F"

#define RADIO_TX "frequencyTX"
#define RADIO_RX "frequencyRX"

#define WEST_SR "west343"
#define WEST_MR "west148"
#define WEST_LR "west117"

#define EAST_SR "east343"
#define EAST_MR "east148"
#define EAST_LR "east117"

#define INDY_SR "indy343"
#define INDY_MR "indy148"
#define INDY_LR "indy117"

#define CIV_SR "civ343"
#define CIV_MR "civ148"
#define CIV_LR "civ117"

// Default setting values
#define DEFAULT_ENABLED false

#define DEFAULT_SR_NAMES "Alpha","Bravo","Charlie","1st Platoon","Delta","Echo","Foxtrot","2nd Platoon","Golf","Hotel","India","3rd Platoon","COY","Air","Armor","Fire Support"
#define DEFAULT_MR_NAMES "PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"
#define DEFAULT_LR_NAMES "PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"

#define DEFAULT_COMMON_CH_NAME "Negotiations"
#define DEFAULT_COMMON_CH_NUM 8
#define DEFAULT_COMMON_CH_FREQ 90.75
#define DEFAULT_COMMON_CH_ENABLED false

#define DEFAULT_WEST_PRESET "default2"
#define DEFAULT_WEST_LANGS "en"

#define DEFAULT_EAST_PRESET "default3"
#define DEFAULT_EAST_LANGS "ru"

#define DEFAULT_INDY_PRESET "default4"
#define DEFAULT_INDY_LANGS "ar"

#define DEFAULT_CIV_PRESET "default"
#define DEFAULT_CIV_LANGS "en","ru","ar"

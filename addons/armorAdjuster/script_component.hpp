#define COMPONENT armorAdjuster
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define DEBUG_SYNCHRONOUS
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_ARMOR_MODIFIER_ACE
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_ARMOR_MODIFIER_ACE
    #define DEBUG_SETTINGS DEBUG_SETTINGS_ARMOR_MODIFIER_ACE
#endif

#include "\z\potato\addons\core\script_macros.hpp"
#define GETMVAR(var1,var2) (missionNamespace getVariable [ARR_2(var1,var2)])
#define SETMVAR(var1,var2,var3) (missionNamespace setVariable [ARR_3(var1,var2,var3)])

#define DEFAULT_SETTINGS [ARR_3(1,0,0)]
#define MINIMUM_SETTINGS [ARR_3(0.001,0,0)]
#define DEFAULT_HASH_SETTINGS createHashMapFromArray [["hithead",[1,0,0]],["hitdiaphragm",[1,0,0]],["hitleftarm",[1,0,0]],["hitleftleg",[1,0,0]],["hitneck",[1,0,0]],["hitpelvis",[1,0,0]],["hitrightleg",[1,0,0]],["hitchest",[1,0,0]],["hitabdomen",[1,0,0]],["hitrightarm",[1,0,0]],["hitface",[1,0,0]]]

#define DFUNC(var1) TRIPLES(ADDON,fnc,var1)

// #include "\z\ace\addons\medical_engine\script_component.hpp"
#define PRIORITY_HEAD       3
#define PRIORITY_BODY       4
#define PRIORITY_LEFT_ARM   (1 + random 1)
#define PRIORITY_RIGHT_ARM  (1 + random 1)
#define PRIORITY_LEFT_LEG   (1 + random 1)
#define PRIORITY_RIGHT_LEG  (1 + random 1)
#define PRIORITY_STRUCTURAL 1

#define GET_NUMBER(config,default) (if (isNumber (config)) then {getNumber (config)} else {default})

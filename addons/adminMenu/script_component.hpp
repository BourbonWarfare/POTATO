#define COMPONENT ADMINMENU
#include "\z\potato\addons\core\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
#define CBA_DEBUG_SYNCHRONOUS

#ifdef DEBUG_ENABLED_ADMINMENU
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_ADMINMENU
    #define DEBUG_SETTINGS DEBUG_SETTINGS_ADMINMENU
#endif

#include "\z\potato\addons\core\script_macros.hpp"


#define VERSION_STRING                "2015/10/28"
#define AUTHORIZED_USERS            ["76561197993419566", "76561197970715242","76561198087419490", "76561197997311964", "76561197985457597", "76561197988968579"]

#define UI_TAB_LISTBOX                ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 1500)
#define UI_TAB_ZEUS                    ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2300)
#define UI_TAB_ZEUS_PLAYERS            ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2100)
#define UI_TAB_SUPPLIES                ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2301)
#define UI_TAB_SUPPLIES_TYPE        ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2120)
#define UI_TAB_SUPPLIES_GROUP        ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2121)
#define UI_TAB_TELEPORT                ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2302)
#define UI_TAB_TELEPORT_PERSON        ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2130)
#define UI_TAB_TELEPORT_GROUP        ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2131)
#define UI_TAB_END                    ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2303)
#define UI_TAB_END_TEXT                ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 1100)
#define UI_TAB_END_UNLOCK             ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 1101)
#define UI_TAB_SAFESTART            ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2305)
#define UI_SERVER_MONITOR            ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 1102)
#define UI_TAB_CHECKMODS            ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2306)

#define UI_TABS_NAMES    ["Zeus",      "Supplies",     "End Mission", "Teleport",      "Safe Start",    "Verify Mods"]
#define UI_TABS_CONTROLS [UI_TAB_ZEUS, UI_TAB_SUPPLIES, UI_TAB_END,   UI_TAB_TELEPORT, UI_TAB_SAFESTART, UI_TAB_CHECKMODS]


//["classname", "optional description"]  - don't worry about what mods, will only show valid classnames
#define SUPPLIES_ARRAY                [["AGM_Box_Medical"], ["AGM_Box_Misc"], ["x39_medicBox"], ["TF_NATO_Radio_Crate"], ["TF_EAST_Radio_Crate"], ["TF_IND_Radio_Crate"], ["Box_NATO_Ammo_F"], ["Box_East_Ammo_F"], ["Box_IND_Ammo_F"], ["Box_mas_all_rifle_Wps_F"], ["Box_NATO_AmmoOrd_F"], ["HLC_AK_ammobox"], ["HLC_M14_ammobox"], ["C_Offroad_01_F"], ["I_MRAP_03_hmg_F"], ["B_MBT_01_TUSK_F"]]
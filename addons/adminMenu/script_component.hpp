#define COMPONENT adminMenu
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
#define UI_TAB_MISSIONHINT                ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 2307)
#define UI_TAB_MISSIONHINT_SIDE        ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 23071)
#define UI_TAB_MISSIONHINT_RANK        ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 23072)
#define UI_TAB_MISSIONHINT_TEXT       ((uiNamespace getVariable QGVAR(adminMenuDialog)) displayCtrl 23073)

#define UI_TABS_NAMES    ["Zeus",      "Supplies",     "End Mission", "Teleport",     "Safe Start",     "Tests",            "Send Hint"]
#define UI_TABS_CONTROLS [UI_TAB_ZEUS, UI_TAB_SUPPLIES, UI_TAB_END,   UI_TAB_TELEPORT, UI_TAB_SAFESTART, UI_TAB_CHECKMODS,  UI_TAB_MISSIONHINT]

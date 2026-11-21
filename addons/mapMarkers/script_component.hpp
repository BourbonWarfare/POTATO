#define COMPONENT mapMarkers
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#include "\z\potato\addons\core\script_macros.hpp"

// Recall markers dialog
#define IDD_RECALL_MARKERS_MAIN 261119
#define IDC_RECALL_MARKERS_LISTBOX 2000
#define IDC_RECALL_MARKERS_BUTTON_CLEAR 2100
#define IDC_RECALL_MARKERS_BUTTON_LOAD 2101
#define IDC_RECALL_MARKERS_BUTTON_SAVE 2102
#define IDC_RECALL_MARKERS_BUTTON_SAVEAS 2103
#define IDC_RECALL_MARKERS_BUTTON_DELETE 2104
// Generic confirm button
#define IDD_RECALL_MARKERS_CONFIRM 261120
#define IDC_RECALL_MARKERS_CONFIRM_TEXT 3019
#define CONFIRM_TEXT_CLEAR "Are you sure you want to clear all user map markers?"
#define CONFIRM_TEXT_LOAD "Are you sure you want to load ""%1""?"
#define CONFIRM_TEXT_SAVE_OVER "Are you sure you want to save over the existing save?"
#define CONFIRM_TEXT_DELETE "Are you sure you want to delete this save?"

// Save as button context
#define IDD_RECALL_MARKERS_SAVEAS 261121
#define IDC_RECALL_MARKERS_SAVEAS_TEXT 4018

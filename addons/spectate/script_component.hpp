#define COMPONENT spectate
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_SPECTATE
    #define DEBUG_MODE_FULL
#endif

#define XFACTOR (((safeZoneW / safeZoneH) min 1.2) / 40)
#define XOFFSET (safeZoneX + (safeZoneW - ((safeZoneW / safeZoneH) min 1.2)) / 2)
#define YFACTOR ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)
#define YOFFSET (safeZoneY + (safeZoneH - (((safeZoneW / safeZoneH) min 1.2) / 1.2)) / 2)

#define GLOBAL_CHANNEL_INDEX 0
#define SIDE_CHANNEL_INDEX 1
#define COMMAND_CHANNEL_INDEX 2
#define GROUP_CHANNEL_INDEX 3
#define VEHICLE_CHANNEL_INDEX 4
#define DIRECT_CHANNEL_INDEX 5

#define DISTANCE_NAMES 175.0
#define NAME_MAX_CHARACTERS 17

#define MAX_TRACKED_GRENADES 15
#define MAX_TRACKED_PROJECTILES 50
#define MAX_TRACKED_PROJECTILE_SEGMENTS 40

#define FIRE_HIGHLIGHT_TIME 0.05

#define ZERO_POS [ARR_3(0,0,0)]

#define FIRST_PERSON 0
#define THIRD_PERSON 1
#define FREE_CAMERA 2

#define SP_PAUSE_CLASS "RscDisplayInterrupt"
#define MP_PAUSE_CLASS "RscDisplayMPInterrupt"

#define CAM_ICON_FREE "a3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\FreeSelected.paa"
#define CAM_ICON_FREE_SELECTED "a3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\Free.paa"
#define CAM_ICON_THIRD "a3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\FollowSelected.paa"
#define CAM_ICON_THIRD_SELECTED "a3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\Follow.paa"
#define CAM_ICON_FIRST "a3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\FpsSelected.paa"
#define CAM_ICON_FIRST_SELECTED "a3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\Fps.paa"

#define MAIN_DISPLAY (findDisplay 46)

#define OVERLAY_IDD 726420
#define OVERLAY (findDisplay OVERLAY_IDD)

#define MOUSE_IDC 773650
#define MOUSE (OVERLAY displayCtrl MOUSE_IDC)

#define MENU_IDC 752880
#define MENU (OVERLAY displayCtrl MENU_IDC)

#define LIST_IDC 769790
#define LIST_CTR (OVERLAY displayCtrl LIST_IDC)

#define COMPASS_IDC 769795
#define COMPASS (OVERLAY displayCtrl COMPASS_IDC)

#define MAP_GROUP_IDC 735450
#define MAP_GROUP (OVERLAY displayCtrl MAP_GROUP_IDC)

#define MAP_IDC 735451
#define MAP_DISPLAY (OVERLAY displayCtrl MAP_IDC)

#define MAP_TITLE_IDC 735452
#define MAP_TITLE (OVERLAY displayCtrl MAP_TITLE_IDC)

#define MAP_SPEC_COUNT_IDC 735453
#define MAP_SPEC_COUNT (OVERLAY displayCtrl MAP_SPEC_COUNT_IDC)

#define MAP_FOOTER_IDC 735454
#define MAP_FOOTER (OVERLAY displayCtrl MAP_FOOTER_IDC)

#define MAP_HEADER_IDC 735455
#define MAP_HEADER (OVERLAY displayCtrl MAP_HEADER_IDC)

#define MAP_SPEC_ICON_IDC 735456
#define MAP_SPEC_ICON (OVERLAY displayCtrl MAP_SPEC_ICON_IDC)

#define FULL_MAP_IDC 735460
#define FULL_MAP (OVERLAY displayCtrl FULL_MAP_IDC)

#define CAM_GROUP_IDC 776270
#define CAM_GROUP (OVERLAY displayCtrl CAM_GROUP_IDC)

#define CAM_FREE_IDC 776271
#define CAM_FREE (OVERLAY displayCtrl CAM_FREE_IDC)

#define CAM_THIRD_IDC 776272
#define CAM_THIRD (OVERLAY displayCtrl CAM_THIRD_IDC)

#define CAM_FIRST_IDC 776273
#define CAM_FIRST (OVERLAY displayCtrl CAM_FIRST_IDC)

#define CAM_BG_IDC 776274
#define CAM_BG (OVERLAY displayCtrl CAM_BG_IDC)

#define TIMER_IDC 751824
#define TIMER (OVERLAY displayCtrl TIMER_IDC)

#define FOCUS_GROUP_IDC 734290
#define FOCUS_GROUP (OVERLAY displayCtrl FOCUS_GROUP_IDC)

#define FOCUS_UP_BG_IDC 734291
#define FOCUS_UP_BG (OVERLAY displayCtrl FOCUS_UP_BG_IDC)

#define FOCUS_DOWN_BG_IDC 734292
#define FOCUS_DOWN_BG (OVERLAY displayCtrl FOCUS_DOWN_BG_IDC)

#define FOCUS_VEHICLE_IDC 734293
#define FOCUS_VEHICLE (OVERLAY displayCtrl FOCUS_VEHICLE_IDC)

#define FOCUS_UNIT_IDC 734294
#define FOCUS_UNIT (OVERLAY displayCtrl FOCUS_UNIT_IDC)

#define FOCUS_NAME_IDC 734295
#define FOCUS_NAME (OVERLAY displayCtrl FOCUS_NAME_IDC)

#define FOCUS_KILL_IDC 734296
#define FOCUS_KILL (OVERLAY displayCtrl FOCUS_KILL_IDC)

#define FOCUS_KILL_CG_IDC 734297
#define FOCUS_KILL_CG (OVERLAY displayCtrl FOCUS_KILL_CG_IDC)

#define FOCUS_MEDICAL_GC_IDC 734298
#define FOCUS_MEDICAL_GC (OVERLAY displayCtrl FOCUS_MEDICAL_GC_IDC)

#define FOCUS_MEDICAL_HEAD_IDC 734299
#define FOCUS_MEDICAL_HEAD (OVERLAY displayCtrl FOCUS_MEDICAL_HEAD_IDC)

#define FOCUS_MEDICAL_TORSO_IDC 734300
#define FOCUS_MEDICAL_TORSO (OVERLAY displayCtrl FOCUS_MEDICAL_TORSO_IDC)

#define FOCUS_MEDICAL_LEFT_ARM_IDC 734301
#define FOCUS_MEDICAL_LEFT_ARM (OVERLAY displayCtrl FOCUS_MEDICAL_LEFT_ARM_IDC)

#define FOCUS_MEDICAL_RIGHT_ARM_IDC 734302
#define FOCUS_MEDICAL_RIGHT_ARM (OVERLAY displayCtrl FOCUS_MEDICAL_RIGHT_ARM_IDC)

#define FOCUS_MEDICAL_LEFT_LEG_IDC 734303
#define FOCUS_MEDICAL_LEFT_LEG (OVERLAY displayCtrl FOCUS_MEDICAL_LEFT_LEG_IDC)

#define FOCUS_MEDICAL_RIGHT_LEG_IDC 734304
#define FOCUS_MEDICAL_RIGHT_LEG (OVERLAY displayCtrl FOCUS_MEDICAL_RIGHT_LEG_IDC)

#define FOCUS_MEDICAL_BG_IDC 734305
#define FOCUS_MEDICAL_BG (OVERLAY displayCtrl FOCUS_MEDICAL_BG_IDC)

#define FOCUS_MEDICAL_RATIO_BLOOD_IDC 734306
#define FOCUS_MEDICAL_RATIO_BLOOD (OVERLAY displayCtrl FOCUS_MEDICAL_RATIO_BLOOD_IDC)

#define FOCUS_MEDICAL_RATIO_PAIN_IDC 734307
#define FOCUS_MEDICAL_RATIO_PAIN (OVERLAY displayCtrl FOCUS_MEDICAL_RATIO_PAIN_IDC)

#define FOCUS_MEDICAL_RATIO_PAINSUPPRESS_IDC 734308
#define FOCUS_MEDICAL_RATIO_PAINSUPPRESS (OVERLAY displayCtrl FOCUS_MEDICAL_RATIO_PAINSUPPRESS_IDC)

#define FOCUS_MEDICAL_INFO_HR_IDC 734309
#define FOCUS_MEDICAL_INFO_HR (OVERLAY displayCtrl FOCUS_MEDICAL_INFO_HR_IDC)

#define FOCUS_MEDICAL_INFO_WATCHES_IDC 734310
#define FOCUS_MEDICAL_INFO_WATCHES (OVERLAY displayCtrl FOCUS_MEDICAL_INFO_WATCHES_IDC)


#define BRIEFING_GROUP_IDC 751870
#define BRIEFING_GROUP (OVERLAY displayCtrl BRIEFING_GROUP_IDC)

#define BRIEFING_BG_IDC 751871
#define BRIEFING_BG (OVERLAY displayCtrl BRIEFING_BG_IDC)

#define BRIEFINGS_GROUP_IDC 751872
#define BRIEFINGS_GROUP (OVERLAY displayCtrl BRIEFINGS_GROUP_IDC)

#define RESPAWN_IDC 751885
#define RESPAWN (OVERLAY displayCtrl RESPAWN_IDC)

#define HELP_IDC 751886
#define HELP (OVERLAY displayCtrl HELP_IDC)
#define HELP_TEXT \
<t size='0.9'>Controls:<br/><br/></t>\
<t size='0.76'>\
'F1' to open/close this dialog<br/>\
'Space' to switch the current camera<br/>\
'Right Arrow' to switch focus to the next unit<br/>\
'Left Arrow' to switch focus to the previous unit<br/>\
'Backspace' to toggle the UI<br/>\
'Back Slash' to toggle the Tags<br/>\
Map toggle (default 'M') to open/close the full map<br/>\
GPS toggle (default 'Ctrl + M') to open/close the mini map<br/>\
Zero up (default 'Page Up') to increase client view distance<br/>\
Zero down (default 'Page Down') to decrease client view distance<br/>\
Night vision toggle (default 'N') to change image modes<br/>\
Open curator (default 'Y') to open the curator interface (if assigned)<br/>\
Light toggle (default 'L') to add local point lights<br/>\
Lock target (default 'T') to add bullet tracking<br/>\
Player stats (default 'P') to view the selected player's stats<br/>\
Get over (default 'V') to toggle camera speed at ground level<br/>\
Tasks/diary (default 'J') to open/close the briefings<br/>\
Compass (default 'K') to open/close the compass<br/>\
</t>

#include "\z\potato\addons\core\script_macros.hpp"

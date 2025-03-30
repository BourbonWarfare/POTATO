#define COMPONENT missionModules
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_MISSIONMODULES
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define COLOR_IDC 288066
#define ICON_IDC 709588

#define ICON_VALUES_STR "mil_dot_noShadow",\
"mil_box_noShadow",\
"mil_triangle_noShadow",\
"mil_circle_noShadow",\
"mil_unknown_noShadow",\
"mil_warning_noShadow",\
"mil_join_noShadow",\
"mil_pickup_noShadow",\
"mil_start_noShadow",\
"mil_end_noShadow",\
"mil_destroy_noShadow",\
"mil_ambush_nowShadow",\
"mil_arrow_noShadow",\
"mil_arrow2_noShadow",\
"mil_flag_noShadow",\
"mil_marker_noShadow",\
"mil_objective_noShadow"

#define ICON_VALUES 'mil_dot_noShadow',\
'mil_box_noShadow',\
'mil_triangle_noShadow',\
'mil_circle_noShadow',\
'mil_unknown_noShadow',\
'mil_warning_noShadow',\
'mil_join_noShadow',\
'mil_pickup_noShadow',\
'mil_start_noShadow',\
'mil_end_noShadow',\
'mil_destroy_noShadow',\
'mil_ambush_nowShadow',\
'mil_arrow_noShadow',\
'mil_arrow2_noShadow',\
'mil_flag_noShadow',\
'mil_marker_noShadow',\
'mil_objective_noShadow'

#define COLOR_VALUES_STR "ColorBlack",\
"ColorRed",\
"ColorBrown",\
"ColorOrange",\
"ColorYellow",\
"ColorGreen",\
"ColorBlue",\
"ColorPink",\
"ColorCIV",\
"ColorWhite"

#define COLOR_VALUES 'ColorBlack',\
'ColorRed',\
'ColorBrown',\
'ColorOrange',\
'ColorYellow',\
'ColorGreen',\
'ColorBlue',\
'ColorPink',\
'ColorCIV',\
'ColorWhite'

#define SET_SKILLS_IDD 751000
#define SET_SKILLS_MASTER_BX_IDC 751001
#define SET_SKILLS_AIM_ACC_MIN_SLIDER_IDC 751002
#define SET_SKILLS_AIM_ACC_MAX_SLIDER_IDC 751003
#define SET_SKILLS_AIM_SHK_MIN_SLIDER_IDC 751004
#define SET_SKILLS_AIM_SHK_MAX_SLIDER_IDC 751005
#define SET_SKILLS_AIM_SPD_MIN_SLIDER_IDC 751006
#define SET_SKILLS_AIM_SPD_MAX_SLIDER_IDC 751007
#define SET_SKILLS_CMDING_MIN_SLIDER_IDC 751008
#define SET_SKILLS_CMDING_MAX_SLIDER_IDC 751009
#define SET_SKILLS_CRG_MIN_SLIDER_IDC 751010
#define SET_SKILLS_CRG_MAX_SLIDER_IDC 751011
#define SET_SKILLS_GNRL_MIN_SLIDER_IDC 751012
#define SET_SKILLS_GNRL_MAX_SLIDER_IDC 751013
#define SET_SKILLS_RLD_SPD_MIN_SLIDER_IDC 751014
#define SET_SKILLS_RLD_SPD_MAX_SLIDER_IDC 751015
#define SET_SKILLS_SPT_DST_MIN_SLIDER_IDC 751016
#define SET_SKILLS_SPT_DST_MAX_SLIDER_IDC 751017
#define SET_SKILLS_SPT_TM_MIN_SLIDER_IDC 751018
#define SET_SKILLS_SPT_TM_MAX_SLIDER_IDC 751019
#define SET_SKILLS_AUTOCOMBAT_BX_IDC 751020
#define SET_SKILLS_COVER_BX_IDC 751021
#define SET_SKILLS_PATH_BX_IDC 751022
#define SET_SKILLS_SUPPRESSION_BX_IDC 751023

#define GET_CTRL(IDC) ((findDisplay 751000) displayCtrl IDC)

#define SUB_SKILLS [\
    ["general", GVAR(aiSkill_general_min), GVAR(aiSkill_general_max), SET_SKILLS_GNRL_MIN_SLIDER_IDC, SET_SKILLS_GNRL_MAX_SLIDER_IDC],\
    ["aimingAccuracy", GVAR(aiSkill_aimingAccuracy_min), GVAR(aiSkill_aimingAccuracy_max), SET_SKILLS_AIM_ACC_MIN_SLIDER_IDC, SET_SKILLS_AIM_ACC_MAX_SLIDER_IDC],\
    ["aimingShake", GVAR(aiSkill_aimingShake_min), GVAR(aiSkill_aimingShake_max), SET_SKILLS_AIM_SHK_MIN_SLIDER_IDC, SET_SKILLS_AIM_SHK_MAX_SLIDER_IDC],\
    ["aimingSpeed", GVAR(aiSkill_aimingSpeed_min), GVAR(aiSkill_aimingSpeed_max), SET_SKILLS_AIM_SPD_MIN_SLIDER_IDC, SET_SKILLS_AIM_SPD_MAX_SLIDER_IDC],\
    ["commanding", GVAR(aiSkill_commanding_min), GVAR(aiSkill_commanding_max), SET_SKILLS_CMDING_MIN_SLIDER_IDC, SET_SKILLS_CMDING_MAX_SLIDER_IDC],\
    ["courage", GVAR(aiSkill_courage_min), GVAR(aiSkill_courage_max), SET_SKILLS_CRG_MIN_SLIDER_IDC, SET_SKILLS_CRG_MAX_SLIDER_IDC],\
    ["reloadSpeed", GVAR(aiSkill_reloadSpeed_min), GVAR(aiSkill_reloadSpeed_max), SET_SKILLS_RLD_SPD_MIN_SLIDER_IDC, SET_SKILLS_RLD_SPD_MAX_SLIDER_IDC],\
    ["spotDistance", GVAR(aiSkill_spotDistance_min), GVAR(aiSkill_spotDistance_max), SET_SKILLS_SPT_DST_MIN_SLIDER_IDC, SET_SKILLS_SPT_DST_MAX_SLIDER_IDC],\
    ["spotTime", GVAR(aiSkill_spotTime_min), GVAR(aiSkill_spotTime_max), SET_SKILLS_SPT_TM_MIN_SLIDER_IDC, SET_SKILLS_SPT_TM_MAX_SLIDER_IDC]\
]

#define AI_BEHAVIORS [\
    ["AUTOCOMBAT", GVAR(aiSkill_AUTOCOMBAT), SET_SKILLS_AUTOCOMBAT_BX_IDC],\
    ["COVER", GVAR(aiSkill_COVER), SET_SKILLS_COVER_BX_IDC],\
    ["PATH", GVAR(aiSkill_PATH), SET_SKILLS_PATH_BX_IDC],\
    ["SUPPRESSION", GVAR(aiSkill_SUPPRESSION), SET_SKILLS_SUPPRESSION_BX_IDC]\
]

#define SAFESTART_MARKER_ALPHA 0.6
#define SAFESTART_MARKER_ALPHA_NOTSELECT 0.4
#define SAFESTART_TELEPORT_TIMER 10

#define LOADOUT_DIARY_TYPE_BOX 0
#define LOADOUT_DIARY_TYPE_VEHICLE 1
#define LOADOUT_DIARY_TYPE_BOXOFBOX 2

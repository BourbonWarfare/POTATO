#include "\z\potato\addons\seeding\script_macros.hpp"

#define BW_MAP_CLICK_HOLD_OFF 0.25
#define BW_TP_FLAG_TYPE GVAR(rallyObj)
#define BW_TP_FLAG_DIST 8.5
#define BW_AI_MAX_SPAWN 200
#define BW_UNIT_SPAWN_POS [12170,12190,0]
#define BW_IGNORE_GARRISON_BUILDINGS ["land_nav_pier_m_1","Land_Brana02nodoor","land_nav_pier_c_t20","land_nav_pier_M_fuel","Land_A_statue02","land_nav_pier_c_big","land_nav_pier_m_end","land_nav_pier_c2_end","Land_nav_pier_m_2","Land_Wall_CBrk_5_D", "Land_Wall_CGry_5_D", "Land_Stanek_1", "Land_Stanek_1B", "Land_Misc_Cargo1Eo_EP1", "Misc_Cargo1Bo_civil", "Land_Misc_Cargo1A_EP1", "Misc_Cargo1Bo_military"]

#define BW_FADE_CONTROL(display,var1,idc) var1 = display displayCtrl idc;\
var1 ctrlSetFade 0.8;\
var1 ctrlCommit 0.4
#define BW_DEFADE_CONTROL(display,var1,idc) var1 = display displayCtrl idc;\
var1 ctrlSetFade 0;\
var1 ctrlCommit 0.4
#define BW_MISSION_SET_DROPDOWN_DENSITY(display,control) control = display displayCtrl IDC_MISSION_DROPDOWN;\
control lbSetText [BW_TRAINING_DENSITY_RANDOM, "Random"];\
control lbSetText [BW_TRAINING_DENSITY_UNIFORM, "Uniform"];\
control lbSetText [BW_TRAINING_DENSITY_SINGLE, "Single Center"];\
control lbSetText [BW_TRAINING_DENSITY_SINGLEMARKED, "Single Center (Marked)"];\
control lbSetText [BW_TRAINING_DENSITY_MULTI, "Multiple Centers - Best for larger zones"];\
control lbSetText [BW_TRAINING_DENSITY_MULTIMARKED, "Multiple Centers (Marked) - Best for larger zones"]
#define BW_MISSION_SET_DROPDOWN_DENSITY_TEXT(display,control) control = display displayCtrl IDC_MISSION_DROPDOWN_TEXT;\
control ctrlSetText "Enemy Dispersion"
#define BW_MISSION_SET_DROPDOWN_DRAWTYPE(display,control) control = display displayCtrl IDC_MISSION_DROPDOWN;\
control lbSetText [BW_TRAINING_DENSITY_RANDOM, "Circle - Center-Radius"];\
control lbSetText [BW_TRAINING_DENSITY_UNIFORM, "Ellipse - Corner-Corner"];\
control lbSetText [BW_TRAINING_DENSITY_SINGLE, "Ellipse - Center-Corner"];\
control lbSetText [BW_TRAINING_DENSITY_SINGLEMARKED, "Rectangle - Center-Corner"];\
control lbSetText [BW_TRAINING_DENSITY_MULTI, "Rectangle - Corner-Corner"];\
control lbSetText [BW_TRAINING_DENSITY_MULTIMARKED, "-"]
#define BW_MISSION_SET_DROPDOWN_DRAWTYPE_TEXT(display,control) control = display displayCtrl IDC_MISSION_DROPDOWN_TEXT;\
control ctrlSetText "Zone Draw Method"
#define BW_MISSION_SET_OPTIONS_DEFAULT(display,control) control = display displayCtrl IDC_MISSION_OPTION0_TEXT;\
control ctrlSetText "Min Units Per Building: 2";\
control = display displayCtrl IDC_MISSION_OPTION0;\
control sliderSetRange [0.25, 1];\
control sliderSetPosition 0.5;\
SET_MENU_OPTION(option0,0.5);\
control = display displayCtrl IDC_MISSION_OPTION1_TEXT;\
control ctrlSetText "Max Units: 100";\
control = display displayCtrl IDC_MISSION_OPTION1;\
control sliderSetRange [0.1, 1];\
control sliderSetPosition 0.5;\
SET_MENU_OPTION(option1,0.5);\
control = display displayCtrl IDC_MISSION_OPTION2_TEXT;\
control ctrlSetText "Chance to de-Garrison";\
control = display displayCtrl IDC_MISSION_OPTION2;\
control sliderSetRange [0,1];\
control sliderSetPosition 0;\
SET_MENU_OPTION(option2,0);\
control = display displayCtrl IDC_MISSION_OPTION3_TEXT;\
control ctrlSetText "Patrol Count";\
control = display displayCtrl IDC_MISSION_OPTION3;\
control sliderSetRange [0,1];\
control sliderSetPosition 0;\
SET_MENU_OPTION(option3,0);\
control = display displayCtrl IDC_MISSION_OPTION4_TEXT;\
control ctrlSetText "Average Patrol Size";\
control = display displayCtrl IDC_MISSION_OPTION4;\
control sliderSetRange [0,1];\
control sliderSetPosition 0;\
SET_MENU_OPTION(option4,0)
#define BW_MISSION_SET_OPTIONS_DEFEND(display,control) control = display displayCtrl IDC_MISSION_OPTION0_TEXT;\
control ctrlSetText "Max Spawn Radius: 500m";\
control = display displayCtrl IDC_MISSION_OPTION0;\
control sliderSetRange [200, 2500];\
control sliderSetPosition 500;\
SET_MENU_OPTION(option0,500);\
control = display displayCtrl IDC_MISSION_OPTION1_TEXT;\
control ctrlSetText "Units per Player: 9";\
control = display displayCtrl IDC_MISSION_OPTION1;\
control sliderSetRange [8, 15];\
control sliderSetPosition 9;\
SET_MENU_OPTION(option1,9);\
control = display displayCtrl IDC_MISSION_OPTION2_TEXT;\
control ctrlSetText "Defense Length: 1800s";\
control = display displayCtrl IDC_MISSION_OPTION2;\
control sliderSetRange [600,3600];\
control sliderSetPosition 1800;\
SET_MENU_OPTION(option2,900);\
control = display displayCtrl IDC_MISSION_OPTION3_TEXT;\
control ctrlSetText "Approach Arc 1: -180";\
control = display displayCtrl IDC_MISSION_OPTION3;\
control sliderSetRange [-360,360];\
control sliderSetPosition -180;\
SET_MENU_OPTION(option3,-180);\
control = display displayCtrl IDC_MISSION_OPTION4_TEXT;\
control ctrlSetText "Approach Arc 2: 180";\
control = display displayCtrl IDC_MISSION_OPTION4;\
control sliderSetRange [-360,360];\
control sliderSetPosition 180;\
SET_MENU_OPTION(option4,180)

/// Menu defines
// IDD Define
#define IDD_MISSION_MENU 241107

// IDCs numbers
#define IDC_MISSION_OPERATIONTYPE 900
#define IDC_MISSION_ENEMYTYPE 901
#define IDC_MISSION_MAP 1200
#define IDC_MISSION_AISKILLMIN 902
#define IDC_MISSION_AISKILLMAX 903
#define IDC_MISSION_DROPDOWN  904
#define IDC_MISSION_DROPDOWN_TEXT  804
#define IDC_MISSION_OPTION0 905
#define IDC_MISSION_OPTION0_TEXT 805
#define IDC_MISSION_OPTION1 906
#define IDC_MISSION_OPTION1_TEXT 806
#define IDC_MISSION_OPTION2 907
#define IDC_MISSION_OPTION2_TEXT 807
#define IDC_MISSION_OPTION3 908
#define IDC_MISSION_OPTION3_TEXT 808
#define IDC_MISSION_OPTION4 909
#define IDC_MISSION_OPTION4_TEXT 809
#define IDC_MISSION_OPTION5 910
#define IDC_MISSION_OPTION5_TEXT 810
#define IDC_MISSION_OPTION6 911
#define IDC_MISSION_OPTION6_TEXT 811
#define IDC_MISSION_RANDOM 912
#define IDC_MISSION_RANDOM_TEXT 812

// Spawn Zones
#define BW_MOUT_MAX_CHECK 15
#define BW_MOUT_BASE_STRING "moutPos_"
#define BW_ZONE_MAX_CHECK 100
#define BW_ZONE_BASE_STRING "clearableZone_"

// Operation Types
#define BW_TRAINING_OPERATION_MOUT 0
#define BW_TRAINING_OPERATION_ZONE 1
#define BW_TRAINING_OPERATION_ZONE_DRAW 2
#define BW_TRAINING_OPERATION_DEFEND 3
#define BW_TRAINING_OPERATION_MECH 4

// Enemy Types
#define BW_TRAINING_ENEMY_OPFOR 0
#define BW_TRAINING_ENEMY_INDY  1

// Enemy Density
#define BW_TRAINING_DENSITY_RANDOM 0
#define BW_TRAINING_DENSITY_UNIFORM 1
#define BW_TRAINING_DENSITY_SINGLE 2
#define BW_TRAINING_DENSITY_SINGLEMARKED 3
#define BW_TRAINING_DENSITY_MULTI 4
#define BW_TRAINING_DENSITY_MULTIMARKED 5

// Menu Hash accessors
#define GET_MENU_OPTION(var1) (GVAR(menuOptions) get QUOTE(var1))
#define SET_MENU_OPTION(var1,var2) (GVAR(menuOptions) set [ARR_2(QUOTE(var1),var2)])

/// Vehicle Spawner Vehicles
#define SPAWN_HELI_OBJ "Land_HelipadCircle_F"
#define SPAWN_PLANE_OBJ "Land_HelipadEmpty_F"

// Menu update w/ accessor
#define BW_MISSION_SET_MOUT_TEXT(display,control) control = display displayCtrl IDC_MISSION_OPTION0_TEXT;\
control ctrlSetText format ["Min Units Per Building: %1", round (4 * GET_MENU_OPTION(option0))]
#define BW_MISSION_SET_ZONE_TEXT(display,control) BW_MISSION_SET_MOUT_TEXT(display,control)

// Circle Spawn Menu Defines
#define IDD_CIRCLESPAWN_MENU 250527
#define IDC_CIRCLESPAWN_MAP 4000
#define IDC_CIRCLESPAWN_RAD 4100
#define IDC_CIRCLESPAWN_RAD_TEXT 4101
#define IDC_CIRCLESPAWN_LENGTH 4102
#define IDC_CIRCLESPAWN_LENGTH_TEXT 4103
#define IDC_CIRCLESPAWN_CNT 4104
#define IDC_CIRCLESPAWN_CNT_TEXT 4105
#define IDC_CIRCLESPAWN_MIN 4106
#define IDC_CIRCLESPAWN_MIN_TEXT 4107
#define IDC_CIRCLESPAWN_MAX 4108
#define IDC_CIRCLESPAWN_MAX_TEXT 4109
#define IDC_CIRCLESPAWN_PRD 4110
#define IDC_CIRCLESPAWN_PRD_TEXT 4111

#define CIRCLESPAWN_PARAM_LNGTH_PARAM_RAD 0
#define CIRCLESPAWN_PARAM_LNGTH_PARAM_LNGTH 1
#define CIRCLESPAWN_PARAM_UNIT_PARAM_CNT 2
#define CIRCLESPAWN_PARAM_UNIT_PARAM_MIN 3
#define CIRCLESPAWN_PARAM_UNIT_PARAM_MAX 4
#define CIRCLESPAWN_PARAM_UNIT_PARAM_PRD 5

#define CIRCLESPAWN_VIC_STARTING 1.177
#define CIRCLESPAWN_VIC_DECAY 0.984
#define CIRCLESPAWN_VIC_END_RATE 0.7

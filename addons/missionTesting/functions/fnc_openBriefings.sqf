/*
 * Author: BadWolf
 * Function is called by a button in the testing menu to view the Breifings for all sides.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_openBriefings;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [""];

createDialog GVAR(displayBreifings);

private _ctrlBackground = DISPLAY_BRIEF ctrlCreate [QUOTE(RscBackgroundGUI),-1];
_ctrlBackground ctrlSetPosition [0,0,1,1];
_ctrlBackground ctrlCommit 0;
private _leftFrame = DISPLAY_BRIEF ctrlCreate [QUOTE(RscFrame),-1];
_leftFrame ctrlSetPosition [0,0.05,0.35,0.95];
_leftFrame ctrlCommit 0;
private _rightFrame = DISPLAY_BRIEF ctrlCreate [QUOTE(RscFrame),-1];
_rightFrame ctrlSetPosition [0.5,0.05,0.35,0.95];
_rightFrame ctrlCommit 0;
private _leftGroup = DISPLAY_BRIEF ctrlCreate [QUOTE(RscControlsGroup),BRIEFINGS_GROUP_L];
_leftGroup ctrlSetPosition [0,0.05,0.65,0.95];
_leftGroup ctrlCommit 0;
private _rightGroup = DISPLAY_BRIEF ctrlCreate [QUOTE(RscControlsGroup),BRIEFINGS_GROUP_R];
_rightGroup ctrlSetPosition [0.6,0.05,0.35,0.95];
_rightGroup ctrlCommit 0;
private _westButton = DISPLAY_BRIEF ctrlCreate [QUOTE(RscButton),-1];
_westButton setText "WEST";
_westButton ctrlSetPosition [0,0,0.25,0.05];
_westButton buttonSetAction QUOTE([0] call FUNC(briefingsSideChanged));
_westButton ctrlCommit 0;
private _eastButton = DISPLAY_BRIEF ctrlCreate [QUOTE(RscButton),-1];
_eastButton setText "EAST";
_eastButton ctrlSetPosition [0.25,0,0.25,0.05];
_eastButton buttonSetAction QUOTE([1] call FUNC(briefingsSideChanged));
_eastButton ctrlCommit 0;
private _indyButton = DISPLAY_BRIEF ctrlCreate [QUOTE(RscButton),-1];
_indyButton setText "INDY";
_indyButton ctrlSetPosition [0.5,0,0.25,0.05];
_indyButton buttonSetAction QUOTE([2] call FUNC(briefingsSideChanged));
_indyButton ctrlCommit 0;
private _civiButton = DISPLAY_BRIEF ctrlCreate [QUOTE(RscButton),-1];
_civiButton setText "CIVI";
_civiButton ctrlSetPosition [0.75,0,0.25,0.05];
_civiButton buttonSetAction QUOTE([3] call FUNC(briefingsSideChanged));
_civiButton ctrlCommit 0;
private _menuCancel = DISPLAY_BRIEF ctrlCreate [QUOTE(RscButtonMenuCancel),-1];
_menuCancel ctrlSetText "Close";
_menuCancel ctrlSetPosition [0.73,1,0.12,0.1];
_menuCancel buttonSetAction "closeDialog 2;";
_menuCancel ctrlCommit 0;

[0] call FUNC(briefingsSideChanged);

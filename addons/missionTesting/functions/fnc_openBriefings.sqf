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

private _display = DISPLAY_TESTMENU createDisplay QGVAR(displayBreifings);

if (isNull DISPLAY_BRIEF) exitWith { systemChat "bad display"; };

private _ctrlBackground = _display ctrlCreate [QUOTE(RscBackgroundGUI),-1];
_ctrlBackground ctrlSetPosition [0,0,1,1];
_ctrlBackground ctrlCommit 0;
private _leftFrame = _display ctrlCreate [QUOTE(RscFrame),-1];
_leftFrame ctrlSetPosition [0,0.05,0.65,0.95];
_leftFrame ctrlCommit 0;
private _rightFrame = _display ctrlCreate [QUOTE(RscFrame),-1];
_rightFrame ctrlSetPosition [0.65,0.05,0.35,0.95];
_rightFrame ctrlCommit 0;
private _leftGroup = _display ctrlCreate [QUOTE(RscControlsGroup),BRIEFINGS_GROUP_L_IDC];
_leftGroup ctrlSetPosition [0,0.05,0.65,0.95];
_leftGroup ctrlCommit 0;
private _rightGroup = _display ctrlCreate [QUOTE(RscControlsGroup),BRIEFINGS_GROUP_R_IDC];
_rightGroup ctrlSetPosition [0.65,0.05,0.35,0.9];
_rightGroup ctrlCommit 0;
private _westButton = _display ctrlCreate [QUOTE(RscButtonMenu),-1];
_westButton ctrlSetText "WEST";
_westButton ctrlSetPosition [0,0,0.2,0.05];
_westButton buttonSetAction QUOTE([0] call FUNC(briefingsChangeSide));
_westButton ctrlCommit 0;
private _eastButton = _display ctrlCreate [QUOTE(RscButtonMenu),-1];
_eastButton ctrlSetText "EAST";
_eastButton ctrlSetPosition [0.25,0,0.2,0.05];
_eastButton buttonSetAction QUOTE([1] call FUNC(briefingsChangeSide));
_eastButton ctrlCommit 0;
private _indyButton = _display ctrlCreate [QUOTE(RscButtonMenu),-1];
_indyButton ctrlSetText "INDY";
_indyButton ctrlSetPosition [0.5,0,0.2,0.05];
_indyButton buttonSetAction QUOTE([2] call FUNC(briefingsChangeSide));
_indyButton ctrlCommit 0;
private _civiButton = _display ctrlCreate [QUOTE(RscButtonMenu),-1];
_civiButton ctrlSetText "CIVI";
_civiButton ctrlSetPosition [0.75,0,0.2,0.05];
_civiButton buttonSetAction QUOTE([3] call FUNC(briefingsChangeSide));
_civiButton ctrlCommit 0;
private _menuCancel = _display ctrlCreate [QUOTE(RscButtonMenuCancel),-1];
_menuCancel ctrlSetText "Close";
_menuCancel ctrlSetPosition [0.73,1,0.12,0.1];
_menuCancel buttonSetAction "closeDialog 2;";
_menuCancel ctrlCommit 0;
private _ctrlCreateZeuzIntentTitle = DISPLAY_BRIEF ctrlCreate [QUOTE(RscText),IDC_BREIFING + 0,BRIEFINGS_GROUP_L];
private _ctrlCreateZeuzIntentText = DISPLAY_BRIEF ctrlCreate [QUOTE(RscStructuredText),IDC_BREIFING + 1,BRIEFINGS_GROUP_L];
private _ctrlCreateSituationTitle = DISPLAY_BRIEF ctrlCreate [QUOTE(RscText),IDC_BREIFING + 2,BRIEFINGS_GROUP_L];
private _ctrlCreateSituationText = DISPLAY_BRIEF ctrlCreate [QUOTE(RscStructuredText),IDC_BREIFING + 3,BRIEFINGS_GROUP_L];
private _ctrlCreateMissionTitle = DISPLAY_BRIEF ctrlCreate [QUOTE(RscText),IDC_BREIFING + 4,BRIEFINGS_GROUP_L];
private _ctrlCreateMissionText= DISPLAY_BRIEF ctrlCreate [QUOTE(RscStructuredText),IDC_BREIFING + 5,BRIEFINGS_GROUP_L];
private _ctrlCreateAdministrationTitle = DISPLAY_BRIEF ctrlCreate [QUOTE(RscText),IDC_BREIFING + 6,BRIEFINGS_GROUP_L];
private _ctrlCreateAdministrationText = DISPLAY_BRIEF ctrlCreate [QUOTE(RscStructuredText),IDC_BREIFING + 7,BRIEFINGS_GROUP_L];
private _ctrlCreateWeaponsReportTitle = DISPLAY_BRIEF ctrlCreate [QUOTE(RscText),IDC_BREIFING + 8,BRIEFINGS_GROUP_R];
private _ctrlCreateWeaponsReport = DISPLAY_BRIEF ctrlCreate [QUOTE(RscStructuredText),IDC_BREIFING + 9,BRIEFINGS_GROUP_R];

[0] call FUNC(briefingsChangeSide);

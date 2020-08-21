/*
 * Author: BadWolf
 * Function is called by the user at the time that they want to use the checklist. This can be called either using the ACE Self interact, or in Zues.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_displayMenu;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params[""];

createDialog GVAR(display);

if (isNull DISPLAY) exitWith { systemChat "bad display"; };

_createChecklistLine = {
    params["_idc"];

    private _text = _this select 0;
    private _checked = _this select 1;
    private _itemApplicable = _this select 2;
    private _missionType = GVAR(missionType);

    if(_itemApplicable == _missionType) then {
        //Create Structure Text and Insert Text. Get hight of text and resize control appropriately.
        private _ctrlCreateText = DISPLAY ctrlCreate [QUOTE(RscStructuredText),-1,CONTROL_GROUP];
        _ctrlCreateText ctrlSetStructuredText parseText _text;
        _ctrlCreateText ctrlSetBackgroundColor [1, 1, 1, 0.25];
        _ctrlCreateText ctrlSetPosition [0.01,GVAR(yStartCoord),0.78,0.05];
        _ctrlCreateText ctrlCommit 0;
        private _ctrlHeight = ctrlTextHeight _ctrlCreateText;
        _ctrlCreateText ctrlSetPosition [0.01,GVAR(yStartCoord),0.78,_ctrlHeight + 0.01];
        _ctrlCreateText ctrlCommit 0;
        //Create check box and add eventhandler that updates the Master Array when changed.
        private _ctrlCreateCB = DISPLAY ctrlCreate [QUOTE(RscCheckBox),_idc,CONTROL_GROUP];
        _ctrlCreateCB ctrlSetPosition [0.79,GVAR(yStartCoord),0.05,0.05];
        _ctrlCreateCB ctrlCommit 0;
        _ctrlCreateCB cbSetChecked _checked;
        _ctrlCreateCB ctrlAddEventHandler [QUOTE(CheckedChanged),{_this call FUNC(updateCheckedCB);}];
        //Set new value of yStartCoord so that the next line is created at the right point below the previous line.
        GVAR(yStartCoord) = GVAR(yStartCoord) + _ctrlHeight + 0.01;
    };
};


_createChecklistSection  = {
    params[""];

    {
        private _sectionTitle = _this select 0;
        private _sectionArray = _this select 1;
        private _sectionPassFail = _this select 2;
        private _sectionNotes = _this select 3;
        private _sectionIndex = _forEachIndex;

        CONTROL_LINE
        INCREMENT_YCOORD

        private _ctrlCreateSectionTitle = DISPLAY ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        _ctrlCreateSectionTitle ctrlSetText _sectionTitle;
        _ctrlCreateSectionTitle ctrlSetTextColor TEXT_RED;
        _ctrlCreateSectionTitle ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,0.05];
        _ctrlCreateSectionTitle ctrlCommit 0;

        INCREMENT_YCOORD

        private _ctrlCreateSectionInstruction = DISPLAY ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        _ctrlCreateSectionInstruction ctrlSetText "Check the box to confirm that the mission meets the requirement.";
        _ctrlCreateSectionInstruction ctrlSetTextColor TEXT_RED;
        _ctrlCreateSectionInstruction ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,0.05];
        _ctrlCreateSectionInstruction ctrlCommit 0;

        INCREMENT_YCOORD
        CONTROL_LINE
        INCREMENT_YCOORD

        {
            private _idc = 3000 + (_sectionIndex * 100) + _forEachIndex;
            [_idc] call _createChecklistLine;
        } forEach _sectionArray;

        CONTROL_LINE
        INCREMENT_YCOORD

        private _ctrlCreateSectionPassQuestion = DISPLAY ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        private _sectionQuestionPassFail = format ["Does this mission pass the %1 requirements?",_sectionTitle];
        _ctrlCreateSectionPassQuestion ctrlSetText _sectionQuestionPassFail;
        _ctrlCreateSectionPassQuestion ctrlSetPosition [0.01,GVAR(yStartCoord),0.7,0.05];
        _ctrlCreateSectionPassQuestion ctrlCommit 0;

        private _ctrlCreateSectionInstruction = DISPLAY ctrlCreate [QUOTE(RscCombo),-1,CONTROL_GROUP];
        lbCLear _ctrlCreateSectionInstruction;
        {
            _ctrlCreate lbAdd _x;
        } forEach A_PASSFAIL;
        _ctrlCreateSectionInstruction lbSetCurSel _sectionPassFail;
        _ctrlCreateSectionInstruction ctrlSetPosition [0.72,GVAR(yStartCoord),0.12,0.05];
        _ctrlCreateSectionInstruction ctrlAddEventHandler [QUOTE(LBSelChanged),{_this call FUNC(updateSelectionLB);}];
        _ctrlCreateSectionInstruction ctrlCommit 0;

        INCREMENT_YCOORD
        CONTROL_LINE
        INCREMENT_YCOORD

        private _ctrlCreateSectionMMNotes = DISPLAY ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        _ctrlCreateSectionMMNotes ctrlSetText "Notes for Mission Maker:";
        _ctrlCreateSectionMMNotes ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,0.05];
        _ctrlCreateSectionMMNotes ctrlCommit 0;

        INCREMENT_YCOORD

        private _ctrlCreateSectionMMNotesEdit = DISPLAY ctrlCreate [QUOTE(RscEditMulti),-1,CONTROL_GROUP];
        _ctrlCreateSectionMMNotesEdit ctrlSetText _sectionNotes;
        _ctrlCreateSectionMMNotesEdit ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,0.05];
        _ctrlCreateSectionInstruction ctrlAddEventHandler [QUOTE(KillFocus),{_this call FUNC(updateNotesFlag);}];
        _ctrlCreateSectionMMNotesEdit ctrlCommit 0;

        INCREMENT_YCOORD

    } forEach GVAR(TestingChecklistMaster);
};

//Main Function

GVAR(yStartCoord) = 0.01;

//Main Frame. This should be moved to a Class system so that I can have multiple types of main frames and customize from there.
private _ctrlBackground = MENU_DISPLAY ctrlCreate ["RscBackgroundGUI",-1];
_ctrlBackground ctrlSetPosition [0,0,1,0.85];
_ctrlBackground ctrlCommit 0;
private _leftFrame = MENU_DISPLAY ctrlCreate ["RscFrame",-1];
_leftFrame ctrlSetPosition [0,0,1,0.85];
_leftFrame ctrlCommit 0;
private _leftGroup = MENU_DISPLAY ctrlCreate ["RscControlsGroup",9991];
_leftGroup ctrlSetPosition [0,0,1,0.85];
_leftGroup ctrlCommit 0;
private _menuCancel = MENU_DISPLAY ctrlCreate ["RscButtonMenuCancel",-1];
_menuCancel ctrlSetText "Close";
_menuCancel ctrlSetPosition [0.88,1,0.12,0.1];
_menuCancel buttonSetAction "closeDialog 2;";
_menuCancel ctrlCommit 0;

private _missionMaker = getMissionConfigValue ["author","????"];
private _missionName = ;
private _missionPlayerCount = ;
private _missionTags = ;


if(_missionMaker == name player) then {
    {
        [] call _createChecklistSection;
    } forEach GVAR(MissionMakerChecklistMaster);
} else {
    {
        [] call _createChecklistSection;
    } forEach GVAR(TestingChecklistMaster);
};

private _ctrlCreateGenerateReport = DISPLAY ctrlCreate [QUOTE(RscButton),-1,CONTROL_GROUP];
_ctrlCreateGenerateReport ctrlSetText "Generate Report";
_ctrlCreateGenerateReport buttonSetAction QUOTE([] call FUNC(generateReport););

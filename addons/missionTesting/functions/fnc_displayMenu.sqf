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

private _createChecklistSection  = {
    TRACE_1("Params",_this);

    params["_sectionTitle","_sectionArray","_sectionPassFail","_sectionNotes"];

        private _sectionIndex = _forEachIndex;

        private _createCtrlLine0 = DISPLAY_TESTMENU ctrlCreate ["RscLine",-1,CONTROL_GROUP];
        TRACE_1("Section Item 0",_createCtrlLine0);
        _createCtrlLine0 ctrlSetPosition [0.01,GVAR(yStartCoord),0.79,0];
        INCREMENT_YCOORD;

        private _ctrlCreateSectionTitle = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        TRACE_1("Section Item 1",_ctrlCreateSectionTitle);
        _ctrlCreateSectionTitle ctrlSetText _sectionTitle;
        _ctrlCreateSectionTitle ctrlSetTextColor TEXT_RED;
        _ctrlCreateSectionTitle ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,CONTROL_SIZE_H];
        _ctrlCreateSectionTitle ctrlCommit 0;

        INCREMENT_YCOORD;

        private _ctrlCreateSectionInstruction = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        TRACE_1("Section Item 2",_ctrlCreateSectionInstruction);
        _ctrlCreateSectionInstruction ctrlSetText "Check the box to confirm that the mission meets the requirement.";
        _ctrlCreateSectionInstruction ctrlSetTextColor TEXT_RED;
        _ctrlCreateSectionInstruction ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,CONTROL_SIZE_H];
        _ctrlCreateSectionInstruction ctrlCommit 0;

        INCREMENT_YCOORD;
        private _createCtrlLine1 = DISPLAY_TESTMENU ctrlCreate ["RscLine",-1,CONTROL_GROUP];
        TRACE_1("Section Item 3",_createCtrlLine1);
        _createCtrlLine1 ctrlSetPosition [0.01,GVAR(yStartCoord),0.79,0];
        INCREMENT_YCOORD;

        {
            private _idc = IDC_GENERAL + (_sectionIndex * 100) + _forEachIndex;
            private _text = _x select 0;
            private _checked = _x select 1;
            private _itemApplicable = _x select 2;

            if(_itemApplicable == GVAR(missionType) || _itemApplicable == 0) then {
                TRACE_4("Variables for control: ",_idc,_text,_checked,_itemApplicable);
                //Create Structure Text and Insert Text. Get hight of text and resize control appropriately.
                _ctrlCreateText = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscStructuredText),-1,CONTROL_GROUP];
                TRACE_1("Checklist Item Text",_ctrlCreateText);
                _ctrlCreateText ctrlSetStructuredText parseText _text;
                _ctrlCreateText ctrlSetBackgroundColor [1, 1, 1, 0.25];
                _ctrlCreateText ctrlSetPosition [0.01,GVAR(yStartCoord),0.78,CONTROL_SIZE_H];
                _ctrlCreateText ctrlCommit 0;
                _ctrlHeight = ctrlTextHeight _ctrlCreateText;
                _ctrlCreateText ctrlSetPosition [0.01,GVAR(yStartCoord),0.78,_ctrlHeight + 0.01];
                _ctrlCreateText ctrlCommit 0;
                //Create check box and add eventhandler that updates the Master Array when changed.
                _ctrlCreateCB = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscCheckBox),_idc,CONTROL_GROUP];
                TRACE_1("Checklist Item CB",_ctrlCreateCB);
                _ctrlCreateCB ctrlSetPosition [0.79,GVAR(yStartCoord),0.05,CONTROL_SIZE_H];
                _ctrlCreateCB ctrlCommit 0;
                _ctrlCreateCB cbSetChecked _checked;
                _ctrlCreateCB ctrlAddEventHandler [QUOTE(CheckedChanged),{_this call FUNC(updateCheckedCB);}];
                //Set new value of yStartCoord so that the next line is created at the right point below the previous line.
                GVAR(yStartCoord) = GVAR(yStartCoord) + _ctrlHeight + 0.02;
            };
        } forEach _sectionArray;

        private _createCtrlLine2 = DISPLAY_TESTMENU ctrlCreate ["RscLine",-1,CONTROL_GROUP];
        TRACE_1("Section Item 4",_createCtrlLine2);
        _createCtrlLine2 ctrlSetPosition [0.01,GVAR(yStartCoord),0.79,0];
        INCREMENT_YCOORD;

        private _ctrlCreateSectionPassQuestion = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        TRACE_1("Section Item 5",_ctrlCreateSectionPassQuestion);
        private _sectionQuestionPassFail = format ["Does this mission pass the %1 requirements?",_sectionTitle];
        _ctrlCreateSectionPassQuestion ctrlSetText _sectionQuestionPassFail;
        _ctrlCreateSectionPassQuestion ctrlSetPosition [0.01,GVAR(yStartCoord),0.7,CONTROL_SIZE_H];
        _ctrlCreateSectionPassQuestion ctrlCommit 0;

        private _idcPassFail = IDC_CBITEMS + _forEachIndex;
        private _ctrlCreateSectionInstruction = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscCombo),_idcPassFail,CONTROL_GROUP];
        TRACE_1("Section Item 6",_ctrlCreateSectionPassQuestion);
        lbCLear _ctrlCreateSectionInstruction;
        {
            _ctrlCreate lbAdd _x;
        } forEach A_PASSFAIL;
        _ctrlCreateSectionInstruction lbSetCurSel _sectionPassFail;
        _ctrlCreateSectionInstruction ctrlSetPosition [0.72,GVAR(yStartCoord),0.12,CONTROL_SIZE_H];
        _ctrlCreateSectionInstruction ctrlAddEventHandler [QUOTE(LBSelChanged),{_this call FUNC(updateSelectionLB);}];
        _ctrlCreateSectionInstruction ctrlCommit 0;

        INCREMENT_YCOORD;
        private _createCtrlLine3 = DISPLAY_TESTMENU ctrlCreate ["RscLine",-1,CONTROL_GROUP];
        TRACE_1("Section Item 7",_createCtrlLine3);
        _createCtrlLine3 ctrlSetPosition [0.01,GVAR(yStartCoord),0.79,0];
        INCREMENT_YCOORD;

        private _ctrlCreateSectionMMNotes = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        TRACE_1("Section Item 8",_ctrlCreateSectionMMNotes);
        _ctrlCreateSectionMMNotes ctrlSetText "Notes for Mission Maker:";
        _ctrlCreateSectionMMNotes ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,CONTROL_SIZE_H];
        _ctrlCreateSectionMMNotes ctrlCommit 0;

        INCREMENT_YCOORD;

        private _idcMMNotes = IDC_PASSFAIL + _forEachIndex;
        private _ctrlCreateSectionMMNotesEdit = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),-1,CONTROL_GROUP];
        TRACE_1("Section Item 9",_ctrlCreateSectionMMNotesEdit);
        _ctrlCreateSectionMMNotesEdit ctrlSetText _sectionNotes;
        _ctrlCreateSectionMMNotesEdit ctrlSetPosition [0.01,GVAR(yStartCoord),0.82,0.15];
        _ctrlCreateSectionInstruction ctrlAddEventHandler [QUOTE(KillFocus),{_this call FUNC(updateNotesFlag);}];
        _ctrlCreateSectionMMNotesEdit ctrlCommit 0;

        INCREMENT_YCOORD + 0.15;
};

//Main Function

private _display = createDialog QGVAR(displayMissionTesting);

if (isNull DISPLAY_TESTMENU) exitWith { systemChat "bad display"; };

GVAR(yStartCoord) = 0.01;

//Main Frame. This should be moved to a Class system so that I can have multiple types of main frames and customize from there.
private _ctrlBackground = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscBackgroundGUI),-1];
_ctrlBackground ctrlSetPosition [0,0,0.85,1];
_ctrlBackground ctrlCommit 0;
private _leftFrame = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscFrame),-1];
_leftFrame ctrlSetPosition [0,0,0.85,1];
_leftFrame ctrlCommit 0;
private _leftGroup = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscControlsGroup),CONTROL_GROUP_IDC];
_leftGroup ctrlSetPosition [0,0,0.85,1];
_leftGroup ctrlCommit 0;
private _menuCancel = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscButtonMenuCancel),-1];
_menuCancel ctrlSetText "Close";
_menuCancel ctrlSetPosition [0.73,1,0.12,0.1];
_menuCancel buttonSetAction "closeDialog 2;";
_menuCancel ctrlCommit 0;
private _menuBreifingPage = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscButtonMenu),-1];
_menuBreifingPage ctrlSetText "Brieifing";
_menuBreifingPage ctrlSetPosition [0.60,1,0.12,0.1];
_menuBreifingPage ctrlAddEventHandler [QUOTE(SetFocus),{[] spawn FUNC(openBreifings)}];
_menuBreifingPage ctrlCommit 0;

private _missionMaker = getMissionConfigValue ["author","????"];
private _missionName = getMissionConfigValue ["onLoadName", getMissionConfigValue ["briefingName","????"]];
private _missionType = "";
private _missionVersion = "";
private _missionPlayerCountMax = "";
private _missionPlayerCountMin = "";
private _missionPlayerCountRec = "";
private _missionTag1 = "";
private _missionTag2 = "";
private _missionTag3 = "";
private _missionCustomScripting = "";
private _missionCustomLoadout = "";
private _missionCustomVicLoadout = "";
private _unitSpecificBrief = "";
private _missionNotesForTester = "";
private _masterChecklistArray = nil;

if(_missionMaker == name player) then {
    _masterChecklistArray = GVAR(MissionTestingChecklistMaster);// Needs to Be changed back after testing "MissionMakerChecklistMaster"
} else {
    _masterChecklistArray = GVAR(MissionTestingChecklistMaster);
};

{
    _x call _createChecklistSection;
} forEach _masterChecklistArray;

TRACE_1("Am I even getting this far?",_this);

private _ctrlCreateGenerateReport = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscButton),-1,CONTROL_GROUP];
_ctrlCreateGenerateReport ctrlSetText "Generate Report";
_ctrlCreateGenerateReport ctrlSetPosition [0.01,GVAR(yStartCoord),0.78,0.15];
_ctrlCreateGenerateReport ctrlAddEventHandler [QUOTE(MouseButtonClick),{[] call FUNC(generateReport)}];
_ctrlCreateGenerateReport ctrlCommit 0;

//Strutured Text Attributes.
private _separator = parseText "<br />------------------------<br />";

private _ctrlCreateInfoBlock = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscStructureText),-1];
_ctrlCreateInfoBlock ctrlSetBackgroundColor [1, 1, 1, 0];
_ctrlCreateInfoBlock ctrlSetPosition [0,0.86,0.5,1];
_ctrlCreateInfoBlockText = composeText [
    "MISSION INFORMATION",lineBreak
    ,_seperator, lineBreak
    ,"Mission Maker: ",_missionMaker, lineBreak
    ,"Mission Name: ", _missionName, lineBreak
    ,"Mission Type: ",_missionType, lineBreak
    ,"Mission Version: ",_missionVersion, lineBreak
    ,lineBreak
    ,"Mission Player Count",lineBreak
    ,_seperator, lineBreak
    ,"Min: ",_missionPlayerCountMin,"Rec: ",_missionPlayerCountRec,"Max: ",_missionPlayerCountMax, lineBreak
    ,_seperator, lineBreak
    ,lineBreak
    ,"Mission Tags", lineBreak
    ,_seperator, lineBreak
    ,_missionTag1,", ",_missionTag2,", ",_missionTag3,lineBreak
    ,_seperator, lineBreak
    ,lineBreak
    ,"Mission Flags for Tester", lineBreak
    ,_seperator, lineBreak
    ,"Custom Scripting: ",_missionCustomScripting, lineBreak
    ,"Custom Loadouts: ",_missionCustomLoadout, lineBreak
    ,"Custom Vichicle Loadouts: ",_missionCustomVicLoadout, lineBreak
    ,"Unit specific Breifs: ",_unitSpecificBrief, lineBreak
    ,_seperator, lineBreak
    ,lineBreak
    ,_seperator, lineBreak
    ,"Notes for Mission Tester"
    ,_seperator, lineBreak
    ,_missionNotesForTester,lineBreak
];
_ctrlCreateInfoBlock ctrlSetStructuredText _ctrlCreateInfoBlockText;
_ctrlCreateInfoBlock ctrlCommit 0;

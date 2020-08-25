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

private _createChecklistLine = {
    TRACE_1("Params",_this);

    params["_idc",["_text","_checked","_itemApplicable"]]; //This is fucked. Need to rethink.

    private _text = _this select 0;
    private _checked = _this select 1;
    private _itemApplicable = _this select 2;
    private _missionType = GVAR(missionType); //This still hasn't been set so needs to be updated manually to test.

    if(_itemApplicable == _missionType) then {
        //Create Structure Text and Insert Text. Get hight of text and resize control appropriately.
        private _ctrlCreateText = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscStructuredText),-1,CONTROL_GROUP];
        _ctrlCreateText ctrlSetStructuredText parseText _text;
        _ctrlCreateText ctrlSetBackgroundColor [1, 1, 1, 0.25];
        _ctrlCreateText ctrlSetPosition [0.01,GVAR(yStartCoord),0.78,0.05];
        _ctrlCreateText ctrlCommit 0;
        private _ctrlHeight = ctrlTextHeight _ctrlCreateText;
        _ctrlCreateText ctrlSetPosition [0.01,GVAR(yStartCoord),0.78,_ctrlHeight + 0.01];
        _ctrlCreateText ctrlCommit 0;
        //Create check box and add eventhandler that updates the Master Array when changed.
        private _ctrlCreateCB = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscCheckBox),_idc,CONTROL_GROUP];
        _ctrlCreateCB ctrlSetPosition [0.79,GVAR(yStartCoord),0.05,0.05];
        _ctrlCreateCB ctrlCommit 0;
        _ctrlCreateCB cbSetChecked _checked;
        _ctrlCreateCB ctrlAddEventHandler [QUOTE(CheckedChanged),{_this call FUNC(updateCheckedCB);}];
        //Set new value of yStartCoord so that the next line is created at the right point below the previous line.
        GVAR(yStartCoord) = GVAR(yStartCoord) + _ctrlHeight + 0.01;
    };
};


private _createChecklistSection  = {
    TRACE_1("Params",_this);

    params["_sectionTitle","_sectionArray","_sectionPassFail","_sectionNotes"];

    {
        private _sectionIndex = _forEachIndex;

        private _createCtrlLine = DISPLAY_TESTMENU ctrlCreate ["RscLine",-1,CONTROL_GROUP];
        _createCtrlLine ctrlSetPosition [0.01,GVAR(yStartCoord),0.79,0];
        INCREMENT_YCOORD;

        private _ctrlCreateSectionTitle = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        _ctrlCreateSectionTitle ctrlSetText _sectionTitle;
        _ctrlCreateSectionTitle ctrlSetTextColor TEXT_RED;
        _ctrlCreateSectionTitle ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,0.05];
        _ctrlCreateSectionTitle ctrlCommit 0;

        INCREMENT_YCOORD;

        private _ctrlCreateSectionInstruction = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        _ctrlCreateSectionInstruction ctrlSetText "Check the box to confirm that the mission meets the requirement.";
        _ctrlCreateSectionInstruction ctrlSetTextColor TEXT_RED;
        _ctrlCreateSectionInstruction ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,0.05];
        _ctrlCreateSectionInstruction ctrlCommit 0;

        INCREMENT_YCOORD;
        private _createCtrlLine = DISPLAY_TESTMENU ctrlCreate ["RscLine",-1,CONTROL_GROUP];
        _createCtrlLine ctrlSetPosition [0.01,GVAR(yStartCoord),0.79,0];
        INCREMENT_YCOORD;

        {
            private _idc = IDC_GENERAL + (_sectionIndex * 100) + _forEachIndex;
            [_idc,_x] call _createChecklistLine;
        } forEach _sectionArray;

        private _createCtrlLine = DISPLAY_TESTMENU ctrlCreate ["RscLine",-1,CONTROL_GROUP];
        _createCtrlLine ctrlSetPosition [0.01,GVAR(yStartCoord),0.79,0];
        INCREMENT_YCOORD;

        private _ctrlCreateSectionPassQuestion = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        private _sectionQuestionPassFail = format ["Does this mission pass the %1 requirements?",_sectionTitle];
        _ctrlCreateSectionPassQuestion ctrlSetText _sectionQuestionPassFail;
        _ctrlCreateSectionPassQuestion ctrlSetPosition [0.01,GVAR(yStartCoord),0.7,0.05];
        _ctrlCreateSectionPassQuestion ctrlCommit 0;

        private _idcPassFail = IDC_CBITEMS + _forEachIndex;
        private _ctrlCreateSectionInstruction = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscCombo),_idcPassFail,CONTROL_GROUP];
        lbCLear _ctrlCreateSectionInstruction;
        {
            _ctrlCreate lbAdd _x;
        } forEach A_PASSFAIL;
        _ctrlCreateSectionInstruction lbSetCurSel _sectionPassFail;
        _ctrlCreateSectionInstruction ctrlSetPosition [0.72,GVAR(yStartCoord),0.12,0.05];
        _ctrlCreateSectionInstruction ctrlAddEventHandler [QUOTE(LBSelChanged),{_this call FUNC(updateSelectionLB);}];
        _ctrlCreateSectionInstruction ctrlCommit 0;

        INCREMENT_YCOORD;
        private _createCtrlLine = DISPLAY_TESTMENU ctrlCreate ["RscLine",-1,CONTROL_GROUP];
        _createCtrlLine ctrlSetPosition [0.01,GVAR(yStartCoord),0.79,0];
        INCREMENT_YCOORD;

        private _ctrlCreateSectionMMNotes = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP];
        _ctrlCreateSectionMMNotes ctrlSetText "Notes for Mission Maker:";
        _ctrlCreateSectionMMNotes ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,0.05];
        _ctrlCreateSectionMMNotes ctrlCommit 0;

        INCREMENT_YCOORD;

        private _idcMMNotes = IDC_PASSFAIL + _forEachIndex;
        private _ctrlCreateSectionMMNotesEdit = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),-1,CONTROL_GROUP];
        _ctrlCreateSectionMMNotesEdit ctrlSetText _sectionNotes;
        _ctrlCreateSectionMMNotesEdit ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,0.05];
        _ctrlCreateSectionInstruction ctrlAddEventHandler [QUOTE(KillFocus),{_this call FUNC(updateNotesFlag);}];
        _ctrlCreateSectionMMNotesEdit ctrlCommit 0;

        INCREMENT_YCOORD;

    } forEach GVAR(MissionTestingChecklistMaster);
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
private _leftGroup = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscControlsGroup),CONTROL_GROUP];
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

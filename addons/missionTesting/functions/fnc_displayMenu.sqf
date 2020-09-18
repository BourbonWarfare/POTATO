/*
 * Author: BadWolf
 * Function is called by the user at the time that they want to use the checklist. This can be called either using the ACE Self interact, or in Zues from the POTATO Modules Section.
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

        private _createCtrlLine0 = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscLine),-1,CONTROL_GROUP_L];
        _createCtrlLine0 ctrlSetPosition [0.01,GVAR(yStartCoord),LINE_W,0];
        _createCtrlLine0 ctrlCommit 0;
        INCREMENT_YCOORD;

        private _ctrlCreateSectionTitle = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP_L];
        _ctrlCreateSectionTitle ctrlSetText _sectionTitle;
        _ctrlCreateSectionTitle ctrlSetTextColor TEXT_ORANGE;
        _ctrlCreateSectionTitle ctrlSetFontHeight TEXT_H_LARGE;
        _ctrlCreateSectionTitle ctrlSetPosition [0.01,GVAR(yStartCoord),LINE_W,CONTROL_SIZE_H];
        _ctrlCreateSectionTitle ctrlCommit 0;

        INCREMENT_YCOORD_TEXT;

        private _ctrlCreateSectionInstruction = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP_L];
        _ctrlCreateSectionInstruction ctrlSetText "Check the box to confirm that the mission meets the requirement.";
        _ctrlCreateSectionInstruction ctrlSetTextColor TEXT_RED;
        _ctrlCreateSectionInstruction ctrlSetPosition [0.01,GVAR(yStartCoord),0.83,CONTROL_SIZE_H];
        _ctrlCreateSectionInstruction ctrlCommit 0;

        INCREMENT_YCOORD_TEXT;
        private _createCtrlLine1 = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscLine),-1,CONTROL_GROUP_L];
        _createCtrlLine1 ctrlSetPosition [0.01,GVAR(yStartCoord),LINE_W,0];
        _createCtrlLine1 ctrlCommit 0;
        INCREMENT_YCOORD;

        {
            private _idc = IDC_GENERAL + (_sectionIndex * 100) + _forEachIndex;
            private _text = _x select 0;
            private _checked = _x select 1;
            private _itemApplicable = _x select 2;

            if(_itemApplicable == (getMissionConfigValue QGVAR(missionType)) || _itemApplicable == 0) then {
                //Create Structure Text and Insert Text. Get hight of text and resize control appropriately.
                _ctrlCreateText = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscStructuredText),-1,CONTROL_GROUP_L];
                _ctrlCreateText ctrlSetStructuredText parseText _text;
                _ctrlCreateText ctrlSetBackgroundColor [1, 1, 1, 0.25];
                _ctrlCreateText ctrlSetPosition [0.01,GVAR(yStartCoord),0.77,CONTROL_SIZE_H];
                _ctrlCreateText ctrlCommit 0;
                _ctrlHeight = ctrlTextHeight _ctrlCreateText;
                _ctrlCreateText ctrlSetPosition [0.01,GVAR(yStartCoord),0.77,_ctrlHeight + 0.01];
                _ctrlCreateText ctrlCommit 0;
                //Create check box and add eventhandler that updates the Master Array when changed.
                _ctrlCreateCB = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscCheckBox),_idc,CONTROL_GROUP_L];
                _ctrlCreateCB ctrlSetPosition [0.78,GVAR(yStartCoord),0.05,CONTROL_SIZE_H];
                _ctrlCreateCB ctrlCommit 0;
                _ctrlCreateCB cbSetChecked _checked;
                _ctrlCreateCB ctrlAddEventHandler [QUOTE(CheckedChanged),{_this call FUNC(updateCheckedCB);}];
                //Set new value of yStartCoord so that the next line is created at the right point below the previous line.
                GVAR(yStartCoord) = GVAR(yStartCoord) + _ctrlHeight + 0.02;
            };
        } forEach _sectionArray;

        private _createCtrlLine2 = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscLine),-1,CONTROL_GROUP_L];
        _createCtrlLine2 ctrlSetPosition [0.01,GVAR(yStartCoord),LINE_W,0];
        _createCtrlLine2 ctrlCommit 0;
        INCREMENT_YCOORD;

        private _ctrlCreateSectionPassQuestion = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP_L];
        private _sectionQuestionPassFail = format ["Does this mission pass the %1 requirements?",_sectionTitle];
        _ctrlCreateSectionPassQuestion ctrlSetText _sectionQuestionPassFail;
        _ctrlCreateSectionPassQuestion ctrlSetPosition [0.01,GVAR(yStartCoord),0.7,CONTROL_SIZE_H];
        _ctrlCreateSectionPassQuestion ctrlCommit 0;

        private _idcPassFail = IDC_CBITEMS + _forEachIndex;
        private _ctrlCreateSectionInstruction = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscCombo),_idcPassFail,CONTROL_GROUP_L];
        lbCLear _ctrlCreateSectionInstruction;
        {
            _ctrlCreateSectionInstruction lbAdd _x;
        } forEach A_PASSFAIL;
        _ctrlCreateSectionInstruction lbSetCurSel _sectionPassFail;
        _ctrlCreateSectionInstruction ctrlSetPosition [0.70,GVAR(yStartCoord),0.12,CONTROL_SIZE_H];
        _ctrlCreateSectionInstruction ctrlAddEventHandler [QUOTE(LBSelChanged),{_this call FUNC(updateSelectionLB);}];
        _ctrlCreateSectionInstruction ctrlCommit 0;

        INCREMENT_YCOORD_TEXT;
        private _createCtrlLine3 = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscLine),-1,CONTROL_GROUP_L];
        _createCtrlLine3 ctrlSetPosition [0.01,GVAR(yStartCoord),LINE_W,0];
        _createCtrlLine3 ctrlCommit 0;
        INCREMENT_YCOORD;

        if(_missionMaker != name ACE_PLAYER) then {
            private _ctrlCreateSectionMMNotes = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP_L];
            _ctrlCreateSectionMMNotes ctrlSetText "NOTES FOR MISSION MAKER:";
            _ctrlCreateSectionMMNotes ctrlSetPosition [0.01,GVAR(yStartCoord),LINE_W,CONTROL_SIZE_H];
            _ctrlCreateSectionMMNotes ctrlCommit 0;

            INCREMENT_YCOORD_TEXT;

            private _idcMMNotes = IDC_PASSFAIL + _forEachIndex;
            private _ctrlCreateSectionMMNotesEdit = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),_idcMMNotes,CONTROL_GROUP_L];
            _ctrlCreateSectionMMNotesEdit ctrlSetText _sectionNotes;
            _ctrlCreateSectionMMNotesEdit ctrlSetPosition [0.01,GVAR(yStartCoord),LINE_W,0.15];
            _ctrlCreateSectionMMNotesEdit ctrlAddEventHandler [QUOTE(KillFocus),{_this call FUNC(updateNotesFlag);}];
            _ctrlCreateSectionMMNotesEdit ctrlCommit 0;

            INCREMENT_YCOORD + 0.14;
        };
};

//Main Function

private _display = createDialog QGVAR(displayMissionTesting);

if (isNull DISPLAY_TESTMENU) exitWith { systemChat "bad display"; };

GVAR(yStartCoord) = 0.01;

private _ctrlBackground = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscBackgroundGUI),-1];
_ctrlBackground ctrlSetPosition [0,0,0.85,1];
_ctrlBackground ctrlCommit 0;
private _leftFrame = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscFrame),-1];
_leftFrame ctrlSetPosition [0,0,0.85,1];
_leftFrame ctrlCommit 0;
private _leftGroup = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscControlsGroup),CONTROL_GROUP_L_IDC];
_leftGroup ctrlSetPosition [0,0,0.85,1];
_leftGroup ctrlCommit 0;
private _rightGroup = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscControlsGroup),CONTROL_GROUP_R_IDC];
_rightGroup ctrlSetPosition [0.86,0,0.51,1];
_rightGroup ctrlCommit 0;
private _menuCancel = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscButtonMenuCancel),-1];
_menuCancel ctrlSetText "Close";
_menuCancel ctrlSetPosition [0.73,1,0.12,0.1];
_menuCancel buttonSetAction "closeDialog 2;";
_menuCancel ctrlCommit 0;
private _menuBreifingPage = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscButtonMenu),-1];
_menuBreifingPage ctrlSetText "Brieifing";
_menuBreifingPage ctrlSetPosition [0.60,1,0.12,0.1];
_menuBreifingPage buttonSetAction QUOTE([] call FUNC(openBriefings));
_menuBreifingPage ctrlCommit 0;

private _missionMaker = getMissionConfigValue ["author","????"];
private _missionName = getMissionConfigValue ["onLoadName", getMissionConfigValue ["briefingName","????"]];
private _missionType = A_MISSION_TYPE select (getMissionConfigValue QGVAR(missionType));
private _missionVersion = getMissionConfigValue QGVAR(missionVersion);
private _missionPlayerCountMax = getMissionConfigValue QGVAR(playerCountMaximum);
private _missionPlayerCountMin = getMissionConfigValue QGVAR(playerCountMinimum);
private _missionPlayerCountRec = getMissionConfigValue QGVAR(playerCountRecommended);
private _missionTag1 = A_MISSION_TAGS select (getMissionConfigValue QGVAR(missionTag1));
private _missionTag2 = A_MISSION_TAGS select (getMissionConfigValue QGVAR(missionTag2));
private _missionTag3 = A_MISSION_TAGS select (getMissionConfigValue QGVAR(missionTag3));
private _missionCustomScripting =  A_YESNO select (getMissionConfigValue QGVAR(missionFlagCustomScripting));
private _missionCustomLoadout =  A_YESNO select (getMissionConfigValue QGVAR(missionFlagCustomLoadout));
private _missionCustomVicLoadout =  A_YESNO select (getMissionConfigValue QGVAR(missionFlagCustomVicLoadout));
private _unitSpecificBrief =  A_YESNO select (getMissionConfigValue QGVAR(missionFlagUnitSpecificBriefing));
private _missionNotesForTester =  getMissionConfigValue QGVAR(missionMakerNotesForTesters);
//private _missionSummary = "Multiplayer" get3DENMissionAttribute "IntelOverviewText"; - Mission Summary Block Removed for now as not functioning.
private _masterChecklistArray = nil;

if(_missionMaker == name ACE_PLAYER) then {
    _masterChecklistArray = GVAR(MissionMakerChecklistMaster);
} else {
    _masterChecklistArray = GVAR(MissionTestingChecklistMaster);
};

{
    _x call _createChecklistSection;
} forEach _masterChecklistArray;
//
INCREMENT_YCOORD_TEXT;
private _createCtrlLine4 = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscLine),-1,CONTROL_GROUP_L];
_createCtrlLine4 ctrlSetPosition [0.01,GVAR(yStartCoord),LINE_W,0];
_createCtrlLine4 ctrlCommit 0;
INCREMENT_YCOORD;

private _ctrlGeneralMMNotesTitle = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1,CONTROL_GROUP_L];
if(_missionMaker == name ACE_PLAYER) then {
    _ctrlGeneralMMNotesTitle ctrlSetText "Any other Notes for Mission Testers/Version";
} else {
    _ctrlGeneralMMNotesTitle ctrlSetText "General Notes for Mission Maker:";
};
_ctrlGeneralMMNotesTitle ctrlSetTextColor TEXT_ORANGE;
_ctrlGeneralMMNotesTitle ctrlSetFontHeight TEXT_H_LARGE;
_ctrlGeneralMMNotesTitle ctrlSetPosition [0.01,GVAR(yStartCoord),LINE_W,CONTROL_SIZE_H];
_ctrlGeneralMMNotesTitle ctrlCommit 0;

INCREMENT_YCOORD_TEXT;

private _ctrlGeneralMMNotes = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),IDC_GENERAL_MT_NOTES,CONTROL_GROUP_L];
_ctrlGeneralMMNotes ctrlSetText GVAR(GeneraMissionNotesForMM);//could use the EFUNC(briefing,convertHTMLToNewLine) to maintain new lines.
_ctrlGeneralMMNotes ctrlSetPosition [0.01,GVAR(yStartCoord),LINE_W,0.15];
_ctrlGeneralMMNotes ctrlAddEventHandler [QUOTE(KillFocus),{GVAR(GeneraMissionNotesForMM) = ctrlText (_this select 0);}]; //could use the EFUNC(briefing,convertNewLineToHTML) to maintain new lines.
_ctrlGeneralMMNotes ctrlCommit 0;

INCREMENT_YCOORD + 0.14;

private _ctrlCreateGenerateReport = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscButton),-1,CONTROL_GROUP_L];
_ctrlCreateGenerateReport ctrlSetText "Generate Report";
_ctrlCreateGenerateReport ctrlSetPosition [0.01,GVAR(yStartCoord),LINE_W,0.15];
_ctrlCreateGenerateReport ctrlAddEventHandler [QUOTE(MouseButtonClick),{[] call FUNC(generateReport)}];
_ctrlCreateGenerateReport ctrlCommit 0;

//Strutured Text Attributes.
private _separator = parseText "<br />------------------------<br />";

private _ctrlCreateInfoBlock = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscStructuredText),-1,CONTROL_GROUP_R];
TRACE_1("Create Control Structure Text Info",_ctrlCreateInfoBlock);
_ctrlCreateInfoBlock ctrlSetBackgroundColor [1, 1, 1, 0];
_ctrlCreateInfoBlock ctrlSetPosition [0,0,0.5,1];
_ctrlCreateInfoBlock ctrlCommit 0;
_ctrlCreateInfoBlockText = composeText [
    parseText "<t color='#FF8000'>MISSION INFORMATION</t>"
    ,_separator
    ,parseText "<t color='#0080FF'>Mission Maker:</t> ",_missionMaker, lineBreak
    ,parseText "<t color='#0080FF'>Mission Name:</t> ", _missionName, lineBreak
    ,parseText "<t color='#0080FF'>Mission Type:</t> ",_missionType, lineBreak
    ,parseText "<t color='#0080FF'>Mission Version:</t> ",_missionVersion, lineBreak
    ,lineBreak
    ,parseText "<t color='#FF8000'>MISSION PLAYER COUNT</t>"
    ,_separator
    ,parseText "<t color='#0080FF'>Min:</t> ",_missionPlayerCountMin,parseText "<t color='#0080FF'>Rec:</t> ",_missionPlayerCountRec,parseText "<t color='#0080FF'>Max:</t> ",_missionPlayerCountMax, lineBreak
    ,lineBreak
    ,parseText "<t color='#FF8000'>MISSION TAGS</t>"
    ,_separator
    ,_missionTag1,", ",_missionTag2,", ",_missionTag3, lineBreak
    ,lineBreak
    ,parseText "<t color='#FF8000'>MISSION TAGS FOR TESTER</t>"
    ,_separator
    ,parseText "<t color='#0080FF'>Custom Scripting:</t> ",_missionCustomScripting, lineBreak
    ,parseText "<t color='#0080FF'>Custom Loadouts:</t> ",_missionCustomLoadout, lineBreak
    ,parseText "<t color='#0080FF'>Custom Vichicle Loadouts:</t> ",_missionCustomVicLoadout, lineBreak
    ,parseText "<t color='#0080FF'>Unit specific Breifs:</t> ",_unitSpecificBrief, lineBreak
    ,lineBreak
    ,parseText "<t color='#FF8000'>MISSION MAKER NOTES FOR TESTER</t>"
    ,_separator
    ,_missionNotesForTester,lineBreak
];
TRACE_1("Compose Text: ",_ctrlCreateInfoBlockText);
_ctrlCreateInfoBlock ctrlSetStructuredText _ctrlCreateInfoBlockText;
private _ctrlCreateInfoBlockHeight = ctrlTextHeight _ctrlCreateInfoBlock;
_ctrlCreateInfoBlock ctrlSetPosition [0,0,0.5,_ctrlCreateInfoBlockHeight + 0.01];
_ctrlCreateInfoBlock ctrlCommit 0;

/*

    Mission Summary Block Removed for now as not functioning.

    ,parseText "<t color='#FF8000'>MISSION SUMMARY</t>"
    ,_separator
    ,_missionSummary, lineBreak
    ,lineBreak

*/

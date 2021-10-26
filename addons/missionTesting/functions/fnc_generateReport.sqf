/*
 * Author: BadWolf
 * Function called to generate the report. The reports generated are dependant on if the player calling the testing menu is the mission maker or not.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_generateReport;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params[""];


private _trueFalse = {
    params["_cbValue"];
    if (_cbValue) then {BBTRUE} else {BBFALSE};
};

private _checkBoxes = {
    params["_text","_cbValue","_applicable"];
    private _cbValueStr = [_cbValue] call _trueFalse;
    private _missionType = getMissionConfigValue QGVAR(missionType);
    if (_applicable == _missionType || _applicable == 0) then {
        S_NEWTEXTLINE_FORMATTEXT ["[*]%1 : %2",_text,_cbValueStr];
    };
};

private _overallPassFail ={
    params["_masterChecklistArray"];
    private _failFlag = false;
    private _text = BBPASS;
    {
        private _sectionPassFail = _x select 2;
        if(_sectionPassFail == 0) exitWith {_failFlag = true};
    }forEach _masterChecklistArray;
    if(_failFlag) then {
        _text = BBFAIL;
    };
    _text;
};

private _createReportSection = {
    params["_sectionTitle","_sectionArray","_passFailInt","_sectionNotes","_sectionNotesFlag"];

    private _passFailText = BBPASSFAIL_A select _passFailInt;
    //private _notesFlatStr = BBNOTEFLAG_A select _sectionNotesFlag;
    S_NEWTEXTLINE_FORMATTEXT ["__**%1**__ : %2",_sectionTitle,_passFailText];
    //{_x call _checkBoxes;} forEach _sectionArray;
    if(_missionMaker != name ACE_PLAYER && _passFailText == ":x:") then {
        S_NEWTEXTLINE_FORMATTEXT ["NOTES:
		%1",_sectionNotes];
    };
};

private _missionMaker = getMissionConfigValue ["author","????"];
private _missionName = getText (missionConfigFile >> "MissionSQM" >> "Mission" >> "Intel" >> "briefingName");
private _missionType = A_MISSION_TYPE select (getMissionConfigValue QGVAR(missionType));
private _missionVersion = getMissionConfigValue QGVAR(missionVersion);
private _missionSummary = "Intel" get3DENMissionAttribute "IntelOverviewText";
private _missionCustomScripting = getMissionConfigValue QGVAR(missionFlagCustomScripting);
private _missionCustomScriptingStr = if(isNil QUOTE(_missionCustomScripting)) then {BBFALSE} else {[_missionCustomScripting] call _trueFalse};
private _missionCustomLoadout = getMissionConfigValue QGVAR(missionFlagCustomLoadout);
private _missionCustomLoadoutStr = if(isNil QUOTE(_missionCustomLoadout)) then {BBFALSE} else {[_missionCustomLoadout] call _trueFalse};
private _missionCustomVicLoadout = getMissionConfigValue QGVAR(missionFlagCustomVicLoadout);
private _missionCustomVicLoadoutStr = if(isNil QUOTE(_missionCustomVicLoadout)) then {BBFALSE} else {[_missionCustomVicLoadout] call _trueFalse};
private _unitSpecificBrief = getMissionConfigValue QGVAR(missionFlagUnitSpecificBriefing);
private _unitSpecificBriefStr = if(isNil QUOTE(_unitSpecificBrief)) then {BBFALSE} else {[_unitSpecificBrief] call _trueFalse};
private _missionNotesForTester =  getMissionConfigValue QGVAR(missionMakerNotesForTesters);
private _masterChecklistArray = nil;
private _textArray = [];
private _textArrayShort = [];

if(_missionMaker == name ACE_PLAYER) then {
    _masterChecklistArray = GVAR(MissionMakerChecklistMaster);
	//S_NEWTEXTLINE ["<@251962627561881602>"]; //Ping the QA Master
	S_NEWTEXTLINE_FORMATTEXT ["My mission has passed the mission maker checklist and is now ready for initial QA.
	
	**Mission:** %1
	**Type:** %2
	**Version:** %3",

	_missionName,_missionType,_missionVersion];
    if (isServer && name ACE_PLAYER == _missionMaker) then {
        S_NEWTEXTLINE_FORMATTEXT ["**Mission Summary:**
		%1",_missionSummary];
    };

    S_NEWTEXTLINE_SHORT ["**New Version:** %1",_missionVersion];

    /* {
        _x call _createReportSection;
    } forEach _masterChecklistArray; */

    S_NEWTEXTLINE_FORMATTEXT_SHORT ["**Version Changes:**
	%1",GVAR(GeneraMissionNotesForMM)];
    S_NEWTEXTLINE_FORMATTEXT["**Notes for QA Testers:**
	```%1```",GVAR(GeneraMissionNotesForMM)];

    private _textLong = _textArray joinString (endl + endl);
    private _textShort = _textArrayShort joinString (endl + endl);
    private _reportCtrlLong = DISPLAY_TESTMENU displayCtrl IDC_REPORT_L;
    private _reportCtrlShort = DISPLAY_TESTMENU displayCtrl IDC_REPORT_S;
    if (isNull _reportCtrlLong) then {
        private _reportBackground = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscBackgroundGUI),-1];
        _reportBackground ctrlSetPosition [-0.35,0,0.34,1];
        _reportBackground ctrlCommit 0;
        private _reportCtrlNewTitle = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1];
        _reportCtrlNewTitle ctrlSetPosition [-0.35,0,0.34,0.05];
        _reportCtrlNewTitle ctrlSetTextColor TEXT_ORANGE;
        _reportCtrlNewTitle ctrlCommit 0;
        _reportCtrlNewTitle ctrlSetText "Initial Report";
        private _reportCtrlNew = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),IDC_REPORT_L];
        _reportCtrlNew ctrlSetPosition [-0.35,0.05,0.34,0.5];
        _reportCtrlNew ctrlCommit 0;
        _reportCtrlNew ctrlSetText _textLong;
        private _reportCtrlNewTitleShort = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1];
        _reportCtrlNewTitleShort ctrlSetPosition [-0.35,0.55,0.34,0.05];
        _reportCtrlNewTitleShort ctrlSetTextColor TEXT_ORANGE;
        _reportCtrlNewTitleShort ctrlCommit 0;
        _reportCtrlNewTitleShort ctrlSetText "Update Report (Updates only)";
        private _reportCtrlNewShort = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),IDC_REPORT_S];
        _reportCtrlNewShort ctrlSetPosition [-0.35,0.6,0.34,0.4];
        _reportCtrlNewShort ctrlCommit 0;
        _reportCtrlNewShort ctrlSetText _textShort;
    } else {
        _reportCtrlLong ctrlSetText _textLong;
        _reportCtrlShort ctrlSetText _textShort;
    };
    hint "Report generated! Copy the report and comment it in your mission database thread, then click 'Request Testing'.";
} else {
    _masterChecklistArray = GVAR(MissionTestingChecklistMaster);
    S_NEWTEXTLINE_FORMATTEXT ["**Version:** %1
	**QA Tester:** %2
	**Test Result:** %3",_missionVersion,name ACE_PLAYER,_missionOverallPassFail];
    private _missionOverallPassFail = [_masterChecklistArray] call _overallPassFail;

    {
        _x call _createReportSection;
    } forEach _masterChecklistArray;

    S_NEWTEXTLINE_FORMATTEXT ["**Feedback from QA Tester:**
	%1",GVAR(GeneraMissionNotesForMM)];

    private _text = _textArray joinString (endl + endl);
    private _reportCtrl = DISPLAY_TESTMENU displayCtrl IDC_REPORT_L;
    if (isNull _reportCtrl) then {
        private _reportBackground = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscBackgroundGUI),-1];
        _reportBackground ctrlSetPosition [-0.35,0,0.34,1];
        _reportBackground ctrlCommit 0;
        private _reportCtrlNew = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),IDC_REPORT_L];
        _reportCtrlNew ctrlSetPosition [-0.35,0,0.35,1];
        _reportCtrlNew ctrlCommit 0;
        _reportCtrlNew ctrlSetText _text;
    } else {
        _reportCtrl ctrlSetText _text;
    };
    hint "Report generated! Copy the text to the left and post it in the mission database thread. If it failed, tick the 'rejection' box.";
};

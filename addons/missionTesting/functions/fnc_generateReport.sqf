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
    [MDFALSE, MDTRUE] select _cbValue
};

private _checkBoxes = {
    params["_text","_cbValue","_applicable"];
    private _cbValueStr = [_cbValue] call _trueFalse;
    private _missionType = getMissionConfigValue QGVAR(missionType);
    if (_cbValueStr == ":x:" && {_applicable == _missionType || _applicable == 0}) then {
        S_NEWTEXTLINE_FORMATTEXT ["[*]%1 : %2",_text,_cbValueStr];
    };
};

private _overallPassFail ={
    params["_masterChecklistArray"];
    private _failFlag = false;
    private _text = MDPASS;
    {
        private _sectionPassFail = _x select 2;
        if(_sectionPassFail == 0) exitWith {_failFlag = true};
    }forEach _masterChecklistArray;
    if(_failFlag) then {
        _text = MDFAIL;
    };
    _text;
};

private _createReportSection = {
    params["_sectionTitle","_sectionArray","_passFailInt","_sectionNotes","_sectionNotesFlag"];

    S_NEWTEXTLINE ["## __%1__: %2 ",_sectionTitle,MDPASSFAIL_A select _passFailInt];
    {_x call _checkBoxes;} forEach _sectionArray;
    if(_missionMaker != name ACE_player) then {
        S_NEWTEXTLINE ["### __ NOTES :__"];
        S_NEWTEXTLINE ["%1",_sectionNotes];
    };
};

private _missionMaker = getMissionConfigValue ["author","????"];
private _missionName = getMissionConfigValue ["onLoadName", getMissionConfigValue ["briefingName","????"]];
private _missionFrameworkDate = getMissionConfigValue ["bwmfDate", "Pre-March2016"];
private _missionType = A_MISSION_TYPE select (getMissionConfigValue QGVAR(missionType));
private _missionVersion = getMissionConfigValue QGVAR(missionVersion);
private _missionSummary = "Intel" get3DENMissionAttribute "IntelOverviewText";
private _missionPlayerCountMax = getMissionConfigValue QGVAR(playerCountMaximum);
private _missionPlayerCountMin = getMissionConfigValue QGVAR(playerCountMinimum);
private _missionPlayerCountRec = getMissionConfigValue QGVAR(playerCountRecommended);
private _missionSSTime = getMissionConfigValue QGVAR(SSTimeGiven);
private _missionTimeLength = getMissionConfigValue QGVAR(missionTimeLength);
private _missionTag1Var = getMissionConfigValue QGVAR(missionTag1);
private _missionTag1 = if(isNil QUOTE(_missionTag1Var)) then {"NONE"} else {A_MISSION_TAGS select _missionTag1Var};
private _missionTag2Var = getMissionConfigValue QGVAR(missionTag2);
private _missionTag2 = if(isNil QUOTE(_missionTag2Var)) then {"NONE"} else {A_MISSION_TAGS select _missionTag2Var};
private _missionTag3Var = getMissionConfigValue QGVAR(missionTag3);
private _missionTag3 = if(isNil QUOTE(_missionTag3Var)) then {"NONE"} else {A_MISSION_TAGS select _missionTag3Var};
private _missionCustomScripting = getMissionConfigValue QGVAR(missionFlagCustomScripting);
private _missionCustomScriptingStr = if(isNil QUOTE(_missionCustomScripting)) then {MDCHECK} else {[_missionCustomScripting] call _trueFalse};
private _missionCustomLoadout = getMissionConfigValue QGVAR(missionFlagCustomLoadout);
private _missionCustomLoadoutStr = if(isNil QUOTE(_missionCustomLoadout)) then {MDCHECK} else {[_missionCustomLoadout] call _trueFalse};
private _missionCustomVicLoadout = getMissionConfigValue QGVAR(missionFlagCustomVicLoadout);
private _missionCustomVicLoadoutStr = if(isNil QUOTE(_missionCustomVicLoadout)) then {MDCHECK} else {[_missionCustomVicLoadout] call _trueFalse};
private _unitSpecificBrief = getMissionConfigValue QGVAR(missionFlagUnitSpecificBriefing);
private _unitSpecificBriefStr = if(isNil QUOTE(_unitSpecificBrief)) then {MDCHECK} else {[_unitSpecificBrief] call _trueFalse};
private _missionNotesForTester =  getMissionConfigValue QGVAR(missionMakerNotesForTesters);
private _masterChecklistArray = nil;
private _armotTestingText = call FUNC(summarizeArmorTesting);
private _textArray = [];
private _textArrayShort = [];

if(_missionMaker == name ACE_player || is3DEN) then {
    _masterChecklistArray = GVAR(MissionMakerChecklistMaster);
    S_NEWTEXTLINE ["# __**Mission: %1**__   **__Type : %2__**", _missionName, _missionType];
    S_NEWTEXTLINE ["# __**Version: %1**__   __**BWMF Version : %2**__",_missionVersion,_missionFrameworkDate];
    // TEMP CODE Remove cicrca 2026-10-01
    if (_missionSSTime > 0 && _missionSSTime < 30) then {
        _missionSSTime = _missionSSTime * 60; // assume it was in minutes, convert to seconds
    };
    if (_missionTimeLength > 0 && _missionTimeLength < 200) then {
        _missionTimeLength = _missionTimeLength * 60; // assume it was in minutes, convert to seconds
    };
    // END TEMP CODE Remove cicrca 2026-10-01
    S_NEWTEXTLINE ["## Mission Tags : %1, %2, %3  SS Length (mins): %4  Mission Length (mins): %5 ",_missionTag1,_missionTag2,_missionTag3,ceil (_missionSSTime / 60), ceil (_missionTimeLength / 60)];
    if (isServer && name ACE_player == _missionMaker) then {
        S_NEWTEXTLINE ["## __Mission Summary (As shown in Slotting screen, Inc of Ratio if TvT) :__"];
        S_NEWTEXTLINE ["%1",_missionSummary];
    };
    S_NEWTEXTLINE ["## Player Count - MIN: %1 Recommended: %2 MAX: %3",_missionPlayerCountMin, _missionPlayerCountRec,_missionPlayerCountMax];
    S_NEWTEXTLINE_FORMATTEXT ["## Custom Scripting: %1 Custom Loadout: %2 Custom Vic Loadout: %3  Unit Specific Briefings: %4",_missionCustomScriptingStr,_missionCustomLoadoutStr,_missionCustomVicLoadoutStr,_unitSpecificBriefStr];

    S_NEWTEXTLINE_SHORT ["## __**New Version: %1**__",_missionVersion];

    {
        _x call _createReportSection;
    } forEach _masterChecklistArray;

    S_NEWTEXTLINE_SHORT ["## **__Version Changes__**:"];
    S_NEWTEXTLINE_SHORT ["%1",GVAR(GeneraMissionNotesForMM)];
    S_NEWTEXTLINE["## **__Any other notes for Mission Testers__**:"];
    S_NEWTEXTLINE["%1",GVAR(GeneraMissionNotesForMM)];

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
        _reportCtrlNewTitle ctrlSetText "Long Form Report";
        private _reportCtrlNew = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),IDC_REPORT_L];
        _reportCtrlNew ctrlSetPosition [-0.35,0.05,0.34,0.5];
        _reportCtrlNew ctrlCommit 0;
        _reportCtrlNew ctrlSetText _textLong;
        private _reportCtrlNewTitleShort = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1];
        _reportCtrlNewTitleShort ctrlSetPosition [-0.35,0.55,0.34,0.05];
        _reportCtrlNewTitleShort ctrlSetTextColor TEXT_ORANGE;
        _reportCtrlNewTitleShort ctrlCommit 0;
        _reportCtrlNewTitleShort ctrlSetText "Short Report (Version Update)";
        private _reportCtrlNewShort = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),IDC_REPORT_S];
        _reportCtrlNewShort ctrlSetPosition [-0.35,0.6,0.34,0.4];
        _reportCtrlNewShort ctrlCommit 0;
        _reportCtrlNewShort ctrlSetText _textShort;
    } else {
        _reportCtrlLong ctrlSetText _textLong;
        _reportCtrlShort ctrlSetText _textShort;
    };
    hint "Reports Generated. Highlight the contents to the left of the checklist and copy it to discord forum.";
} else {
    _masterChecklistArray = +GVAR(MissionTestingChecklistMaster);
    S_NEWTEXTLINE ["# __**Version: %1**__",_missionVersion];
    S_NEWTEXTLINE ["## Mission Tester: %1",name ACE_player];
    private _missionOverallPassFail = [_masterChecklistArray] call _overallPassFail;
    S_NEWTEXTLINE ["# Test Result: %1",_missionOverallPassFail];

    if (_armotTestingText isNotEqualTo "") then {
        private _otherConsid = _masterChecklistArray select -1;
        _otherConsid set [3, [_otherConsid#3, _armotTestingText] joinString endl];
        _otherConsid set [4, 1];
    };

    {
        _x call _createReportSection;
    } forEach _masterChecklistArray;

    S_NEWTEXTLINE["## **__General Feedback from Mission Tester__**:"];
    S_NEWTEXTLINE["%1",GVAR(GeneraMissionNotesForMM)];

    private _text = _textArray joinString endl;
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
    hint "Report Generated. Highlight the contents to the left of the checklist and copy it to the discord forum.";
};

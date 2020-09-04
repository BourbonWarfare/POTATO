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
    private _notesFlatStr = BBNOTEFLAG_A select _sectionNotesFlag;
    S_NEWTEXTLINE ["[size=150][u][color=#00BFFF]%1[/color][/u] : %2 [/size] %3",_sectionTitle,_passFailText,_notesFlatStr];
    S_NEWTEXTLINE ["[spoiler=%1 Checklist + Notes if applicable]",_sectionTitle];
    S_NEWTEXTLINE ["[list]"];
    {_x call _checkBoxes;} forEach _sectionArray;
    S_NEWTEXTLINE ["[/list]"];
    if(_missionMaker != name player) then {
        S_NEWTEXTLINE ["[u][color=#FF4000][size=150]NOTES :[/size][/color][/u]"];
        S_NEWTEXTLINE ["%1",_sectionNotes];
    };
    S_NEWTEXTLINE ["[/spoiler]"];
};

private _missionMaker = getMissionConfigValue ["author","????"];
private _missionName = getMissionConfigValue ["onLoadName", getMissionConfigValue ["briefingName","????"]];
private _missionType = A_MISSION_TYPE select (getMissionConfigValue QGVAR(missionType));
private _missionVersion = getMissionConfigValue QGVAR(missionVersion);
private _missionSummary = getMissionConfigValue "IntelOverviewText";
private _missionPlayerCountMax = getMissionConfigValue QGVAR(playerCountMaximum);
private _missionPlayerCountMin = getMissionConfigValue QGVAR(playerCountMinimum);
private _missionPlayerCountRec = getMissionConfigValue QGVAR(playerCountRecommended);
private _missionTag1 = A_MISSION_TAGS select (getMissionConfigValue QGVAR(missionTag1));
private _missionTag2 = A_MISSION_TAGS select (getMissionConfigValue QGVAR(missionTag2));
private _missionTag3 = A_MISSION_TAGS select (getMissionConfigValue QGVAR(missionTag3));
private _missionCustomScripting = getMissionConfigValue QGVAR(missionFlagCustomScripting);
private _missionCustomScriptingStr = [_missionCustomScripting] call _trueFalse;
private _missionCustomLoadout = getMissionConfigValue QGVAR(missionFlagCustomLoadout);
private _missionCustomLoadoutStr = [_missionCustomLoadout] call _trueFalse;
private _missionCustomVicLoadout = getMissionConfigValue QGVAR(missionFlagCustomVicLoadout);
private _missionCustomVicLoadoutStr = _missionCustomVicLoadout call _trueFalse;
private _unitSpecificBrief = getMissionConfigValue QGVAR(missionFlagUnitSpecificBriefing);
private _unitSpecificBriefStr = [_unitSpecificBrief] call _trueFalse;
private _missionNotesForTester =  getMissionConfigValue QGVAR(missionMakerNotesForTesters);
private _masterChecklistArray = nil;
private _textArray = [];
private _textArrayShort = [];

if(_missionMaker == name player) then {
    _masterChecklistArray = GVAR(MissionMakerChecklistMaster);
    S_NEWTEXTLINE ["[size=200][u][b]Mission : [color=#FF4000]%1[/color][/b][/u]   [b][u]Type : [color=#FF4000]%2[/color][/u][/b][/size]", _missionName, _missionType];
    S_NEWTEXTLINE ["[size=200][u][b]Version : [color=#FF4000]%4[/color][/b][/u][/size] [size=150]  Mission Tags : [color=#FF4000]%1,%2,%3[/color]  [/size] ",_missionTag1,_missionTag2,_missionTag3,_missionVersion];
    S_NEWTEXTLINE ["[size=150][u]Mission Summary (As shown in Slotting screen, Inc of Ratio if TvT) :[/u][/size]"];
    S_NEWTEXTLINE ["[color=#FF4000]%1[/color]",_missionSummary];
    S_NEWTEXTLINE ["[size=150]Player Count - MIN: [color=#FF4000]%1[/color] Recommended: [color=#FF4000]%2[/color] MAX: [color=#FF4000]%3[/color][/size]",_missionPlayerCountMin, _missionPlayerCountRec,_missionPlayerCountMax];
    S_NEWTEXTLINE_FORMATTEXT ["[size=150]Custom Scripting : %1 Custom Loadout : %2 Custom Vic Loadout : %3  Unit Specific Breigings : %4[/size]",_missionCustomScriptingStr,_missionCustomLoadoutStr,_missionCustomVicLoadoutStr,_unitSpecificBriefStr];

    S_NEWTEXTLINE_SHORT ["[size=150][u][b]New Version : [color=#FF4000]%1[/color][/b][/u][/size]",_missionVersion];

    {
        _x call _createReportSection;
    } forEach _masterChecklistArray;

    S_NEWTEXTLINE_SHORT ["[size=150][b][u]Version Changes[/u][/b][/size] :"];
    S_NEWTEXTLINE_SHORT ["%1",GVAR(GeneraMissionNotesForMM)];
    S_NEWTEXTLINE["[size=150][b][u]Any other notes for Mission Testers[/u][/b][/size] :"];
    S_NEWTEXTLINE["[color=#FF4000]%1[/color]",GVAR(GeneraMissionNotesForMM)];

    private _textLong = _textArray joinString (endl + endl);
    private _textShort = _textArrayShort joinString (endl + endl);
    private _reportCtrlLong = DISPLAY_TESTMENU displayCtrl IDC_REPORT_L;
    private _reportCtrlShort = DISPLAY_TESTMENU displayCtrl IDC_REPORT_S;
    if (isNull _reportCtrlLong) then {
        private _reportCtrlNewTitle = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1];
        _reportCtrlNewTitle ctrlSetPosition [-0.35,0,0.35,0.05];
        _reportCtrlNewTitle ctrlCommit 0;
        _reportCtrlNewTitle ctrlSetText "Long Form Report";
        private _reportCtrlNew = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),IDC_REPORT_L];
        _reportCtrlNew ctrlSetPosition [-0.35,0.05,0.35,0.5];
        _reportCtrlNew ctrlCommit 0;
        _reportCtrlNew ctrlSetText _textLong;
        private _reportCtrlNewTitleShort = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscText),-1];
        _reportCtrlNewTitleShort ctrlSetPosition [-0.35,0.55,0.35,0.05];
        _reportCtrlNewTitleShort ctrlCommit 0;
        _reportCtrlNewTitleShort ctrlSetText "Short Report (Version Update)";
        private _reportCtrlNewShort = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),IDC_REPORT_S];
        _reportCtrlNewShort ctrlSetPosition [-0.35,0.6,0.35,0.4];
        _reportCtrlNewShort ctrlCommit 0;
        _reportCtrlNewShort ctrlSetText _textShort;
    } else {
        _reportCtrlLong ctrlSetText _textLong;
        _reportCtrlShort ctrlSetText _textShort;
    };
    hint "Reports Generated. Highlight the contents to the left of the checklist and copy it to forum.";
} else {
    _masterChecklistArray = GVAR(MissionTestingChecklistMaster);
    S_NEWTEXTLINE ["[size=200][u][b]Version : [color=#FF4000]%1[/color][/b][/u][/size]",_missionVersion];
    S_NEWTEXTLINE ["[size=150]Mission Tester : [color=#FF4000]%1[/color][/size]",name player];
    private _missionOverallPassFail = [_masterChecklistArray] call _overallPassFail;
    S_NEWTEXTLINE ["[size=200]Test Result : %1[/size]",_missionOverallPassFail];

    {
        _x call _createReportSection;
    } forEach _masterChecklistArray;

    S_NEWTEXTLINE["[size=150][b][u]General Feedback from Mission Tester[/u][/b][/size] :"];
    S_NEWTEXTLINE["%1",GVAR(GeneraMissionNotesForMM)];

    private _text = _textArray joinString (endl + endl);
    private _reportCtrl = DISPLAY_TESTMENU displayCtrl IDC_REPORT_L;
    if (isNull _reportCtrl) then {
        private _reportCtrlNew = DISPLAY_TESTMENU ctrlCreate [QUOTE(RscEditMulti),IDC_REPORT_L];
        _reportCtrlNew ctrlSetPosition [-0.35,00.5,0.35,1];
        _reportCtrlNew ctrlCommit 0;
        _reportCtrlNew ctrlSetText _text;
    } else {
        _reportCtrl ctrlSetText _text;
    };
    hint "Report Generated. Highlight the contents to the left of the checklist and copy it to forum.";
};


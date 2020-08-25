/*
 * Author: BadWolf
 * Function called to generate the report.
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

private _missionType = ;
private _missionMaker = getMissionConfigValue ["author","????"];

private _trueFalse = {
    params["_cbValue"];
    if (_cbValue) then {BBTRUE;} else {BBFALSE};
};
private _passFail = {
    params["_value"];
    switch (_value) do {
    case 0 : {_value = BBFAIL};
    case 1 : {_value = BBPASS};
    case 2 : {_value = BBNA};
    };
_value;
};

private _checkBoxes = {
    params["_textIndex"];
    private _cbText = GVAR(checklist) select _textIndex select 0;
    private _cbValue = GVAR(checklist) select (_textIndex + 1) select 0;
    _cbValue = [_cbValue] call _trueFalse;
    S_NEWTEXTLINE_FORMATTEXT ["[*]%1 : %2",_cbText,_cbValue];
};

private _generateReportHeaderMissionMaker = {
    params[""];

};

private _generateReportHeaderMissionTester = {
    params[""];

};

private _createReportSection = {
    params[""];

};

private _createReportLine = {
    params[""];

};

if(_missionMaker == name player) then {
    [] call _generateReportHeaderMissionMaker;
    {
        [] call _createReportSection;
    } forEach GVAR(MissionMakerChecklistMaster);
} else {
    [] call _generateReportHeaderMissionTester;
    {
        [] call _createReportSection;
    } forEach GVAR(MissionTestingChecklistMaster);
};

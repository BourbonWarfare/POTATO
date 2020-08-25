/*
 * Author: BadWolf
 * Function is called by a control EH everytime that a CB is changed in the checklist.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_updateCheckedCB;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_control", "_checked"];

private _idc = ctrlIDC _control;
private _str = str _idc;
private _array = _str splitString "";
private _subsection = parseNumber _array select 1;
private _lineTens = parseNumber _array select 2;
private _lineUnits = parseNumber _array select 3;
private _line = (_lineTens * 10) + _lineUnits;
private _masterChecklist = nil;

if(_missionMaker == name player) then {
    _masterChecklist = GVAR(MissionTestingChecklistMaster);// Needs to Be changed back after testing "MissionMakerChecklistMaster"
} else {
    _masterChecklist = GVAR(MissionTestingChecklistMaster);
};

private _subsectionArray = _masterChecklist select _subSection;
private _subSectionArrayCBs = _subsectionArray select 1;
private _specificLine = _subsectionArrayCBs select _line;

_specificLine set [1,_checked];
_subSectionArrayCBs set [_line,_specificLine];
_subSectionArray set [1,_subSectionArrayCBs];
_masterChecklist set [_subsection,_subSectionArray];

if(_missionMaker == name player) then {
    GVAR(MissionTestingChecklistMaster) = _masterChecklist;// Needs to Be changed back after testing "MissionMakerChecklistMaster"
} else {
    GVAR(MissionTestingChecklistMaster) = _masterChecklist;
};

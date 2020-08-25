/*
 * Author: BadWolf
 * Function is called by a control EH everytime that a multiEdit box is exited by the used.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_updateNotesFlag;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_control"];

private _idc = ctrlIDC _controls;
private _str = str _idc;
private _array = _str splitString "";
private _subsection = parseNumber _array select 3;
private _masterChecklist = nil;
private _text = ctrlText _control;


if(_missionMaker == name player) then {
    _masterChecklist = GVAR(MissionTestingChecklistMaster);// Needs to Be changed back after testing "MissionMakerChecklistMaster"
} else {
    _masterChecklist = GVAR(MissionTestingChecklistMaster);
};

private _subSectionArray = _masterChecklist select _subsection;

_subSectionArray set [3,_text];
_masterChecklist set [_subsection,_subSectionArray];

if(_text == "") then {
    _subSectionArray set [4,D_NOTEFLAG];
} else {
    _subSectionArray set [4,1];
};
_masterChecklist set [_subsection,_subSectionArray];

if(_missionMaker == name player) then {
    GVAR(MissionTestingChecklistMaster) = _masterChecklist;// Needs to Be changed back after testing "MissionMakerChecklistMaster"
} else {
    GVAR(MissionTestingChecklistMaster) = _masterChecklist;
};

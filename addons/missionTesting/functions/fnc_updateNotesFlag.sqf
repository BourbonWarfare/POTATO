/*
 * Author: BadWolf
 * Function is called by a control EH everytime that a multiEdit box is exited by the used.
 *
 * Arguments:
 *
 * Examples:
 * [contol] call potato_missionTesting_fnc_updateNotesFlag;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_control"];

private _idc = ctrlIDC _control;
private _str = str _idc;
private _array = _str splitString "";
private _subsection = parseNumber (_array select 3);
TRACE_2("_subSectionArray Before",_array,_subsection);
private _masterChecklist = nil;
private _text = ctrlText _control;
private _missionMaker = getMissionConfigValue ["author","????"];


if(_missionMaker == name ACE_PLAYER) then {
    _masterChecklist = GVAR(MissionMakerChecklistMaster);
} else {
    _masterChecklist = GVAR(MissionTestingChecklistMaster);
};
TRACE_1("_masterChecklist Before",_masterChecklist);

private _subSectionArray = _masterChecklist select _subsection;

_subSectionArray set [3,_text];
TRACE_1("_subSectionArray After",_subSectionArray);
_masterChecklist set [_subsection,_subSectionArray];
TRACE_1("_masterChecklist After",_masterChecklist);

if(_text == "") then {
    _subSectionArray set [4,D_NOTEFLAG];
} else {
    _subSectionArray set [4,1];
};
_masterChecklist set [_subsection,_subSectionArray];

if(_missionMaker == name ACE_PLAYER) then {
    GVAR(MissionMakerChecklistMaster) = _masterChecklist;
} else {
    GVAR(MissionTestingChecklistMaster) = _masterChecklist;
};

/*
 * Author: BadWolf
 * Function called to update the checklistMaster everytime that a selection is changed in a ListBox.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_updateSelectionLB;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_control", "_selectedIndex"];

private _idc = ctrlIDC _control;
private _str = str _idc;
private _array = _str splitString "";
private _subsection = parseNumber (_array select 3);
private _masterChecklist = nil;
private _missionMaker = getMissionConfigValue ["author","????"];

if(_missionMaker == name player) then {
    _masterChecklist = GVAR(MissionTestingChecklistMaster);// Needs to Be changed back after testing "MissionMakerChecklistMaster"
} else {
    _masterChecklist = GVAR(MissionTestingChecklistMaster);
};

private _subSectionArray = _masterChecklist select _subsection;

_subSectionArray set [2,_selectedIndex];
_masterChecklist set [_subsection,_subSectionArray];

if(_missionMaker == name player) then {
    GVAR(MissionTestingChecklistMaster) = _masterChecklist;// Needs to Be changed back after testing "MissionMakerChecklistMaster"
} else {
    GVAR(MissionTestingChecklistMaster) = _masterChecklist;
};

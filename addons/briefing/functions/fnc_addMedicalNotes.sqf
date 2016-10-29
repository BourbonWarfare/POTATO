/*
 * Author: AACO
 * Function used to add medical notes to a player's diary
 *
 * Arguments:
 * 0: Unit to add to the notes to <OBJECT>
 *
 * Examples:
 * [player] call potato_briefing_fnc_addMedicalNotes;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_newPlayer);
params ["_newPlayer"];

if !(_newPlayer diarySubjectExists "medical") then { _newPlayer createDiarySubject ["medical","Medical"]; };

private _wounds = "true" configClasses (configfile >> "ACE_Medical_Advanced" >> "Injuries" >> "wounds"); // get wounds
private _playerClass = typeOf _newPlayer; // get player class
private _isMedic = [_newPlayer] call ACEFUNC(medical,isMedic);

[_newPlayer, _isMedic, _wounds] call FUNC(addTreatmentDiary);
[_newPlayer, _wounds] call FUNC(addWoundDiary);
[_newPlayer, _isMedic] call FUNC(addResponsibilitiesDiary);

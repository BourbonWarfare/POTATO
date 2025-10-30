#include "script_component.hpp"

params ["_sideUpdated"];

if (!hasInterface || {!alive ACE_player}) exitWith {};
private _playerSide = side group ACE_player;
if (_sideUpdated != _playerSide) exitWith {};

private _key = format [QGVAR(briefing_coyIntent_%1), _playerSide];
(missionNamespace getVariable [_key, ["", ""]]) params ["_author", "_currentText"];

private _diaryRec = objNull;
{
    _x params ["", "_xId", "", "", "", "", "", "", "_xRecord"];
    if (_xId == "COY's Intent") exitWith { _diaryRec = _xRecord; };
} forEach (ACE_player allDiaryRecords "Diary");
if ((isNull _diaryRec) && {_currentText == ""}) exitWith {}; // never set
if (isNull _diaryRec) then { _diaryRec = ACE_player createDiaryRecord ["Diary", ["COY's Intent", "###"]]; };

ACE_player setDiaryRecordText [["diary", _diaryRec], ["COY's Intent", format ["%1:<br/><br/>%2", _author, _currentText]]];

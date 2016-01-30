#include "script_component.hpp"

TRACE_1("params",_this);

private _selectedIndexSide = lbCurSel UI_TAB_MISSIONHINT_SIDE;
if ((_selectedIndexSide < 0) || (_selectedIndexSide >= (count HINT_SIDES))) exitWith {};
private _selectedSide = HINT_SIDES select _selectedIndexSide;

private _selectedRankIndex = lbCurSel UI_TAB_MISSIONHINT_RANK;
if ((_selectedRankIndex < 0) || (_selectedRankIndex >= (count HINT_RANKS))) exitWith {};
private _selectedRank = HINT_RANKS select _selectedRankIndex;

private _hintText = ctrlText UI_TAB_MISSIONHINT_TEXT;

TRACE_3("sel",_selectedSide,_selectedRank,_hintText);

//Debug trace to admin log:
private _debugMsg = format ["Sending Hint to %1", _selectedSide];
["potato_adminMsg", [_debugMsg, profileName]] call ACEFUNC(common,globalEvent);

//Actual misison hint event:
private _debugMsg = format ["Sending Hint to %1", _selectedSide];
["potato_missionHint", [_hintText, _selectedSide, _selectedRank]] call ACEFUNC(common,globalEvent);

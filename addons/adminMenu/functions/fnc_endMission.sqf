#include "script_component.hpp"

params ["_winningSide"];
TRACE_1("params",_this);

// OCAP
potato_saveOcap =
{
	params ["_side"];

	_playableSideArray = [];
	{
		if ((playersNumber _x) > 0) then {
			_playableSideArray pushBack _x;
		};
	} forEach [WEST, EAST, RESISTANCE];
	if ((count _playableSideArray) > 1) then {
		_gameMode = "TvT";
	} else {
		_gameMode = "COOP";
	};

	[_side, "Mission ended", _gameMode] call ocap_fnc_exportData;
};

[_side] remoteExecCall ["potato_saveOcap", 2];

if ((!hasInterface) || {EGVAR(core,playerStartingSide) == _winningSide}) then {
    ["", true, 1] call BIS_fnc_endMission;
} else {
    ["", false, 1] call BIS_fnc_endMission;
};

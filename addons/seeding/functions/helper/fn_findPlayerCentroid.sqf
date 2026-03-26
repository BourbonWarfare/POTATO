#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This fucntion calculates the center point of alive players evenly weighted.
* Then uses that center to filter out players who are far away by first relying
* on the
*
* Arguments:
* None
*
* Return:
* Position (ATL) of the center of the players
*
* Example:
* [] call bw_fnc_findPlayerCentroid;
*//***************************************************************************/
private _meanPos = [0, 0, 0];
private _players = call CBA_fnc_players;
private _playerPoses = [];
private _countValidPlayers = 0;
{
	private _posPlayer = getPosATL _x;
	if (_posPlayer isNotEqualTo [0, 0, 0] && alive _x) then {
		_meanPos = _meanPos vectorAdd _posPlayer;
		_playerPoses pushBack _posPlayer;
		_countValidPlayers = _countValidPlayers + 1;
	};
} forEach _players;
private _inversePlayerCount = 1 / (_countValidPlayers max 1);
_meanPos set [2, 0];
_meanPos = _meanPos vectorMultiply _inversePlayerCount;

private _distances = _playerPoses apply {_x distance2D _meanPos};
private _distanceMean = 0;
{
	_distanceMean = _distanceMean + _x;
} forEach _distances;
_distanceMean = _distanceMean * _inversePlayerCount;

private _distanceSD = 0;
{
	_distanceSD = _distanceSD + (_x - _distanceMean)^2;
} forEach _distances;
_distanceSD = sqrt (_distanceSD * _inversePlayerCount);
private _maxDistance = 250 max (_distanceMean + _distanceSD);

private _centroid = [0, 0, 0];
private _countNonOutliers = 0;
{
	if (_distances#_forEachIndex < _maxDistance) then {
		_centroid = _centroid vectorAdd _x;
		_countNonOutliers = _countNonOutliers + 1;
	};
} forEach _playerPoses;

if (_centroid isEqualTo [0, 0, 0]) then {
	private _player = selectRandom (_players select {isNull objectParent _x});
	if (isNil "_player") then {
		_meanPos
	} else {
		getPosATL _player
	};
} else {
	_centroid set [2, 0];
	_centroid vectorMultiply (1 / (_countNonOutliers max 1))
}

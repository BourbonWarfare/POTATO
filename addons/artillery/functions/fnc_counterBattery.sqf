#include "..\script_component.hpp"
/**************************************************************//*
* Uses the artilleryFrame array to conduct counter battery
* missions
*
*
*   addMissionEventHandler ["ArtilleryShellFired", {
*       params ["_vehicle", "", "", "_gunner"];
*       if (side _gunner != west) exitWith {};
*       if (isNil QGVAR(cBatHash)) then {
*           GVAR(cBatHash) = createHashMap;
*           [{call FUNC(counterBattery)}, 0, 30] call CBA_fnc_waitAndExecute;
*       };
*       private _pos = _vehicle getPos [random 50, random 360];
*       private _notFound = true;
*       {
*           if (_pos inArea [_x, 100, 100, 0, true]) exitWith {
*               (_y#0) pushBack _pos;
*               _y set [1, CBA_missionTime];
*               _notFound = false;
*           };
*       } forEach GVAR(cBatHash);
*       if (_notFound) then {
*           GVAR(cBatHash) set [_pos apply {200 * round (_x / 200)}, [[_pos], CBA_missionTime]];
*       };
*   }];
*
*
*
*
*
*
* Arguments:
* None
*
* Example:
* [] call lmd_fnc_counterBattery;
*//**************************************************************/
private _cBatHash = GVAR(cBatHash);
if (isNil "_cBatHash") exitWith {
};
private _lastCBTime = _cBatHash getOrDefault ["lastCBTime", -180, true];
private _lastLocation = _cBatHash getOrDefault ["lastCBLoc", [], true];
if (_lastCBTime + 180 > CBA_missionTime || count keys _cBatHash < 3) exitWith {
    if (_lastCBTime + 180 < CBA_missionTime) then {
        GVAR(cBatHash) = nil;
    };
};
_cBatHash deleteAt "lastCBTime";
_cBatHash deleteAt "lastCBLoc";
{
    if (_y#1 < CBA_missionTime - 300) then {
        _cBatHash deleteAt _x;
    };
} forEach _cBatHash;
if (_cBatHash isEqualTo createHashMap) exitWith {
    GVAR(cBatHash) = nil;
};
private _keys = keys _cBatHash;
private _groups = [];
if (_lastCBTime - CBA_missionTime < 300) then {
    _keys = _keys - _lastLocation;
};
{
	private _notFound = true;
	private _pos = _x;
	{
		private _group = _x;
		{
			if (_x distance2D _pos < 283) exitWith {
				_notFound = false;
				_group pushBack _pos;
			};
		} forEach _x;
	} forEach _groups;
	if (_notFound) then {
		_groups pushBack [_pos];
	};
} forEach _keys;

private _maxValue = -1;
private _sumValue = 0;
private _groupID = 0;
{
	private _value = 0;
	{
		(_cBatHash get _x) params ["_points", "_lastTIme"];
		_value = _value + exp (-0.00385*(CBA_missionTime - _lastTIme)) * count _points;
	} forEach _x;
	if (_value > _maxValue) then {
		_maxValue = _value;
		_groupID = _forEachIndex;
	};
    _sumValue = _sumValue + _value;
} forEach _groups;

if (_sumValue < 3) exitWith {
    _cBatHash set ["lastCBTime", _lastCBTime];
    _cBatHash set ["lastCBLoc", _lastLocation];
    [{call FUNC(counterBattery)}, 0, 20 + random [0, 10, 20]] call CBA_fnc_waitAndExecute;
};
hintSilent format ["Value: %1", _sumValue];

private _posArr = [];
private _group = _groups#_groupID;
{
	_posArr append ((_cBatHash get _x)#0);
    _cBatHash deleteAt _x;
} forEach _group;

private _avgPos = [0,0,0];
{
	_avgPos = _avgPos vectorAdd _x;
} forEach _posArr;
private _cntInv = 1 / count(_posArr);
_avgPos = _avgPos vectorMultiply _cntInv;
private _std = [0, 0, 0];
{
	private _diff = (_avgPos vectorDiff _x);
	_std = _std vectorAdd (_diff apply {_x^2});
} forEach _posArr;

private _rad = 3 * sqrt vectorMagnitude (_std vectorMultiply _cntInv); // something something six sigma
_avgPos set [2, 0];


private _immediateStrike = _sumValue > 10;
if (_immediateStrike) then {_rad = _rad max 100;};
[QGVAR(addMission), [
    profileName + ":" + str CBA_missionTime,
    clientOwner,
    createHashMapFromArray [["gunCount", round linearConversion [50, 250, _rad, 2, 4]],
        ["position", _avgPos],
        ["roundType", [82, "CUP_8Rnd_82mm_Mo_shells_veh"]],
        ["dispersion", _rad max 60],
        ["missionType", [ARTILLERY_MISSIONTYPE_BRACKET, ARTILLERY_MISSIONTYPE_POINT] select _immediateStrike],
        ["missionLength", linearConversion [0, 20, _sumValue, 4, 12, true]],
        ["missionDelay", [5, linearConversion [20, 10, _sumValue, 10, 35, true]] select _immediateStrike]
    ]
]] call CBA_fnc_serverEvent;
_cBatHash set ["lastCBTime", CBA_missionTime];
_cBatHash set ["lastCBLoc", _group];
[{call FUNC(counterBattery)}, 0, 180.1] call CBA_fnc_waitAndExecute;

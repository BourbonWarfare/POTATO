#include "..\script_component.hpp"
/**************************************************************//*
* Helper function that fires mortar rounds
*
* Arguments:
* _artilleryPiece - artillery piece to fire
* _targetse - Array of positions to hit
* _mag - magazine to fires
* _roundDelay - simulated time between shots, minimum of 5
* _cleanUp - Should reset tags on unit
*//**************************************************************/
params [
  "_artillery",
  "_targets",
  "_mag",
  ["_roundDelay", -1],
  ["_cleanUp", true]
];

private _gunner = _artillery turretUnit [0];
if (!alive _artillery || !alive _gunner || _targets isEqualTo []) exitWith {};

if !(local _gunner) then {
    [_this] remoteExecCall [QFUNC(fireOnArray), _gunner];
};

if (alive _gunner && {magazinesAmmo _artillery isNotEqualTo []}) exitWith {
  if (_artillery magazineTurretAmmo [_mag, [0]] == 0) then {
    _artillery setMagazineTurretAmmo [_mag, 1, [0]];
  };
  [{_this call FUNC(fireOnArray)}, _this, 0.25] call CBA_fnc_waitAndExecute;
};

private _weapon = (_artillery weaponsTurret [0])#0;
if (_roundDelay < 0) then {
    _roundDelay = _weapon call FUNC(getArtyReloadTime);
    _this set [3, _roundDelay];
};

_roundDelay = 4 max _roundDelay;
removeAllWeapons _artillery;
{
  _artillery removeMagazinesTurret [_x, [0]];
} forEach getArtilleryAmmo [_artillery];

if (_artillery currentMagazineTurret [0] != "") then {
  _artillery removeMagazineTurret [_artillery currentMagazineTurret [0], [0]];
};

_artillery addMagazineTurret [_mag, [0], 1];
[{
    params ["_artillery", "_weapon", "_gunner", "_targ", "_mag"];
    _artillery addWeapon _weapon;
    _gunner doArtilleryFire [_targ, _mag, 1];
}, [_artillery, _weapon, _gunner, ((_this#1) deleteAt [-1])#0, _mag], 1] call CBA_fnc_waitAndExecute;

if (_cleanUp && _targets isEqualTo []) then {
    [{
        params ["_artillery", "_magazine"];
        private _missionParams = _artillery getVariable [QGVAR(artyMission), [""]];
        _missionParams params [
            "_missionID", "", "_holdTime", ["_missionType", ARTILLERY_MISSIONTYPE_POINT]
        ];
        if (_missionID != "" &&
           _missionType in ARTILLERY_REPORT_ON_COMPLETION) then {
            [QGVAR(missionComplete), [_missionID]] call CBA_fnc_serverEvent;
            _missionParams set [3, ARTILLERY_MISSIONTYPE_UNDEF];
            _missionParams set [2, 420 + _missionParams#2];
        } else {
            _artillery setVariable [QGVAR(artyMission), nil];
        };
        _artillery removeMagazinesTurret [_magazine, [0]];

    }, [_artillery, _mag], _roundDelay + 15] call CBA_fnc_waitAndExecute;
};

if (_targets isNotEqualTo []) then {
    [{_this call FUNC(fireOnArray)}, _this, _roundDelay] call CBA_fnc_waitAndExecute;
};

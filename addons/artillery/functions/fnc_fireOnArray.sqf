#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Recursive function that manages a single gun firing on an array of targets
 * positions using a specified magazine. A round delay can be specified, or
 * if the delay is less than 0 the config value is used. The relevant artillery
 * piece has it's magazines and weapons manipulated to load a single round
 * and then fire that round. The target array, conceptually a stack, is
 * used from the end to the front, removing each last element and using it
 * to target a round. When the _targets array is empty the function will
 * no longer call itself.
 *
 * Arguments:
 * _artillery - The artillery piece to shoot, OBJECT
 * _targets - An array of positions to fire on, ARRAY of posAGL
 * _mag - The magazine the artillery piece should fire, STRING
 * _roundDelay - Simulated time between shots. NUMBER, default -1
 * _cleanUp - Should reset gun tags on mission compelte. BOOLEAN, default true
 *
 * Return:
 * None
 *
 * Example:
 * [arty0, [getPosATL player], "relevantArtyMag"] call potato_artillery_fnc_fireOnArray;
 *
 * Public: No
 */
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

private _weapon = GVAR(vehicleWeaponCache) getOrDefaultCall [typeOf _artillery, {
    private _cfg = (configOf _artillery) >> "Turrets";
    private _turret = 0;
    while {getNumber ((_cfg select _turret) >> "primaryGunner") == 0} do {_turret = _turret + 1;};
    (_artillery weaponsTurret [_turret])#0
}, true];
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

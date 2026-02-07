#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Local handler to start artillery guns onto an artillery mission.
 * This function takes a number of paramters and uses _missionType to start
 * a specific type of mission using the parameters. If an invalid missionType
 * is given or hte gunner of the gun is not local, the function exits. If the
 * gunner is local, then the function will rotate the artillery piece using
 * setDir and remove all magazines from turret path [0].
 *
 * Arguments:
 * _gun - The gun (vehicle) firing in the mission. OBJECT, default objNull
 * _offset - Position offset of the main fire mission target. ARRAY, default [0,0,0]
 * _missionType - The mission type, prefence is defined types. SCALAR, default ARTILLERY_MISSIONTYPE_POINT
 * _magazine - Magazine the artillery piece should fire. STRING
 * _posATL - Position in ATL format the center of the mission occurs at. ARRAY
 * _dispersion - Round dispersion, typically the minor radius of the fire mission. SCALAR, default 100
 * _rotation - Rotation in degrees of the mission. SCALAR, default 0
 * _avoidPlayers - Attempt to avoid players, currently does nothing. BOOLEAN, true
 * _rounds - The number of rounds a gun should fire. SCALAR, default 4
 * _tof - Time of flight or other timing params, calculated by server. SCALAR, default -1
 * _gunIdx - An index of which gun is given, used for slow barrages. SCALAR, default 0
 * _nGuns - Number of guns involved in the mission, used in slow barrages. SCALAR, default 1
 * _length - Length of the mission in seconds, used in slow barrages. SCALAR, default 180
 *
 * Return:
 * None
 *
 * Example:
 * [_arty0, [0,0,0], ARTILLERY_MISSIONTYPE_POINT, "8Rnd_82mm_Mo_Smoke_white", getPosATL palyer] call potato_artillery_fnc_localmissionInit;
 *
 * Public: No
 */
params [
    ["_gun", objNull, [objNull]],
    ["_offset", [0, 0, 0], [[]]],
    ["_missionType", ARTILLERY_MISSIONTYPE_POINT, [ARTILLERY_MISSIONTYPE_POINT]],
    "_magazine",
    "_posATL",
    ["_dispersion", 100, [100]],
    ["_rotation", 0, [0]],
    ["_avoidPlayers", true, [true]],
    ["_rounds", 4, [4]],
    ["_tof", -1, [-1]],
    ["_gunIdx", 0, [0]],
    ["_nGuns", 1, [1]],
    ["_length", 180, [180]]
];
if (!alive _gun) exitWith {};

private _gunner = gunner _gun;
if !(local _gunner) then {};

_gun setDir (_gun getDir _posATL);

// clear mortar and load with magazines
private _magazinesToRemove = _gun magazinesTurret [0];
{_gun removeMagazinesTurret [_x, [0]]} count _magazinesToRemove;

// save weapon parameters
(GVAR(vehicleWeaponCache) getOrDefaultCall [typeOf _gun, {
    private _cfg = (configOf _gun) >> "Turrets";
    private _turret = 0;
    while {getNumber ((_cfg select _turret) >> "primaryGunner") == 0} do {_turret = _turret + 1;};
    (_gun weaponsTurret [_turret])#0
}, true]) params ["_weapon", "_turret"];

// Fire barrage
switch (_missionType) do {
    case ARTILLERY_MISSIONTYPE_LAZY_WALK: {
        private _targetArray = [];
        _rotation = 180 + _rotation;
        {
            _targetArray pushBack (_posATL getPos [_x, _rotation - 5 + random 10]);
        } forEach ARTILLERY_POSITIONS_LAZYADJUST;
        [_gun, _targetArray, _magazine, _tof + 20 + random 15] call FUNC(fireOnArray);
    };
    case ARTILLERY_MISSIONTYPE_BRACKET_BARRAGE;
    case ARTILLERY_MISSIONTYPE_LAZY_BARRAGE;
    case ARTILLERY_MISSIONTYPE_POINT: {
        [_gunner, _gun, _posATL, _dispersion,
         _magazine, [_weapon, _turret], _rounds,
        [[cos _rotation, sin _rotation],[-sin _rotation, cos _rotation]]] call FUNC(fireOnPos);
    };
    case ARTILLERY_MISSIONTYPE_SLOW: {
        private _reloadTime = [_weapon] call FUNC(getArtyReloadTime);
        _length = _length max (_reloadTime * _rounds);
        private _intrRnd = _length / (_rounds + 1);
        _gunIdx = _gunIdx max 0;
        private _interRndStart = _intrRnd * (_gunIdx + random [0, 0.3 + random 0.4, 1]) / _nGuns;
        [
            {call FUNC(fireOnPos)},
            [_gunner, _gun, _posATL, _dispersion, _magazine, [_weapon, _turret], _rounds,
            [[cos _rotation, sin _rotation],[-sin _rotation, cos _rotation]],
            call CBA_fnc_players, _intrRnd],
            _interRndStart
        ] call CBA_fnc_waitAndExecute;
    };
    case ARTILLERY_MISSIONTYPE_BRACKET_SHOTS: {
        private _targetArray = [];
        private _playerArray = call CBA_fnc_players;
        _rotation = 180 + _rotation;
        {
            _targetArray pushBack ([
                _posATL, _x, _rotation, _playerArray
            ] call FUNC(findSafeMortarPos));
        } forEach ARTILLERY_POSITIONS_BRACKET(_dispersion);
        [_gun, _targetArray, _magazine, _tof + 10] call FUNC(fireOnArray);
    };
    case ARTILLERY_MISSIONTYPE_LINEAR: {
        [[_offset getPos [_dispersion, _rotation - 180],
          _offset getPos [_dispersion, _rotation]],
          _gun,
          _magazine,
          2 * _rounds,
          1,
          true
        ] call FUNC(linearBarrage);
    };
    case ARTILLERY_MISSIONTYPE_CREEPING: {
        [[_offset getPos [_dispersion, _rotation],
            _offset getPos [_dispersion, 180 + _rotation]],
            _gun,
            _magazine,
            _rounds,
            2,
            false
        ] call FUNC(linearBarrage);
    };
    default {};
};

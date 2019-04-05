/*
 * Author: Brandon (TCVM)
 * Checks hitpoint damage and determines if a vehicle should cookoff
 *
 * Arguments:
 * 0: The vehicle
 * 1: Hitindex that got hit
 * 2: Vehicle damage before hit
 * 3: Damage applied
 * 4: Projectile
 *
 * Return Value:
 * None
 *
 * Example:
 * [tank2] call potato_aiVehicleBail_fnc_handleCookoff;
 *
 *
 * Public: No
 */
#include "script_component.hpp"
params ["_vehicle", "_hitIndex", "_oldDamage", "_newDamage", "_projectile"];

if !(GVAR(enableCookoff)) exitWith {};

private _hitPoint = toLower ((getAllHitPointsDamage _vehicle param [0, []]) select _hitIndex);

private _possibleCookoff = (_hitPoint isEqualTo "hitturret") || { _hitPoint isEqualTo "hithull" } || { _hitPoint isEqualTo "hitengine" };
if !(_possibleCookoff) exitWith {};
private _currentVehicleAmmo = [_vehicle] call ACEFUNC(cookoff,getVehicleAmmo);

private _chanceOfDetonation = 0;
private _countOfExplodableAmmo = 0;
if (count (_currentVehicleAmmo select 0) > 0) then {
    private _magConfig = configFile >> "CfgMagazines";
    {
        _x params ["_ammoClassname", "_currentAmmoCount"];
        private _initialAmmoCount = getNumber(_magConfig >> _ammoClassname >> "count");
        _chanceOfDetonation = _chanceOfDetonation + (_currentAmmoCount / _initialAmmoCount);
        _countOfExplodableAmmo = _countOfExplodableAmmo + 1;
    } forEach (_currentVehicleAmmo select 0);
    _chanceOfDetonation = _chanceOfDetonation / _countOfExplodableAmmo;
};
private _currentFuel = fuel _vehicle;

private _warheadType = getText (_projectile call CBA_fnc_getObjectConfig >> "warheadName");
private _incendiary = 1;
private _explosiveType = ["HE", "AP", "HEAT", "TandemHEAT"] find _warheadType;
if (_explosiveType >= 0) then {
    _incendiary = [0.3, 0.85, 1, 1] select _explosiveType;
};
private _chanceOfDetonate = 0;
private _chanceOfFire = 0;

private _vehicleConfig = _vehicle call CBA_fnc_getObjectConfig;

switch (_hitPoint) do {
    case "hitturret": {
        _chanceOfDetonate = ([_vehicleConfig >> QGVAR(turretDetonationProb), "number", 0] call CBA_fnc_getConfigEntry) * _incendiary * _chanceOfDetonation;
        _chanceOfFire = ([_vehicleConfig >> QGVAR(turretFireProb), "number", 0] call CBA_fnc_getConfigEntry) * _incendiary * _chanceOfDetonation;
    };
    case "hithull": {
        _chanceOfDetonate = ([_vehicleConfig >> QGVAR(hullDetonationProb), "number", 0] call CBA_fnc_getConfigEntry) * _incendiary * ((_chanceOfDetonation + _currentFuel) / 2);
        _chanceOfFire = ([_vehicleConfig >> QGVAR(hullFireProb), "number", 0] call CBA_fnc_getConfigEntry) * _incendiary * ((_chanceOfDetonation + _currentFuel) / 2);
    };
    case "hitengine": {
        _chanceOfDetonate = ([_vehicleConfig >> QGVAR(engineDetonationProb), "number", 0] call CBA_fnc_getConfigEntry) * _incendiary * _currentFuel;
        _chanceOfFire = ([_vehicleConfig >> QGVAR(engineFireProb), "number", 0] call CBA_fnc_getConfigEntry) * _incendiary * _currentFuel;
    };
};

private _alreadyDetonating = _vehicle getVariable [QGVAR(detonating), false];
private _alreadyCookingOff = _vehicle getVariable [QGVAR(cookingOff), false];

if (!_alreadyDetonating && { _chanceOfDetonate > random 1 }) exitWith {
    [_vehicle, _currentVehicleAmmo] call FUNC(detonate);
    diag_log text format["[POTATO] (cookoff) Detonating [%1] with a chance-to-detonate [%2] hit [%3]", _vehicle, _chanceOfDetonate, _hitPoint];
    _vehicle setVariable [QGVAR(detonating), true];
};

if (!_alreadyCookingOff && { _chanceOfFire > random 1 }) exitWith {
    [_vehicle] call ACEFUNC(cookoff,cookOff);
    if (!_alreadyDetonating && { [_vehicleConfig >> QGVAR(detonationDuringFireProb), "number", 0] call CBA_fnc_getConfigEntry > random 1 }) then {
        [_vehicle, _currentVehicleAmmo] call FUNC(detonate);
        diag_log text format["[POTATO] (cookoff) Detonating [%1] while cooking off with a chance of [%2] hit [%3]", _vehicle, [_vehicleConfig >> QGVAR(detonationDuringFireProb), "number", 0] call CBA_fnc_getConfigEntry, _hitPoint];
        _vehicle setVariable [QGVAR(detonating), true];
    };
    _vehicle setVariable [QGVAR(cookingOff), true];
    diag_log text format["[POTATO] (cookoff) Cooking-off [%1] with a chance-of-fire [%2] hit [%3]", _vehicle, _chanceOfFire, _hitPoint];
    [_vehicle] spawn FUNC(abandon);
    diag_log text format["[POTATO] [%1] is on fire is bailing", _vehicle];
};

// Avoid RPT spam
if (_alreadyDetonating || _alreadyCookingOff) exitWith { };

diag_log text format["[POTATO] (cookoff) [%1] No Cook-off, no detonations (Chance of fire [%2] Chance of detonation [%3] Incendiary [%4] Warhead Type [%5])", _vehicle, _chanceOfFire, _chanceOfDetonate, _incendiary, _warheadType];

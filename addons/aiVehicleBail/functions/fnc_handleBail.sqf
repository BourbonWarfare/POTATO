/*
 * Author: Brandon (TCVM)
 * Handles whether or not the crew should bail
 *
 * Arguments:
 * 0: The vehicle
 * 1: Can the vehicle move?
 * 2: Can the vehicle shoot?
 *
 * Return Value:
 * None
 *
 * Example:
 * [tank1, false, true] call potato_aiVehicleBail_fnc_determineGenericSelectionType
 *
 *
 * Public: No
 */
#include "script_component.hpp"
params["_vehicle", "_canMove", "_canShoot"];

if (_canMove) then {
    _canMove = alive driver _vehicle;
};

if (_canShoot) then {
    _canShoot = alive gunner _vehicle;
};

_vehicle setVariable[QGVAR(can_move), _canMove];
_vehicle setVariable[QGVAR(can_shoot), _canShoot];

private _rand = random 1;

if (!_canMove && !_canShoot) exitWith { // If you can't move and you can't shoot, you better GTFO
    [_vehicle] spawn FUNC(abandon);
    diag_log text format["[POTATO] [%1] is a sitting duck and is bailing", _vehicle];
};

if (!_canShoot) exitWith {
    if (0.5 > _rand) then { // 50% chance of bailing out if turret/gun is destroyed
        [_vehicle] spawn FUNC(abandon);
        diag_log text format["[POTATO] [%1] Cannot shoot and is bailing with chance [%2]", _vehicle, _rand];
    } else {
        _vehicle allowFleeing 1;
        diag_log text format["[POTATO] [%1] Cannot shoot and is fleeing with chance [%2]", _vehicle, _rand];
    };
};

if (!_canMove) exitWith {
    if (0.8 > _rand) then { // 80% Chance of bailing out if engine is destroyed
        [_vehicle] spawn FUNC(abandon);
        diag_log text format["[POTATO] [%1] Cannot move and is bailing with chance [%2]", _vehicle, _rand];
    } else {
        diag_log text format["[POTATO] [%1] Cannot move and is bunkering with chance [%2]", _vehicle, _rand];
    };
};



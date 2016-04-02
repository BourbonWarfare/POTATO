/*
 * Author: PabstMirror
 *
 *
 * Arguments:
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_mortarVeh", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile"];
TRACE_7("",_mortarVeh, _weapon, _muzzle, _mode, _ammo, _magazine, _projectile);

if (!local _mortarVeh) exitWith {};

//Remove the empty magazine, so a new one will load correctly
private _loadedEmpty = _mortarVeh magazinesTurret [0];
if (!(_loadedEmpty isEqualTo [])) then {
    TRACE_1("removing empty mag", _loadedEmpty);
    _mortarVeh removeMagazinesTurret [(_loadedEmpty select 0), [0]];
};

// _fuze

switch (_fuze) do {
case ("proximity"): {[_projectile, _ammo] call FUNC(fuze_proximity);};
};

[{
    params ["_args", "_pfID"];
    _args params ["_projectile", "_armedTime"];

    if (!alive _projectile) exitWith {
        TRACE_1("exit PFEH",_projectile);
        [_pfID] call CBA_fnc_removePerFrameHandler;
    };

    //Wait for it to arm (heading down)
    if (time < _armedTime) exitWith {};

    _height = (getPos _projectile) select 2;
    if (_height > 10) exitWith {};

    private _position = getPosATL _projectile;
    private _subMunition = createVehicle [QGVAR(ammo_he_airburst), _position, [], 0, "FLY"];

    _subMunition setPosATL _position;
    _subMunition setVelocity [0, 0, -10];

    deleteVehicle _projectile;
    [_pfID] call CBA_fnc_removePerFrameHandler;

}, 0, [_projectile, (time + 5)]] call CBA_fnc_addPerFrameHandler;

x3 = _projectile;
/*
 * Author: PabstMirror
 * Handle the mortar's Fired event.
 *
 * Arguments:
 * 0: unit - Object the event handler is assigned to <OBJECT>
 * 1: weapon - Fired weapon <STRING>
 * 2: muzzle - Muzzle that was used <STRING>
 * 3: mode - Current mode of the fired weapon <STRING>
 * 4: ammo - Ammo used <STRING>
 * 5: magazine - magazine name which was used <STRING>
 * 6: projectile - Object of the projectile that was shot <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [firedBIS] call potato_vz99_fnc_doSelectNextMagazine
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

private _fuze = getText (configFile >> "CfgMagazines" >> _magazine >> QGVAR(fuze));
if (_fuze == "") exitWith {};

private _detonationHeight = switch (true) do {
case (_fuze == "prx"): {3.5}; //M734 says "PRX = Proximity air burst between 3 and 13 feet"
    default {-1};
};

[{
    params ["_args", "_pfID"];
    _args params ["_projectile", "_detonationHeight", "_armedTime"];

    if (!alive _projectile) exitWith {
        TRACE_1("exit PFEH",_projectile);
        [_pfID] call CBA_fnc_removePerFrameHandler;
    };

    //Wait for it to arm (heading down)
    if (time < _armedTime) exitWith {};

    _height = (getPos _projectile) select 2;
    if (_height > _detonationHeight) exitWith {};

    TRACE_3("",_height,_detonationHeight,diag_fps);

    private _position = getPosATL _projectile;
    private _subMunition = createVehicle [QGVAR(ammo_he_airburst), _position, [], 0, "FLY"];

    _subMunition setPosATL _position;
    _subMunition setVelocity [0, 0, -10];

    deleteVehicle _projectile;
    [_pfID] call CBA_fnc_removePerFrameHandler;

}, 0, [_projectile, _detonationHeight, (time + 5)]] call CBA_fnc_addPerFrameHandler;

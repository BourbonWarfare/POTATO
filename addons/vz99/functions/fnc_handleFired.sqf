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

private _loadedFull = magazinesAmmoFull _mortarVeh;
TRACE_1("",_loadedFull);
if (!(_loadedFull isEqualTo [])) exitWith {TRACE_1("loaded",_loadedFull);};

private _loadedEmpty = _mortarVeh magazinesTurret [0];
if (!(_loadedEmpty isEqualTo [])) then {
    TRACE_1("removing empty mag", _loadedEmpty);
    _mortarVeh removeMagazinesTurret [(_loadedEmpty select 0), [0]];
};

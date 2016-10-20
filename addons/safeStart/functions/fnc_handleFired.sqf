/*
 * Author: PabstMirror
 * Function used to remove a fired projectile when safe start is active.
 * Sould only be called from an event handler
 *
 * Arguments:
 * 0: Unit, Object the event handler is assigned to <OBJECT>
 * 1: Weapon, Fired weapon <STRING>
 * 2: Muzzle, Muzzle that was used <STRING>
 * 3: Mode, Current mode of the fired weapon <STRING>
 * 4: Ammo, Ammo used <STRING>
 * 5: Magazine, magazine name which was used <STRING>
 * 6: Projectile, Object of the projectile that was shot out <OBJECT>
 *
 * Examples:
 * [_this] call potato_safeStart_fnc_handleFired;
 * [_this] call potato_safeStart_fnc_handleFired;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_unit", "", "", "", "", "", "_projectile"];

if (local _unit) then {
    deleteVehicle _projectile;
};
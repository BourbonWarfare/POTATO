/*
 * Author: PabstMirror
 * Picks up a deployed static weapon.
 *
 * Arguments:
 * 0: Target (mortar) <OBJECT>
 * 1: Player <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [mortar, player] call potato_vz99_fnc_doPickupWeapon
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_target", "_player"];
TRACE_2("params",_target,_player);

{
    _x params ["_xClassname", "_xAmmo"];
    if (_xAmmo > 0) then {
        private _baseMag = getText (configFile >> "CfgMagazines" >> _xClassname >> QGVAR(base));
        TRACE_2("adding loaded mag to player inv",_xClassname,_baseMag);
        [_player, _baseMag, "", _xAmmo] call ACEFUNC(common,addToInventory);
    };
} forEach (magazinesAmmoFull _target);

deleteVehicle _target;
_player addWeapon QGVAR(carryWeapon);


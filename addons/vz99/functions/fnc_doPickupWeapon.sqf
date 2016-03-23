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


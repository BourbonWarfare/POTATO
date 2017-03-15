/*
 * Author: AACO
 * Sets optic on player's main weapon.
 * Should only be called from interact menu
 *
 * Arguments:
 * 0: Target of interaction <OBJECT>
 * 1: Player who is interacting <OBJECT>
 * 2: Optic classname <STRING>
 *
 * Example:
 * [objNull, player, ["opticClassName", []]] call potato_assignGear_fnc_setOptic;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["", "_player", "_params"];
_params params ["_opticClassname", "_opticClassnames"];

if (({_x == _opticClassname} count ([primaryWeapon _player] call CBA_fnc_compatibleItems)) > 0) then {
    {
        if ((toLower _x) in _opticClassnames) then {
            _player removeItemFromUniform _x;
        };
        nil
    } count (uniformItems _player);

    {
        if ((toLower _x) in _opticClassnames) then {
            _player removeItemFromVest _x;
        };
        nil
    } count (vestItems _player);

    {
        if ((toLower _x) in _opticClassnames) then {
            _player removeItemFromBackpack _x;
        };
        nil
    } count (backpackItems _player);

    _player addPrimaryWeaponItem _opticClassname;
} else {
    WARNING_2("Optic not compatible with player's weapon", primaryWeapon _player, _opticClassname);
};

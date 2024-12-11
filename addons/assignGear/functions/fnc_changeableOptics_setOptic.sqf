#include "script_component.hpp"
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
* [objNull, player, ["opticClassName", []]] call potato_assignGear_fnc_changeableOptics_setOptic
 *
 * Public: No
 */

params ["", "_player", "_params"];
_params params ["_opticClassname", "_opticClassnames"];
TRACE_3("setOptic",_player,_opticClassname,_opticClassnames);

{
    if (_x in _opticClassnames) then {
        _player removeItemFromUniform _x;
    };
} forEach (uniformItems _player);

{
    if (_x in _opticClassnames) then {
        _player removeItemFromVest _x;
    };
} forEach (vestItems _player);

{
    if (_x in _opticClassnames) then {
        _player removeItemFromBackpack _x;
    };
} forEach (backpackItems _player);

if (_opticClassname != (primaryWeaponItems _player)#2) then {
    _player addPrimaryWeaponItem _opticClassname;
};

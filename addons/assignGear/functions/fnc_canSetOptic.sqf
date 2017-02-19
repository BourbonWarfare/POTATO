/*
 * Author: AACO
 * Checks if a provided optic can be added to a player's weapon
 * Should only be called from interact menu
 *
 * Arguments:
 * 0: Target of interaction <OBJECT>
 * 1: Player who is interacting <OBJECT>
 * 2: Optic classname <STRING>
 *
 * Return Value:
 * If the optic is valid <BOOL>
 *
 * Example:
 * [objNull, player,  ["opticClassName", []]] call potato_assignGear_fnc_canSetOptic;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["", "_player", "_params"];
_params params ["_opticClassname"];

missionNamespace getVariable [QEGVAR(safeStart,startTime_PV), -1] != -1 &&
    {((primaryWeaponItems _player) select 2) != _opticClassname} &&
    {({toLower _x == _opticClassname} count ([primaryWeapon _player] call CBA_fnc_compatibleItems)) > 0}

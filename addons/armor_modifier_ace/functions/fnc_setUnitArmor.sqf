#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Sets the armor value for a specific unit.
 *
 * Arguments:
 * 0: Unit to set hit point armor values <OBJECT>
 * 1: Hit point to apply armor value to <STRING>
 * 2: Armor array in format [multiplier, minimum, maximum] <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject, "hitFace", [1, 2, 2]] call potato_armor_modifier_ace_setClassArmor;
 * [player, "ama_hitTorso", [1, 2, 2]] call potato_armor_modifier_ace_setClassArmor;
 *
 * Public: Yes
 */
params [
    ["_unit", objNull, [objNull]],
    ["_hitPoint", "", [""]],
    ["_armorArray", [1, 0, 0], [[]], [3]]
];

_hitPoint = toLowerANSI _hitPoint;

if (isNull _unit) exitWith {
    ["Null unit given",2] call ace_common_fnc_displayTextStructured;
};
if (_hitPoint == "") exitWith {
    ["No hitpoint given",2] call ace_common_fnc_displayTextStructured;
};
if (false in (_armorArray apply {_x isEqualType 0})) exitWith {
    [format ["Invalid format for _armorArray: %1", _armorArray],2] call ace_common_fnc_displayTextStructured;
};

_this set [1, _hitPoint];
[QGVAR(updateUnitArmor), _this, _unit] call CBA_fnc_globalEventJIP;
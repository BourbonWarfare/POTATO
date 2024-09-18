#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Sets the armor value for a specific class. This is not retroactive or inherited.
 *
 * Arguments:
 * 0: Unit classname to set hit point armor values <STRING>
 * 1: Hit point to apply armor value to <STRING>
 * 2: Armor array in format [multiplier, minimum, maximum] <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [typeOf player, "hitFace", [1, 2, 2]] call potato_armorAdjuster_setClassArmor;
 * [typeOf player, "ama_hitTorso", [1, 2, 2]] call potato_armorAdjuster_setClassArmor;
 *
 * Public: Yes
 */
params [
    ["_classname", "", [""]],
    ["_hitPoint", "", [""]],
    ["_armorArray", [1, 0, 0], [[]], [3]]
];

_hitPoint = toLowerANSI _hitPoint;

if (_classname == "") exitWith {
    ["No classname given",2] call ace_common_fnc_displayTextStructured;
};
if (_hitPoint == "") exitWith {
    ["No hitpoint given",2] call ace_common_fnc_displayTextStructured;
};
if (false in (_armorArray apply {_x isEqualType 0})) exitWith {
    [format ["Invalid format for _armorArray: %1", _armorArray],2] call ace_common_fnc_displayTextStructured;
};

_this set [1, _hitPoint];
[QGVAR(updateClassArmor), _this] call CBA_fnc_globalEventJIP;

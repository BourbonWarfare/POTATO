/*
 * Author: KoffeinFlummi, Glowbal
 * Callback when the treatment fails
 *
 * Arguments:
 * 0: The medic <OBJECT>
 * 1: The patient <OBJECT>
 * 2: SelectionName <STRING>
 * 3: Treatment classname <STRING>
 * 4: Items available <ARRAY<STRING>>
 *
 * Return Value:
 * None
 *
 * Example:
 * [bob, kevin, "selectionname", "classname", ["bandage"]] call ACE_medical_fnc_treatment_failure
 *
 * Public: No
 */

#include "script_component.hpp"

(_this select 0) params ["_caller", "", "_usersOfItems"];

[_caller] call FUNC(resetAnimation);

{
    _x params ["_unit", "_item"];
    _unit addItem _item;
} forEach _usersOfItems;

/*
 * Author: AACO
 * Callback when putting in a body bag fails. Mainly reset animation and gives back medication
 *
 * Arguments:
 * 0: The mortician <OBJECT>
 * 2: unit to item used array <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, nil, [[player, "ACE_bodyBag"]]] call potato_bodyBag_fnc_failurePlaceInBodyBag
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

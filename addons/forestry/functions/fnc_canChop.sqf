#include "..\script_component.hpp"
/*
 * Author: AChesheireCat, Cyruz, Commy2, Drofseh
 * Condition for chopping the shrubbery.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * 0: Can Chop <BOOL>
 *
 * Example:
 * [] call potato_forestry_fnc_canChop
 */

params ["_unit"];

if (potato_disableForestry) exitWith {false};

if (
    potato_requireEntrenchingTool &&
    {!(_unit call ace_trenches_fnc_hasEntrenchingTool)}
) exitWith {false};

private _nearObj = nearestTerrainObjects [player, ["TREE", "SMALL TREE", "BUSH"], 5, false, true];

if (isNil "_nearObj" || { _nearObj isEqualTo [] }) exitWith {
    false;
};

true

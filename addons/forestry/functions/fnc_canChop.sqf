#include "..\script_component.hpp"
/*
 * Author: AChesheireCat, Cyruz, Commy2, Drofseh
 * Condition for chopping the shrubbery.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * 0: Can Chop <BOOL>
 *
 * Example:
 * [player] call potato_forestry_fnc_canChop
 */

params ["_unit"];

if ((GVAR(forestryEnabled) == 0) || 
    {GVAR(forestryEnabled) == 2 && {!EGVAR(safeStart,safeStartEnabled)}}) exitWith {false};

if (
    GVAR(requireEntrenchingTool) &&
    {!(_unit call ace_trenches_fnc_hasEntrenchingTool)}
) exitWith {false};

private _nearObj = nearestTerrainObjects [ACE_player, ["TREE", "SMALL TREE", "BUSH"], 5, false, true];

if (isNil "_nearObj" || { _nearObj isEqualTo [] }) exitWith {
    false;
};

true

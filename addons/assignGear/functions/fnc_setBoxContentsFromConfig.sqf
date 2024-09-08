#include "script_component.hpp"
/*
 * Author: Bailey
 * Fills box with gear from a config
 * Edited by Lambda.Tiger to add box names
 *
 * Arguments:
 * 0: Box <OBJECT>
 * 1: Config path for the box's loadout <STRING>
 * 2: Optional format string for box name, must contain "%1" <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject, missionConfigFile >> "CfgLoadouts" >> "SupplyBox" >> (typeOf cursorObject)] call potato_assignGear_fnc_assignGearSupplyBox
 *
 * Public: No
 */

params ["_theBox", "_path", ["_nameFormatString", "%1", [""]]];

[_theBox, _path] call FUNC(setContainerContentsFromConfig);

private _boxName = getText (_path >> "boxCustomName");
if (_boxName isNotEqualTo "") then {
    _theBox setVariable ["ace_cargo_customName", format [_nameFormatString, _boxName], true];
};

private _overrideCarryWeight = 1 == (getNumber (_path >> "forceAllowCarry"));
private _overrideDragWeight = 1 == (getNumber (_path >> "forceAllowDrag"));
_theBox setVariable ["ace_cargo_ignoreWeightCarry", _overrideCarryWeight, true];
_theBox setVariable ["ace_cargo_ignoreWeightDrag", _overrideCarryWeight || _overrideDragWeight, true];

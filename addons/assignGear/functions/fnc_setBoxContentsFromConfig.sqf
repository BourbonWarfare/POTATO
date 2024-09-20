#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Fills box with gear from a config
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
 * [cursorObject, missionConfigFile >> "CfgLoadouts" >> "SupplyBoxes" >> (typeOf cursorObject), missionConfigFile >> "CfgLoadouts" >> "SupplyBox" >> (typeOf cursorObject)] call potato_assignGear_fnc_setBoxContentsFromConfig
 *
 * Public: No
 */

params ["_theBox", "_path", ["_nameFormatString", "%1", [""]]];

[_theBox, _path] call FUNC(setContainerContentsFromConfig);

private _boxName = getText (_path >> "boxCustomName");
if (_boxName isNotEqualTo "") then {
    _theBox setVariable [QACEGVAR(cargo,customName), format [_nameFormatString, _boxName], true];
};

private _overrideCarryWeight = 1 == (getNumber (_path >> "forceAllowCarry"));
private _overrideDragWeight = 1 == (getNumber (_path >> "forceAllowDrag"));
_theBox setVariable [QACEGVAR(cargo,ignoreWeightCarry), _overrideCarryWeight, true];
_theBox setVariable [QACEGVAR(cargo,ignoreWeightDrag), _overrideCarryWeight || _overrideDragWeight, true];

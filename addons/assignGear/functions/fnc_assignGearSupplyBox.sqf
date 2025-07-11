#include "script_component.hpp"
/*
 * Author: Bailey
 * Fills supply box with gear for a faction
 * Edit by Lambda.tiger
 * Supports boxes containing other boxes
 *
 * Arguments:
 * 0: Box <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject] call potato_assignGear_fnc_assignGearSupplyBox
 *
 * Public: No
 */

params ["_theBox"];

TRACE_1("",GVAR(setSupplyBoxLoadouts));

if (_theBox getVariable [QGVAR(initialized), false]) exitWith {};
_theBox setVariable [QGVAR(initialized), true, true];

//Leave default gear when GVAR(setSupplyBoxLoadouts) is 0
if (GVAR(setSupplyBoxLoadouts) == 0) exitWith {};

//Clean out starting inventory when GVAR(setSupplyBoxLoadouts) is -1
if (GVAR(setSupplyBoxLoadouts) == -1) exitWith {
    clearWeaponCargoGlobal _theBox;
    clearMagazineCargoGlobal _theBox;
    clearItemCargoGlobal _theBox;
    clearBackpackCargoGlobal _theBox;
};

private _path = missionConfigFile >> "CfgLoadouts" >> "SupplyBoxes" >> typeOf _theBox;

if (!isClass _path) exitWith {
    diag_log formatText ["[POTATO-assignGear] - No loadout found for %1 (typeOf %2)", _theBox, typeOf _theBox];
};

[_theBox, _path] call FUNC(fillObjectFromConfig);

private _addMarkingActions = getNumber (_path >> "addMarkingActions");
if (_addMarkingActions >= 1) then {
    [QGVAR(resupplyBoxAddActions), [_theBox, _addMarkingActions]] call CBA_fnc_globalEventJIP;
};

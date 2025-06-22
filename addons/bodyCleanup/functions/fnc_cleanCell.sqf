#include "script_component.hpp"

/*
 * Author: Bailey
 * Cleans a cell: If deleting bodies enabled, deletes all objects and removes cell from hashmap
 * If hiding bodies enabled, hides all bodies and disables simulation
 *
 * Arguments:
 * Cell key <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call potato_bodyCleanup_fnc_cleanCell;
 *
 * Public: No
 */
params ["_key"];

private _units = (GVAR(cells) get _key) select 1;
{
    if (_x isKindOf "CAManBase") then {
        if (GVAR(hideInsteadOfDelete)) then {
            hideObjectGlobal _x;
            _x enableSimulationGlobal false;
        } else {
            deleteVehicle _x;
        };
    };
} forEach _units;

if (GVAR(hideInsteadOfDelete)) then {
    private _cell = GVAR(cells) get _key;
    _cell set [3, true];
    GVAR(cells) set [_key, _cell];
} else {
    GVAR(cells) deleteAt _key;
};

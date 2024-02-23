#include "script_component.hpp"

/*
 * Author: Bailey
 * Uncleans a cell: If the cell is "hidden", then we unhide the bodies and re-enable simulation
 *
 * Arguments:
 * Cell key <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call potato_bodyCleanup_fnc_uncleanCell;
 *
 * Public: No
 */
params ["_key"];

if (GVAR(hideInsteadOfDelete)) then {
    private _cell = GVAR(cells) get _key;
    _cell set [3, false];
    _cell set [2, CBA_missionTime];
    GVAR(cells) set [_key, _cell];

    private _units = _cell select 1;
    {
        if (_x isKindOf "CAManBase") then {
            _x hideObjectGlobal false;
            _x enableSimulationGlobal true;
        };
    } forEach _units;
};

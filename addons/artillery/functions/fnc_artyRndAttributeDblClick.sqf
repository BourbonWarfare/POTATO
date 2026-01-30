#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles double clicking to toggle on or off a specific
 * magazine for use in mission as part of the artillery array.
 *
 * Arguments:
 * _ctrl - The listbox control. CONTROL
 * _row - The row index that was double clicked on. SCALAR
 *
 * Example:
 * [_controlGroup, 5] call potato_artillery_fnc_artyRndAttributeDblClick;
 *
 * Based on ACE 3 Object Arsenal Context by mharis001: https://github.com/acemod/ACE3/blob/master/addons/
 * Public: No
 */
params ["_ctrl", "_row"];
private _isSelected = 1 == (_ctrl lnbColor [_row, 0])#3;

if (_isSelected) then {
    _ctrl lnbSetColor [[_row, 0], [1, 1, 1, 0.6]];
    _ctrl lnbSetColor [[_row, 1], [1, 1, 1, 0.6]];
    _ctrl lnbSetText [[_row, 2], ""];
} else {
    _ctrl lnbSetColor [[_row, 0], [1, 1, 1, 1]];
    _ctrl lnbSetColor [[_row, 1], [1, 1, 1, 1]];
    _ctrl lnbSetText [[_row, 2], "*"];
};

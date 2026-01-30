#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Listbox side arrow buttons (no longer arrows) that either set or clear
 * a magazine as being set.
 *
 * Arguments:
 * _ctrlGroup - The attribute control group. CONTROL
 * _enable - Whether to enable or disable the round for use. BOOLEAN
 *
 * Example:
 * [_controlGroup, false] call potato_artillery_fnc_artyRndAttributeArrow;
 *
 * Based on ACE 3 Object Arsenal Context by mharis001: https://github.com/acemod/ACE3/blob/master/addons/
 * Public: No
 */
params ["_ctrlGroup", "_enable"];
private _ctrl = _ctrlGroup controlsGroupCtrl ARTILLERY_EDITOR_ROUND_LISTBOX;
private _row = lnbCurSelRow _ctrl;

if (_enable) then {
    _ctrl lnbSetColor [[_row, 0], [1, 1, 1, 0.6]];
    _ctrl lnbSetColor [[_row, 1], [1, 1, 1, 0.6]];
    _ctrl lnbSetText [[_row, 2], ""];
} else {
    _ctrl lnbSetColor [[_row, 0], [1, 1, 1, 1]];
    _ctrl lnbSetColor [[_row, 1], [1, 1, 1, 1]];
    _ctrl lnbSetText [[_row, 2], "*"];
};


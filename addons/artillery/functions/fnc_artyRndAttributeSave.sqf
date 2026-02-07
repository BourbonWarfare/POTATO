#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function saves the attribute information. Specifically it checks every
 * item in the list box for whether the third column is empty or "*," the
 * latter indicating that it is enabled. It then returns an array of every
 * active magazine.
 *
 * Arguments:
 * _ctrlGroup - The attribute control group, CONTROL
 *
 * Example:
 * Called by attribute BIS EH
 *
 * Return:
 * Array of magazines to be used for artillery missions.
 *
 * Based on ACE 3 Object Arsenal Context by mharis001: https://github.com/acemod/ACE3/blob/master/addons/
 * Public: No
 */
params ["_ctrlGroup"];
private _magazines = [];
private _ctrl = _ctrlGroup controlsGroupCtrl ARTILLERY_EDITOR_ROUND_LISTBOX;
private _row = 0;
private _magText = _ctrl lnbText [0, 1];
while {_magText != ""} do {
    if (_ctrl lnbText [_row, 2] != "") then {
        _magazines pushBack _magText;
    };
    _row = _row + 1;
    _magText = _ctrl lnbText [_row, 1];
};
_magazines

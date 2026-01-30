#include "..\script_component.hpp"
#include "\a3\ui_f\hpp\defineDIKCodes.inc"
/*
 * Author: Lambda.Tiger
 * This function handles key events for the arty magazine NListBox.
 * We check if the the interface is in focuse and then either set or clear
 * a list element based on input. Left and right arrow add or remove items.
 * Shift+A adds all entries, Shift+C clears all entries.
 *
 * Arguments:
 * _display - The display containing the magazine control group. DISPLAY
 * _keyCode - The keycode for the key being pressed. SCALAR
 * _shift - Whether shift is held down. BOOLEAN
 *
 * Example:
 * Called via BIS EH
 *
 * Based on ACE 3 Object Arsenal Context by mharis001: https://github.com/acemod/ACE3/blob/master/addons/
 * Public: No
 */
params ["_display", "_keyCode", "_shift"];
TRACE_2("Attribute key down",_display,_keyCode);

// Exit if attribute is not in focus
if !(missionNamespace getVariable [QGVAR(artyRoundUIFocused), false]) exitWith {false};
private _ctrlGroup = _display displayCtrl ARTILLERY_EDITOR_ROUND_ATTRIBUTE;

switch (_keyCode) do {
    case DIK_A: {
        if (_shift) then {
            private _ctrl = _ctrlGroup controlsGroupCtrl ARTILLERY_EDITOR_ROUND_LISTBOX;
            private _row = 0;
            private _magText = _ctrl lnbText [0, 1];
            while {_magText != ""} do {
                _ctrl lnbSetColor [[_row, 0], [1, 1, 1, 1]];
                _ctrl lnbSetColor [[_row, 1], [1, 1, 1, 1]];
                _ctrl lnbSetText [[_row, 2], "*"];
                _row = _row + 1;
                _magText = _ctrl lnbText [_row, 1];
            };
            true
        } else {
            false
        };
    };
    case DIK_C: {
        if (_shift) then {
            private _ctrl = _ctrlGroup controlsGroupCtrl ARTILLERY_EDITOR_ROUND_LISTBOX;
            private _row = 0;
            private _magText = _ctrl lnbText [0, 1];
            while {_magText != ""} do {
                _ctrl lnbSetColor [[_row, 0], [1, 1, 1, 0.6]];
                _ctrl lnbSetColor [[_row, 1], [1, 1, 1, 0.6]];
                _ctrl lnbSetText [[_row, 2], ""];
                _row = _row + 1;
                _magText = _ctrl lnbText [_row, 1];
            };
            true
        } else {
            false
        };
    };
    case DIK_LEFT: {
        [_ctrlGroup, true] call FUNC(artyRndAttributeArrow);
        true
    };
    case DIK_RIGHT: {
        [_ctrlGroup, false] call FUNC(artyRndAttributeArrow);
        true
    };
    default {false};
};

#define DEBUG_MODE_FULL
#include "script_component.hpp"
/*
 * Author: PabstMirror
 * Based on acre_sys_spectator_fnc_spectatorACEDisplayLoad
 * Adds keybind passthough and adapts display to show acre spectate features
 *
 * Arguments:
 * 0: Potato Spectate Display <DISPLAY>
 *
 * Examples:
 * [] call potato_spectate_fnc_acreSpectateCompat
 *
 * Public: No
 */
#define ACRE_IDC_RADIOS_GROUP 100
#define ACRE_IDC_RADIOS_BACKGROUND 110
#define ACRE_IDC_RADIOS_NONE 120
#define ACRE_IDC_RADIOS_LIST 130
#define ACRE_IDC_SPEAKING 140

params ["_display"]; // OVERLAY
TRACE_1("acreSpectateCompat",_display);

// add ACRE passthrough to display
[_display] call acre_api_fnc_addDisplayPassthroughKeys;

// Adjust group to handle new element
private _ctrlFocusInfo = FOCUS_GROUP;
_ctrlFocusInfo ctrlSetPositionH (7.7 * YFACTOR);
_ctrlFocusInfo ctrlCommit 0;

// Create radios control and adjust width to match focus info
private _ctrlRadios = _display ctrlCreate ["acre_sys_spectator_RscRadios", ACRE_IDC_RADIOS_GROUP, _ctrlFocusInfo];
_ctrlRadios ctrlSetPositionX (5.5 * XFACTOR);
_ctrlRadios ctrlSetPositionY (5.7 * YFACTOR);
_ctrlRadios ctrlSetPositionW (12.4 * XFACTOR);
_ctrlRadios ctrlSetPositionH (2 * YFACTOR);
_ctrlRadios ctrlCommit 0;
{
    private _ctrl = _display displayCtrl _x;
    _ctrl ctrlSetPositionW (12.4 * XFACTOR);
    _ctrl ctrlSetPositionH (2 * YFACTOR);
    _ctrl ctrlCommit 0;
} forEach [ACRE_IDC_RADIOS_BACKGROUND, ACRE_IDC_RADIOS_NONE, ACRE_IDC_RADIOS_LIST];

private _ctrlSpeaking = _display ctrlCreate ["acre_sys_spectator_RscSpeaking", ACRE_IDC_SPEAKING];

[
    _display, {
        GVAR(camTarget) // Target function must return the currently focused entity.
    }, {
        GVAR(uiVisible) // Visible function must return whether the interface is currently visible.
    }
] call acre_sys_spectator_fnc_initDisplay;
TRACE_3("called acre initDisplay",_display,_ctrlRadios,_ctrlSpeaking);

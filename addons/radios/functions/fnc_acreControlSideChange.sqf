/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlSide","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlSide;
private _ctrlBabel = _ctrlGroup controlsGroupCtrl BABEL_LIST_IDC;
private _ctrlRadio = _ctrlGroup controlsGroupCtrl RADIO_CHOOSE_IDC;
private _ctrlChannels = _ctrlGroup controlsGroupCtrl RADIO_CHANNEL_IDC;

private _side = switch (_index) do {
    case (0): {
        GVAR(selectedLanguages) = GVAR(westDefaultLanguages);
        west
    };
    case (1): {
        GVAR(selectedLanguages) = GVAR(eastDefaultLanguages);
        east
    };
    case (2): {
        GVAR(selectedLanguages) = GVAR(indyDefaultLanguages);
        independent
    };
    default {
        GVAR(selectedLanguages) = GVAR(civDefaultLanguages);
        civilian
    };
};

TRACE_5("Babel junk",GVAR(selectedLanguages),GVAR(westDefaultLanguages),GVAR(eastDefaultLanguages),GVAR(indyDefaultLanguages),GVAR(civDefaultLanguages));

{
    if ((_x select 0) in GVAR(selectedLanguages)) then {
        _ctrlBabel lbSetSelected [_forEachIndex, true];
    } else {
        _ctrlBabel lbSetSelected [_forEachIndex, false];
    };
} forEach GVAR(availableLanguages);

[_side] call FUNC(setChannelArrays);
[_ctrlRadio,lbCurSel _ctrlRadio] call FUNC(acreControlRadioChange);

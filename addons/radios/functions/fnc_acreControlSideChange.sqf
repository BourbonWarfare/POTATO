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
private _ctrlSharedMR = _ctrlGroup controlsGroupCtrl CFG_SHARED_MR;
private _ctrlSharedLR = _ctrlGroup controlsGroupCtrl CFG_SHARED_LR;

private _side = switch (_index) do {
    case (0): {
        GVAR(selectedLanguages) = GVAR(westDefaultLanguages);
        _ctrlSharedMR cbSetChecked GVAR(addCommonChannelWestMR);
        _ctrlSharedLR cbSetChecked GVAR(addCommonChannelWestLR);
        west
    };
    case (1): {
        GVAR(selectedLanguages) = GVAR(eastDefaultLanguages);
        _ctrlSharedMR cbSetChecked GVAR(addCommonChannelEastMR);
        _ctrlSharedLR cbSetChecked GVAR(addCommonChannelEastLR);
        east
    };
    case (2): {
        GVAR(selectedLanguages) = GVAR(indyDefaultLanguages);
        _ctrlSharedMR cbSetChecked GVAR(addCommonChannelIndyMR);
        _ctrlSharedLR cbSetChecked GVAR(addCommonChannelIndyLR);
        independent
    };
    default {
        GVAR(selectedLanguages) = GVAR(civDefaultLanguages);
        _ctrlSharedMR cbSetChecked GVAR(addCommonChannelCivMR);
        _ctrlSharedLR cbSetChecked GVAR(addCommonChannelCivLR);
        civilian
    };
};

TRACE_5("Babel junk",GVAR(selectedLanguages),GVAR(westDefaultLanguages),GVAR(eastDefaultLanguages),GVAR(indyDefaultLanguages),GVAR(civDefaultLanguages));

[_ctrlBabel] call FUNC(setBabelList);

[_ctrlGroup,_side] call FUNC(setChannelArrays);
[_ctrlRadio,lbCurSel _ctrlRadio] call FUNC(acreControlRadioChange);

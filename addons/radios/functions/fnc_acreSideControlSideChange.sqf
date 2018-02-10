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
private _ctrlSharedMR = _ctrlGroup controlsGroupCtrl CFG_S_SHARED_MR;
private _ctrlSharedLR = _ctrlGroup controlsGroupCtrl CFG_S_SHARED_LR;

TRACE_8("Shared settings",GVAR(addCommonChannelWestMR),GVAR(addCommonChannelWestLR),\
GVAR(addCommonChannelEastMR),GVAR(addCommonChannelEastLR),\
GVAR(addCommonChannelIndyMR),GVAR(addCommonChannelIndyLR),\
GVAR(addCommonChannelCivMR),GVAR(addCommonChannelCivLR));

private _side = switch (_index) do {
    case (0): {
        _ctrlGroup setVariable [QGVAR(selectedLanguages), missionNamespace getVariable [QGVAR(westDefaultLanguages), [DEFAULT_WEST_LANGS]]];
        _ctrlSharedMR lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(addCommonChannelWestMR), DEFAULT_COMMON_CH_ENABLED]));
        _ctrlSharedLR lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(addCommonChannelWestLR), DEFAULT_COMMON_CH_ENABLED]));
        west
    };
    case (1): {
        _ctrlGroup setVariable [QGVAR(selectedLanguages), missionNamespace getVariable [QGVAR(eastDefaultLanguages), [DEFAULT_EAST_LANGS]]];
        _ctrlSharedMR lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(addCommonChannelEastMR), DEFAULT_COMMON_CH_ENABLED]));
        _ctrlSharedLR lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(addCommonChannelEastLR), DEFAULT_COMMON_CH_ENABLED]));
        east
    };
    case (2): {
        _ctrlGroup setVariable [QGVAR(selectedLanguages), missionNamespace getVariable [QGVAR(indyDefaultLanguages), [DEFAULT_INDY_LANGS]]];
        _ctrlSharedMR lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(addCommonChannelIndyMR), DEFAULT_COMMON_CH_ENABLED]));
        _ctrlSharedLR lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(addCommonChannelIndyLR), DEFAULT_COMMON_CH_ENABLED]));
        independent
    };
    default {
        _ctrlGroup setVariable [QGVAR(selectedLanguages), missionNamespace getVariable [QGVAR(civDefaultLanguages), [DEFAULT_CIV_LANGS]]];
        _ctrlSharedMR lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(addCommonChannelCivMR), DEFAULT_COMMON_CH_ENABLED]));
        _ctrlSharedLR lbSetCurSel (parseNumber (missionNamespace getVariable [QGVAR(addCommonChannelCivLR), DEFAULT_COMMON_CH_ENABLED]));
        civilian
    };
};

TRACE_4("Babel junk",GVAR(westDefaultLanguages),GVAR(eastDefaultLanguages),GVAR(indyDefaultLanguages),GVAR(civDefaultLanguages));

[_ctrlBabel, _ctrlGroup getVariable QGVAR(selectedLanguages)] call FUNC(setBabelList);
[_ctrlGroup, _side] call FUNC(setChannelArrays);
[_ctrlRadio, lbCurSel _ctrlRadio] call FUNC(acreSideControlRadioChange);

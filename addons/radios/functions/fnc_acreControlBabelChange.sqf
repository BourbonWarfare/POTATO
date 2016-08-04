/*
 *
 */
disableSerialization;
#include "script_component.hpp"
TRACE_1("params",_this);
params ["_ctrlBabel","_index"];

uiSleep 0.05;

private _ctrlGroup = ctrlParentControlsGroup _ctrlBabel;
private _ctrlSide = _ctrlGroup controlsGroupCtrl CFG_SIDE_IDC;

private _selectedIndices = lbSelection _ctrlBabel;
TRACE_1("selected indices",_selectedIndices);

private _languages = [];
{
    _languages pushBack (_ctrlBabel lnbText [_x,0]);
} forEach _selectedIndices;

switch (lbcurSel _ctrlSide) do {
    case (0): { GVAR(westDefaultLanguages) = _languages; };
    case (1): { GVAR(eastDefaultLanguages) = _languages; };
    case (2): { GVAR(indyDefaultLanguages) = _languages; };
    default { GVAR(civDefaultLanguages) = _languages; };
};

/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

disableSerialization;
uiSleep 0.1;

params ["_ctrlBabel","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlBabel;
private _ctrlSide = _ctrlGroup controlsGroupCtrl CFG_S_SIDE_IDC;

private _selectedIndices = lbSelection _ctrlBabel;
_selectedIndices pushBackUnique _index;
TRACE_1("selected indices",_selectedIndices);

private _languages = [];
{
    _languages pushBack (_ctrlBabel lnbText [_x,0]);
} forEach _selectedIndices;

TRACE_1("selected languages",_languages);

if (_languages isNotEqualTo []) then {
    switch (lbCurSel _ctrlSide) do {
        case (0): { GVAR(westDefaultLanguages) = _languages; };
        case (1): { GVAR(eastDefaultLanguages) = _languages; };
        case (2): { GVAR(indyDefaultLanguages) = _languages; };
        default { GVAR(civDefaultLanguages) = _languages; };
    };
};

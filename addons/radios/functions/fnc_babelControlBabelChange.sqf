/*
 *
 */
disableSerialization;
#include "script_component.hpp"
TRACE_1("params",_this);
params ["_ctrlBabel","_index"];

uiSleep 0.05;

private _ctrlGroup = ctrlParentControlsGroup _ctrlBabel;
private _selectedIndices = lbSelection _ctrlBabel;
TRACE_1("selected indices",_selectedIndices);

private _languages = [];
{
    _languages pushBack (_ctrlBabel lnbText [_x,0]);
} forEach _selectedIndices;

_ctrlGroup setVariable [QGVAR(selectedLanguages),_languages];

/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlBabel"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlBabel;
private _selectedLanguages = _ctrlGroup setVariable [QGVAR(selectedLanguages),[]];
{
    if ((_x select 0) in _selectedLanguages) then {
        _ctrlBabel lbSetSelected [_forEachIndex, true];
    } else {
        _ctrlBabel lbSetSelected [_forEachIndex, false];
    };
} forEach GVAR(availableLanguages);

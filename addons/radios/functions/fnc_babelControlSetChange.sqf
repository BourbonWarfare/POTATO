/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlSet","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlSet;
private _ctrlBabel = _ctrlGroup controlsGroupCtrl BABEL_LIST_IDC;

private _switch = _index == 1;
private _fade = if (_switch) then { FADE_ENABLED } else { FADE_DISABLED };

_ctrlGroup setVariable [QGVAR(setBabel), _switch];

_ctrlBabel ctrlEnable _switch;
_ctrlBabel ctrlSetFade _fade;
_ctrlBabel ctrlCommit FADE_LENGTH;

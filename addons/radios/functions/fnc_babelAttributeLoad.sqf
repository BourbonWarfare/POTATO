/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if (GVAR(babelInvalid)) exitWith { LOG("Multiple sides selected, exiting early"); };

params ["_ctrlGroup",["_params", [], [[],true]]];
if (isNil "_params" || {_params isEqualType true && {_params}} || {_params isEqualTo []}) exitWith { LOG("languages not set, or in strange state, exiting early"); };

private _ctrlSet = _ctrlGroup controlsGroupCtrl RADIO_SET_IDC;
private _ctrlBabel = _ctrlGroup controlsGroupCtrl BABEL_LIST_IDC;

GVAR(setBabel) = _isSet;
GVAR(selectedLanguages) = _params;

_ctrlSet lbSetCurSel 1;
[_ctrlSet,1] call FUNC(babelControlSetChange);

[_ctrlBabel] call FUNC(setBabelList);

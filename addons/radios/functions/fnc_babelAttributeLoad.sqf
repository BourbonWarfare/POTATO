/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup",["_languageString", "", ["",true]]];
if (_ctrlGroup getVariable [QGVAR(babelInvalid), false]) exitWith { LOG("Multiple sides selected, exiting early"); };
if ((_languageString isEqualType true && {_languageString}) || {_languageString isEqualTo ""}) exitWith { LOG("languages not set, or in strange state, exiting early"); };

private _ctrlSet = _ctrlGroup controlsGroupCtrl RADIO_SET_IDC;

_ctrlSet lbSetCurSel 1;
[_ctrlSet,1] call FUNC(babelControlSetChange);
[_ctrlGroup controlsGroupCtrl BABEL_LIST_IDC, _languageString splitString ","] call FUNC(setBabelList);

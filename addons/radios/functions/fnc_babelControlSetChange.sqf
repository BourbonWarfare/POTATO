/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlSet","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlSet;

private _switch = _index == 1;
_ctrlGroup setVariable [QGVAR(setBabel), _switch];

[_switch, [_ctrlGroup controlsGroupCtrl BABEL_LIST_IDC]] call EFUNC(core,setControlFade);

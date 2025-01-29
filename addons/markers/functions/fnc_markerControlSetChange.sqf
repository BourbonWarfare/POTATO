/*
 *
 */

#include "..\script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlSet","_index"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlSet;

private _switch = _index == 1;
_ctrlGroup setVariable [QGVAR(setMarker), _switch];

[_switch, [
    _ctrlGroup controlsGroupCtrl MARKER_ICON_IDC,
    _ctrlGroup controlsGroupCtrl MARKER_NAME_IDC,
    _ctrlGroup controlsGroupCtrl MARKER_SIZE_IDC,
    _ctrlGroup controlsGroupCtrl MARKER_COLOR_IDC
]] call EFUNC(core,setControlFade);

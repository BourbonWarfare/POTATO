/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);
params ["_ctrlGroup","_value"];

(_ctrlGroup controlsGroupCtrl GROUP_MARKER_ICON_IDC) lbSetCurSel ([UNIT_MARKERS] find _value);

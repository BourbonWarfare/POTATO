/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);
params ["_ctrlGroup","_value"];

(_ctrlGroup controlsGroupCtrl TEAM_COLOR_IDC) lbSetCurSel ([TEAM_COLORS] find _value);

/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup"];

// register event handlers
(_ctrlGroup controlsGroupCtrl CFG_G_TI_EDIT_IDC) ctrlAddEventHandler ["killFocus",{[_this, false] call FUNC(acreGlobalTIChange);}];
(_ctrlGroup controlsGroupCtrl CFG_G_TI_SLIDER_IDC) ctrlAddEventHandler ["sliderPosChanged", {[_this, true] call FUNC(acreGlobalTIChange);}];

[_ctrlGroup] call FUNC(acreGlobalSetControlsFromGVars);

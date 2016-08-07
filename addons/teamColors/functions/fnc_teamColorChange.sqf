/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);
params ["_ctrlIcon","_index"];
private _ctrlGroup = ctrlParentControlsGroup _ctrlIcon;

_ctrlGroup setVariable [QGVAR(selectedColor),_index];

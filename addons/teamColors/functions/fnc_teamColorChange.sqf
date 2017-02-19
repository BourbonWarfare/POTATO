/*
 * Author: AACO
 * Function to handle a selection change in the team color component.
 * Should only be called from the 3DEN workflow
 *
 * Arguments:
 * 0: Control of the team color selection component <CONTROL>
 * 1: Fireteam color index <NUMBER>
 *
 * Example:
 * [control, 2] call potato_teamColors_fnc_teamColorChange;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_ctrlIcon","_index"];

(ctrlParentControlsGroup _ctrlIcon) setVariable [QGVAR(selectedColor), _index];

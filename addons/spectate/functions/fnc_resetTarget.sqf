/*
 * Author: AACO
 * Function used to reset the camera target
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_resetTarget;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

GVAR(cam) camPrepareTarget objNull;
GVAR(cam) camCommitPrepared 0.0;

detach GVAR(dummy);

GVAR(hasTarget) = false;

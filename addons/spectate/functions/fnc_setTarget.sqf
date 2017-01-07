/*
 * Author: AACO
 * Function used to
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_spectate_fnc_;
 *
 * Public: No
 */

#include "script_component.hpp"
#define CAMERA_TARGET_CHANGE_TIME 0.5
TRACE_1("Params",_this);

params ["_object"];

private _location = _object worldToModel (_object modelToWorldVisual (_object selectionPosition "Head"));

GVAR(dummy) attachTo [vehicle _object, _location];
GVAR(cam) camPrepareTarget GVAR(dummy);
GVAR(cam) camCommitPrepared CAMERA_TARGET_CHANGE_TIME;

GVAR(hasTarget) = true;

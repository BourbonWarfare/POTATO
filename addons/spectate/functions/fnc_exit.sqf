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
TRACE_1("Params",_this);

GVAR(running) = false;
OVERLAY closeDisplay 1;

[GVAR(thingsToDrawEH)] call CBA_fnc_removePerFrameHandler;
GVAR(thingsToDrawEH) = nil;

[GVAR(straggleUpdateEH)] call CBA_fnc_removePerFrameHandler;
GVAR(straggleUpdateEH) = nil;

removeMissionEventHandler ["Draw3D", GVAR(draw3DEH)];
GVAR(draw3DEH) = nil;

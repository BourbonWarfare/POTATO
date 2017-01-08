/*
 * Author: AACO
 * Function used to exit spectator
 * Should only be called by events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_exit;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

// Handle cameras/lights
GVAR(cam) cameraEffect ["Terminate", "BACK"];
player switchCamera "INTERNAL";
deleteVehicle GVAR(cam);

{ deleteVehicle _x; } forEach GVAR(camLights);
GVAR(camLights) = [];

setViewDistance GVAR(oldViewDistance);

[false] call acre_api_fnc_setSpectator;

[GVAR(thingsToDrawEH)] call CBA_fnc_removePerFrameHandler;
GVAR(thingsToDrawEH) = nil;

[GVAR(straggleUpdateEH)] call CBA_fnc_removePerFrameHandler;
GVAR(straggleUpdateEH) = nil;

removeMissionEventHandler ["Draw3D", GVAR(draw3DEH)];
GVAR(draw3DEH) = nil;

OVERLAY closeDisplay 1;
GVAR(running) = false;

#include "..\script_component.hpp"
#define IDD_CURATORFRAME 312
/*
 * Author: Lambda.Tiger
 * This function is run by a module on init. It takes the configured
 * side and configs to create resupply entries for them in the
 * players diary. This function can be called on the module later as the
 * module should not be automatically deleted.
 *
 * Arguments:
 * 0: The module being initialized
 * 2: Whether the module is active
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
params ["_logic"];
if !(local _logic) exitWith {};
TRACE_1("Running local EH",_this);

GVAR(nClickFunc) = getText (configOf _logic >> QGVAR(functionHandle));
GVAR(nClick_posText) = getArray (configOf _logic >> QGVAR(iconText));
GVAR(nClickPos) = [ASLToAGL getPosASL _logic];
GVAR(fucked) = findDisplay IDD_CURATORFRAME displayAddEventHandler ["MouseButtonDown", {call FUNC(zeus_nClickClickEH)}];
GVAR(nClickDraw3D) = addMissionEventHandler ["Draw3D", FUNC(zeus_nClickDraw3DEH)];

deleteVehicle _logic;

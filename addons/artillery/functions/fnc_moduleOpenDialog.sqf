#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function takes a module, uses it's position to initialize local
 * artillery target information and opens the artillery menu interface.
 *
 * Arguments:
 * _logic - The logic that is calling the function. OBJECT
 *
 * Example:
 * Called via module function
 *
 * Public: No
 */
params ["_logic"];
if !(local _logic) exitWith {};
if (isNil QGVAR(artilleryParams)) then {GVAR(artilleryParams) = createHashMap};
GVAR(artilleryParams) set ["position", ASLToAGL getPosASL _logic];
deleteVehicle _logic;
createDialog QGVAR(ArtilleryDisplay);

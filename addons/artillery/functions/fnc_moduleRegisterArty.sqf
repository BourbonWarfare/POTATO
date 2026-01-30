#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function takes a module, uses it's position and uses the position to
 * add nearby artillery pieces to every clients local artillery array. The
 * module is intended to be used by zeus but can be used in the editor.
 * The module is deleted wherever it is local after running.
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
[ASLToAGL getPosASL _logic] call FUNC(registerArtilleryUnits);
if (local _logic) then {
    deleteVehicle _logic;
};

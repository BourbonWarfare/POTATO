#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function takes the editor module and initializes the magazines added
 * to choose artilery round options. The array is spread globablly so JIPs
 * and non-local clients get the array.
 *
 * Arguments:
 * _module - The module that is calling the function. OBJECT
 * _value - Not directly passed, but accesible from parent function.
 *          Array of all the artillery magazines selected. ARRAY, default []
 *
 * Example:
 * Called via module function
 *
 * Public: No
 */
params ["_module"];
if (is3DEN || !local _module) exitWith {};
//IGNORE_PRIVATE_WARNING["_value"];
missionNamespace setVariable [QGVAR(artilleryAmmoTypes), +_value, true];
deleteVehicle _module;

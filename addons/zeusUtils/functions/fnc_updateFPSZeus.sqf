#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function initializes the GVAR(fpsAvgCalc) array and adds the per
 * frame event handler to calculate and report FPS
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * [] call potato_zeusUtils_fnc_initLocalFPSEH;
 *
 * Public: No
 */
params [["_hashmap", createHashMap, [createHashMap]]];

if (_hashmap isEqualTo createHashMap) exitWith {};

{

} forEach _hashmap;

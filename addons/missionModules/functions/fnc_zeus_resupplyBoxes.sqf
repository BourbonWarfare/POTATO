/*
 * Author: Lambda.Tiger
 * Creates a single copy of every resupply box defined in CfgLoadouts
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);
params ["_logic"];

if (!local _logic) exitWith {};

private _boxes = configProperties [missionConfigFile >> "CfgLoadouts" >> "SupplyBoxes", "isClass _x"];
private _posAGL = ASLToAGL getPosASL _logic;
deleteVehicle _logic;

{
    [{createVehicle [_this#0, _this#1, [], 5, "NONE"]}, [configName _x, _posAGL], _forEachIndex] call CBA_fnc_waitAndExecute;
} forEach _boxes;


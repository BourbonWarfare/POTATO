/*
 * Author: AACO
 * Function used create the spawned group with the given configuration
 *
 * Arguments:
 * 0: location to spawn the units <ARRAY>
 * 1: unit classnames to add <ARRAY>
 *
 * Examples:
 * [position player, ["WB_Soldier"]] call potato_zeusHC_fnc_buildAGroupSpawnLocal;
 * [[1,2,3], ["WB_Soldier"]] call potato_zeusHC_fnc_buildAGroupSpawnLocal;
 *
 * Public: No
 */

// NO_SIDE -1, EAST 0, WEST 1, RESISTANCE 2, CIVILIAN 3, NEUTRAL 4, ENEMY 5, FRIENDLY 6, LOGIC 7
#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_location","_unitsToAdd"];

if (count _unitsToAdd < 1) exitWith { diag_log QUOTE(No units passsed to FUNC(buildAGroupSpawn)) };

// get leader to determine side
private _leaderClass = (_unitsToAdd select 0) select 0;
private _leaderSide = getNumber (configFile >> "CfgVehicles" >> _leaderClass >> "side");
if (_leaderSide < 0 || _leaderSide > 3) exitWith { diag_log QUOTE(Leader passed to FUNC(buildAGroupSpawn) is not a 'playable' side) };

private _side = switch (_leaderSide) do { case 0: {east}; case 1: {west}; case 2: {resistance}; case 3: {civilian}; };

[_side, _location, _unitsToAdd, "FORM"] call FUNC(createGroup);

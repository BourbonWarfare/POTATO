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
private _group = createGroup _side;
{
    (_x select 0) createUnit [_location, _group];
    nil
} count _unitsToAdd;

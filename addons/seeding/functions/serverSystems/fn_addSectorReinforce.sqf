#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This takes a zone that will need reinforcements and either adds it to the
* running handler or initializes a new handler.
*
* Arguments:
* _marker - The marker zone (STRING).
* _squadsToSpawn - The number of reinforcment squads to spawn (SCALAR, default 2)
* _armedVehicles - Whether the vehicles to be spawned are armed or not (BOOL, default false)
* _sideHolding - The side holding the zone at the start (SIDE, default east)
* _startingUnits - The nunmber of units holding the zone, if < 0 then the
*                  number is calculated after the hold off time (SCALAR, default -1)
* _initHoldOff - How long to wait in seconds before checking the sector (SCALAR, default 0)
*
* Return:
* none
*
* Example:
* ["zone_14", 2, true, east, -1, 100] call bw_fnc_addSectorReinforce;
*//***************************************************************************/
params [
    ["_marker", "", [""]],
    ["_squadsToSpawn", 2, [2]],
    ["_armedVehicles", false, [false]],
    ["_sideHolding", east, [east]],
    ["_startingUnits", -1, [-1]],
    ["_initHoldOff", 0, [0]]
];

// Don't bother with bad sectors
if (_marker == "" || _squadsToSpawn == 0 || _startingUnits == 0) exitWith {};

// Hold off for enough time to activate the sector
if (_initHoldOff > 0) exitWith {
    [{_this call FUNC(addSectorReinforce)},
      [_marker, _squadsToSpawn, _armedVehicles, _sideHolding, _startingUnits],
    _initHoldOff] call CBA_fnc_waitAndExecute;
};

// Count units as requested
if (_startingUnits < 0) then {
    _startingUnits = count (units _sideHolding select {_x inArea _marker && alive _x});
};

// Call the loop function as needed or add if not
if (GVAR(reinforceHashMap) isEqualTo createHashMap) exitWith {
    GVAR(reinforceHashMap) set [_marker, [_squadsToSpawn, _armedVehicles, _sideHolding, _startingUnits]];
    [] call FUNC(handleSectorReinforce);
};
GVAR(reinforceHashMap) set [_marker, [_squadsToSpawn, _armedVehicles, _sideHolding, _startingUnits]];

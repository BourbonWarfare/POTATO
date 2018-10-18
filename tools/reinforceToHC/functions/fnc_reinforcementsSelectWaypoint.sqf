/*
 * Author: AACO
 * Helper function to determine LZ/RP waypoints
 *
 * Arguments:
 * 0: list of waypoints to choose from <ARRAY>
 * 1: index of waypoint selection <NUMBER>
 * 2: the name of the var used to count number of times chosen <STRING>
 * 3: where to compare distances to <ARRAY>
 *
 * Return Value:
 * The selected waypoint <OBJECT>
 *
 * Example:
 * [GVAR(allLzs), _vehicleLZIndex, "Ares_Lz_Count", GVAR(reinforcementLocation)] call potato_reinforceToHC_fnc_reinforcementsSelectWaypoint;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_wayPoints","_index","_countVar","_comparePosition"];

private _wp = switch (_index) do {
    case 0: { // Random
        selectRandom _wayPoints
    };
    case 1: { // Nearest
        [_comparePosition, _wayPoints] call Ares_fnc_GetNearest
    };
    case 2: { // Furthest
        [_comparePosition, _wayPoints] call Ares_fnc_GetFarthest
    };
    case 3: { // Least used
        private _leastUsed = selectRandom _wayPoints; // Choose randomly to start.
        {
            if (_x getVariable [_countVar, 0] < _leastUsed getVariable [_countVar, 0]) then {
                _leastUsed = _x;
            };
            nil
        } count _wayPoints;
        _leastUsed
    };
    default { // Specific LZ.
        _wayPoints select (_index - FIRST_SPECIFIC_LZ_OR_RP_OPTION_INDEX)
    };
};

_wp setVariable [_countVar, (_wp getVariable [_countVar, 0]) + 1];
_wp

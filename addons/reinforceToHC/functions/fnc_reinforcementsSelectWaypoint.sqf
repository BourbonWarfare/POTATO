/*
 * Author: AACO
 * Function called by the placed ARES reinforcement module to create the UI
 * to gather the reinforcment configuration, and send that information to the server
 *
 * Arguments:
 * 0: placed logic object <OBJECT>
 *
 * Return Value:
 * True if the logic is local to execution, false otherwise <BOOL>
 *
 * Example:
 * [gameLogic] call potato_reinforceToHC_fnc_reinforcementsDialogLoad;
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

/*
 * Author: AACO
 * Function to get the nearest AI group compared to the given logic
 *
 * Arguments:
 * 0: Object to compare group leaders to <OBJECT>
 *
 * Return Value:
 * grpNull if there was an error, the closest group to the provided object <GROUP>
 *
 * Examples:
 * [player] call potato_zeusHC_fnc_getNearestAIGroup;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];
if (isNull _logic) exitWith { grpNull };

private _nearestAiGroup = grpNull;
private _nearestAiGroupDistance = -1;
{
    private _noPlayers = true;
    {
        if (isPlayer _x) exitWith { _noPlayers = false; };
    } forEach (units _x);

    if (_noPlayers) then {
        private _distance = (leader _x) distance _logic;

        if (_distance < _nearestAiGroupDistance || {isNull _nearestAiGroup}) then {
            _nearestAiGroup = _x;
            _nearestAiGroupDistance = _distance;
        };
    };
} forEach allGroups;

_nearestAiGroup

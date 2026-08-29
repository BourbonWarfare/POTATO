#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles sending markers to a request array of players.
 * It takes an array of players and a boolean of whether to share across sides.
 * It then filters by side from ace_player side if the boolean is true, and
 * then collects map markers and sends a target event if there are markers to
 * send.
 *
 * Arguments:
 * _targets - An array of units that markers should be shared with (ARRAY, default [])
 * _allowOtherSides - Allow copying maps between different sides (BOOL, default false)
 *
 * Return:
 * None
 *
 * Public: No
 */
params [["_targets", []], ["_allowOtherSides", false, [false]]];
if !(_allowOtherSides) then {
    private _side = side ace_player;
    _targets = _targets select {side _x == _side};
};
private _marks = [true] call FUNC(collectMarkers);
if (_marks != "{}") then {
    [QGVAR(recieveMarkers), _marks, _targets] call CBA_fnc_targetEvent;
};

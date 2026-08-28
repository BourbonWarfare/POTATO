#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is run by a module on init. It takes the configured
 * radio parameters, adds relevant events and ACE actions, and configures
 * local variables for marker sharing
 *
 * Arguments:
 * 0: The module being initialized
 * 2: Whether the module is active
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
[QGVAR(recieveMarkers), [true] call FUNC(collectMarkers), _targets] call CBA_fnc_targetEvent;

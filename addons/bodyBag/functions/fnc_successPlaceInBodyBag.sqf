/*
 * Author: AACO
 * Callback when putting in a body bag succeeds. Mainly reset animation and handles the body
 *
 * Arguments:
 * 0: The mortician <OBJECT>
 * 1: The dead <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, cursorTarget] call potato_bodyBag_fnc_successPlaceInBodyBag
 *
 * Public: No
 */

#include "script_component.hpp"

(_this select 0) params ["_caller", "_target"];

[_caller] call FUNC(resetAnimation);

if (local _target) then {
    [_caller, _target] call FUNC(actionPlaceInBodyBag);
} else {
    TRACE_1("running where local", local _target);
    [_caller, _target] remoteExecCall [QFUNC(actionPlaceInBodyBag), _target];
};

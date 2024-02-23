#include "script_component.hpp"
/*
 * Author: Bailey
 * Register an egress for the paradrop system
 *
 * Arguments:
 * 1: Ingress ID <Number>
 * 2: Position <ARRAY>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [5213, [1, 2, 3]] call potato_paradrop_fnc_registerDz;
 *
 * Public: Yes
 */
params ["_ingressId", "_egressPosition"];
(GVAR(paradropObjects) get _ingressId) set ["egressPosition", _egressPosition];


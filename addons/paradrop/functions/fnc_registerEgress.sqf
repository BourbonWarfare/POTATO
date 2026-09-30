#include "script_component.hpp"
/*
 * Author: Bailey
 * Register an egress for the paradrop system
 *
 * Arguments:
 * 0: Ingress ID <Number>
 * 1: Position <ARRAY>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [5213, [1, 2, 3]] call potato_paradrop_fnc_registerEgress;
 *
 * Public: Yes
 */
params ["_ingressId", "_egressPosition"];
(GVAR(paradropObjects) get _ingressId) set ["egressPosition", _egressPosition];


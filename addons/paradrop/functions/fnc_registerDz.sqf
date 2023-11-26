#include "script_component.hpp"
/*
 * Author: Bailey
 * Register a DZ for the paradrop system
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
params ["_ingressId", "_dzPosition"];
private _dzPositions = (GVAR(paradropObjects) get _ingressId) getOrDefault ["dzPositions", [], true];
_dzPositions pushBack _dzPosition;
(GVAR(paradropObjects) get _ingressId) set ["dzPositions", _dzPositions];


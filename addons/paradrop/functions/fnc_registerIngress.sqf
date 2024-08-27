#include "script_component.hpp"
/*
 * Author: Bailey
 * Register the ingress point for the paradrop
 *
 * Arguments:
 * 1: Position <ARRAY>
 * 2: (Optional) Fly in height <NUMBER>
 * 3: (Optional) Drop delay <NUMBER>
 * 4: (Optional) Infantry Parachute Classname <STRING>
 * 5: (Optional) Cargo Parachute Classname <STRING>
 *
 * Return Value:
 * Ingress point ID <NUMBER>
 *
 * Example:
 * [[1, 2, 3], 0.5, "MyCoolParachute"] call potato_paradrop_fnc_registerIngress;
 *
 * Public: Yes
 */
params ["_position", ["_flyInHeight", 150], ["_dropDelay", 0.3], ["_infantryParachuteClassname", "Steerable_Parachute_F"], ["_cargoParachuteClassname", "B_Parachute_02_F"]];
GVAR(paradropId) = GVAR(paradropId) + 1;

GVAR(paradropObjects) set [GVAR(paradropId), createHashMapFromArray [
    ["ingressPosition", _position],
    ["flyInHeight", _flyInHeight],
    ["dropDelay", _dropDelay],
    ["infantryParachuteClassname", _infantryParachuteClassname],
    ["cargoParachuteClassname", _cargoParachuteClassname]
]];

GVAR(paradropId)


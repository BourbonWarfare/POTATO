#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Sets the armor value for a specific class.
 *
 * Arguments:
 * 0: Hit point to resolve to one or more hitpoints <STRING>
 *
 * Return Value:
 * Array of hitpoints
 *
 * Public: Yes
 */
params [["_hitPoint", "", [""]]];

_hitPoint = toLowerANSI _hitPoint;

switch (_hitPoint) do {
    case "ama_hitbody": {
        ["hitabdomen", "hitdiaphragm", "hitchest", "hitpelvis"]
    };
    case "ama_hittorso": {
        ["hitabdomen", "hitdiaphragm", "hitchest"]
    };
    case "ama_hitarms": {
        ["hitleftarm", "hitrightarm"]
    };
    case "ama_hitlegs": {
        ["hitleftleg", "hitrightleg"]
    };
    case "ama_hitlimbs": {
        ["hitleftarm", "hitrightarm", "hitleftleg", "hitrightleg"]
    };
    default {
        [_hitPoint]
    };
}

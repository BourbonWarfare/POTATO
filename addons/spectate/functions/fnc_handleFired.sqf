/*
 * Author: AACO
 * Function used to handle a unit firing it's weapon
 * Should only be called by events
 *
 * Arguments:
 * 0: Unit firing <OBJECT>
 * 1: Fired weapon <STRING>
 * 6: Fired projectile <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_handleFired;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [
    "_unit",
    ["_weapon", "", [""]],
    "", // muzzle (ignored)
    "", // mode (ignored)
    "", // ammo (ignored)
    "", // magazine (ignored)
    ["_projectile", objNull, [objNull]]
];

// Fire time used for highlighting
_unit setVariable [QGVAR(highlightTime), time + FIRE_HIGHLIGHT_TIME];

// Store projectiles / grenades for drawing
if (GVAR(drawProjectiles) && {!isNull _projectile}) then {
    if (_weapon == "Throw") then {
        if (count GVAR(grenades) > MAX_TRACKED_GRENADES) then { GVAR(grenades) deleteAt 0; };
        GVAR(grenades) pushBack _projectile;
    } else {
        if (count GVAR(projectiles) > MAX_TRACKED_PROJECTILES) then { GVAR(projectiles) deleteAt 0; };
        GVAR(projectiles) pushBack [_projectile, [[getPosVisual _projectile, [1,0,0,0]]]];
    };
};

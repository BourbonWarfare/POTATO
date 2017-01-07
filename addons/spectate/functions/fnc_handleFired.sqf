/*
 * Author: AACO
 * Function used to
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_spectate_fnc_;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

if (GVAR(running)) then {
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
};

#include "script_component.hpp"

/*
 * Author: Bailey
 * Returns array of view cones of all players
 *
 * Arguments:
 * None
 *
 * Return Value:
 * View Cones <ARRAY>
 *
 * Example:
 * [] call potato_bodyCleanup_fnc_getPlayerViewCones;
 *
 * Public: No
 */

private _viewCones = [];

private _players = allPlayers select {
    alive _x &&
    _x isEqualTo vehicle _x &&
    !(_x isKindOf "VirtualMan_F")
};

private _sampleSize = ceil (MAX_SAMPLE_SIZE * count _players);

// Sample a random selection of players to determine if anyone can see any cells
// Since cleanup isnt immediate, we assume that we will sample enough players such that in the majority
// of cases we won't accidentally delete something within view
private _sample = [];
for "_i" from 0 to _sampleSize do {
    private _index = floor random count _players;
    _sample pushBack (_players select _index);
    _players deleteAt _index;
};

{
    _viewCones pushBack [
        getPosASLVisual _x,
        getCameraViewDirection _x,
        (getCameraViewDirection _x) call CBA_fnc_vect2polar,
        ARMA_DEFAULT_FOV
    ];
} forEach _sample;

_viewCones
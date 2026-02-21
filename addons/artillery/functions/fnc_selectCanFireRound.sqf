#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Selects and returns artillery pieces from the local artillery pool that can
 * fire a given magazine at an array of target positions point ordered by TOF.
 * This function will add and remove magazines from the vehicles as there must
 * be one for the getArtilleryETA command to work.
 *
 * Arguments:
 * _targetsAGL - Positions (AGL) to check against. ARRAY of positions (AGL), default []
 * _magazine - The magaine that the artillery gun should attempt to fire at the targets. STRING
 *
 * Return:
 * None
 *
 * Example:
 * [[[12,42,0], getPosATL player], "8Rnd_82mm_Mo_Smoke_white"] call potato_artillery_fnc_selectCanFireRound;
 *
 * Public: No
 */
params [["_targetsAGL", [], [[]]], "_magazine"];

if (isNil QGVAR(artilleryGunArray)) exitWith {
    []
};

// update artillery array contents to
GVAR(artilleryGunArray) = GVAR(artilleryGunArray) select {
    alive _x && local _x && alive gunner _x && !isPlayer gunner _x
};

private _viableArty = GVAR(artilleryGunArray) select {
    private _artyPiece = _x;
    ARTILLERY_MISSION_STATUS_FREE == ((_artyPiece getVariable [
        QGVAR(artyMission), [
            "", ARTILLERY_MISSION_STATUS_FREE
    ]])#1) && {[_artyPiece, _magazine] call FUNC(canFireRound)} && {
        _artyPiece addMagazineTurret [_magazine, [0], 0];
        private _canHit = true;
        {
            _canHit = _canHit && _x inRangeOfArtillery [[_artyPiece], _magazine];
        } forEach _targetsAGL;
        _artyPiece removeMagazinesTurret [_magazine, [0]];
        _canHit &&
        alive gunner _x
    }
};
_viableArty = _viableArty apply {
    _x addMagazineTurret [_magazine, [0], 0];
    private _tof = _x getArtilleryETA [_targetsAGL#0, _magazine];
    _x removeMagazinesTurret [_magazine, [0]];
    [_tof, _x];
};

_viableArty sort true;
_viableArty

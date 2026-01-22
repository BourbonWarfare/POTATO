#include "..\script_component.hpp"
/**************************************************************//*
* Selects and returns artillery pieces that can fire given
* magazine at a given point ordered by TOF
*
* Arguments:
* _targetAGL - Position (AGL) of the target
* _magazine - Magazine desired to be fired
*
* Example:
* [[12,42,0], "8Rnd_82mm_Mo_Smoke_white"] call lmd_fnc_selectCanFireRound;
*//**************************************************************/

// Initialization
params [["_targetsAGL", [], [[]]], "_magazine"];

if (isNil QGVAR(artilleryGunArray)) exitWith {
    []
};

// update artillery array contents to
GVAR(artilleryGunArray) = GVAR(artilleryGunArray) select {
    alive _x && local _x && alive gunner _x
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

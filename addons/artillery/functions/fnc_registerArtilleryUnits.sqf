#include "..\script_component.hpp"
/**************************************************************//*
* Adds artillery to pool for artillery missions.
*
* Arguments:
* _posAGL - Position to search near for artillery pieces
* _attachedObject - Artillery piece to add
*
* Example:
* [getpos target, objNull] call lmd_fnc_registerArtilleryUnits;
* [[0, 0, 0], _myMortar] call lmd_fnc_registerArtilleryUnits;
*//**************************************************************/
params [
  "_posAGL",
  ["_attachedObject", objNull]
];

if (isNil QGVAR(artilleryGunArray)) then {
    GVAR(artilleryGunArray) = [];
};

if (isNull _attachedObject) then {
    private _nearObjects = (ASLToAGL _posAGL) nearEntities [["StaticWeapon", "Car_F", "Tank_F"], 50];
    private _artilleryToAdd = _nearObjects select {
        local _x &&
        {0 < getNumber ((configOf _x) >> "artilleryScanner")}
    };
    GVAR(artilleryGunArray) = GVAR(artilleryGunArray) - _artilleryToAdd;
    GVAR(artilleryGunArray) append _artilleryToAdd;
} else {
    if (local _attachedObject && {0 < getNumber ((configOf _attachedObject) >> "artilleryScanner")}) then {
        GVAR(artilleryGunArray) pushBackUnique _attachedObject;
    };
};

#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Adds nearby or a specific artillery piece to the local pool of artillery
 * guns for artillery missions. It takes a position to search near and a
 * specific object. If the object is not defined or null, a search within
 * 50m of _posAGL will be conducted for valid artillery guns. To be a valid gun
 * the vehicle must have the artilleryScanner component that allows AI to fire.
 *
 * Arguments:
 * _posAGL - Position to search near for artillery pieces in AGL format. ARRAY
 * _attachedObject - A specific artillery gun to add to the artillery pool.
 *
 * Return:
 * None
 *
 * Example:
 * [ASLToAGL getPosASL player] call potato_artillery_fnc_registerArtilleryUnits;
 *
 * Public: No
 */
params [
  "_posAGL",
  ["_attachedObject", objNull]
];

if (isNil QGVAR(artilleryGunArray)) then {
    GVAR(artilleryGunArray) = [];
};

if (isNull _attachedObject) then {
    private _nearObjects = _posAGL nearEntities [["StaticWeapon", "Car_F", "Tank_F"], 50];
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

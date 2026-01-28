#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function beginning takes an artillery piece and a magazine and checks
 * whether the primary weapon of the vehicle can fire the requested round.
 *
 * Arguments:
 * _artilleryPiece - The artillery piece firing, Object default objNull
 * _magazine - The magazine to be tested, STRING, default ""
 *
 * Return:
 * BOOL - Whether the piece can fire the round.
 *
 * Example:
 * [_artyGun, "someArtilleryMagazine"] call potato_artillery_fnc_canFireRound;
 *
 * Public: No
 */
params [["_artilleryPiece", objNull], ["_magazine", ""]];

if (!alive _artilleryPiece ||
    _magazine == "" ||
    !local _artilleryPiece) exitWith {false};

if (isNil QGVAR(vehicleMagazineCache)) then {
    GVAR(vehicleMagazineCache) = createHashMap;
};

_magazine in (GVAR(vehicleMagazineCache) getOrDefaultCall [typeOf _artilleryPiece, {
    private _weapon = (_artilleryPiece weaponsTurret [0])#0;
    compatibleMagazines _weapon
}, true])

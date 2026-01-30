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
private _type = typeOf _artilleryPiece;
_magazine in (GVAR(vehicleMagazineCache) getOrDefaultCall [_type, {
    if (isNil QGVAR(vehicleWeaponCache)) then {GVAR(vehicleMagazineCache) = createHashMap;};
    private _weapon = GVAR(vehicleWeaponCache) getOrDefaultCall [_type, {
        private _cfg = (configOf _artilleryPiece) >> "Turrets";
        private _turret = 0;
        while {getNumber ((_cfg select _turret) >> "primaryGunner") == 0} do {_turret = _turret + 1;};
        (_artilleryPiece weaponsTurret [_turret])#0
    }, true];
	compatibleMagazines _weapon
}, true])

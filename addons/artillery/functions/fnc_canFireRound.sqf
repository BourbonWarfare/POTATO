#include "..\script_component.hpp"
/**************************************************************//*
* Helper function that checks if an artillery piece can fire a round
*
* Arguments:
* _artilleryPiece - artillery piece to check for compatability
* _magazine - magazine to check
*
* Return:
* Whether a unit can fire a round type (BOOL)
*
*
* Example:
* [cursorObject, currentMagazine cursorObject] call FUNC(canFireRound);
*//**************************************************************/
params [["_artilleryPiece", objNull], ["_magazine", ""]];

if (!alive _artilleryPiece ||
    _magazine == "" ||
    !local _artilleryPiece) exitWith {false};

if (isNil QGVAR(vehicleMagazineCache)) then {
    GVAR(vehicleMagazineCache) = createHashMap;
};

_magazine in (GVAR(vehicleMagazineCache) getOrDefaultCall [typeOf _artilleryPiece, {
    private _weapon = (_artilleryPiece weaponsTurret [0])#0;
    getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines")
}, true])

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _vehicle = (vehicle _unit);
if (_vehicle in VGVAR(ArtilleryArray)) exitWith {};

//Get the vehicles class name.
private _class = typeOf _vehicle;

if (isNil ("_class")) exitWith {};

//Figure out if it is defined as artillery
private _artyScan = ;

//Exit the script if it is not defined as artillery
if (isNumber(configfile >> "CfgVehicles" >> _class >> "artilleryScanner")) then {
    _vehicle setVariable [VQGVAR(isArtillery), true];
    VGVAR(ArtilleryArray) pushBack _vehicle;
} else {
    if (_vehicle in VGVAR(ArtilleryArray)) then {
        VGVAR(ArtilleryArray) = VGVAR(ArtilleryArray) - [_vehicle];
    };
}

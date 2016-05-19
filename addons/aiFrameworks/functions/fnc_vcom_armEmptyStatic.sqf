#include "script_component.hpp"
TRACE_1("params",_this);

if !(VGVAR(usePlacedStaticWeapons)) exitWith {};

params["_unit"];

private _position = getPosATL _unit;
private _weapon = nearestObject [_position, "StaticWeapon"];

if (isNull _weapon || {(_weapon distance _unit) > VGVAR(maxDistanceToMountEmptyStatic)}) exitWith {};

if (isNull (assignedGunner _weapon)) then {
    _unit doMove (getposATL _weapon);
    _unit assignAsGunner _weapon;
    [_unit] orderGetIn true;
};

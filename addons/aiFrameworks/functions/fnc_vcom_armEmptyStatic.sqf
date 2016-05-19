#include "script_component.hpp"
TRACE_1("params",_this);

if !(VGVAR(usePlacedStaticWeapons)) exitWith {};

params["_unit"];

private _weapons = nearestObjects [_unit,"StaticWeapon",VGVAR(maxDistanceToMountEmptyStatic)];
if ((count _weapons) > 0 && {isNull (assignedGunner _weapon)}) then {
    private _weapon = _weapons select 0;
    _unit doMove (getposATL _weapon);
    _unit assignAsGunner _weapon;
    [_unit] orderGetIn true;
};

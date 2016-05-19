#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _weapons = nearestObjects [_unit,"StaticWeapon",VGVAR(maxDistanceToMountEmptyStatic)];
_unit setVariable [VQGVAR(StaticNearby), (count _weapons > 0)];

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _weapons = nearestObjects [_unit,["StaticWeapon"],VGVAR(maxDistanceToMountEmptyStatic)];
count _weapons > 0

#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

_unit setVariable [VQGVAR(orderedIntoStatic),diag_tickTime];

private _weapons = nearestObjects [_unit,["StaticWeapon"],VGVAR(maxDistanceToMountEmptyStatic)];
if ((count _weapons) > 0) then {
    private _weapon = _weapons select 0;
    TRACE_2("params",_weapon,assignedGunner _weapon);
    if (isNull (assignedGunner _weapon)) then {
        _unit doMove (getposATL _weapon);
        _unit assignAsGunner _weapon;
        [_unit] orderGetIn true;
    };
};

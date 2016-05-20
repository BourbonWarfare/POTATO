#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _weapon = _unit getVariable VQGVAR(staticWeapon);

_unit leaveVehicle _weapon;
private _unitStatic = _unit getVariable VQGVAR(usedStatic);

sleep 0.25;

_unit action ["DisAssemble",_weapon];
deleteVehicle _weapon;

sleep 1;
_unit addBackpack _unitStatic;
_unit setVariable [VQGVAR(hasDeployed),false];

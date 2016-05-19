#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _currentBackpack = backpack _unit;
if (isNil "_currentBackpack") exitWith {};

private _class = [_currentBackpack] call VFUNC(classvehicle);
if (isNil "_class") exitWith {};

private _parents = [_class,true] call BIS_fnc_returnParents;

if (("StaticWeapon" in _parents) || {("Weapon_Bag_Base" in _parents)}) then {
    _unit setVariable [VQGVAR(hasStatic),true];
    _unit setVariable [VQGVAR(staticClassname),_currentBackpack];

    if ("UAV" in (toUpper _currentBackpack)) then {
        _unit setVariable [VQGVAR(hasUAV),true];
    };
}
else {
    _unit setVariable [VQGVAR(hasStatic),false];
    _unit setVariable [VQGVAR(hasUAV),false];
};

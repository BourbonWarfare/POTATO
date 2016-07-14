#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _currentBackpack = backpack _unit;
if (_currentBackpack == "") exitWith {};

private _class = [_currentBackpack] call VFUNC(classVehicle);

private _parents = [_class,true] call BIS_fnc_returnParents;
TRACE_2("bag",_class,_parents);
if (("StaticWeapon" in _parents) || {("Weapon_Bag_Base" in _parents)}) then {
    _unit setVariable [VQGVAR(hasStatic),true];
    _unit setVariable [VQGVAR(staticClassname),_currentBackpack];

    if (["UAV",_currentBackpack] call BIS_fnc_inString) then {
        _unit setVariable [VQGVAR(hasUAV),true];
    };
}
else {
    _unit setVariable [VQGVAR(hasStatic),false];
    _unit setVariable [VQGVAR(hasUAV),false];
};

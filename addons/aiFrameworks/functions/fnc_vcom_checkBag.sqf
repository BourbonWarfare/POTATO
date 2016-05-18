#include "script_component.hpp"
TRACE_1("params",_this);

private ["_Unit", "_CurrentBackPack", "_class", "_parents", "_IsUAV"];
_Unit = _this;

_CurrentBackPack = backpack _Unit;

if (isNil "_CurrentBackPack") exitWith {};
_class = [_CurrentBackPack] call VCOMAI_Classvehicle;

if (isNil "_class") exitWith {};
_parents = [_class,true] call BIS_fnc_returnParents;
if (("StaticWeapon" in _parents) || {("Weapon_Bag_Base" in _parents)}) then
{
	_Unit setVariable ["VCOM_HASSTATIC",true,false];
	_Unit setVariable ["VCOM_StaticClassName",_CurrentBackPack,false];
	_IsUAV = ["UAV",_CurrentBackPack,false] call BIS_fnc_inString;
	if (_IsUAV) then {_Unit setVariable ["VCOM_HASUAV",true,false];};
}
else
{
	_Unit setVariable ["VCOM_HASSTATIC",false,false];
};

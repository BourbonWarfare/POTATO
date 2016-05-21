#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _vehicle = (vehicle _unit);
private _class = typeOf _vehicle;

TRACE_3("",_vehicle,_class,isNumber(configfile >> "CfgVehicles" >> _class >> "artilleryScanner"));

if (isNil ("_class")) exitWith {};

//Exit the script if it is not defined as artillery
if (isNumber(configfile >> "CfgVehicles" >> _class >> "artilleryScanner")) then {
    _unit setVariable [VQGVAR(isArtillery),true,true];
} else {
    if (_unit getVariable [VQGVAR(isArtillery),false]) then {
        _unit setVariable [VQGVAR(isArtillery),false,true];
    };
}

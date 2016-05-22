#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _fnc_setIfNotSet = {
    TRACE_1("private func params",_this);
    params ["_unit","_value"];
    if !(_unit getVariable [VQGVAR(isArtillery),false] isEqualTo _value) then {
        _unit setVariable [VQGVAR(isArtillery),_value,true];
    };
};

private _vehicle = (vehicle _unit);
private _class = typeOf _vehicle;

if (_unit == _vehicle || {isNil "_class"}) exitWith {
    TRACE_1("Exiting early",false);
    [_unit, false] call _fnc_setIfNotSet;
};

TRACE_3("",_vehicle,_class,isNumber(configfile >> "CfgVehicles" >> _class >> "artilleryScanner"));
[_unit, isNumber(configfile >> "CfgVehicles" >> _class >> "artilleryScanner")] call _fnc_setIfNotSet;

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

private _isArtillery = isNumber(configfile >> "CfgVehicles" >> _class >> "artilleryScanner");
private _hasAmmo = count (getArtilleryAmmo [_vehicle]) > 0;

TRACE_4("",_vehicle,_class,_isArtillery,_hasAmmo);
[_unit, _isArtillery && _hasAmmo] call _fnc_setIfNotSet;

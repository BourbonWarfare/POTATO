#include "script_component.hpp"

private _vehicles = (all3DENEntities select 0) select {(_x isKindOf "LandVehicle") || {_x isKindOf "Air"} || {_x isKindOf "Ship"}};

private _types = [];
private _output = [];

{
    private _typeOf = typeOf _x;
    private _index = _types pushBackUnique _typeOf;
    if (_index != -1) then {
        private _displayName = getText (configFile >> "CfgVehicles" >> _typeOf >> "displayName");
        // Some RHS are Vehicle-in-Vehicle transports and won't take any troops
        private _vivCargo = getArray (configFile >> "CfgVehicles" >> _typeOf >> "VehicleTransport" >> "Carrier" >> "cargoBayDimensions");
        private _vivWarn = if (_vivCargo isEqualTo []) then { "" } else { "[VIV Carrier - Probably not for infantry!]" };
        // Fullcrew is usually good enough, some RHS/CUP? vics may have scripted locked turrets for complex weapon systems
        _output pushBack format ["%1 - %2 %3", _displayName, count fullCrew [_x, "", true], _vivWarn];
    };
} forEach _vehicles;

TRACE_2("",_types,_output);

[(_output joinString "<br/>")] call BIS_fnc_3DENNotification;

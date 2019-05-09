#include "script_component.hpp"

private _vehicles = (all3DENEntities select 0) select {(_x isKindOf "LandVehicle") || {_x isKindOf "Air"} || {_x isKindOf "Ship"}};

private _types = [];
private _output = [];

{
    private _typeOf = typeOf _x;
    private _index = _types pushBackUnique _typeOf;
    if (_index != -1) then {
        private _displayName = getText (configFile >> "CfgVehicles" >> _typeOf >> "displayName");
        // Fullcrew is usually good enough, some RHS/CUP? vics may have scripted locked turrets for complex weapon systems
        _output pushBack format ["%1 - %2", _displayName, count fullCrew [_x, "", true]];
    };
} forEach _vehicles;

TRACE_2("",_types,_output);

[(_output joinString "<br/>")] call BIS_fnc_3DENNotification;

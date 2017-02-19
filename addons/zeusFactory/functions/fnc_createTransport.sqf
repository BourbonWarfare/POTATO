// createTransport
#include "script_component.hpp"

params ["_factory", "_transportType", "_group", "_side"];
TRACE_4("createTransport",_factory,_transportType,_group,_side);

([_factoryLogic,_transportType,_side] call FUNC(getTransportType)) params ["_vehType", "_crewType", "_maxCargoRoom", "_addGunner"];
TRACE_4("getTransportType",_vehType,_crewType,_maxCargoRoom,_addGunner);
if ((_vehType == "") || {_crewType == ""}) exitWith {ERROR_2("bad data[%1-%2]",_vehType,_crewType);};

private _vehicle = _vehType createVehicle ((leader _group) getRelPos [5, 0]);

private _group = createGroup _side;
private _driver = _group createUnit [_crewType, (getPos _vehicle), [], 0, "NONE"];

[{
    params ["_driver"];
    TRACE_1("setting driver skill", _driver);
    if (isNull _driver || {!local _driver}) exitWith {};
    // Let's have the driver be as competent as possible, because AI drivers are terrible
    _driver setSkill ["general", 1];
    _driver setSkill ["courage", 1];
    _driver disableAI "AUTOCOMBAT";
    _driver disableAI "SUPPRESSION";
    _driver allowFleeing 0;
}, [_driver], 2] call CBA_fnc_waitAndExecute; // this should be on delay to avoid conflicts with setSkill module

_group addVehicle _vehicle;
_driver moveInDriver _vehicle;

if (_addGunner) then {
    private _gunner = _group createUnit [_crewType, (getPos _vehicle), [], 0, "NONE"];
    _gunner moveInGunner _vehicle;
};

_vehicle engineOn true;
_vehicle lock 0;

TRACE_2("return",_vehicle,_group);
[_vehicle, _group]

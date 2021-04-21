// createTransport
#include "script_component.hpp"

params ["_factoryLogic", "_transportType", "_group", "_side"];
TRACE_4("createTransport",_factoryLogic,_transportType,_group,_side);

([_factoryLogic,_transportType,_side] call FUNC(getTransportType)) params ["_vehType", "_crewType"];
TRACE_2("getTransportType",_vehType,_crewType);
if ((_vehType == "") || {_crewType == ""}) exitWith {ERROR_2("bad data[%1-%2]",_vehType,_crewType);};

private _vehicle = _vehType createVehicle ((leader _group) getRelPos [5, 0]);
[_vehicle] call EFUNC(core,addToCurator);

private _group = createGroup [_side, true]; // explicitly mark for cleanup
private _driver = _group createUnit [_crewType, (getPos _vehicle), [], 0, "NONE"];
[_driver] call EFUNC(core,addToCurator);

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

// add a gunner to all available turrets
// just ace_common_fnc_getDoorTurrets but without getting FFV seats

private _gunnerTurrets = [];
private _turrets = allTurrets [_vehicle, false];

{
    private _config = configOf _vehicle;
    _config = [_config, _x] call ACEFUNC(common,getTurretConfigPath);

    if (((getNumber (_config >> "isCopilot")) == 0) && {count getArray (_config >> "weapons") > 0}) then {
        _gunnerTurrets pushBack _x;
    };
} forEach _turrets;

{
    private _gunner = _group createUnit [_crewType, (getPos _vehicle), [], 0, "NONE"];
    [_gunner] call EFUNC(core,addToCurator);
    _gunner assignAsTurret [_vehicle, _x];
    _gunner moveInTurret [_vehicle, _x];
} forEach _gunnerTurrets;

_vehicle engineOn true;
_vehicle lock 0;

TRACE_2("return",_vehicle,_group);
[_vehicle, _group]

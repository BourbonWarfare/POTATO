#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function handles opening the GRAD mission with only specific
* vehicle types
*
* Arguments:
* Action Params
*
* Return:
* None
*
* Example:
* [] call bw_fnc_gradVicHandle;
*//***************************************************************************/
//IGNORE_PRIVATE_WARNING ["_player"];
if (((_player nearEntities ["CAManBase", 400]) select {
        alive _x &&
        (side _x == east ||
        side _x == resistance)
        }) isNotEqualTo []) exitWith {
    ["Notif_Picture", [
        "Failed to Open Menu",
        "Enemy within 400 meters, you may not manage vehicles.",
        "\a3\ui_f\data\igui\cfg\actions\returnflag_ca.paa"
    ]] call BIS_fnc_showNotification;
};
private _centerPos = getPosATL _player;
private _spawnPositions = flatten ([_centerPos] call FUNC(findRoadPos));
private _heliSpawns = _centerPos nearObjects [SPAWN_HELI_OBJ, 100];
private _plansSpawns = _centerPos nearObjects [SPAWN_PLANE_OBJ, 100];
if (_spawnPositions isEqualTo [0, 0, 0, 0] &&
    _heliSpawns isEqualTo [] &&
    _plansSpawns isEqualTo []) exitWith {
    ["Notif_Picture", [
        "No Nearby Flag",
        "Flag must be within 100m of a road or vehicle spawn to spawn a vehicle.",
        "\a3\ui_f\data\igui\cfg\actions\returnflag_ca.paa"
    ]] call BIS_fnc_showNotification;
};
private _cfgPath = missionConfigFile >> "CfgLoadouts" >> "potato_w";
private _vehicles = [];
_spawnPositions = [_spawnPositions, _spawnPositions];
if (_spawnPositions isNotEqualTo [0, 0, 0, 0]) then {
    _vehicles = (getArray (_cfgPath >> "transportVehiclePool")) + getArray (_cfgPath >> "armedSoftVehiclePool");
};
if (_spawnPositions isNotEqualTo [0, 0, 0, 0]&& GVAR(enableGRADMode) != 3) then {
    _vehicles = _vehicles + getArray (_cfgPath >> "armedSoftVehiclePool");
};
if (_spawnPositions isNotEqualTo [0, 0, 0, 0] && GVAR(enableGRADMode) < 3) then {
    _vehicles = _vehicles + getArray (_cfgPath >> "armoredVehiclePool");
};
if (_spawnPositions isNotEqualTo [0, 0, 0, 0] && GVAR(enableGRADMode) < 3) then {
    _vehicles = _vehicles + getArray (_cfgPath >> "tankVehiclePool");
};
if (_heliSpawns isNotEqualTo [] && GVAR(enableGRADMode) < 3) then {
    private _finalHeli = selectRandom _heliSpawns;
    _spawnPositions pushBack ((getPosATL  _finalHeli) + [getDir _finalHeli]);
    _vehicles = _vehicles + getArray (_cfgPath >> "heliVehiclePool");
}  else {
    _spawnPositions pushBack [0, 0, 0, 0];
};
if (_plansSpawns isNotEqualTo [] && GVAR(enableGRADMode) < 3) then {
    private _finalPlane = selectRandom _plansSpawns;
    _spawnPositions pushBack ((getPosATL _finalPlane) + [getDir _finalPlane]);
    _vehicles = _vehicles + getArray (_cfgPath >> "planeVehiclePool");
};
if (_vehicles isNotEqualTo []) then {
    [{
        _this spawn grad_vehicleSpawner_fnc_openDialog;
    }, [_vehicles,_spawnPositions]] call CBA_fnc_execNextFrame;
};

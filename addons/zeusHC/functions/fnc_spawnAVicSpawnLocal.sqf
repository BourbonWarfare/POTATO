/*
 * Author: AACO
 * Function used to safely spawn crewed vehicles, will check for a group count and a total AI count
 *
 * Arguments:
 * 0: location you want the units to spawn <ARRAY>
 * 1: class name of the vehicle you want to spawn <STRING>
 * 2: side of the group you want spawned <SIDE>
 *
 * Return Value:
 * The created group or grpNull if the group couldn't be created <GROUP>
 *
 * Examples:
 * [GVAR(vicSpawnLocation), _vehicleClass, _side] call potato_zeusHC_fnc_spawnAVicSpawnLocal
 * [getPos player, "B_MBT_01_cannon_F", west] call potato_zeusHC_fnc_spawnAVicSpawnLocal
 *
 * Public: Yes
 */

// NO_SIDE -1, EAST 0, WEST 1, RESISTANCE 2, CIVILIAN 3, NEUTRAL 4, ENEMY 5, FRIENDLY 6, LOGIC 7
#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_location","_vehicleToAdd","_side"];

private _simulation = getText(configFile >> "CfgVehicles" >> _vehicleToAdd >> "simulation");
private _vehicle = switch (tolower _simulation) do {
    case "airplanex";
    case "helicopterrtd";
    case "helicopterx": {
        //Make sure aircraft start at a reasonable height.
        _location set [2, (_location select 2) + 100];
        createVehicle [_vehicleToAdd, _location, [], 0, "FLY"]
    };
    default {
        _vehicleToAdd createVehicle _location
    };
};

[_vehicle] call EFUNC(core,addToCurator);

// only dismount via scripting/zeus
_vehicle setUnloadInCombat [false, false];

//Set a good velocity in the correct direction.
if (_simulation == "airplanex") then { _vehicle setVelocity [100, 100, 0]; };

private _crewType = if (isText (configFile >> "CfgVehicles" >> _vehicleToAdd >> "crew")) then {
    getText (configFile >> "CfgVehicles" >> _vehicleToAdd >> "crew")
} else {
    switch (_side) do {
        case (west): { "potato_w_vicc" };
        case (east): { "potato_e_crew" };
        case (resistance): { "potato_i_vicc" };
        default { "C_man_w_worker_F" };
    }
};

[_side, _vehicle, _crewType, true] call FUNC(createCrew);

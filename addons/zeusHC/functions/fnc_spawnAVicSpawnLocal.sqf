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

//Set a good velocity in the correct direction.
if (_simulation == "airplanex") then { _vehicle setVelocity [100, 100, 0]; };

if ([_side, count (fullCrew [_vehicle, "", true])] call EFUNC(common,canCreateGroup)) then {
    private _group = createGroup _side;

    //Spawn the crew and add the vehicle to the group.
    createVehicleCrew _vehicle;
    (crew _vehicle) joinSilent _group;
    _group addVehicle _vehicle;
    _group selectLeader (commander _vehicle);
    _group
} else {
    deleteVehicle _vehicle;
    grpNull
};

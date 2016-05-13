/*
 * Author: AACO
 * Function called on the HC/Server to spawn reinforcements with the given
 * configuration
 *
 * Arguments:
 * 0: vehicle pool <ARRAY>
 * 1: vehicle pool index <NUMBER>
 * 2: position to spawn reinforcement <ARRAY>
 * 3: side of the reinforcements <SIDE>
 * 4: placed LZ logic object <OBJECT>
 * 5: LZ size <NUMBER>
 * 6: vehicle behavior (index) <NUMBER>
 * 7: unit behavior (index) <NUMBER>
 * 8: All RPs <ARRAY>
 * 9: Selected RP type (index) <NUMBER>
 * 10: RP size <NUMBER>
 *
 * Example:
 * [
 *         _pool,
 *         _vehiclePoolIndex,
 *         _spawnPosition,
 *         _side,
 *         _lz,
 *         _lzSize,
 *         _dialogVehicleBehaviour,
 *         _dialogUnitBehaviour,
 *         _allRps,
 *         _dialogRpAlgorithm,
 *         _rpSize
 * ] call potato_reinforceToHC_fnc_spawnReinforcements;
 *
 * Public: No
 */

#include "script_component.hpp"
params [
    "_side",
    "_vehicleClassname",
    "_vehicleBehaviorIndex",
    "_lz",
    "_lzSize",
    "_unitPool",
    "_unitBehaviorIndex",
    "_rp",
    "_rpSize",
    "_spawnPosition"
];

TRACE_1("params",_this);

private _vehicleGroup = [_spawnPosition, _vehicleClassname, _side] call EFUNC(zeusHC,spawnAVicSpawnLocal);

if (isNull _vehicleGroup) exitWith {};

private _vehicleDummyWp = _vehicleGroup addWaypoint [position (leader _vehicleGroup), 0];
private _vehicleUnloadWp = _vehicleGroup addWaypoint [position _lz, _lzSize];
_vehicleUnloadWp setWaypointType "TR UNLOAD";

private _vehicle = vehicle (leader _vehicleGroup);

// Make the driver full skill. This makes him less likely to do dumb things when they take contact.
(driver _vehicle) setSkill 1;

if (_lzSize == 150) then {
    // Special settings for helicopters. Otherwise they tend to run away instead of land
    {
        _x allowFleeing 0;
        nil
    } count (crew _vehicle);

    _vehicleUnloadWp setWaypointTimeout [0,0,0]; // Take off ASAP
} else {
    _vehicleUnloadWp setWaypointTimeout [5,10,20]; // Give the units some time to get away from truck
};

// Generate the waypoints for after the transport drops off the troops.
if (_vehicleBehaviorIndex == 0) then {
    // RTB and despawn.
    private _vehicleReturnWp = _vehicleGroup addWaypoint [_spawnPosition, 0];
    _vehicleReturnWp setWaypointTimeout [2,2,2]; // Let the unit stop before being despawned.
    _vehicleReturnWp setWaypointStatements ["true", "deleteVehicle (vehicle this); {deleteVehicle _x} foreach thisList;"];
};

// Spawn the units and load them into the vehicle
private _maxCargoSpacesToLeaveEmpty = 3;
if ((_vehicle emptyPositions "Cargo") <= 3) then {
    // Vehicles with low cargo space shouldn't leave empty seats, otherwise they often won't have any units at all.
    _maxCargoSpacesToLeaveEmpty = 0;
};

private _rp = nil;

while { (_vehicle emptyPositions "Cargo") > _maxCargoSpacesToLeaveEmpty } do {
    private _squadMembers = selectRandom _unitPool;
    private _freeSpace = _vehicle emptyPositions "Cargo";
    if (_freeSpace < count _squadMembers) then {
        // Trim the squad size so they will fit.
        _squadMembers resize _freeSpace;
    };

    // Spawn the squad members.
    private _infantryGroup = [_side,_spawnPosition,_squadMembers] call EFUNC(zeusHC,createGroup);
    if (isNull _infantryGroup) exitWith {};

    // Set the default behaviour of the squad
    switch (_unitBehaviorIndex) do {
        case 1: { // Relaxed
            _infantryGroup setBehaviour "SAFE";
            _infantryGroup setSpeedMode "LIMITED";
        };
        case 2: { // Cautious
            _infantryGroup setBehaviour "AWARE";
            _infantryGroup setSpeedMode "LIMITED";
        };
        case 3: { // Combat
            _infantryGroup setBehaviour "COMBAT";
            _infantryGroup setSpeedMode "FULL";
        };
    };

    // Choose a RP for the squad to head to once unloaded and set their waypoint.
    if (isNil "_rp") then {
        _infantryGroup addWaypoint [position _lz, _rpSize];
    } else {
        _infantryGroup addWaypoint [position _rp, _rpSize];
    };

    // Load the units into the vehicle.
    {
        _x moveInCargo _vehicle;
        nil
    } count (units _infantryGroup);
};

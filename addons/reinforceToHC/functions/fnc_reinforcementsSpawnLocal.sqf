/*
 * Author: AACO
 * Function called on the HC/Server to spawn reinforcements with the given
 * configuration
 *
 * Arguments:
 * 0: side of the reinforcements <SIDE>
 * 1: classname of the vehicle to spawn <STRING>
 * 2: vehicle behavior (index) <NUMBER>
 * 3: placed LZ logic object <OBJECT>
 * 4: LZ size <NUMBER>
 * 5: Pool of units to use as reinforcments<ARRAY>
 * 6: unit behavior (index) <NUMBER>
 * 7: placed PZ logic object (can be nil) <OBJECT>
 * 8: RP size <NUMBER>
 * 9: position to spawn reinforcement <ARRAY>
 *
 * Example:
 * [
 *         _side,
 *         _vehicleClassname,
 *         _vehicleBehaviorIndex,
 *         _lz,
 *         _lzSize,
 *         _unitPool,
 *         _unitBehaviorIndex,
 *         _rp,
 *         _rpSize,
 *         _spawnPosition
 * ] call potato_reinforceToHC_fnc_reinforcementsSpawnLocal;
 *
 * Public: No
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

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

private _vehicleGroup = [_spawnPosition, _vehicleClassname, _side] call EFUNC(zeusHC,spawnAVicSpawnLocal);

if (isNull _vehicleGroup) exitWith {};

private _vehicleDummyWp = _vehicleGroup addWaypoint [position (leader _vehicleGroup), 0];
private _vehicleUnloadWp = _vehicleGroup addWaypoint [position _lz, _lzSize];
_vehicleUnloadWp setWaypointType "TR UNLOAD";

private _vehicle = vehicle (leader _vehicleGroup);

// Make the driver full skill. This makes him less likely to do dumb things when they take contact.
(driver _vehicle) setSkill 1;

{
    _x allowFleeing 0;
    _x setVariable ["potato_aiFrameworks_vcom_disabledUnit", true];
    nil
} count (crew _vehicle);

if (_lzSize == 150) then {
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

/*
 * Author: AACO
 * Function called on the HC/Server to spawn reinforcements with the given
 * configuration
 *
 * Arguments:
 * 0: side of the reinforcements <SIDE>
 * 1: classname of the cre to spawn <STRING>
 * 2: classname of the vehicle to spawn <STRING>
 * 3: vehicle behavior (index) <NUMBER>
 * 4: placed LZ logic object <OBJECT>
 * 5: LZ size <NUMBER>
 * 6: Pool of units to use as reinforcments<ARRAY>
 * 7: unit behavior (index) <NUMBER>
 * 8: placed PZ logic object (can be nil) <OBJECT>
 * 9: RP size <NUMBER>
 * 10: position to spawn reinforcement <ARRAY>
 *
 * Example:
 * [
 *         _side,
 *         _crewClass,
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

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    "_side",
    "_crewClass",
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

private _vehicle = createVehicle [_vehicleClassname, _spawnPosition, [], 0, ["NONE", "FLY"] select (_vehicleClassname isKindOf "AIR")];
_vehicle setVariable ["F_Gear", "Empty", true]; //Clear gear on these [BWMF]
_vehicle setUnloadInCombat [false, false]; // only dismount via scripting/zeus
private _vehicleGroup = [_side, _vehicle, _crewClass, true] call EFUNC(zeusHC,createCrew);

if (isNull _vehicleGroup) exitWith {};

private _vehicleDummyWp = _vehicleGroup addWaypoint [position (leader _vehicleGroup), 0];
private _vehicleUnloadWp = _vehicleGroup addWaypoint [position _lz, _lzSize];
_vehicleUnloadWp setWaypointType "TR UNLOAD";

// Make the driver full skill. This makes him less likely to do dumb things when they take contact.
(driver _vehicle) setSkill 1;

{
    _x allowFleeing 0;
} forEach (crew _vehicle);

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
    private _infantryGroup = [_side,[0,0,0],_squadMembers,true] call EFUNC(zeusHC,createGroup);
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
    } forEach (units _infantryGroup);
    sleep 1;
};

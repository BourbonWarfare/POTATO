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
    "_pool",
    "_vehiclePoolIndex",
    "_spawnPosition",
    "_side",
    "_lz",
    "_lzSize",
    "_dialogVehicleBehaviour",
    "_dialogUnitBehaviour",
    "_allRps",
    "_dialogRpAlgorithm",
    "_rpSize"
];

TRACE_1("params",_this);

private _vehicleType = _pool selectRandom _vehiclePoolIndex;
private _vehicleGroup = [[_spawnPosition, _vehicleType, _side] EFUNC(zeusHC,spawnAVicSpawnLocal);

if (isNull _vehicleGroup) exitWith {};

private _vehicleDummyWp = _vehicleGroup addWaypoint [position (leader _vehicleGroup), 0];
private _vehicleUnloadWp = _vehicleGroup addWaypoint [position _lz, _lzSize];
_vehicleUnloadWp setWaypointType "TR UNLOAD";

// Make the driver full skill. This makes him less likely to do dumb things
// when they take contact.
(driver (vehicle (leader _vehicleGroup))) setSkill 1;

if (_vehiclePoolIndex == UNARMED_HELO_UNIT_POOL_INDEX || _vehiclePoolIndex == ARMED_HELO_UNIT_POOL_INDEX) then {
    // Special settings for helicopters. Otherwise they tend to run away instead of land
    // if the LZ is hot.
    {
        _x allowFleeing 0; // Especially for helos... They're very cowardly.
        nil
    } count (crew (vehicle (leader _vehicleGroup)));
    _vehicleUnloadWp setWaypointTimeout [0,0,0];
} else {
    _vehicleUnloadWp setWaypointTimeout [5,10,20]; // Give the units some time to get away from truck
};

// Generate the waypoints for after the transport drops off the troops.
if (_dialogVehicleBehaviour == 0) then {
    // RTB and despawn.
    private _vehicleReturnWp = _vehicleGroup addWaypoint [_spawnPosition, 0];
    _vehicleReturnWp setWaypointTimeout [2,2,2]; // Let the unit stop before being despawned.
    _vehicleReturnWp setWaypointStatements ["true", "deleteVehicle (vehicle this); {deleteVehicle _x} foreach thisList;"];
};

// Spawn the units and load them into the vehicle
private _vehicle = vehicle (leader _vehicleGroup);
private _maxCargoSpacesToLeaveEmpty = 3;
if ((_vehicle emptyPositions "Cargo") <= 3) then {
    // Vehicles with low cargo space shouldn't leave empty seats, otherwise they often won't have any units at all.
    _maxCargoSpacesToLeaveEmpty = 0;
};

private _rp = nil;

if (count _allRps > 0) then {
    // Choose the RP based on the algorithm the user selected
    _rp = switch (_dialogRpAlgorithm) do {
        case 0: { // Random
            _allRps selectRandom
        };
        case 1: { // Nearest
            [position _lz, _allRps] call Ares_fnc_GetNearest
        };
        case 2: { // Furthest
            [position _lz, _allRps] call Ares_fnc_GetFarthest
        };
        case 3: { // Least Used
            private _leastUsed = _allRps selectRandom; // Choose randomly to begin with.
            {
                if (_x getVariable ["Ares_Rp_Count", 0] < _rp getVariable ["Ares_Rp_Count", 0]) then {
                    _leastUsed = _x;
                };
                nil
            } count _allRps;
            _leastUsed
        };
        default {
            _allRps select (_dialogRpAlgorithm - FIRST_SPECIFIC_LZ_OR_RP_OPTION_INDEX)
        };
    };

    // Now that we've chosen an RP, increment the count for it.
    _rp setVariable ["Ares_Rp_Count", (_rp getVariable ["Ares_Rp_Count", 0]) + 1];
    private _infantryRpWp = _infantryGroup addWaypoint [position _rp, _rpSize];
};

while { (_vehicle emptyPositions "Cargo") > _maxCargoSpacesToLeaveEmpty } do {
    private _squadMembers = _pool selectRandom INFANTRY_UNIT_POOL_INDEX;
    private _freeSpace = (vehicle (leader _vehicleGroup)) emptyPositions "Cargo";
    if (_freeSpace < count _squadMembers) then {
        // Trim the squad size so they will fit.
        _squadMembers resize _freeSpace;
    };

    // Spawn the squad members.
    private _infantryGroup = [_side,_spawnPosition,_squadMembers] call EFUNC(zeusHC,createGroup);
    if (isNull _infantryGroup) exitWith {};

    // Set the default behaviour of the squad
    switch (_dialogUnitBehaviour) do {
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
            _infantryGroup setSpeedMode "NORMAL";
        };
    };

    // Choose a RP for the squad to head to once unloaded and set their waypoint.
    if (isNil "_rp") then {
        private _infantryMoveOnWp = _infantryGroup addWaypoint [position _lz, _rpSize];
    } else {
        private _infantryRpWp = _infantryGroup addWaypoint [position _rp, _rpSize];
    };

    // Load the units into the vehicle.
    {
        _x moveInCargo (vehicle (leader _vehicleGroup));
        nil
    } count (units _infantryGroup);
};

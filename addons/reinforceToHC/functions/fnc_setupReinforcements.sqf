#include "script_component.hpp"

params["_logic"];

[format["Inner logic running - %1", _logic]], call Ares_fnc_LogMessage;

if (!local _logic) exitWith { false };

// HACK - Some modules seem to fire twice. This way we don't get a race condition where they
// are both executing their code. Assume the REAL module logic will cleanup the module if
// necessary.
if (_logic getVariable ["ares_hasRunModuleLogicAlready", false]) exitWith { false };
_logic setVariable ["ares_hasRunModuleLogicAlready", true];

if (isNil "Ares_Reinforcement_Unit_Pools"
  || typeName Ares_Reinforcement_Unit_Pools != typeName []
  || count Ares_Reinforcement_Unit_Pools == 0) exitWith {
  [objNull, "Unable to load unit pools. Is your 'Ares_Reinforcement_Unit_Pools.sqf' file corrupt?"] call bis_fnc_showCuratorFeedbackMessage;
  true
};

private _allUnitPools = if (isNil "Ares_Reinforcement_Mission_Unit_Pools") then { Ares_Reinforcement_Unit_Pools } else {Ares_Reinforcement_Unit_Pools + Ares_Reinforcement_Mission_Unit_Pools };

private _allLzsUnsorted = allMissionObjects "Ares_Module_Reinforcements_Create_Lz";
if (count _allLzsUnsorted == 0) exitWith {
  [objNull, "You must have at least one LZ for the transport to head to."] call bis_fnc_showCuratorFeedbackMessage;
  true
};
private _allLzs = [_allLzsUnsorted, [], { _x getVariable ["SortOrder", 0]; }, "ASCEND"] call BIS_fnc_sortBy;

private _allRpsUnsorted = allMissionObjects "Ares_Module_Reinforcements_Create_Rp";
private _allRps = [_allRpsUnsorted, [], { _x getVariable ["SortOrder", 0]; }, "ASCEND"] call BIS_fnc_sortBy;

// Generate list of pool names to let user choose from
private _poolNames = [];
private _validPools = [];
{
  if ((_x select ADDON_CLASS_INDEX) == "" || isClass(configFile >> "CfgPatches" >> (_x select ADDON_CLASS_INDEX))) then {
    _poolNames pushBack (_x select DISPLAY_NAME_INDEX);
    _validPools pushBack _x;
  };
  nil
} count _allUnitPools;

private _lzOptions = ["Random", "Nearest", "Farthest", "Least Used"];
{
  _lzOptions pushBack (name _x);
  nil
} count _allLzs;

private _rpOptions = ["Random", "Nearest", "Farthest", "Least Used"];
{
  _rpOptions pushBack (name _x);
  nil
} count _allRps;

// Show the user the dialog
private _dialogResult = ["Create Reinforcements",
  [
    ["Side", _poolNames, 0],
    ["Vehicle Type", ["Unarmed Light Vehicles + Scouts", "Armed Light Vehicles", "Dedicated Troop Trucks", "APC's & Heavy Troop Transports", "Unarmed Aircraft", "Light Armed Aircraft", "Unarmed Boats", "Armed Boats"]],
    ["Vehicle Behaviour After Dropoff", ["RTB and Despawn", "Stay at LZ"]],
    ["Vehicle Landing Zone", _lzOptions],
    ["Unit Rally Point", _rpOptions],
    ["Unit Behaviour", ["Default", "Relaxed", "Cautious", "Combat"]]
  ]
] call Ares_fnc_ShowChooseDialog;

if (count _dialogResult == 0) exitWith {
  true
};

// Get the data from the dialog to use when choosing what units to spawn
private _dialogPool =             _dialogResult select 0;
private _dialogVehicleClass =     _dialogResult select 1;
private _dialogVehicleBehaviour = _dialogResult select 2;
private _dialogLzAlgorithm =      _dialogResult select 3;
private _dialogRpAlgorithm =      _dialogResult select 4;
private _dialogUnitBehaviour =    _dialogResult select 5;
private _lzSize = 20;  // TODO make this a dialog parameter?
private _rpSize = 20;  // TODO make this a dialog parameters?
private _spawnPosition = position _logic;

if (not isNil "Ares_CuratorObjectPlaces_LastPlacedObjectPosition") then {
  _spawnPosition = Ares_CuratorObjectPlaces_LastPlacedObjectPosition;
};

// Lz's for helicopters get more randomness because they tend to crash into eachother.
if (_dialogVehicleClass == UNARMED_HELO_UNIT_POOL_INDEX || _dialogVehicleClass == ARMED_HELO_UNIT_POOL_INDEX) then {
  _lzSize = 150;
};

[format ["Dialog results: Pool=%1, VehicleType=%2, Behaviour=%3, LzAlgorithm=%4, RpAlgorithm=%5", _dialogPool, _dialogVehicleClass, _dialogVehicleBehaviour, _dialogLzAlgorithm, _dialogRpAlgorithm]] call Ares_fnc_LogMessage;

// Choose the LZ based on what the user indicated
private _lz = switch (_dialogLzAlgorithm) do {
  case 0: { // Random
    _allLzs call BIS_fnc_selectRandom
  };
  case 1: { // Nearest
    [_spawnPosition, _allLzs] call Ares_fnc_GetNearest
  };
  case 2: { // Furthest
    [_spawnPosition, _allLzs] call Ares_fnc_GetFarthest
  };
  case 3: { // Least used
    private _leastUsed = _allLzs call BIS_fnc_selectRandom; // Choose randomly to start.
    {
      if (_x getVariable ["Ares_Lz_Count", 0] < _lz getVariable ["Ares_Lz_Count", 0]) then {
        _leastUsed = _x;
      };
      nil
    } count _allLzs;
    _leastUsed
  };
  default { // Specific LZ.
    _allLzs select (_dialogLzAlgorithm - FIRST_SPECIFIC_LZ_OR_RP_OPTION_INDEX)
  };
};

// Now that we've chosen an LZ, increment the count for it.
_lz setVariable ["Ares_Lz_Count", (_lz getVariable ["Ares_Lz_Count", 0]) + 1];

// Get the unit pool and the side it's associated with
private _pool = _validPools select _dialogPool;
private _side = _pool select SIDE_INDEX;

if (count (_pool select INFANTRY_UNIT_POOL_INDEX) == 0) exitWith {
  [objNull, "No infantry squads defined for side."] call bis_fnc_showCuratorFeedbackMessage;
  true
};

// Spawn a vehicle, send it to the LZ and have it unload the troops before returning home and
// deleting itself.
private _vehiclePoolIndex = (_dialogVehicleClass + VEHICLE_POOL_START_INDEX);

if (count (_pool select _vehiclePoolIndex) == 0) exitWith {
  [objNull, "Vehicle pool had no vehicles defined for this faction."] call bis_fnc_showCuratorFeedbackMessage;
  true
};

//spawn on remote machine
[
  _pool,
  _vehiclePoolIndex,
  _spawnPosition,
  _side,
  _lz,
  _lzSize,
  _dialogUnitBehaviour,
  _allRps,
  _dialogRpAlgorithm
] remoteExecCall [QFUNC(spawnReinforcements), [] call FUNC(getSpawnMachineId)];

if (count _allRps > 0) then {
  [objNull, "Transport dispatched to LZ. Squad will head to RP."] call bis_fnc_showCuratorFeedbackMessage;
} else {
  [objNull, "Transport dispatched to LZ. Squad will stay at LZ."] call bis_fnc_showCuratorFeedbackMessage;
};

true
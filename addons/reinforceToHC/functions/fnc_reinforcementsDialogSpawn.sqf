/*
 * Author: AACO
 * Function called by the UI spawn the reinforcments with the given configuration
 * Should only be called from UI events
 *
 * Example:
 * [] call potato_reinforceToHC_fnc_reinforcementsDialogSpawn;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// Get values from UI
private _factionIndex = lbCurSel REINFORCEMENT_FACTIONS_IDC;
private _selectedPool = GVAR(validPools) select _factionIndex;

private _vehicleTypeIndex = lbCurSel REINFORCEMENT_TYPE_IDC;
private _vehiclePool = _selectedPool select (_vehicleTypeIndex + VEHICLE_POOL_START_INDEX);
private _vehicleIndex = lbCurSel REINFORCEMENT_VEHICLE_IDC;
private _vehicleBehaviorIndex = lbCurSel REINFORCEMENT_VEHICLE_BEHAVIOR_IDC;
private _vehicleLZIndex = lbCurSel REINFORCEMENT_VEHICLE_LZ_IDC;

private _unitRPIndex = lbCurSel REINFORCEMENT_UNIT_RP_IDC;
private _unitBehaviorIndex = lbCurSel REINFORCEMENT_UNIT_BEHAVIOR_IDC;
private _unitPool = _selectedPool select INFANTRY_UNIT_POOL_INDEX;

private _side = _selectedPool select SIDE_INDEX;

// Validate pools
if (!(_selectedPool isEqualType []) || count _selectedPool < 1) exitWith {
    ["Unable to spawn reinforcements. Nonexistant/empty pool"] call EFUNC(zeusHC,sendCuratorHint);
};

if (!(_vehiclePool isEqualType []) || count _vehiclePool < 1) exitWith {
    ["Unable to spawn reinforcements. Nonexistant/empty vehicle pool"] call EFUNC(zeusHC,sendCuratorHint);
};

if (!(_unitPool isEqualType []) || count _unitPool < 1) exitWith {
    ["Unable to spawn reinforcements. Nonexistant/empty unit pool"] call EFUNC(zeusHC,sendCuratorHint);
};

// get vehicle class name
private _vehicleClassname = if (_vehicleIndex < 1) then {
    selectRandom _vehiclePool
} else {
    _vehiclePool select (_vehicleIndex - 1)
};

// setup default LZ/RP sizes
private _lzSize = 20;
private _rpSize = 20;

// give helicopters bigger LZs to (hopefully) avoid crashes
if (_vehicleTypeIndex == UNARMED_HELO_UNIT_POOL_INDEX || _vehicleTypeIndex == ARMED_HELO_UNIT_POOL_INDEX) then {
    _lzSize = 150;
};

private _lz = [GVAR(allLzs), _vehicleLZIndex, "Ares_Lz_Count", GVAR(reinforcementLocation)] call FUNC(reinforcementsSelectWaypoint);

private _rp = nil;

if (count GVAR(allRps) > 0) then {
    _rp = [GVAR(allRps), _unitRPIndex, "Ares_Rp_Count", getPos _lz] call FUNC(reinforcementsSelectWaypoint);
};

// save current indexes for next run
GVAR(lastFactionIndex) = _factionIndex;
GVAR(lastTypeIndex) = _vehicleTypeIndex;
GVAR(lastVehicleIndex) = _vehicleIndex;
GVAR(lastVehicleBehaviorIndex) = _vehicleBehaviorIndex;
GVAR(lastVehicleLZIndex) = _vehicleLZIndex;
GVAR(lastUnitRPIndex) = _unitRPIndex;
GVAR(lastUnitBehaviorIndex) = _unitBehaviorIndex;

// send to HC
[
    [
        _side,
        _vehicleClassname,
        _vehicleBehaviorIndex,
        _lz,
        _lzSize,
        _unitPool,
        _unitBehaviorIndex,
        _rp,
        _rpSize,
        GVAR(reinforcementLocation)
    ],
    QFUNC(reinforcementsSpawnLocal),
    true
] call EFUNC(zeusHC,hcPassthrough);

if (isNil "_rp") then {
    [objNull, "Transport dispatched to LZ. Squad will stay at LZ."] call bis_fnc_showCuratorFeedbackMessage;
} else {
    [objNull, "Transport dispatched to LZ. Squad will head to RP."] call bis_fnc_showCuratorFeedbackMessage;
};

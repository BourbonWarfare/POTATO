#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* Spawns a given number of vehicles in a radius around a center point and
* optionally within a marker. The number of vehicles is set by _fillCount,
* and as _fill intensity increases, the vehicles become more threatening.
*
* Arguments:
* _posATL - center of position of region to garrison (ARRAY).
* _radius - radius of area to garrison (SCALAR, default 50 m).
* _marker - Marker that sets bounds for buildings to be garrisoned (STRING, default "").
* _fillCount - The number of vehicles to spawn (SCALAR, default 3).
* _fillIntensity - Force composition strength, i.e. technicals or APCs, or IFVs (SCALAR, default 0.4).
* _sideVehicles - Side of the garrison units (SIDE, east).
*
* Return:
* None
*
* Example:
* [getPosATL player, 100, "zone_0", 3, 0.6, east] call bw_fnc_spawnZoneVehicles;
*//***************************************************************************/
params [
    ["_posATL", [0, 0, 0], [[]], [3]],
    ["_radius", 50, [50]],
    ["_marker", "", [""]],
    ["_fillCount", 3, [3]],
    ["_fillIntensity", 0.4, [0.4]],
    ["_sideVehicles", east, [east]]
];

if (_posATL isEqualTo [0, 0, 0]) exitWith {};

private _roads = _posATL nearRoads _radius;
if (_marker != "") then {
    _roads = _roads select {_x inArea _marker};
};
[_roads, true] call cba_fnc_shuffle;

private _sideConfig = switch (_sideVehicles) do {
    case east: {"potato_e"};
    case west: {"potato_w"};
    case resistance: {"potato_i"};
    case civilian: {"CIV_F"};
    default {"potato_e"};
};
private _transportTypes = getArray (missionConfigFile >> "CfgLoadouts" >> _sideConfig >> "transportVehiclePool");
private _softArmedTypes = getArray (missionConfigFile >> "CfgLoadouts" >> _sideConfig >> "armedSoftVehiclePool");
private _armoredTypes = getArray (missionConfigFile >> "CfgLoadouts" >> _sideConfig >> "armoredVehiclePool");
private _tankTypes = getArray (missionConfigFile >> "CfgLoadouts" >> _sideConfig >> "tankVehiclePool");

if (_transportTypes isEqualTo [] &&
    _softArmedTypes isEqualTo [] &&
    _softArmedTypes isEqualTo [] &&
    _armoredTypes isEqualTo []) exitWith {
    diag_log formatText ["[SEED][VEHICLES] Faction %1 not configured for vehicle spawns", _sideConfig];
};
if (_transportTypes isNotEqualTo [] && _softArmedTypes isEqualTo []) then {
    _softArmedTypes = _transportTypes;
};
if (_softArmedTypes isNotEqualTo [] && _armoredTypes isEqualTo []) then {
    _armoredTypes = _softArmedTypes;
};
if (_armoredTypes isNotEqualTo [] && _tankTypes isEqualTo []) then {
    _tankTypes = _armoredTypes;
};

if (_transportTypes isEqualTo []) then {
    _transportTypes = [""];
};
if (_softArmedTypes isEqualTo []) then {
    _softArmedTypes = [""];
};
if (_armoredTypes isEqualTo []) then {
    _armoredTypes = [""];
};
if (_tankTypes isEqualTo []) then {
    _tankTypes = [""];
};

private _vehicleSplit = [
    round linearConversion [0, 0.75, _fillIntensity, _fillCount, 0, true],
    0,
    round linearConversion [0.4, 0.75, _fillIntensity, 0, _fillCount * 2 / 3, true],
    round linearConversion [0.6, 1, _fillIntensity, 0, _fillCount / 3, true]
];

_vehicleSplit set [1, _fillCount - _vehicleSplit#0 - _vehicleSplit#2 - _vehicleSplit#3];

for "_i" from 1 to _fillCount do {
    private _road = selectRandom _roads;
    private _vehicleType = switch (true) do {
        case (_vehicleSplit#3 > 0): {
            _vehicleSplit set [3, _vehicleSplit#3 - 1];
            selectRandom _tankTypes
        };
        case (_vehicleSplit#2 > 0): {
            _vehicleSplit set [2, _vehicleSplit#2 - 1];
            selectRandom _armoredTypes
        };
        case (_vehicleSplit#1 > 0): {
            _vehicleSplit set [1, _vehicleSplit#1 - 1];
            selectRandom _softArmedTypes
        };
        default {
            selectRandom _transportTypes
        };
    };
    if (_vehicleType == "") then {continue};
    private _posATL = getPosATL _road vectorAdd ([1 - random 2, 1 - random 2, 0] apply {_x * 4});
    private _vic = createVehicle [_vehicleType, _posATL, [], 0, "NONE"];
    (getRoadInfo _road) params ["", "", "", "", "", "", "_begPos", "_endPos"];
    _vic setDir (-10 + random 20 + (_endPos getDir _begPos) * (selectRandom [-1, 1]));
    if (_vehicleType in _softArmedTypes) then {
        [
            [_sideVehicles, _vic, _sideConfig + "_rifleman", true],
            QPFUNC(zeusHC,createCrew),
            true
        ] call PFUNC(zeusHC,hcPassthrough);
    } else {
        if !(_vehicleType in _transportTypes) then {
            [
                [_sideVehicles, _vic, _sideConfig + "_vicc", true],
                QPFUNC(zeusHC,createCrew),
                true
            ] call PFUNC(zeusHC,hcPassthrough);
        };
    };
};


#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This handles calling reinforcements when a zone hits 60% of it's pop.
*
* Arguments:
* none
*
* Return:
* none
*
* Example:
* [] call bw_fnc_handleSectorReinforce;
*//***************************************************************************/
if (GVAR(reinforceHashMap) isEqualTo createHashMap) exitWith {};

private _entriesToRemove = [];

private _aircraft = vehicles select {side _x == west && {alive driver _x && _x isKindOf "Air"}};
{
    private _zone = _x;
    _y params ["_squadCount", "_armedVehicles", "_side", "_startingUnits", ["_lastAirTime", -500]];
    private _countZone = count (units _side select {alive _x && _x inArea _zone});
    if (_countZone < (0.6 + random 0.2) * _startingUnits && _countZone > 0) then {
        _entriesToRemove pushBack _zone;
        [_zone, 10, _squadCount, _side, _armedVehicles] call FUNC(spawnReinforcements);
    };
    // once every 4-10 minutes create an aircraft to challenge air superiority
    private _zonePos = getMarkerPos _zone;
    if (_lastAirTime + 240 + random [0, 60, 360] < time &&
        {[] isNotEqualTo (_aircraft select {_x distance2D _zonePos < 3000})} &&
        {random 1 < 0.25}) then {
        private _sideConfig = switch (_side) do {
            case east: {"potato_e"};
            case west: {"potato_w"};
            case resistance: {"potato_i"};
            case civilian: {"CIV_F"};
            default {"potato_e"};
        };
        private _pos = _zonePos getPos [4500, random 360];
        private _aircraftType =  getArray (missionConfigFile >> "CfgLoadouts" >> _sideConfig >> (selectRandomWeighted ["heliVehiclePool",0.8,"planeVehiclePool",0.2]));
        if (_aircraftType isEqualTo []) exitWith {};
        _pos set [2, 100];
        [[_zonePos, selectRandom _aircraftType, _pos, _side, true], QFUNC(spawnAircraft)] call PFUNC(zeusHC,hcPassthrough);
        _y set [4, time];
    };
} forEach GVAR(reinforceHashMap);

{
    private _zone = _x;
    private _zoneParams = GVAR(reinforceHashMap) getOrDefault [_zone, [0, false, east, 0]];
    if ( units (_zoneParams#2) select {alive _x && _x inArea _zone} isNotEqualTo []) then {
        [{
            params ["_zone", "_squadsToSpawn", "_armedVehicles", "_side"];
            private _startingUnits = count (units _side select {alive _x && _x inArea _zone});
            if (_startingUnits > 20) then {
                [_zone, _squadsToSpawn, _armedVehicles, _side, _startingUnits] call FUNC(addSectorReinforce);
            };
        }, [_zone] + _zoneParams, 900 + random 300] call CBA_fnc_waitAndExecute;
    };
    GVAR(reinforceHashMap) deleteAt _x;
} forEach _entriesToRemove;

if (GVAR(reinforceHashMap) isNotEqualTo createHashMap) then {
    [{[] call FUNC(handleSectorReinforce)}, 0, 30 + random 15] call CBA_fnc_waitAndExecute;
};

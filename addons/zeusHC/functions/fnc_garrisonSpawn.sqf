/*
 * Author: AACO
 * Function to garrison an area with the given parameters
 *
 * Arguments:
 * 0: Faction to spawn units as <STRING>
 * 1: Maximum number of units to spawn <NUMBER>
 * 2: Chance a building will be occupied <NUMBER>
 * 3: Radius to search for buildings <NUMBER>
 * 4: Minimum number of soldiers per house <NUMBER>
 * 5: Maximum number of soldiers per house <NUMBER>
 * 6: Location to search <ARRAY>
 *
 * Example:
 * [
 *     "blu_f",
 *     60,
 *     70,
 *     100,
 *     1,
 *     3,
 *     getPos player
 * ] call potato_zeusHC_fnc_garrisonSpawn
 *
 * Public: Yes
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_faction","_unitLimit","_occupyChance","_occupyRadius","_occupyMinNumber","_occupyMaxNumber",["_garrisonLocation",[0,0,0],[[]],3]];

// validate input data
_unitLimit = [_unitLimit, 1, [] call FUNC(garrisonUnitLimit)] call EFUNC(core,ensureRange);
_occupyChance = [_occupyChance, 0, 100] call EFUNC(core,ensureRange);
_occupyRadius = [_occupyRadius, 0, 2000] call EFUNC(core,ensureRange);
([_occupyMinNumber, _occupyMaxNumber, 1, 20] call EFUNC(core,ensureBoundedMinMax)) params ["_occupyMin","_occupyMax"];


private _side = switch (getNumber (configfile >> "CfgFactionClasses" >> _faction >> "side")) do { case 0: {east}; case 1: {west}; case 2: {resistance}; default {civilian}; };

// handle EDEN placed module
if (isNil QGVAR(garrisonCache)) then {
    [] call FUNC(garrisonCache);
};

private _units = (GVAR(garrisonCache) select 1) select ((GVAR(garrisonCache) select 0) find _faction);

private _buildingPositions = [];
{
    if ((floor random 100) <= _occupyChance) then {
        private _positions = (_x buildingPos -1);
        if ((count _positions) >= _occupyMinNumber) then {
            _buildingPositions pushBack _positions;
        };
    };
    nil
} count (nearestObjects [_garrisonLocation, ["house"], _occupyRadius]);

TRACE_3("",_garrisonLocation,_occupyChance,count _buildingPositions);

if (count _buildingPositions < 1) exitWith {
    ["Did not find any buildings to garrison (is your occupy chance to low, or min occupy units to high?)"] call FUNC(sendCuratorHint);
};

diag_log text format ["[POTATO] Garrison Running With Max [%1]", _unitLimit];

[_buildingPositions, _side, _units, _unitLimit, _occupyMin, _occupyMax] spawn {
    params ["_buildingPositions","_side","_units","_unitLimit","_occupyMin","_occupyMax"];
    TRACE_6("params",count _buildingPositions,_side,_units,_unitLimit,_occupyMin,_occupyMax);

    private _unitsAdded = 0;

    {
        if (({side _x == _side} count allGroups) > GVAR(maxGroupCountPerSide)) exitWith { //Don't loop to close to max group limit of 144
            [
                text format ["Stopping Garrision because of group limit. %1 groups for side %2", {side _x == _side} count allGroups, _side]
            ] call FUNC(sendCuratorHint);
        };

        private _numberOfUnits = [_occupyMin,_occupyMax] call EFUNC(core,getBoundedRandom);
        private _unitsToAdd = [];
        private _unitPositions = [];
        private _index = 0;
        while {_index < _numberOfUnits && _index < (count _x)} do {
            if ((_unitsAdded + _index) >= _unitLimit) exitWith { TRACE_1("Unit limit reached, exiting while loop",_unitLimit); };
            private _position = selectRandom _x;
            _x = _x - [_position];

            _unitsToAdd pushBack (selectRandom _units);
            _unitPositions pushBack _position;
            _index = _index + 1;
        };

        TRACE_2("",_unitsToAdd, _unitPositions);

        if (count _unitsToAdd > 0) then {
            [
                [_unitsToAdd, _unitPositions, _side],
                QFUNC(garrisonLocal)
            ] call FUNC(hcPassthrough);

            _unitsAdded = _unitsAdded + (count _unitsToAdd);
        };

        if (_unitsAdded >= _unitLimit) exitWith { TRACE_1("Unit limit reached, exiting count loop",_unitLimit); };

        sleep GVAR(delayBetweenGroupCreation);
    } forEach _buildingPositions;
};

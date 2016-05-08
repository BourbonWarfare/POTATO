/*
 * Author: AACO
 * Function to garrison an area with the given parameters
 *
 * Arguments:
 * 0: Faction to spawn units as <STRING>
 * 1: Chance a building will be occupied <NUMBER>
 * 2: Radius to search for buildings <NUMBER>
 * 3: Minimum number of soldiers per house <NUMBER>
 * 4: Maximum number of soldiers per house <NUMBER>
 * 5: Location to search <ARRAY>
 *
 * Example:
 * [
 *     "blu_f",
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

params ["_faction","_occupyChance","_occupyRadius","_occupyMinNumber","_occupyMaxNumber",["_garrisonLocation",GVAR(garrisonLocation),[],3]];

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

// get unit limit, look up mission override first
if (isNil QGVAR(garrisonUnitLimit)) then {
    GVAR(garrisonUnitLimit) = if (isNumber (missionConfigFile >> "CfgGarrison" >> "maxUnits")) then {
        getNumber (missionConfigFile >> "CfgGarrison" >> "maxUnits")
    } else {
        getNumber (configFile >> "CfgGarrison" >> "maxUnits")
    };
};

diag_log text format ["[POTATO] Garrison Running With Max [%1]", GVAR(garrisonUnitLimit)];

[_buildingPositions, _side, _units, _occupyMinNumber, _occupyMaxNumber] spawn {
    params ["_buildingPositions","_side","_units","_occupyMinNumber","_occupyMaxNumber"];
    TRACE_5("params",count _buildingPositions,_side,_units,_occupyMinNumber,_occupyMaxNumber);

    private _sleep = if (isNil QGVAR(sleepBetweenSpawns)) then { 0.5 } else { GVAR(sleepBetweenSpawns) };
    private _unitsAdded = 0;

    {
        if (({side _x == _side} count allGroups) > GVAR(maxGroupCountPerSide)) exitWith {//Don't loop to close to max group limit of 144
            [
                text format ["Stopping Garrision because of group limit. %1 groups for side %2", {side _x == _side} count allGroups, _side]
            ] call FUNC(sendCuratorHint);
        };

        private _numberOfUnits = _occupyMinNumber + (floor random (_occupyMaxNumber - _occupyMinNumber + 1));
        private _unitsToAdd = [];
        private _unitPositions  = [];
        private _index = 0;
        while {_index < _numberOfUnits && _index < (count _x)} do {
            if ((_unitsAdded + _index) >= GVAR(garrisonUnitLimit)) exitWith { TRACE_1("Unit limit reached, exiting while loop",GVAR(garrisonUnitLimit)); };
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

        if (_unitsAdded >= GVAR(garrisonUnitLimit)) exitWith { TRACE_1("Unit limit reached, exiting count loop",GVAR(garrisonUnitLimit)); };

        sleep _sleep;
        nil
    } count _buildingPositions;
};

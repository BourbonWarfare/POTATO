#define DEBUG_MODE_FULL
#include "script_component.hpp"

// get unit limit, look up mission override first
if (isNil QGVAR(garrisonUnitLimit)) {
    GVAR(garrisonUnitLimit) = if (isNumber (missionConfigFile >> "CfgGarrison" >> "maxUnits")) then {
        getNumber (missionConfigFile >> "CfgGarrison" >> "maxUnits")
    } else {
        getNumber (configFile >> "CfgGarrison" >> "maxUnits")
    };
};

diag_log text format ["[POTATO] Garrison Running With Max [%1]", GVAR(garrisonUnitLimit)];

_this spawn {
    params ["_buildingPositions","_side","_units","_occupyMinNumber","_occupyMaxNumber"];
    TRACE_5("params",count _buildingPositions,_side,_units,_occupyMinNumber,_occupyMaxNumber);

    private _sleep = if (isNil QGVAR(sleepBetweenSpawns)) then { 0.5 } else { GVAR(sleepBetweenSpawns) };
    private _unitsAdded = 0;

    {
        if (({side _x == _side} count allGroups) > EGVAR(common,maxGroupCountPerSide)) exitWith {//Don't loop to close to max group limit of 144
            diag_log text format ["[POTATO] - Stopping Garrision because of group limit [%1] for side [%2]", {side _x == _side} count allGroups, _side];
        };

        private _numberOfUnits = _occupyMinNumber + (floor random (_occupyMaxNumber - _occupyMinNumber + 1));
        private _unitsToAdd = [];
        private _unitPositions  = [];
        private _index = 0;
        while {_index < _numberOfUnits && _index < (count _x)} do {
            if ((_unitsAdded + _index) > GVAR(garrisonUnitLimit)) exitWith { TRACE_1("Unit limit reached, exiting while loop",GVAR(garrisonUnitLimit)); };
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

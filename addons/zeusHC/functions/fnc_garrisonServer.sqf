#include "script_component.hpp"
TRACE_1("params",_this);

_this spawn {
    params ["_buildingPositions","_side","_units","_occupyMinNumber","_occupyMaxNumber"];

    private _sleep = if (isNil QGVAR(sleepBetweenSpawns)) then { 0.25 } else { GVAR(sleepBetweenSpawns) };
    private _unitsAdded = 0;

    {
        private _numberOfUnits = _occupyMinNumber + (floor random (_occupyMaxNumber - _occupyMinNumber + 1));
        private _unitsToAdd = [];
        private _index = 0;
        while {_index < _numberOfUnits && _index < (count _x)} do {
            if ((_unitsAdded + _index) > GVAR(garrisonUnitLimit)) exitWith { TRACE_1("Unit limit reached, exiting while loop",GVAR(garrisonUnitLimit)); };
            private _position = selectRandom _x;
            _x = _x - [_position];

            _unitsToAdd pushBack [(selectRandom _units), _position];
            _index = _index + 1;
        };

        if (count _unitsToAdd > 0) then {
            [_unitsToAdd, _side] remoteExecCall [QFUNC(garrisonLocal), [] call FUNC(getSpawnMachineId)];
            _unitsAdded = _unitsAdded + (count _unitsToAdd);
        };

        if (_unitsAdded >= GVAR(garrisonUnitLimit)) exitWith { TRACE_1("Unit limit reached, exiting count loop",GVAR(garrisonUnitLimit)); };

        sleep _sleep;
        nil
    } count _buildingPositions;
};

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_buildingPositions","_side","_units","_occupyMinNumber","_occupyMaxNumber"];

{
    private _numberOfUnits = _occupyMinNumber + (floor random (_occupyMaxNumber - _occupyMinNumber));
    private _unitsToAdd = [];
    private _positions = [];

    private _index = 0;

    while {_index < _numberOfUnits} do {
        _unitsToAdd pushBack (selectRandom _units);

        private _position = selectRandom _x;
        _positions pushBack _positions;
        _x = _x - [_position];

        _index = _index + 1;
    };

    [_unitsToAdd, _positions, _side] remoteExecCall [QFUNC(garrisonLocal), [] call FUNC(getSpawnMachineId)];
    nil
} count _buildingPositions;

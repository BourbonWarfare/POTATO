#include "script_component.hpp"
TRACE_1("Params",_this);

_this spawn {
    params ["_unitsToAdd","_unitPositions","_side"];

    private _building = objNull;
    private _buildingGroup = [_side, nil, _unitsToAdd] EFUNC(common,createGroup);

    if ((isNil "_buildingGroup") || {isNull _buildingGroup}) exitWith {
        ERROR("Group Could not be created");
    };

    {
        private _unit = _x;
        private _position = _unitPositions select _forEachIndex;
        _unit setPos _position;

        doStop _unit;

        if (isNull _building) then {
            _building = (nearestObjects [_position, ["house"], 50]) select 0;
        };

        private _inside = [_unit, 0, 0, 25] call FUNC(garrisonIsFacingWall);
        private _directionToBuilding = [_unit, _building] call BIS_fnc_RelativeDirTo;
        private _finalDirection = _directionToBuilding - 180;

        private _facingWall = if (_inside) then {
            _unit setUnitPos "Up";
            [_unit, getDir _unit] call FUNC(garrisonIsFacingWall)
        } else {
            _unit setUnitPos "Middle";
            [_unit, _finalDirection] call FUNC(garrisonIsFacingWall)
        };

        if (_facingWall) then {
            _finalDirection = _directionToBuilding;

            for "_degree" from 0 to 365 step 5 do {
                if !([_unit, _degree] call FUNC(garrisonIsFacingWall)) exitWith {
                    _finalDirection = _degree;
                    _facingWall = false;
                };
            };
        };

        _unit doWatch ([_unit, 20, _finalDirection] call BIS_fnc_relPos);
    } forEach (units _buildingGroup);
};

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

//Lets find the closest building
private _building = nearestBuilding _unit;

if ((_building distance _unit) > VGVAR(maxDistanceToGarrison)) exitWith {};

//Find positions in a house.
private _buildingPositions = _building buildingPos -1;
if (count _buildingPositions < 1) exitWith {};

//Find the units in the group!
private _unitGroup = group _unit;
private _units = units _unitGroup;
private _side = side _unitGroup;

TRACE_5("",_unit,_unitGroup,_units,_side,_buildingPositions);

[_units, _side] spawn VFUNC(regroup);

while {count _units > 0} do {
    private _garrisonPositions = _buildingPositions;

    while {count _garrisonPositions > 0 && {count _units > 0}} do {
        private _garrisonUnit = selectRandom _units;
        [_garrisonUnit] joinSilent (createGroup _side);
        _units = _units - [_garrisonUnit];

        if !(_garrisonUnit getVariable [VQGVAR(garrisoned),false]) then {
            private _garrisonPosition = selectRandom _garrisonPositions;
            _garrisonPositions = _garrisonPositions - [_garrisonPosition];

            _garrisonUnit doMove _garrisonPosition;
            _garrisonUnit setUnitPosWeak "UP";
            _garrisonUnit setVariable [VQGVAR(garrisoned),true];
        };
    };
};

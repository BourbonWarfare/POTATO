#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_unitGroup"];

//Lets find the closest building
private _building = nearestBuilding _unit;

if ((_building distance _unit) > VGVAR(maxDistanceToGarrison) || {_unit getVariable [VQGVAR(garrisoned),false]}) exitWith {};

//Find positions in a house.
private _buildingPositions = _building buildingPos -1;
if (count _buildingPositions < 1) exitWith {};

//Find the units in the group!
private _units = units _unitGroup;

[_units, side _unitGroup] spawn VFUNC(regroup);

while {count _units > 0} do {
    private _garrisonPositions = _buildingPositions;

    while {count _garrisonPositions > 0} do {
        private _garrisonUnit = selectRandom _units;
        _garrisonUnit joinSilent (createGroup (side _unitGroup));
        _units = _units - [_garrisonUnit];

        if !(_garrisonUnit setVariable [VQGVAR(garrisoned),false]) then {
            private _garrisonPosition = selectRandom _garrisonPositions;
            _garrisonPositions = _garrisonPositions - [_garrisonPosition];

            _garrisonUnit doMove _garrisonPosition;
            _garrisonUnit setUnitPosWeak "UP";
            _garrisonUnit setVariable [VQGVAR(garrisoned),true];
        };
    };
};

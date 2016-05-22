#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

//Script will make AI use the proper stances depending on friendlies behind them.
while {!([_unit,VQGVAR(activelyClearing),VGVAR(clearingThreshold)] call VFUNC(pastThreshold))} do {
    private _behindUnit = _unit modelToWorld [0,-1,0.5];
    private _nearObjects = _behindUnit nearObjects ["Man",2];
    if (_unit in _nearObjects) then { _nearObjects = _nearObjects - [_unit] };
    private _nearestUnit = [_nearObjects,_behindUnit] call VFUNC(closestObject);

    if (isNull _nearestUnit) then {
        _unit setUnitPosWeak "UP";
    } else {
        _StanceCompare = stance _NearestUnit;
        switch (stance _nearestUnit) do {
            case ("STAND"): {
                _unit setUnitPosWeak "MIDDLE";
            };
            case ("CROUCH"): {
                _unit setUnitPosWeak "DOWN";
            };
            default {
                _unit setUnitPosWeak "UP";
            };
        }
    };
    sleep 1;
};

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

if (diag_fps <= 15) exitWith {};

if (diag_tickTime - (_unit getVariable [VQGVAR(firedTime),0]) > 10) then {
    _unit setVariable [VQGVAR(firedTime), diag_tickTime, true];

    private _pos = cursorTarget;
    if (isNull _pos) then {
        if (isPlayer _unit) then {
            _pos = screenToWorld [0.5,0.5];
        } else {
            _pos = getPosATL (assignedTarget _unit);
        };
    } else {
        _pos = getPosATL _pos;
    };

    private _closestEnemy = [_unit] call VFUNC(closestEnemy);
    if (isNull _closestEnemy) exitWith {};

    {
        if ((_pos distance _x) < 50) then {
            _x setSuppression 1;
        };
        nil
    } count (units (group _closestEnemy));
};

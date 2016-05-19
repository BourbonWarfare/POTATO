#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _craterList = _unit nearObjects ["#crater",100];

if (count _craterList > 0) then {
    //Check if an enemy is close to the AI or not.
    private _enemy = [_unit] call VFUNC(closestEnemy);
    if !(isNull _enemy) then {
        if (_enemy distance _unit > VGVAR(maxEngagementDistance)) then {
            _craterList = [];
        };
    };
};

_craterList

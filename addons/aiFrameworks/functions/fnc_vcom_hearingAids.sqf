#include "script_component.hpp"
TRACE_1("params",_this);

//Helps the AI recognize people firing from a better distance
params ["_unit"];

if (diag_tickTime - (_unit getVariable [VQGVAR(firedTimeHearing),0]) > 10) then {
    {
        if ((_x distance _unit) <= VGVAR(gunshotDetectionRange) && !(_x getVariable [VQGVAR(shotsFired),false])) then {
            _x setVariable [VQGVAR(shotsFired),true,true];
        };
        nil
    } count [_unit] call VFUNC(enemyUnits);

    _unit setVariable [VQGVAR(firedTimeHearing),diag_tickTime];
};

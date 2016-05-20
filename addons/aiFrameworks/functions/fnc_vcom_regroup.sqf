#include "script_component.hpp"
TRACE_1("params",_this);

params ["_groupUnits", "_side"];

private _wait = true;
while {_wait} do {
    {
        if ((count (waypoints (group _x))) > 1 || {!(alive _x)}) then { _wait = false };
        nil;
    } count _groupUnits;
    sleep 2;
};



private _group = createGroup _side;

{
    [_x] joinSilent _group;

    if (_x == (leader _x)) then { _x setVariable [VQGVAR(flanking),0]; };
    _x setVariable [VQGVAR(loitering),false];
    _x setVariable [VQGVAR(movedRecently),0];

    nil
} count _groupUnits;

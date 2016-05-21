#include "script_component.hpp"
TRACE_1("params",_this);

params ["_groupLeader", "_group"];

if !(VGVAR(loiteringEnabled)) exitWith {};

private _unitArray = units _group;
private _groupSide = side _group;
[_unitArray, side _group] spawn VFUNC(regroup); //This function will automatically regroup soldiers if they get more than 1 waypoint.

{
    //Each AI will need to join their own group. The plan is to make them re-form when combat starts.
    [_x] joinsilent (createGroup _groupSide);

    _x setVariable [VQGVAR(loitering),true];
    _x setVariable [VQGVAR(loiteringAct),0];
    [_x,_unitArray] spawn VFUNC(loiterAction);

    nil;
} count _unitArray;

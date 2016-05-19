#include "script_component.hpp"
TRACE_1("params",_this);

params [_unit];

private _groupLeader = leader _unit;
if (_groupLeader == _unit) then {
    _unit setVariable [VQGVAR(leader),true];
};

private _subLeader = isFormationLeader _unit;
if (_subLeader) then {
    _unit setVariable [VQGVAR(subLeader),true];
};

[_groupLeader,_subLeader]

#include "script_component.hpp"
TRACE_1("params",_this);

params [_unit];

private _groupLeader = leader _unit;
_unit setVariable [VQGVAR(leader),_groupLeader == _unit];

private _subLeader = isFormationLeader _unit;
_unit setVariable [VQGVAR(subLeader),_subLeader];

[_groupLeader,_subLeader]

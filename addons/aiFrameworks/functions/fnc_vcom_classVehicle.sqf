#include "script_component.hpp"
TRACE_1("params",_this);

params ["_name"];

if (_name isEqualType "STRING") then {
    (configFile >> "cfgVehicles" >> _name)
} else {
    (configFile >> EMPTY_DUMMY)
};

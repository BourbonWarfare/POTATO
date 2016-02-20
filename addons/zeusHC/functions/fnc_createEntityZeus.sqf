#include "script_component.hpp"

params ["_logic"];
TRACE_1("params",_logic);

[getPosATL _logic] call FUNC(createEntityServer);

deleteVehicle _logic;

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];
if (isNull _logic) exitWith { TRACE_1("Logic for zeus object is somehow null, exiting"); };

[true] spawn FUNC(transferGroupsToHC);

deleteVehicle _logic;

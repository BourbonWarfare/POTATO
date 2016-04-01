#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];

if (local _logic) then {
    GVAR(buildSpawnLocation) = getPosATL _logic;
    createDialog QGVAR(build_a_group_dialog);
};

deleteVehicle _logic;

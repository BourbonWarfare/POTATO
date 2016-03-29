#include "script_component.hpp"

params ["_logic"];
TRACE_1("params",_logic);

if (local _logic) then {
    GVAR(buildSpawnLocation) = getPosATL _logic;
    createDialog QGVAR(build_a_group_dialog);
};

deleteVehicle _logic;

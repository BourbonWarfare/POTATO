#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];

if (local _logic) then {
    GVAR(vicSpawnLocation) = getPosATL _logic;
    createDialog QGVAR(spawn_a_vic_dialog);
};

deleteVehicle _logic;

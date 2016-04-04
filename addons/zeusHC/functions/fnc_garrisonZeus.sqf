#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];

if (local _logic) then {
    GVAR(garrisonLocation) = getPosATL _logic;
    createDialog QGVAR(garrison_dialog);
};

deleteVehicle _logic;

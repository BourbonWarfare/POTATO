#include "script_component.hpp"

params ["_beaconLogic"];
TRACE_1("module_attackBeacon",_beaconLogic);

if (!isServer) exitWith {};

{
    if (_x != _beaconLogic) then {
        TRACE_1("deleting old beacon",_x);
        deleteVehicle _x;
    };
} forEach (entities QGVAR(attackBeacon));

TRACE_1("attackBeacon ready",_beaconLogic);

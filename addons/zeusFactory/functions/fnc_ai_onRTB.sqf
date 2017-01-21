#include "script_component.hpp"

params ["_leader"];
private _vehicle = vehicle _leader;
TRACE_2("ai_onRTB",_leader,_vehicle);

deleteVehicle _leader;
deleteVehicle _vehicle;

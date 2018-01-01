#include "script_component.hpp"

params ["_leader"];
TRACE_2("ai_onHeliUnload",_leader,vehicle _leader);
if (!local _leader) exitWith { WARNING_1("Waypoint script ran on non-local unit [%1]",_leader); };

private _dummyPad = (vehicle _leader) getVariable [QGVAR(dummyPad), objNull];
TRACE_1("cleaning up dummy helipad",_dummyPad);
deleteVehicle _dummyPad;

#include "script_component.hpp"

params ["_leader"];
private _group = group _leader;
private _vehicle = vehicle _leader;
TRACE_3("ai_onRTB",_leader,_group,_vehicle);
if (!local _leader) exitWith { WARNING_1("Waypoint script ran on non-local unit [%1]",_leader); };

{
    deleteVehicle _x;
} forEach (crew _vehicle);

if ((units _group) isEqualTo []) then {
    deleteGroup _group;
};

deleteVehicle _vehicle;

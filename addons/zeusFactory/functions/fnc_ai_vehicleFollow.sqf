#include "script_component.hpp"

// Note: this will run in scheduled enviroment

params [["_vehicleGroup", grpNull, [grpNull]], ["_position", [0, 0, 0], [[]], 3]];
TRACE_2("ai_vehicleFollow",_vehicleGroup,_position);
if (!local _vehicleGroup) exitWith { WARNING_1("Waypoint script ran on non-local group [%1]",_vehicleGroup); };

private _vehicle = vehicle leader _vehicleGroup;
private _commander = effectiveCommander _vehicle;

private _followGroup = _vehicleGroup getVariable [QGVAR(followGroup), grpNull];

#ifdef DEBUG_MODE_FULL
private _dummy = "Sign_Arrow_Large_Cyan_F" createVehicle (getPos _vehicle);
#endif

while {(alive _vehicle) && {alive _commander} && {(vehicle _commander) == _vehicle} && {!isNull _followGroup}} do {
    private _leaderPos = getPos leader _followGroup;
    if ((_leaderPos distance2d _vehicle) > 50) then {
        TRACE_2("moving",_vehicle,_leaderPos distance2d _vehicle);
        private _angle = (leader _followGroup) getDir _vehicle;
        _commander doMove ((leader _followGroup) getPos [50, _angle]);
        #ifdef DEBUG_MODE_FULL
        _dummy setPos ((leader _followGroup) getPos [50, _angle]);
    } else {
        TRACE_2("Holding",_vehicle,_leaderPos distance2d _vehicle);
        #endif
    };
    sleep 10;
};

true

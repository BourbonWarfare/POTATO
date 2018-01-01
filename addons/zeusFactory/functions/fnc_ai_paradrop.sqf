#include "script_component.hpp"

params [["_vehicleGroup", grpNull, [grpNull]], ["_wpPos", [0, 0, 0], [[]], 3]];
TRACE_2("ai_paradrop",_vehicleGroup,_wpPos);
if (!local _vehicleGroup) exitWith { WARNING_1("Waypoint script ran on non-local group [%1]",_vehicleGroup); };

_wpPos = _wpPos vectorAdd [0,0,125];
private _vehicle = vehicle leader _vehicleGroup;
private _commander = driver _vehicle;

_vehicle flyInHeight 125;
if ((_vehicle distance2D _wpPos) > 50) then {
    _vehicleGroup move _wpPos;
};

waitUntil {sleep 1; (!alive _vehicle) || {!alive _commander} || {(_vehicle distance2D _wpPos) < 100}};
if ((!alive _vehicle) || {!alive _commander}) exitWith {WARNING_2("para problem [veh %1, com %2]",alive _vehicle, alive _commander); true};

// Fly level and straight while dropping infantry:
private _unloadFlightPos = _vehicle getRelPos [500, 0];
_vehicle flyInHeight 125;
_vehicleGroup setSpeedMode "LIMITED";
_vehicleGroup move _unloadFlightPos;

private _altitude = (getPosATL _vehicle) select 2;
private _crewToUnload = (crew _vehicle) select {(group _x) != _vehicleGroup};
TRACE_2("Starting Unload",_altitude,count _crewToUnload);

{
    moveOut _x;
    unassignVehicle _x;

    // Handle Parachute:
    [{
        params ["_vehicle", "_unit"];
        ((isTouchingGround _unit) || {!alive _unit}) || {(((getPosATL _unit) select 2) < 200) && {(_vehicle distance _unit) > 10}}
    }, {
        params ["_vehicle", "_unit"];
        if ((isTouchingGround _unit) || {!alive _unit}) exitWith {};

        private _posASL = getPosASL _unit;
        private _vel = velocity _unit;
        _vel set [2, ((_vel select 2) + (0 max (-0.3 * (_vel select 2))))];

        private _chute = "NonSteerable_Parachute_F" createVehicle _posASL;
        TRACE_2("opening chute",_unit,_chute);
        [_chute] call EFUNC(core,addToCurator);

        //make sure the idiots don't get out
        _unit moveInAny _chute;
        [{
            params ["_unit", "_chute"];
            if ((!alive _unit) || {!alive _chute} || {isTouchingGround _unit}) exitWith {true};
            if ((vehicle _unit) == _chute) then {
                _unit moveInAny _chute;
                TRACE_1("moving into chute",_unit,_chute);
            };
            false
        }, {TRACE_1("finished",_this);}, [_unit, _chute], 5, {TRACE_1("timeout",_this);}] call CBA_fnc_waitUntilAndExecute;

        _chute setPosASL _posASL;
        _chute setVelocity _vel;
    }, [_vehicle, _x]] call CBA_fnc_waitUntilAndExecute;
    sleep 2;
} forEach _crewToUnload;

TRACE_1("Unload Finished",crew _vehicle);

sleep 1;

_vehicleGroup setSpeedMode "NORMAL";
TRACE_1("WP Done",crew _vehicle);
true

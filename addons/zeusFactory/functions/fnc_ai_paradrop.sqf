#include "script_component.hpp"

#define DROP_DELAY 0.4
#define CHECK_DELAY 0.3
#define PARACHUTE_DEPLOY_DELAY 2
#define EXPAND_MULTIPLIER 0.5
#define PARACHUTE "Steerable_Parachute_F"
#define FLY_IN_HEIGHT 125

params [["_vehicleGroup", grpNull, [grpNull]], ["_wpPos", [0, 0, 0], [[]], 3]];
TRACE_2("ai_paradrop",_vehicleGroup,_wpPos);
if (!local _vehicleGroup) exitWith { WARNING_1("Waypoint script ran on non-local group [%1]",_vehicleGroup); };

private _vehicle = vehicle leader _vehicleGroup;
private _pilot = driver _vehicle;

private _dropPos = _wpPos;
private _movePos = _wpPos vectorAdd [0, 0, 125];
private _expandedPos = _dropPos vectorAdd((_dropPos vectorDiff (getPosASL _vehicle)) vectorMultiply EXPAND_MULTIPLIER);

private _prevVelocity = velocityModelSpace _vehicle;
private _heading = _vehicle getDir _dropPos;
_vehicle setDir _heading;
_vehicle setVelocityModelSpace _prevVelocity;

_vehicle doMove _expandedPos;
_pilot doMove _expandedPos;

_vehicleGroup setCombatMode "BLUE";
_vehicleGroup setBehaviour "CARELESS";
_vehicle flyInHeight FLY_IN_HEIGHT;

private _origDot = ((getPosASL _vehicle) vectorDiff _dropPos) vectorDotProduct (_expandedPos vectorDiff _dropPos);

waitUntil {
    private _dot = ((getPosASL _vehicle) vectorDiff _dropPos) vectorDotProduct (_expandedPos vectorDiff _dropPos);
    sleep CHECK_DELAY;
    (_origDot * _dot) < 0
};

// drop
private _crewToUnload = (crew _vehicle) select {(group _x) != _vehicleGroup};
private _planeVelocity = velocity _vehicle;
{
    if ((driver (vehicle _x)) != _x) then {
        _x disableAI "MOVE";

        _x allowDamage false;
        _x disableCollisionWith _vehicle;
        moveOut _x;
        unassignVehicle _x;
        [_x] allowGetIn false;
        _x setDir (getDir _vehicle);

        [{
            params["_unit", "_parachute", "_vehicle", "_planeVelocity"];
            
            private _para = createVehicle [_parachute, [0, 0, 0], [], 0, "NONE"];
            _unit disableCollisionWith _para;
            
            _para setPosASL (getPosASLVisual _unit);
            _para setVectorDirAndUp [vectorDirVisual _unit, vectorUpVisual _unit];
            _para setVelocity _planeVelocity;
            
            _unit moveInDriver _para;
            _unit assignAsDriver _para;
            [_unit] allowGetIn true;
            [_unit] orderGetIn true;
            
            _unit enableCollisionWith _vehicle;
            _unit allowDamage true;
            
        }, [_x, PARACHUTE, _vehicle, _planeVelocity], PARACHUTE_DEPLOY_DELAY] call CBA_fnc_waitAndExecute;

        _x enableAI "MOVE";
        
        sleep DROP_DELAY;
    };
} forEach _crewToUnload;

sleep 5;

true

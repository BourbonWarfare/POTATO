// dispatch
#include "script_component.hpp"

params ["_factoryLogic", "_placeLogic", "_group"];
TRACE_3("dispatch",_factoryLogic,_placeLogic,_group);
if (isNull _factoryLogic || {isNull _placeLogic} || {isNull _group}) exitWith {ERROR("bad dispatch");};

private _transportType = _placeLogic getVariable [QGVAR(transportType), -1];
private _ordersType = _placeLogic getVariable [QGVAR(ordersType), -1];
TRACE_3("",_factoryLogic,_placeLogic,_transportType,_ordersType);
if ((_ordersType < 0) || {_transportType < 0}) exitWith {ERROR("bad transport-orders");};


private _transportInfo = [];
if ((_transportType != TRANSPORT_FOOT) && {_transportInfo = [_factoryLogic, _transportType, _group, _side] call FUNC(createTransport); (_transportInfo isEqualTo [])}) exitWith {
    TRACE_1("No Transport Available",_transportType);
    false
};

while {(count (waypoints _group)) > 0} do {
    TRACE_1("clearing base group waypoint", ((waypoints _group) select 0));
    deleteWaypoint ((waypoints _group) select 0);
};

if (_transportInfo isEqualTo []) then {
    private _baseMove = _group addWaypoint [getPos _placeLogic, 0];
    _baseMove setWaypointType "MOVE";
    TRACE_1("Adding move on foot wp", _baseMove);
} else {
    _transportInfo params ["_vehicle", "_vehicleGroup"];

    _vehicle setDir (_factory getDir _placeLogic);

    TRACE_3("transport",_vehicleGroup,_vehicle,typeOf _vehicle);
    while {(count (waypoints _vehicleGroup)) > 0} do {
        TRACE_1("clearing transport waypoint", ((waypoints _vehicleGroup) select 0));
        deleteWaypoint ((waypoints _vehicleGroup) select 0);
    };

    // Load infantry into vehicle:
    {
        _x moveInCargo _vehicle;
        if ((vehicle _x) != _vehicle) then {
            _x moveInAny _vehicle;
        };
    } forEach (units _group);
    [{
        params ["_group"];
        {
            if (vehicle _x == _x) then {WARNING_1("deleting straggler [%1]",_x); deleteVehicle _x};
        } forEach (units _group);
    }, [_group], 3] call CBA_fnc_waitAndExecute;

    // Unload infantry
    private _tUnload = _vehicleGroup addWaypoint [getPos _placeLogic, 0];
    if (_transportType == TRANSPORT_PARADROP) then {
        _tUnload setWaypointType "SCRIPTED";
        _tUnload setWaypointScript QPATHTOF(functions\DOUBLES(fnc,ai_paradrop).sqf);
    } else {
        _tUnload setWaypointType "TR UNLOAD";
        _tUnload setWaypointTimeout [3,3,3];
        private _bUnload = _group addWaypoint [getPos _placeLogic, 0];
        _bUnload setWaypointType "GETOUT";
        _tUnload synchronizeWaypoint [_bUnload];
    };

    // Create and cleanup a fake helipad so helicopter can land
    if (_transportType == TRANSPORT_HELI) then {
        #ifdef DEBUG_MODE_FULL
        private _dummyPad = "Land_HelipadCircle_F" createVehicle (getPos _placeLogic);
        #else
        private _dummyPad = "Land_HelipadEmpty_F" createVehicle (getPos _placeLogic);
        #endif
        _vehicle setVariable [QGVAR(dummyPad), _dummyPad];
        _tUnload setWaypointStatements ["true", QUOTE(this call FUNC(ai_onHeliUnload))];
    };

    if (_transportType in [TRANSPORT_CAR_FOLLOW, TRANSPORT_APC_FOLLOW]) then {
        // Add waypoint to support the dismounted infantry
        _vehicleGroup setVariable [QGVAR(followGroup), _group];
        private _tFollow = _vehicleGroup addWaypoint [getPos _placeLogic, 0];
        _tFollow setWaypointType "SCRIPTED";
        _tFollow setWaypointScript QPATHTOF(functions\DOUBLES(fnc,ai_vehicleFollow).sqf);
    } else {
        // Transport should RTB and cleanup
        private _tRTB = _vehicleGroup addWaypoint [getPos _factoryLogic, 0];
        _tRTB setWaypointType "MOVE";
        _tRTB setWaypointCompletionRadius 20;
        _tRTB setWaypointStatements ["true", QUOTE(this call FUNC(ai_onRTB))];
    };
};

// At this point, group has waypoints to arrive at logic, Add orders for after arrival
private _radius = _placeLogic getVariable [QGVAR(radius), 200];
_group setVariable [QGVAR(radius), _radius];
TRACE_1("Adding Orders",_ordersType,_radius);

private _ordersWP = _group addWaypoint [getPos _placeLogic, 0];
_ordersWP setWaypointType "MOVE";
private _readyCondition = "diag_log format ['ready Check %1', thisList]; ((count thisList) == ({(!alive _x) || {isTouchingGround _x}} count thisList));";

switch (_ordersType) do {
case (ORDERS_MOVE): {}; // nothing
case (ORDERS_GARRISION): {
        _ordersWP setWaypointStatements [_readyCondition, QUOTE(this call FUNC(ai_garrison))];
    };
case (ORDERS_PATROL): {
        _ordersWP setWaypointStatements [_readyCondition, QUOTE(this call FUNC(ai_patrol))];
    };
case (ORDERS_SEARCH): {
        _ordersWP setWaypointStatements [_readyCondition, QUOTE(this call FUNC(ai_search))];
    };
case (ORDERS_ATTACK): {
        _ordersWP setWaypointStatements [_readyCondition, QUOTE(this call FUNC(ai_attack))];
    };
    default {
        ERROR_1("Bad Order Type [%1]",_ordersType);
    };
};

// Update queue and delete place logic
private _dispatchQueue = _factory getVariable [QGVAR(dispatchQueue), []];
_dispatchQueue deleteAt (_dispatchQueue find _placeLogic);
_factory setVariable [QGVAR(dispatchQueue), _dispatchQueue, true];
[QGVAR(updateFactory), [_factory], [_placeLogic, _factory]] call CBA_fnc_targetEvent;

deleteVehicle _placeLogic;

// Return
true

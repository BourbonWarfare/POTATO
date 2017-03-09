#include "script_component.hpp"

params ["_placeLogic"];
TRACE_1("module_place",_placeLogic);

if (!isServer) exitWith {};


private _factories = (entities QGVAR(factory)) select {_x getVariable [QGVAR(active), false]};
if (_factories isEqualTo []) exitWith {
    WARNING("No Factoies");
    [QGVAR(zeusFeedback), ["No Factories to handle placement"], [_placeLogic]] call CBA_fnc_targetEvent;
    deleteVehicle _placeLogic;
};

[{
    params ["_placeLogic"];
    (isNull _placeLogic) || {_placeLogic getVariable [QGVAR(set), false]}
}, {
    params ["_placeLogic"];
    if (isNull _placeLogic) exitWith {TRACE_1("null",_placeLogic);};

    // Handle Attack Mark order with no mark down (don't exit, user could still place down before they unload)
    private _ordersType = _placeLogic getVariable [QGVAR(ordersType), -1];
    if (_ordersType == ORDERS_ATTACK) then {
        private _currentBeacon = (entities QGVAR(attackBeacon)) param [0, objNull];
        if (isNull _currentBeacon) exitWith {
            [QGVAR(zeusFeedback), ["No Attack Mark Placed"], [_placeLogic]] call CBA_fnc_targetEvent;
        };
    };

    private _factories = (entities QGVAR(factory)) select {_x getVariable [QGVAR(active), false]};
    TRACE_1("active",_factories);

    private _closestRange = 99999999;
    private _closestFactory = objNull;

    {
        // Basic load balancing:
        private _effectiveDistance = (_x distance2d _placeLogic) + 1000 * (count (_x getVariable [QGVAR(dispatchQueue), []]));

        if (_effectiveDistance < _closestRange) then {
            _closestRange = _effectiveDistance;
            _closestFactory = _x;
        };
    } forEach _factories;

    if (isNull _closestFactory) exitWith {
        WARNING_1("no factory to handle request [%1]",_placeLogic);
    };

    private _dispatchQueue = _closestFactory getVariable [QGVAR(dispatchQueue), []];
    _dispatchQueue pushBack _placeLogic;
    _closestFactory setVariable [QGVAR(dispatchQueue), _dispatchQueue, true];

    [QGVAR(updateFactory), [_closestFactory], [_closestFactory]] call CBA_fnc_targetEvent;
    TRACE_3("added",_closestFactory,_closestRange,_dispatchQueue);
}, [_placeLogic]] call CBA_fnc_waitUntilAndExecute;

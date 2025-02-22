#include "script_component.hpp"
/*
 * Author: Bailey
 * Function called when ingress module is initialised in game.
 *
 * Arguments:
 * 1: Ingress Module <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [logicObj] call potato_paradrop_fnc_placeIngress;
 *
 * Public: No
 */
[{
    params ["_ingressModule"];
    private _runAfterSafeStart = _ingressModule getVariable [QGVAR(runAfterSafeStart), 0];
    private _return = false;
    if (_runAfterSafeStart) then {
        _return = !EGVAR(safeStart,safeStartEnabled);
    } else {
        _return = true;
    };
    _return
}, {
    params ["_ingressModule"];
    private _position = getPosASLVisual _ingressModule;
    private _flyInHeight = parseNumber (_ingressModule getVariable [QGVAR(flyInHeight), 150]);
    private _dropDelay = parseNumber (_ingressModule getVariable [QGVAR(dropDelay), 0.3]);
    private _infantryParachuteClassname = _ingressModule getVariable [QGVAR(infantryParachuteType), "Steerable_Parachute_F"];
    private _cargoParachuteClassname = _ingressModule getVariable [QGVAR(cargoParachuteType), "B_Parachute_02_F"];

    private _syncObjects = synchronizedObjects _ingressModule;
    private _dzs = [];
    private _egress = objNull;
    private _vehicles = [];
    {
        if (_x isKindOf QGVAR(dz)) then {
            _dzs pushBack _x;
        };
        if (_x isKindOf QGVAR(exit)) then {
            _egress = _x;
        };
        if (_x isKindOf "Air") then {
            _vehicles pushBack _x;
        };
    } forEach _syncObjects;

    private _ingress = [_position, _flyInHeight, _dropDelay, _infantryParachuteClassname, _cargoParachuteClassname] call FUNC(registerIngress);
    {
        [_ingress, getPosASLVisual _x] call FUNC(registerDz);
    } forEach _dzs;
    [_ingress, getPosASLVisual _egress] call FUNC(registerEgress);

    [FUNC(launch), [_ingress, _vehicles]] call CBA_fnc_execNextFrame;
}, _this] call CBA_fnc_waitUntilAndExecute;

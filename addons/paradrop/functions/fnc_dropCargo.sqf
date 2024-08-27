#include "script_component.hpp"
/*
 * Author: Bailey
 * Drop cargo with parachute
 *
 * Arguments:
 * 1: Cargo to drop <OBJECT>
 * 2: Cargo dropping from <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [MyCargo] call potato_paradrop_fnc_dropCargo;
 *
 * Public: No
 */
params ["_object", "_source", "_parachuteClassname"];

private _planePos = getPosASLVisual _source;
private _planeDir = (vectorNormalized velocity _source) vectorMultiply -1;
(2 boundingBoxReal _source) params ["", "", "_radius"];

detach _object;
_object setPosASL (_planePos vectorAdd (_planeDir vectorMultiply _radius));
_object allowDamage false;
_object disableCollisionWith _source;
_source disableCollisionWith _object;

[{
    params ["_object", "_source", "_parachuteClassname"];
    _object allowDamage true;
    _object enableCollisionWith _source;

    private _chute = createVehicle [_parachuteClassname, [0, 0, 0], [], 0, "NONE"];

    _object disableCollisionWith _chute;
    _chute disableCollisionWith _source;

    _chute setPosASL (getPosASLVisual _object);
    private _objVel = velocity _object;
    _object attachTo [_chute, [0, 0, 0]];

    _chute setVelocity _objVel;

    [{
        params ["_source"];
        ((getPosASLVisual _source) select 2) < 3
    }, {
        params ["_source", "_chute"];
        private _chuteVel = velocity (attachedTo _source);
        detach _source;
        
        _source setVelocity _chuteVel;
    }, [_source, _chute]] call CBA_fnc_waitUntilAndExecute;
}, _this, 2] call CBA_fnc_waitAndExecute;

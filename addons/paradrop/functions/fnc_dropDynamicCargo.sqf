#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles dropping cargo and troops (TODO) from an air vehicle.
 * It begins by dropping vehicles and then drop units. Finally, it cleans up
 * by sending the air vehicle away and then deleting it.
 *
 * Arguments:
 * 0: Vehicle to start dropping (OBJECT, default objNull)
 * 1: Time between drops (SCALAR, default 3)
 * 2: Final direction to head on exfil (SCALAR, default 0)
 *
 * Return Value:
 * Nothing
 *
 * TODOL
 * - Handle infantry drops
 *
 * Public: No
 */
params [
    ["_vehicle", objNull, [objNull]],
    ["_baseDropRate", 3, [3]],
    ["_exFilDir", 0, [0]]
];
private _velocity = velocity _vehicle;
private _realVics = getVehicleCargo _vehicle;
{
    [{
        params ["_obj", "_vel"];
        objNull setVehicleCargo _obj;
        if (_obj getVariable [QGVAR(failDrop), false]) then {
            [{private _chute = attachedTo (_this#0); detach (_this#0); deleteVehicle _chute; (_this#0) setVelocity (_this#1)}, _this, 0.05] call CBA_fnc_waitAndExecute;
        } else {
            [{private _chute = attachedTo (_this#0); _chute setVelocity (_this#1)}, _this, 0.05] call CBA_fnc_waitAndExecute;
        };
        private _smoke = createVehicle ["SmokeShellYellow", ASLToAGL getPosASL _obj, [], 0, "CAN_COLLIDE"];
        _smoke attachTo [_obj, [0, 0, 0]];
    }, [_x, _velocity], _baseDropRate * _forEachIndex + random 1] call CBA_fnc_waitAndExecute;
} forEach _realVics;
private _virtualVics = _vehicle getVariable [QGVAR(virtualCargo), []];
private _offset = _baseDropRate * count _realVics;
{
    [{
        params ["_type", "_fail", "_dropVic"];
        private _dir = direction _dropVic;
        private _posAGLVic = ASLToAGL getPosASL _dropVic;
        private _posAGL = _posAGLVic getPos [-35, _dir];
        _posAGL set [2, _posAGLVic#2];
        private _obj = createVehicle [_type, _posAGL, [], 0, "CAN_COLLIDE"];
        _obj setDir _dir;
        if !(_fail) then {
            private _parachute = createVehicle ["B_Parachute_02_F", ASLToAGL getPosASL _obj, [], 0, "CAN_COLLIDE"];
            _obj attachTo [_parachute, [0,0,5]];
            _parachute setVelocity velocity _dropVic;
        } else {
            _obj setVelocity velocity _dropVic;
        };
        private _smoke = createVehicle ["SmokeShellYellow", ASLToAGL getPosASL _obj, [], 0, "CAN_COLLIDE"];
        _smoke attachTo [_obj, [0, 0, 0]];
    }, _x + [_vehicle], _offset + _baseDropRate * _forEachIndex + random 1] call CBA_fnc_waitAndExecute;
} forEach _virtualVics;
[{_this setVariable [QGVAR(virtualCargo), []]}, _vehicle, _offset + _baseDropRate * count _virtualVics] call CBA_fnc_waitAndExecute;
[{
    params ["_vehicle"];
    !alive _vehicle ||
    {crew _vehicle isEqualTo [driver _vehicle] &&
    {getVehicleCargo _vehicle isEqualTo []} &&
    {[] isEqualTo (_vehicle getVariable [QGVAR(virtualCargo), []])}}
}, {
    params ["_vehicle", "_dir"];
    if !(alive _vehicle) exitWith {};
    private _group = group driver _vehicle;
    private _wp = _group addWaypoint [_vehicle getPos [7000, _dir], 0];
    _group setCurrentWaypoint _wp;
    _wp setWaypointStatements ["true", "if (local this) then {private _vic = vehicle this; deleteVehicleCrew _vic; deleteVehicle _vic}"];
    _vehicle flyInHeightASL [3000, 3000, 3000];
    _wp setWaypointCompletionRadius 100;
    _vehicle limitSpeed 10000;
}, [_vehicle, _exFilDir]] call CBA_fnc_waitUntilAndExecute;

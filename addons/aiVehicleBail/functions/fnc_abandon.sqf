/*
 * Author: Brandon (TCVM)
 * Forces the AI currently in a vehicle to bail out
 *
 * Arguments:
 * 0: The vehicle in which to bail out
 *
 * Return Value:
 * None
 *
 * Example:
 * [tank2] call potato_aiVehicleBail_abandon;
 *
 * Public: No
 */
#include "script_component.hpp"

params["_vehicle"];
systemChat "Bailing out!";

_vehicle allowCrewInImmobile false;

private _center = getPosASL _vehicle;

{
    if !(isPlayer _x) then {
        [[_center, _x, _vehicle], {
            params["_center", "_crewman", "_vehicle"];
            
            private _cX = _center select 0;
            private _cY = _center select 1;
            
            sleep random 1;
            unassignVehicle _crewman;
            _crewman leaveVehicle _vehicle;
            doGetOut _crewman;
            
            private _angle = floor (random 360);
            private _dist = (30 + (random 10));
            
            private _xEscape = _cX + (_dist * cos _angle);
            private _yEscape = _cY + (_dist * sin _angle);
            
            _crewman doMove [_xEscape, _yEscape, 0];
            _crewman setSpeedMode "FULL";
        }] remoteExec ["spawn", _x];
    };
} forEach crew _vehicle;


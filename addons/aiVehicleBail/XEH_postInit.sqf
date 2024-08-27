#include "script_component.hpp"

GVAR(hitpointTypes) = [false] call CBA_fnc_createNamespace;
{
    _x params ["_hitpoints", "_type"];
    {
        GVAR(hitpointTypes) setVariable [_x, _type];
    } forEach _hitpoints;
} forEach [ENGINE_HITPOINTS, HULL_HITPOINTS, TURRET_HITPOINTS, TRACK_HITPOINTS, WHEEL_HITPOINTS];

[QGVAR(bailOut), {
    params["_center", "_crewman", "_vehicle"];
    TRACE_3("bailOut",_center,_crewman,_vehicle);

    if (isPlayer _crewman) exitWith {};

    unassignVehicle _crewman;
    _crewman leaveVehicle _vehicle;
    doGetOut _crewman;

    private _angle = floor (random 360);
    private _dist = (30 + (random 10));
    private _escape = _center getPos [_dist, _angle];

    _crewman doMove _escape;
    _crewman setSpeedMode "FULL";
}] call CBA_fnc_addEventHandler;

["ace_settingsInitialized", {
    TRACE_1("settingsInit",GVAR(enableCrewBailing));

    ["Tank", "init", LINKFUNC(addEventHandler), nil, nil, true] call CBA_fnc_addClassEventHandler;
    ["Wheeled_APC_F", "init", LINKFUNC(addEventHandler), nil, nil, true] call CBA_fnc_addClassEventHandler;
}] call CBA_fnc_addEventHandler;


#include "script_component.hpp"

[QGVAR(bailOut), {
    params["_center", "_crewman", "_vehicle"];
    
    if !(isPlayer _crewman) exitWith {};
    
    private _cX = _center select 0;
    private _cY = _center select 1;
    
    unassignVehicle _crewman;
    _crewman leaveVehicle _vehicle;
    doGetOut _crewman;
    
    private _angle = floor (random 360);
    private _dist = (30 + (random 10));
    
    private _xEscape = _cX + (_dist * cos _angle);
    private _yEscape = _cY + (_dist * sin _angle);
    
    _crewman doMove [_xEscape, _yEscape, 0];
    _crewman setSpeedMode "FULL";
}] call CBA_fnc_addEventHandler;

["ace_settingsInitialized", {
    TRACE_1("settingsInit", GVAR(enableCrewBailing));

    ["Tank", "init", LINKFUNC(addEventHandler), nil, nil, true] call CBA_fnc_addClassEventHandler;
    ["Wheeled_APC_F", "init", LINKFUNC(addEventHandler), nil, nil, true] call CBA_fnc_addClassEventHandler;
}] call CBA_fnc_addEventHandler;


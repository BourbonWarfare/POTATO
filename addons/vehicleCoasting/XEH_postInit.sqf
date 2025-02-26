#include "script_component.hpp"

if (GVAR(enabled)) then {
    addMissionEventHandler ["EntityKilled", {call FUNC(driverDeathHandle);}];
    ["ace_cookoff_cookOff",{call FUNC(vehicleCookOffHandle)}] call CBA_fnc_addEventHandler;

    #ifdef DEBUG_MODE_DRAW_EH
    GVAR(dev_draw3DEH) = addMissionEventHandler ["Draw3D", {[] call FUNC(dev_debugDraw)}];
    #endif
    ["ace_unconscious", {
        params ["_unit", "_unconscious"];
        TRACE_2("uncon",_unit,_unconscious);
        if !(local _unit && _unconscious &&
            !isNull objectParent _unit) exitWith {};
        private _vehicle = vehicle _unit;
        TRACE_4("uncon vehicle",_vehicle,driver _vehicle,_unit == driver _vehicle,speed _vehicle);
        if (_unit == driver _vehicle && speed _vehicle >= 3) then {
            TRACE_2("entering addCoastingVehicle",_vehicle,_unit);
            [_vehicle, _unit] call FUNC(addCoastingVehicle);
        };
    }] call CBA_fnc_addEventHandler;
};

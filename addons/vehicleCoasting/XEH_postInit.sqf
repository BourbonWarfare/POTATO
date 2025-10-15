#include "script_component.hpp"


["CBA_settingsInitialized", {
    TRACE_1("CBA_settingsInitialized",GVAR(chance));
    if (GVAR(chance) > 0) then {
        addMissionEventHandler ["EntityKilled", {call FUNC(driverDeathHandle);}];
        ["ace_cookoff_cookOff",{call FUNC(vehicleCookOffHandle)}] call CBA_fnc_addEventHandler;
        [QACEGVAR(vehicle_damage,bailOut),{call FUNC(forgetTargets)}] call CBA_fnc_addEventHandler;


        #ifdef DEBUG_MODE_DRAW_EH
        GVAR(dev_draw3DEH) = addMissionEventHandler ["Draw3D", {[] call FUNC(dev_debugDraw)}];
        #endif
        ["ace_unconscious", {
            params ["_unit", "_unconscious"];
            TRACE_2("uncon",_unit,_unconscious);
            if !(local _unit && _unconscious && isPlayer _unit &&
                !isNull objectParent _unit) exitWith {};
            private _vehicle = vehicle _unit;
            TRACE_4("uncon vehicle",_vehicle,driver _vehicle,_unit == driver _vehicle,speed _vehicle);
            if (_unit == driver _vehicle && speed _vehicle >= 3) then {
                TRACE_2("entering addCoastingVehicle",_vehicle,_unit);
                [_vehicle, _unit] call FUNC(addCoastingVehicle);
            };
        }] call CBA_fnc_addEventHandler;
    };
}] call CBA_fnc_addEventHandler;

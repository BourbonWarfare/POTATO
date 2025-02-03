#include "script_component.hpp"

if (isServer) then {
    addMissionEventHandler ["EntityKilled", {
        [_this#0] call FUNC(driverDeathHandle);
    }];
    ["ace_cookoff_engineFire",{
        [driver (_this#0)]Q call FUNC(driverDeathHandle);
    }] call CBA_fnc_addEventHandlerArgs;
};

[QGVAR(driveDeathEvent), LINKFUNC(driverDeathHandle)] call CBA_fnc_addEventHandler;
#include "script_component.hpp"

if (isServer) then {
    addMissionEventHandler ["EntityKilled", {
        [_this#0] call FUNC(driverDeathHandle);
    }];
    ["ace_cookoff_cookOff",{_this call FUNC(vehicleCookOffHandle)}] call CBA_fnc_addEventHandler;
    ["ace_cookoff_engineFire",{_this call FUNC(vehicleCookOffHandle)}] call CBA_fnc_addEventHandler;
};

[QGVAR(driveDeathEvent), {LINKFUNC(driverDeathHandle)}] call CBA_fnc_addEventHandler;

#ifdef DEBUG_MODE_DRAW_EH
GVAR(dev_draw3DEH) = addMissionEventHandler ["Draw3D", {[] call FUNC(dev_debugDraw)}];
#endif

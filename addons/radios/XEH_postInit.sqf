#define DEBUG_MODE_FULL
#include "script_component.hpp"

[
    {
        ACEGVAR(common,settingsInitFinished)
    },
    {
        TRACE_2("",GVAR(enabled),hasInterface);
        if (GVAR(enabled) && hasInterface) then {
            [] call FUNC(initializeRadios);
            [FUNC(addAcreBriefing)] call CBA_fnc_execNextFrame;
            
            [
                {
                    GVAR(initialized) && {[player] call ACRE_FUNC(isInitialized)}
                },
                {
                    TRACE_1("",GVAR(runInitNow));
                    [QEGVAR(assignGear,gearAssigned),GVAR(gearEHID)] call CBA_fnc_removeEventHandler;
                    GVAR(gearEHID) = [QEGVAR(assignGear,gearAssigned), FUNC(configureRadios)] call CBA_fnc_addEventHandler;

                    if (GVAR(runInitNow)) then {
                        [] call FUNC(configureRadios);
                    };
                }
            ] call CBA_fnc_waitUntilAndExecute;
        } else {
            [QEGVAR(assignGear,gearAssigned),GVAR(gearEHID)] call CBA_fnc_removeEventHandler;
        };
    }
] call CBA_fnc_waitUntilAndExecute;

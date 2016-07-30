#include "script_component.hpp"

[
    {
        ACEGVAR(common,settingsInitFinished)
    },
    {
        TRACE_2("",GVAR(enabled),hasInterface);
        if (GVAR(enabled) && hasInterface) then {
            [FUNC(initializeRadios)] call CBA_fnc_execNextFrame;

            [
                {
                    GVAR(initialized) && {player getVariable [QEGVAR(assignGear,gearSetup), false]}
                },
                {
                    [] call FUNC(addAcreBriefing);
                    [{[player] call ACRE_FUNC(isInitialized)}, FUNC(configureRadios)] call CBA_fnc_waitUntilAndExecute;
                }
            ] call CBA_fnc_waitUntilAndExecute;
        };
    }
] call CBA_fnc_waitUntilAndExecute;

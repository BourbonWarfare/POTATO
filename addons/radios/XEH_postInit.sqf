#include "script_component.hpp"

[
    {
        ACEGVAR(common,settingsInitFinished)
    },
    {
        if (GVAR(enabled) && hasInterface) then {
            [] call FUNC(initilizeRadios);

            [
                {
                    [] call ACRE_FUNC(isInitilized) && GVAR(initilized)
                },
                {
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

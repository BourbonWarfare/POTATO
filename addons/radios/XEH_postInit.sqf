#include "script_component.hpp"

[
    {
        ACEGVAR(common,settingsInitFinished)
    },
    {
        if (GVAR(enabled)) then {
            [QEGVAR(assignGear,gearAssigned), FUNC(initilizeRadios)] call CBA_fnc_addEventHandler;
        };
    }
] call CBA_fnc_waitUntilAndExecute;

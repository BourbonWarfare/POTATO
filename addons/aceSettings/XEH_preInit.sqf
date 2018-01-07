#include "script_component.hpp"

// turn off RHS engine startup script
RHS_ENGINE_STARTUP_OFF = 1; // any non-nil value turns this off

// Settings Test:
if (isServer) then {
    [{
        if ((ace_medical_level > 1) && {!ace_medical_healHitPointAfterAdvBandage}) then {
            ["potato_adminMsg", ["Warning: Advanced Medical but healHitPointAfterAdvBandage is false", "Mission"]] call CBA_fnc_globalEvent;
        };
    }, [], 5] call CBA_fnc_waitAndExecute;
};

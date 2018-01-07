#include "script_component.hpp"

// handle RHS engine startup script
[
    QGVAR(rhsEngineStartup),
    "CHECKBOX",
    ["RHS Engine startup script", "True on, false off"],
    "POTATO Misc",
    false,
    1,
    { diag_log _this; RHS_ENGINE_STARTUP_OFF = ([0, nil] select _this); }
] call cba_settings_fnc_init;

// Settings Test:
if (isServer) then {
    [{
        if ((ace_medical_level > 1) && {!ace_medical_healHitPointAfterAdvBandage}) then {
            ["potato_adminMsg", ["Warning: Advanced Medical but healHitPointAfterAdvBandage is false", "Mission"]] call CBA_fnc_globalEvent;
        };
    }, [], 5] call CBA_fnc_waitAndExecute;
};

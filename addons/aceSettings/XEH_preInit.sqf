#include "script_component.hpp"

LOG("Setting STUI settings");
STUI_Occlusion = false; // Default: true
// STHud_ShowBearingInVehicle = true; // Default: true
STHud_NoSquadBarMode = true; // Default: false
// STUI_RemoveDeadViaProximity = true; // Default: true


// Settings Test:
if (isServer) then {
    [{
        if ((ace_medical_level > 1) && {!ace_medical_healHitPointAfterAdvBandage}) then {
            ["potato_adminMsg", ["Warning: Advanced Medical but healHitPointAfterAdvBandage is false", "Mission"]] call CBA_fnc_globalEvent;
        };
    }, [], 5] call CBA_fnc_waitAndExecute;
};

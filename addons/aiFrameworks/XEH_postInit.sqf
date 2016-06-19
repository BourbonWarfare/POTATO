#include "script_component.hpp"

VGVAR(ehAdded) = false;

[
    {
        ACEGVAR(common,settingsInitFinished) && {EGVAR(zeusHC,aiTransfered)} && {diag_tickTime > (_this select 0)}
    },
    {
        if (VGVAR(enabled)) then {
            missionNamespace setVariable [VQGVAR(lastSmokeThrown), 0];
            VGVAR(suppressorCache) = [[],[]];
            VGVAR(vehicleWeaponCache) = [[],[]];
            VGVAR(vehicleTypeCache) = [[],[]];

            [VGVAR(executionEnabledSides)] call VFUNC(stringArrayToSideArray);
            [VGVAR(movementEnabledSides)] call VFUNC(stringArrayToSideArray);

            if (!VGVAR(ehAdded)) exitWith { //install EH
                TRACE_1("Adding Man Init EH", VGVAR(ehAdded));
                ["CaManBase", "init", {_this call VFUNC(addToSystem)}, true, [], true] call CBA_fnc_addClassEventHandler;
                VGVAR(ehAdded) = true;
            };
        };
    },
    [diag_tickTime + 1]
] call CBA_fnc_waitUntilAndExecute;
